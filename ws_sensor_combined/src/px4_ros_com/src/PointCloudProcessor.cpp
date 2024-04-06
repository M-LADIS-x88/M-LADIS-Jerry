#include <chrono>
#include <functional>
#include <memory>
#include <string>

//#include <rclcpp/rclcpp.h>
#include "pcl_ros/transforms.hpp"
#include <sensor_msgs/msg/point_cloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/conversions.h>
#include "object_detection.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "bound_detection.cpp"
#include "geometry_msgs/msg/pose_array.hpp"
//#include "predator_detection.cpp"


class PointCloudProcessor : public rclcpp::Node {
public:

  PointCloudProcessor() : Node("PointCloudProcessor") {
    subscriber_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
        "maps/edges", 1,
        std::bind(&PointCloudProcessor::pointCloudCallback, this, std::placeholders::_1));
    predator_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
        "slam_registered_points", 1,
        std::bind(&PointCloudProcessor::predatorCallback, this, std::placeholders::_1));
    posters_ = this->create_publisher<geometry_msgs::msg::PoseArray>("/current_posters",1);
    walls_ = this->create_publisher<geometry_msgs::msg::Pose>("/walls",1);
    tom_ = this->create_publisher<geometry_msgs::msg::Point>("/Tom",1);
  }

private:
  std::vector<Point> centroids_saturated;
  std::vector<Point> centroids_pred;
  std::vector<Point> bounds;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscriber_;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr predator_;
  rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr walls_;
  rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr posters_;
  rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr tom_;

  float euclideanDistanceXY(const Point& a, const Point& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  }

  std::vector<Point> findHighestZPointsNearCentroids(const std::vector<Point>& centroids, 
  const std::vector<std::vector<float>>& wall_matrix, float xy_threshold) {
    std::vector<Point> highest_z_points;

    // Loop over centroids
    for (const auto& centroid : centroids) {
        Point highest_z_point = {0, 0, -std::numeric_limits<float>::max()};
        bool found = false;

        // Loop over wall matrix
        for (const auto& point_vec : wall_matrix) {
            Point point;
            point.x = point_vec[0];
            point.y = point_vec[1];
            point.z = point_vec[2];

            // Calculate distance in the XY plane
            if (euclideanDistanceXY(point, centroid) <= xy_threshold) {
                // Checking if this point has the highest Z value found so far
                if (point.z > highest_z_point.z) {
                    highest_z_point = point;
                    found = true;
                }
            }
        }
      
        if (found) {
            highest_z_points.push_back(highest_z_point);
        }
    }
    return highest_z_points;
  }

  void writeCentroidsToCSVPred(const std::vector<Point>& centroids) {
    // Open an output file stream for writing to a CSV file
    std::ofstream out_file("predator_centroids.csv");

    // Check if the file was successfully opened
    if (!out_file) {
        std::cerr << "Error: Could not open centroids.csv for writing." << std::endl;
        return;
    }

    // Write the header to the CSV file
    out_file << "x,y,z\n";

    // Loop through each centroid to print and write to CSV
    for (const auto& centroid : centroids) {
        // Write to CSV file
        out_file << centroid.x << ','
                 << centroid.y << ','
                 << centroid.z << '\n';
    }
    // File is closed automatically when out_file goes out of scope
}

  void writeBoundsToCSV(const std::vector<Point>& bounds, const std::string& file_name) {
    if (bounds.size() != 4) {
        // Handle the error: bounds vector must contain exactly four elements
        std::cerr << "Error: Bounds vector must contain exactly four elements.\n";
        return;
    }

    // Open the CSV file for writing
    std::ofstream out_file(file_name);
    if (!out_file) {
        std::cerr << "Error: Could not open " << file_name << " for writing.\n";
        return;
    }

    // Write the header
    out_file << "Boundary, X, Y\n";

    // Write the bounds components to the file
    out_file << "pos_x_avg, " << bounds[0].x << ", " << bounds[0].y << "\n";
    out_file << "neg_x_avg, " << bounds[1].x << ", " << bounds[1].y << "\n";
    out_file << "pos_y_avg, " << bounds[2].x << ", " << bounds[2].y << "\n";
    out_file << "neg_y_avg, " << bounds[3].x << ", " << bounds[3].y << "\n";

    // Close the file
    out_file.close();
}
  
  std::vector<Point> filterArena(std::vector<Point> centroids, std::vector<Point> bounds){
    float pos_x = bounds[0].x;
    float neg_x = bounds[1].x;
    float pos_y = bounds[2].y;
    float neg_y = bounds[3].y;

    std::vector<Point> arena_pings;
    float x_bound;
    float y_bound;

    if(norm(pos_x) > norm(neg_x)){
        x_bound = neg_x;
    }
    else{
        x_bound = pos_x;
    }

    if(norm(pos_y) > norm(neg_y)){
        y_bound = neg_y;
    }
    else{
        y_bound = pos_y;
    }

    for(std::size_t i = 0; i < centroids.size(); ++i){
        if(norm(centroids[i].x) < norm(x_bound) && norm(centroids[i].y) < norm(y_bound)){
            arena_pings.push_back(centroids[i]);
        }
    }
    writeCentroidsToCSVPred(arena_pings);

    return arena_pings;

}
  
  void pointCloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
    // Convert PointCloud2 message to PCL PointCloud
    pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>);
    pcl::fromROSMsg(*msg, *pcl_cloud);

    // Extract XYZ matrix
    int n = pcl_cloud->size();
    std::vector<std::vector<float>> xyzi_matrix(n, std::vector<float>(4)); // Create nx4 matrix for xyzi

    for (int i = 0; i < n; ++i) {
      const auto& pt = pcl_cloud->points[i];
      //flip z values for flight cause lidar is upside down
      if (pt.z < 2 && pt.z > -0.1) {
        double mag_dist = std::sqrt(pt.x*pt.x + pt.y+pt.y);
        if(pt.x < 32 && pt.y < 40 && pt.x > -32 && pt.y > -40 && mag_dist > 0.5){
          xyzi_matrix[i][0] = pt.x; // Store x coordinate
          xyzi_matrix[i][1] = pt.y; // Store y coordinate
          xyzi_matrix[i][2] = pt.z; // Store z coordinate
          xyzi_matrix[i][3] = pt.intensity; // Store intensity
        }
      }
    }

    //Delete all CSV Functionality once ready for flight testing
      // Open a CSV file in write mode
    std::ofstream csv_file;
    csv_file.open("output_xyzi_matrix.csv");

    if (csv_file.is_open()) {
        // Writing the headers to the CSV file
        csv_file << "X,Y,Z,I,\n";
    
        // Write matrix data to the CSV file
        for (int i = 0; i < n; ++i) {
            csv_file << xyzi_matrix[i][0] << ", " << xyzi_matrix[i][1] << ", " 
            << xyzi_matrix[i][2] << ", "<< xyzi_matrix[i][3] <<  "\n";
        }
    
        // Close the file
        csv_file.close();
    } else {
        // Handle the error in case the file is not opened
        std::cerr << "Error opening file for writing.\n";
    }
    //structuring xyz array into format of point structs
    std::vector<Point> pcloud;
  
    //iterate through xyz matrix and put into point structs
    for (int i = 0 ; i<n; i++)
    {
      Point p;
      p.x = xyzi_matrix[i][0];
      p.y = xyzi_matrix[i][1];
      p.z = xyzi_matrix[i][3];
      pcloud.push_back(p);
    }

    std::vector<bool> processed(pcloud.size(), false);
    std::vector<std::vector<Point>> clusters;

    std::vector<float> dataset_flatten(pcloud.size() * 3);
    for (size_t i = 0; i < pcloud.size(); ++i) {
        dataset_flatten[3 * i] = pcloud[i].x;
        dataset_flatten[3 * i + 1] = pcloud[i].y;
        dataset_flatten[3 * i + 2] = pcloud[i].z;
    }

    flann::Matrix<float> dataset(dataset_flatten.data(), pcloud.size(), 3);
    //flann::Matrix<float> dataset(flann_points[0].data(), flann_points.size(), 3);

    //Build kd tree index for point cloud
    flann::Index<flann::L2<float>> kdTree(dataset, flann::KDTreeIndexParams(4));
    kdTree.buildIndex();

    // Perform clustering using the k-d tree
     float clusterDistance = 0.5;
     euclideanClusteringUsingKDTree(pcloud, clusterDistance, processed, kdTree, clusters);
    // //euclideanClustering(pcloud);

     //writeAllClusterPointsToSingleCSV(clusters);
     std::vector<Point> centroids = calculateCentroids(clusters);

     centroids_saturated.insert(centroids_saturated.end(),centroids.begin(),centroids.end());

     writeCentroidsToCSV(centroids_saturated,"centroids.csv");

     bounds = calculateBounds(centroids_saturated);

     geometry_msgs::msg::Pose walls_pose;

    // Set the position of the Pose
    walls_pose.position.x = bounds[1].x;
    //walls_pose.position.y = bounds[3].y;
    walls_pose.position.y = -bounds[2].y;
    walls_pose.position.z = 0.0;

    // Set the orientation in the Pose
    walls_pose.orientation.x = bounds[0].x;
    walls_pose.orientation.y = bounds[2].y;
    walls_pose.orientation.z = 0.0;
    walls_pose.orientation.w = 0.0;

    // Publish the Pose message
    walls_->publish(walls_pose);

    writeBoundsToCSV(bounds,"bounds.csv");
    
    // Posters
    std::vector<std::vector<float>> wall_matrix;
    std::vector<Point> walls;
    float tolerance = 1;
    float xmin = bounds[1].x;
    float xmax = bounds[0].x;
    //float ymin = bounds[3].y;
    float ymax = bounds[2].y;
    for (const auto& point : xyzi_matrix) {
      float x = point[0];
      float y = point[1];
      float i = point[3];
      float threshold = 25;
      // Only include points within the expanded bounds
      if (x >= xmin - tolerance && x <= xmax + tolerance &&
          y >= -ymax - tolerance && y <= ymax + tolerance &&
          i >= threshold) {
          wall_matrix.push_back(point);
      }
    }
    for (size_t i = 0 ; i<wall_matrix.size(); i++)
    {
      Point p;
      p.x = wall_matrix[i][0];
      p.y = wall_matrix[i][1];
      p.z = 1;
      walls.push_back(p);
    }
    std::cout << walls.size() << std::endl;
    if(!walls.empty()){
      std::vector<bool> wall_processed(walls.size(), false);
      std::vector<std::vector<Point>> wall_clusters;

      std::vector<float> wall_dataset_flatten(walls.size() * 3);
      for (size_t i = 0; i < walls.size(); ++i) {
          wall_dataset_flatten[3 * i] = walls[i].x;
          wall_dataset_flatten[3 * i + 1] = walls[i].y;
          wall_dataset_flatten[3 * i + 2] = walls[i].z;
      }
      flann::Matrix<float> wall_dataset(wall_dataset_flatten.data(), walls.size(), 3);
      //Build kd tree index for point cloud
      flann::Index<flann::L2<float>> wall_kdTree(wall_dataset, flann::KDTreeIndexParams(4));
      wall_kdTree.buildIndex();
      // Perform clustering using the k-d tree
      clusterDistance = 0.8;
      euclideanClusteringUsingKDTree(walls, clusterDistance, wall_processed, wall_kdTree, wall_clusters);
      // //euclideanClustering(pcloud);

      //writeAllClusterPointsToSingleCSV(clusters);
      std::vector<Point> wall_centroids = calculateCentroids(wall_clusters);

      // Check points nearby centroid for z range.

      writeCentroidsToCSV(wall_centroids,"wall_centroids.csv");
      
      std::vector<Point> posters = findHighestZPointsNearCentroids(wall_centroids, wall_matrix, 1.0f);

      posters.erase(std::remove_if(posters.begin(), posters.end(),
       [](const Point& pt) {return pt.z > 1; }), posters.end());
      writeCentroidsToCSV(posters,"z.csv");


      geometry_msgs::msg::PoseArray posters_pose_array;
      posters_pose_array.header.stamp = this->get_clock()->now();  // Set the timestamp
      posters_pose_array.header.frame_id = "yolo";  // Set the appropriate frame

      // Convert all `Point` objects to `Pose` messages
      for (const auto& point : posters) {
        geometry_msgs::msg::Pose pose;

        // Set the position from the Point
        pose.position.x = point.x;
        pose.position.y = point.y;
        pose.position.z = point.z;

        // Set the orientation to 0 since we don't have orientation information from Point
        pose.orientation.x = 0.0;
        pose.orientation.y = 0.0;
        pose.orientation.z = 0.0;
        pose.orientation.w = 1.0; 

        // Add this pose to the PoseArray
        posters_pose_array.poses.push_back(pose);
      }

      // Now publish the PoseArray message
      posters_->publish(posters_pose_array);
    }
};
  void predatorCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg){
    pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>);
    pcl::fromROSMsg(*msg, *pcl_cloud);

    // Extract XYZ matrix
    int n = pcl_cloud->size();
    //rclcpp::Subscription<sensor_msgs::msg::Point>
    std::vector<std::vector<float>> xyzi_matrix(n, std::vector<float>(4)); // Create nx4 matrix for xyzi

    bounds = calculateBounds(centroids_saturated);
    float pos_x = bounds[0].x;
    float neg_x = bounds[1].x;
    float pos_y = bounds[2].y;
    float neg_y = bounds[3].y;

    std::vector<Point> arena_pings;

    for (int i = 0; i < n; ++i) {
      const auto& pt = pcl_cloud->points[i];
      //flip z values for flight cause lidar is upside down
      if (pt.z < 10 && pt.z > -1) {
        //double mag_dist = std::sqrt(pt.x*pt.x + pt.y+pt.y);
        if(neg_y == 0){
          neg_y = -pos_y;
        }
        if(pt.x < pos_x - 1.2 && pt.x > neg_x + 1.2 && pt.y < pos_y - 1.2 && pt.y > neg_y + 1.2){
        xyzi_matrix[i][0] = pt.x; // Store x coordinate
        xyzi_matrix[i][1] = pt.y; // Store y coordinate
        xyzi_matrix[i][3] = pt.z; // Store z coordinate
        xyzi_matrix[i][2] = pt.intensity; // Store intensity
        }
      }
    }
    //structuring xyz array into format of point structs
    std::vector<Point> pcloud;
  
    //iterate through xyz matrix and put into point structs
    for (int i = 0 ; i<n; i++)
    {
      Point p;
      p.x = xyzi_matrix[i][0];
      p.y = xyzi_matrix[i][1];
      p.z = xyzi_matrix[i][2];
      pcloud.push_back(p);
    }

      // Open a CSV file in write mode
    std::ofstream csv_file;
    csv_file.open("predator_xyzi_matrix.csv");

    if (csv_file.is_open()) {
        // Writing the headers to the CSV file
        csv_file << "X,Y,Z,I,\n";
    
        // Write matrix data to the CSV file
        for (int i = 0; i < n; ++i) {
            csv_file << xyzi_matrix[i][0] << ", " << xyzi_matrix[i][1] << ", " 
            << xyzi_matrix[i][2] << ", "<< xyzi_matrix[i][3] <<  "\n";
        }
    
        // Close the file
        csv_file.close();
    } else {
        // Handle the error in case the file is not opened
        std::cerr << "Error opening file for writing.\n";
    }

    std::vector<bool> processed(pcloud.size(), false);
    std::vector<std::vector<Point>> clusters;

    
    std::vector<float> dataset_flatten(pcloud.size() * 3);
    for (size_t i = 0; i < pcloud.size(); ++i) {
        dataset_flatten[3 * i] = pcloud[i].x;
        dataset_flatten[3 * i + 1] = pcloud[i].y;
        dataset_flatten[3 * i + 2] = pcloud[i].z;
    }
    flann::Matrix<float> dataset(dataset_flatten.data(), pcloud.size(), 3);

    //Build kd tree index for point cloud
    flann::Index<flann::L2<float>> kdTree(dataset, flann::KDTreeIndexParams(4));
    kdTree.buildIndex();

    // Perform clustering using the k-d tree
     float clusterDistance = 0.5;
     euclideanClusteringUsingKDTreePred(pcloud, clusterDistance, processed, kdTree, clusters);
    // //euclideanClustering(pcloud);

     //writeAllClusterPointsToSingleCSV(clusters);
     std::vector<Point> centroids = calculateCentroids(clusters);
   
    writeCentroidsToCSVPred(centroids);

    if (centroids.size() <= 1){
    // Do not publish anything if (0,0,0) is the only point or the vector is empty
    return;
  }

  // Variables to hold the sum of x, y and z coordinates, and the count of valid points
  float sum_x = 0.0, sum_y = 0.0, sum_z = 0.0;
  int count = 0;

  for (const auto& point : centroids) {
    // Exclude the (0,0,0) point
    if (!(point.x == 0 && point.y == 0 && point.z == 0)) {
      sum_x += point.x;
      sum_y += point.y;
      sum_z += point.z;
      count++;
    }
  }

  if (count > 0) { // Check to prevent division by zero
    float avg_x = sum_x / count;
    float avg_y = sum_y / count;
    float avg_z = sum_z / count;

    // Create a Point message for the average
    geometry_msgs::msg::Point avg_point;
    avg_point.x = avg_x;
    avg_point.y = avg_y;
    avg_point.z = avg_z;

    // Publish the average point
    tom_->publish(avg_point);
  }

    
  };
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PointCloudProcessor>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
};

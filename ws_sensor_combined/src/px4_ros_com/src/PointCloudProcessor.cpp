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


class PointCloudProcessor : public rclcpp::Node {
public:
//or try "maps/edges"
//og is "slam_registered_points"
  PointCloudProcessor() : Node("PointCloudProcessor") {
    // Subscribe to PointCloud2 topic
    subscriber_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
        "maps/edges", 1,
        std::bind(&PointCloudProcessor::pointCloudCallback, this, std::placeholders::_1));
  }

private:
  std::vector<Point> centroids_saturated;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscriber_;
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
  
  
  void pointCloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
    //RCLCPP_INFO(this->get_logger(), "Receiving Point Cloud...");
    // Convert PointCloud2 message to PCL PointCloud
    pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>);
    pcl::fromROSMsg(*msg, *pcl_cloud);

    // Extract XYZ matrix
    int n = pcl_cloud->size();
    //rclcpp::Subscription<sensor_msgs::msg::Point>
    std::vector<std::vector<float>> xyzi_matrix(n, std::vector<float>(4)); // Create nx4 matrix for xyzi


    for (int i = 0; i < n; ++i) {
      const auto& pt = pcl_cloud->points[i];
      if (pt.z < 2 && pt.z > -0.1) {
        double mag_dist = std::sqrt(pt.x*pt.x + pt.y+pt.y);
        if(pt.x < 32 && pt.y < 40 && pt.x > -32 && pt.y > -40 && mag_dist > 0.5){

        xyzi_matrix[i][0] = pt.x; // Store x coordinate
        xyzi_matrix[i][1] = pt.y; // Store y coordinate
        xyzi_matrix[i][3] = pt.z; // Store z coordinate
        xyzi_matrix[i][2] = pt.intensity; // Store intensity
        }
      }
    }
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
      p.z = xyzi_matrix[i][2];
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

     writeAllClusterPointsToSingleCSV(clusters);
     std::vector<Point> centroids = calculateCentroids(clusters);

     centroids_saturated.insert(centroids_saturated.end(),centroids.begin(),centroids.end());

     writeCentroidsToCSV(centroids_saturated);

     std::vector<Point> bounds = calculateBounds(centroids_saturated);

     writeBoundsToCSV(bounds,"bounds.csv");



};
};


int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PointCloudProcessor>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
};

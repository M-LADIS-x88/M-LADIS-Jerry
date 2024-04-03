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


class PointCloudProcessor : public rclcpp::Node {
public:
  PointCloudProcessor() : Node("PointCloudProcessor") {
    // Subscribe to PointCloud2 topic
    subscriber_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
        "/scan", 10,
        std::bind(&PointCloudProcessor::pointCloudCallback, this, std::placeholders::_1));
  }

private:
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscriber_;
  
  void pointCloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
    //RCLCPP_INFO(this->get_logger(), "Receiving Point Cloud...");
    // Convert PointCloud2 message to PCL PointCloud
    pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>);
    pcl::fromROSMsg(*msg, *pcl_cloud);

    // Extract XYZ matrix
    int n = pcl_cloud->size();
    std::vector<std::vector<float>> xyzi_matrix(n, std::vector<float>(4)); // Create nx4 matrix for xyzi


    // Assuming pcl_cloud is a pointer to a data structure containing 3D points
    for (int i = 0; i < n; ++i) {
      const auto& pt = pcl_cloud->points[i];
      if (pt.z < 2 && pt.z > -1) {
        xyzi_matrix[i][0] = pt.x; // Store x coordinate
        xyzi_matrix[i][1] = pt.y; // Store y coordinate
        xyzi_matrix[i][2] = pt.z; // Store z coordinate
        xyzi_matrix[i][3] = pt.intensity; // Store intensity
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
     float clusterDistance = 5.0;
     euclideanClusteringUsingKDTree(pcloud, clusterDistance, processed, kdTree, clusters);
    // //euclideanClustering(pcloud);

     writeAllClusterPointsToSingleCSV(clusters);
     std::vector<Point> centroids = calculateCentroids(clusters);

     writeCentroidsToCSV(centroids);
   

    // Print the stored matrix (optional)
    //std::cout << "Stored Matrix:\n";
    //for (int i = 0; i < n; ++i)
    //{
    //    std::cout << xyz_matrix[i][0] << " " << xyz_matrix[i][1] << " " << xyz_matrix[i][2] << "\n";
    //}

      // Create Open3D point cloud


    // Now you have the XYZ matrix in 'xyz_matrix'
    // You can further process or use it as needed
};

};
int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PointCloudProcessor>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
};

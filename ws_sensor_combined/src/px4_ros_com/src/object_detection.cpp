#include <iostream>
#include <vector>
#include <random>
#include <flann/flann.hpp>
#include <lz4.h>
#include "nanoflann.hpp"
#include <unordered_set>
#include <cmath>
#include <fstream>


//compile using
//g++ -o object_detection  object_detection.cpp -llz4
//run using ./Testing

using namespace std;

//Dependencies:
//nanoflann - for KDTrees
//run sudo apt install libnanoflann-dev
//LZ4 - called by flann
//sudo apt install liblz4-dev

// Define your 3D point type
constexpr double clusterDistance = 0.5; // Maximum distance between points in a cluster
constexpr size_t minClusterSize = 100;    // Minimum number of points to form a cluster


struct Point
{
    float x, y, z;
    bool processed; // Flag to mark if the point has been processed

    //default constructor
    Point() : x(0.0f), y(0.0f), z(0.0f), processed(false) {}

    // Constructor to initialize Point object
    Point(float x_val, float y_val, float z_val) : x(x_val), y(y_val), z(z_val), processed(false) {}
};

struct BoundingBox {
    float min_x, max_x;
    float min_y, max_y;
    float min_z, max_z;
};

struct obj
{
    BoundingBox bounding;
    Point centroid;

};
BoundingBox computeBoundingBox(const std::vector<Point>& cluster) {
    BoundingBox bbox;
    bbox.min_x = std::numeric_limits<float>::max();
    bbox.max_x = std::numeric_limits<float>::lowest();
    bbox.min_y = std::numeric_limits<float>::max();
    bbox.max_y = std::numeric_limits<float>::lowest();
    bbox.min_z = std::numeric_limits<float>::max();
    bbox.max_z = std::numeric_limits<float>::lowest();

    for (const auto& point : cluster) {
        bbox.min_x = std::min(bbox.min_x, point.x);
        bbox.max_x = std::max(bbox.max_x, point.x);
        bbox.min_y = std::min(bbox.min_y, point.y);
        bbox.max_y = std::max(bbox.max_y, point.y);
        bbox.min_z = std::min(bbox.min_z, point.z);
        bbox.max_z = std::max(bbox.max_z, point.z);
    }

    return bbox;
}

std::vector<BoundingBox> computeBoxes(const std::vector<std::vector<Point>>& clusters){
    std::vector<BoundingBox> boxes;
    BoundingBox box;
    for(const auto& cluster : clusters){
        box = computeBoundingBox(cluster);
        boxes.push_back(box);
    }

    return boxes;
}

// Euclidean distance calculation
float euclideanDistance(const Point& p1, const Point& p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    float dz = p1.z - p2.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

// Method to perform Euclidean clustering manually
std::vector<std::vector<Point>> euclideanClustering(const std::vector<Point>& points) {
    std::vector<std::vector<Point>> clusters; // Vector of vectors to store clusters
    for (size_t i = 0; i < points.size(); ++i) {
        if (!points[i].processed) {
            std::vector<Point> cluster;
            cluster.push_back(points[i]); // Add current point to the cluster

            for (size_t j = i + 1; j < points.size(); ++j) {
                if (!points[j].processed) {
                    float distance = euclideanDistance(points[i], points[j]);
                    if (distance <= clusterDistance) {
                        cluster.push_back(points[j]); // Add point to the cluster
                    }
                }
            }

            if (cluster.size() >= minClusterSize) {
                for (size_t count = 0; count < cluster.size(); ++count) {
                    cluster[count].processed = true;
                }
                clusters.push_back(cluster);
            
            }
        }
    }
    return clusters;   
}


Point calculateCentroid(const std::vector<Point>& cluster) {
    float x_sum = 0.0f, y_sum = 0.0f, z_sum = 0.0f;
    for (const auto& point : cluster) {
        x_sum += point.x;
        y_sum += point.y;
        z_sum += point.z;
    }
    // The centroid is the average of the points in the cluster
    Point centroid(x_sum / cluster.size(), y_sum / cluster.size(), z_sum / cluster.size());
    return centroid;
}

// Function to calculate centroids for a vector of clusters
std::vector<Point> calculateCentroids(const std::vector<std::vector<Point>>& clusters) {
    std::vector<Point> centroids;
    centroids.reserve(clusters.size()); // Reserve space to prevent reallocation
    for (const auto& cluster : clusters) {
        centroids.push_back(calculateCentroid(cluster)); // Calculate and store centroid
    }
    return centroids;
}

// Function to print centroids
void printCentroids(const std::vector<Point>& centroids) {
    std::cout << "Centroids:" << std::endl;
    for (const auto& centroid : centroids) {
        std::cout << "Centroid - x: " << centroid.x << ", y: " << centroid.y << ", z: " << centroid.z << std::endl;
    }
}
// Function to generate a matrix of points with clusters and centroids
std::vector<Point> generatePointsWithClusters(int num_points, int num_clusters) {
    // Centroids for each cluster
    std::vector<Point> centroids = {
        {1.0, 2.0, 3.0},    // Cluster 1 centroid
        {8.0, 9.0, 10.0},   // Cluster 2 centroid
        {15.0, 16.0, 17.0}, // Cluster 3 centroid
        {22.0, 23.0, 24.0}, // Cluster 4 centroid
        {29.0, 30.0, 31.0}  // Cluster 5 centroid
    };  

    // Generate points around the centroids
    std::vector<Point> points;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<float> distribution(0.0, 0.5); // Gaussian distribution with mean 0 and standard deviation 0.5

    for (int i = 0; i < num_points; ++i) {
        int cluster_idx = i % num_clusters; // Assign points to clusters cyclically
        Point p;
        p.x = centroids[cluster_idx].x + distribution(gen);
        p.y = centroids[cluster_idx].y + distribution(gen);
        p.z = centroids[cluster_idx].z + distribution(gen);
        points.push_back(p);
    }

    return points;
}
std::vector<obj> outputObjects(vector<Point> centroids, vector<BoundingBox> boxes){
    std::vector<obj> objects;
    for (size_t i = 0; i < centroids.size(); ++i) {
        obj object;
        object.centroid = centroids[i];
        object.bounding = boxes[i];
        objects.push_back(object);
    }
    return objects;
}
// Function to print centroids to console and write them to a CSV file
void writeCentroidsToCSV(const std::vector<Point>& centroids) {
    // Open an output file stream for writing to a CSV file
    std::ofstream out_file("centroids.csv");

    // Check if the file was successfully opened
    if (!out_file) {
        std::cerr << "Error: Could not open centroids.csv for writing." << std::endl;
        return;
    }

    // Write the header to the CSV file
    out_file << "x,y,z\n";

    // Loop through each centroid to print and write to CSV
    for (const auto& centroid : centroids) {
        // Print to console
        // std::cout << "Centroid - x: " << centroid.x 
        //           << ", y: " << centroid.y 
        //           << ", z: " << centroid.z << std::endl;
        
        // Write to CSV file
        out_file << centroid.x << ','
                 << centroid.y << ','
                 << centroid.z << '\n';
    }

    // File is closed automatically when out_file goes out of scope
}
void euclideanClusteringUsingKDTree(
    const std::vector<Point>& points,
    float searchRadius,
    std::vector<bool>& processed,
    flann::Index<flann::L2<float>>& kdTree,
    std::vector<std::vector<Point>>& clusters) {



    for (size_t i = 0; i < points.size(); ++i) {
        if (processed[i]) continue;

        //inside for loop to resize or reallocate on each iteration, fight memory leaks
        std::vector<std::vector<int>> indices;
        std::vector<std::vector<float>> dists;
        std::vector<int> clusterIndices;
        clusterIndices.push_back(i); // Include this point
        processed[i] = true; // Mark it as processed
        
        // Build a list of points belonging to this cluster
        for (size_t j = 0; j < clusterIndices.size(); j++) {
            int idx = clusterIndices[j];
            std::vector<float> query_point = { points[idx].x, points[idx].y, points[idx].z };
            flann::Matrix<float> query_mat(&query_point[0], 1, 3);
            
            // Perform a radius search to find all neighbors
            indices.clear();
            dists.clear();
            kdTree.radiusSearch(query_mat, indices, dists, searchRadius * searchRadius, flann::SearchParams());
            
            for (size_t k = 0; k < indices[0].size(); k++) {
                size_t nIndex = indices[0][k];
                if (!processed[nIndex]) {
                    processed[nIndex] = true;
                    clusterIndices.push_back(nIndex); // Add to current cluster
                }
            }
        }
        
        // Convert indices to actual points for this cluster
        std::vector<Point> cluster;
        cluster.reserve(clusterIndices.size());
        for (int idx : clusterIndices) {
            cluster.push_back(points[idx]);
        }
        
        if (cluster.size() >= minClusterSize) {
            clusters.push_back(cluster);
        }
    }
}


void writeAllClusterPointsToSingleCSV(const std::vector<std::vector<Point>>& clusters) {
    // Open an output file stream for writing to the CSV file
    std::ofstream out_file("all_clusters.csv");

    // Check if the file was opened successfully
    if (!out_file.is_open()) {
        std::cerr << "Cannot open all_clusters.csv for writing." << std::endl;
        return;
    }

    // Optionally, write a header to the CSV
    out_file << "cluster_id,x,y,z\n";

    // Write points of each cluster into the file
    for (size_t i = 0; i < clusters.size(); ++i) {
        for (const auto& point : clusters[i]) {
            // Include the cluster index as the first column
            out_file << i << ',' << point.x << ',' << point.y << ',' << point.z << '\n';
        }
    }

    // Close the file
    out_file.close();
}


// int main() {
//     const int num_points = 1000;
//     const int num_clusters = 5;

//     // Generate points with clusters and centroids
//     vector<Point> points = generatePointsWithClusters(num_points, num_clusters);


//     // Print the first few points to verify
//     std::cout << "Matrix of points:" << std::endl;
//     for (int i = 0; i < std::min(num_points, 10); ++i) {
//         std::cout << "x: " << points[i].x << ", y: " << points[i].y << ", z: " << points[i].z << std::endl;
//     }

//     std::vector<bool> processed(points.size(), false);
//     std::vector<std::vector<Point>> clusters;

//     // Create and build a k-d tree index for point cloud
//     std::vector<std::vector<float>> flann_points(points.size(), std::vector<float>(3));
//     for (size_t i = 0; i < points.size(); ++i) {
//         flann_points[i][0] = points[i].x;
//         flann_points[i][1] = points[i].y;
//         flann_points[i][2] = points[i].z;
//     }
//     flann::Matrix<float> dataset(flann_points[0].data(), flann_points.size(), 3);
//     flann::Index<flann::L2<float>> kdTree(dataset, flann::KDTreeIndexParams(4));
//     kdTree.buildIndex();

//     // Perform clustering using the k-d tree
//     euclideanClusteringUsingKDTree(points, clusterDistance, processed, kdTree, clusters);
//     std::vector<Point> centroids = calculateCentroids(clusters);
//     printCentroids(centroids);

    

// //     // flann::Index<flann::L2<float>> kdTree(flann::KDTreeIndexParams(4)); // 4 is the branching factor
// //     // buildKDTree(points, kdTree);


// //     // std::vector<bool> processed(points.size(), false);
// //     // std::vector<std::vector<Point>> clusteredData = euclideanClustering(points);


// //     // vector<Point> centroids = calculateCentroids(clusteredData);


// //     // printCentroids(centroids);

// //     // std::vector<BoundingBox> boxes = computeBoxes(clusteredData);

//     return 0;
// }
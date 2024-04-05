#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
//#include "object_detection.cpp"
void writeCentroidsToCSVPred(const std::vector<Point>& centroids,string filename) {
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
    writeCentroidsToCSVPred(arena_pings,"predator_centroids.csv");

    return arena_pings;

}


void findPredator(std::vector<Point> centroids, std::vector<Point> bounds){
    //std::vector<Point> pred_candidates = filterArena(centroids,bounds);
    writeCentroidsToCSVPred(centroids,"predator_centroids.csv");

}
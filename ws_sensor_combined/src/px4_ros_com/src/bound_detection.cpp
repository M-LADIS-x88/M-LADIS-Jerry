#include <chrono>
#include <functional>
#include <memory>
#include <string>

//#include <rclcpp/rclcpp.h>
//#include "object_detection.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
//#include "PointCloudProcessor.cpp"

using namespace std;
bool isPositiveY(const Point& p) {
    return p.y > 0 && norm(p.x) < 1;
}
// Named function to check for negative y
bool isNegativeY(const Point& p) {
    return p.y < 0 && norm(p.x) < 1;
}

// Named function to check for positive x
bool isPositiveX(const Point& p) {
    return p.x > 0;
}

// Named function to check for negative x
bool isNegativeX(const Point& p) {
    return p.x < 0;
}
Point calculateWeightedAverage(const std::vector<Point>& points,
                               std::function<bool(const Point&)> condition) {
    float sumWeightX = 0.0f, sumWeightY = 0.0f, sumWeights = 0.0f;
    for (const Point& p : points) {
        if (condition(p)) {
            float dist = std::sqrt(p.x * p.x + p.y * p.y); // 2D distance from the origin
            float weight = std::exp(-dist); // Exponential weight based on distance
            sumWeightX += weight * p.x;
            sumWeightY += weight * p.y;
            sumWeights += weight;
        }
    }
    // Avoid division by zero if no points meet the condition    // Do something with the averaged points...
    // ...
    if (sumWeights == 0) {
        return Point(); // Return a default Point if no points satisfy the condition
    }
    return Point(sumWeightX / sumWeights, sumWeightY / sumWeights, 0.0f);
}

// Functions for specific conditions:
Point calculatePositiveYWeightedAverage(const std::vector<Point>& points) {
    return calculateWeightedAverage(points, isPositiveY);
}

Point calculateNegativeYWeightedAverage(const std::vector<Point>& points) {
    return calculateWeightedAverage(points, isNegativeY);
}

Point calculatePositiveXWeightedAverage(const std::vector<Point>& points) {
    return calculateWeightedAverage(points, isPositiveX);
}

// Function using the named function for negative x condition
Point calculateNegativeXWeightedAverage(const std::vector<Point>& points) {
    return calculateWeightedAverage(points, isNegativeX);
}

// Example usage:
std::vector<Point> calculateBounds(std::vector<Point> centr_sat) {
    Point pos_y_avg = calculatePositiveYWeightedAverage(centr_sat);
    Point neg_y_avg = calculateNegativeYWeightedAverage(centr_sat);
    Point pos_x_avg = calculatePositiveXWeightedAverage(centr_sat);
    Point neg_x_avg = calculateNegativeXWeightedAverage(centr_sat);

    std::vector<Point> bounds = {pos_x_avg,neg_x_avg,pos_y_avg,neg_y_avg};

    return bounds;
}


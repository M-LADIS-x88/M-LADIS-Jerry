#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "std_msgs/msg/float64.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

class OdometryProcessor : public rclcpp::Node
{
public:
    OdometryProcessor()
    : Node("odometry_processor")
    {
        position_publisher_ = this->create_publisher<geometry_msgs::msg::Point>("/position", 10);
        yaw_publisher_ = this->create_publisher<std_msgs::msg::Float64>("/yaw", 10);
        subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/slam_odom", 10,
            std::bind(&OdometryProcessor::odometry_callback, this, std::placeholders::_1));
    }

private:
    void odometry_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        geometry_msgs::msg::Point position_msg;
        position_msg.x = msg->pose.pose.position.x;
        position_msg.y = -msg->pose.pose.position.y;
        position_msg.z = -msg->pose.pose.position.z;
        position_publisher_->publish(position_msg);

        std_msgs::msg::Float64 yaw_msg;
        yaw_msg.data = calculate_yaw(msg->pose.pose.orientation);
        yaw_publisher_->publish(yaw_msg);
    }

    double calculate_yaw(const geometry_msgs::msg::Quaternion& quaternion)
    {
        tf2::Quaternion tf_quaternion;
        tf2::fromMsg(quaternion, tf_quaternion);
        double roll, pitch, yaw;
        tf2::Matrix3x3(tf_quaternion).getRPY(roll, pitch, yaw);
        return yaw;
    }

    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr position_publisher_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr yaw_publisher_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<OdometryProcessor>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
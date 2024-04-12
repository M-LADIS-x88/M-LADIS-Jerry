#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/point.hpp>
#include "nav_msgs/msg/odometry.hpp"
#include <px4_msgs/msg/vehicle_odometry.hpp>

class VisLocGPSSpoofNode : public rclcpp::Node {
public:
    VisLocGPSSpoofNode() : Node("vis_loc_GPS_spoof") {
        // Initialize subscriber and publisher.
        position_subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/slam_odom", 
            10, 
            [this](const nav_msgs::msg::Odometry::SharedPtr msg) {
                this->positionCallback(msg);
            }
        );

        odometry_publisher_ = this->create_publisher<px4_msgs::msg::VehicleOdometry>(
            "/fmu/in/vehicle_visual_odometry",
            10
        );
    }

private:
    void positionCallback(const nav_msgs::msg::Odometry::SharedPtr msg) {
        // Convert the Point message to a VehicleOdometry message.
        auto odom_msg = px4_msgs::msg::VehicleOdometry();
        odom_msg.timestamp = this->get_clock()->now().nanoseconds();
        // Populate odometry message using incoming point data.
        
        odom_msg.q[1] = msg->pose.pose.orientation.x;
        odom_msg.q[2] = msg->pose.pose.orientation.y;
        odom_msg.q[3] = msg->pose.pose.orientation.z;
        odom_msg.q[4] = msg->pose.pose.orientation.w;

        // Set additional required fields to zero or defaults. You may need to adjust these
        // depending on PX4's expectations and your application logic.
        // Note: This is a simplified example; the actual conversion must be appropriate
        // for the position information to be usable as odometry data in your application.
        odom_msg.pose_frame = odom_msg.POSE_FRAME_NED;
        odom_msg.velocity_frame = odom_msg.VELOCITY_FRAME_NED;

        // Publish the converted message.
        odometry_publisher_->publish(odom_msg);
    }

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr position_subscription_;
    rclcpp::Publisher<px4_msgs::msg::VehicleOdometry>::SharedPtr odometry_publisher_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<VisLocGPSSpoofNode>());
    rclcpp::shutdown();
    return 0;
}

/*class VisLocGPSSpoofNode : public rclcpp::Node {
public:
    VisLocGPSSpoofNode() : Node("vis_loc_GPS_spoof") {
        // Initialize subscriber and publisher.
        position_subscription_ = this->create_subscription<geometry_msgs::msg::Point>(
            "/position", 
            10, 
            [this](const geometry_msgs::msg::Point::SharedPtr msg) {
                this->positionCallback(msg);
            }
        );

        odometry_publisher_ = this->create_publisher<px4_msgs::msg::VehicleOdometry>(
            "/fmu/in/vehicle_visual_odometry",
            10
        );
    }

private:
    void positionCallback(const geometry_msgs::msg::Point::SharedPtr msg) {
        // Convert the Point message to a VehicleOdometry message.
        auto odom_msg = px4_msgs::msg::VehicleOdometry();
        odom_msg.timestamp = this->get_clock()->now().nanoseconds();
        // Populate odometry message using incoming point data.
        odom_msg.position[1] = msg->x;
        odom_msg.position[2] = msg->y;
        odom_msg.position[3] = msg->z;
        //odom_msg.q[1] = msg

        // Set additional required fields to zero or defaults. You may need to adjust these
        // depending on PX4's expectations and your application logic.
        // Note: This is a simplified example; the actual conversion must be appropriate
        // for the position information to be usable as odometry data in your application.
        odom_msg.pose_frame = odom_msg.POSE_FRAME_NED;

        // Publish the converted message.
        odometry_publisher_->publish(odom_msg);
    }

    rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr position_subscription_;
    rclcpp::Publisher<px4_msgs::msg::VehicleOdometry>::SharedPtr odometry_publisher_;
};*/

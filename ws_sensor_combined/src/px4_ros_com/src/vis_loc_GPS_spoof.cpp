#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/quaternion.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <px4_msgs/msg/vehicle_odometry.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>



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
        
 /*       odom_msg.q[0] = msg->pose.pose.orientation.w; // w
	odom_msg.q[1] = msg->pose.pose.orientation.x; // x
	odom_msg.q[2] = -msg->pose.pose.orientation.y; // y
	odom_msg.q[3] = -msg->pose.pose.orientation.z; // z
 */     
        odom_msg.position[0] = msg->pose.pose.position.y;
        odom_msg.position[1] = -msg->pose.pose.position.x;
        odom_msg.position[2] = -msg->pose.pose.position.z;

        // If the LiDAR is flipped (over the Y-axis)
        tf2::Quaternion q_orig, q_rot, q_new;
        // rotation quaternion
        q_rot.setRPY(0, M_PI, 0);
        // original orientation
        tf2::convert(msg->pose.pose.orientation, q_orig);
        // new orientation
        q_new = q_rot * q_orig;
        q_new.normalize();

        // Convert back to geometry_msgs::msg::Quaternion and assign to your message
        geometry_msgs::msg::Quaternion q_msg;
        tf2::convert(q_new, q_msg);
        
        odom_msg.q[0] = q_msg.w;
        odom_msg.q[1] = -q_msg.x;  // Flip sign because of LiDAR rotation
        odom_msg.q[2] = q_msg.y;
        odom_msg.q[3] = -q_msg.z;  // Flip sign because of LiDAR rotation


        
/*        odom_msg.velocity[0] = msg->twist.twist.linear.x;
	odom_msg.velocity[1] = msg->twist.twist.linear.y;
	odom_msg.velocity[2] = msg->twist.twist.linear.z;

	odom_msg.angular_velocity[0] = msg->twist.twist.angular.x; // Possibly in different order or sign
	odom_msg.angular_velocity[1] = msg->twist.twist.angular.y; // Possibly in different order or sign
	odom_msg.angular_velocity[2] = msg->twist.twist.angular.z; // Possibly in different order or sign
*/
        // Set additional required fields to zero or defaults. You may need to adjust these
        // depending on PX4's expectations and your application logic.
        // Note: This is a simplified example; the actual conversion must be appropriate
        // for the position information to be usable as odometry data in your application.
        odom_msg.pose_frame = odom_msg.POSE_FRAME_NED;
        //odom_msg.velocity_frame = odom_msg.VELOCITY_FRAME_NED;

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

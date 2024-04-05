#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>

#include <cstdlib>
#include <memory>
#include <string>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <unistd.h>

class MapsEdgesRecorder : public rclcpp::Node {
public:
    MapsEdgesRecorder() 
        : Node("maps_edges_recorder"), rosbag_process_id(-1) {
        // Initialize subscriber
        subscriber_ = this->create_subscription<std_msgs::msg::Bool>(
            "/end_flight", 10, std::bind(&MapsEdgesRecorder::endFlightCallback, this, std::placeholders::_1));

        // Start rosbag recording in a new process
        rosbag_process_id = fork();
        if (rosbag_process_id == 0) { // Child process
            // Execute rosbag record command
            //execl("/bin/bash", "/bin/bash", "-c", "ros2 bag record -o maps_edges /maps_edges", (char *)NULL);
            execl("/bin/bash", "/bin/bash", "-c", "ros2 bag record /velodyne_points", (char *)NULL);
            // If execl returns, it must have failed
            RCLCPP_ERROR(this->get_logger(), "Failed to start rosbag recording!");
            exit(EXIT_FAILURE);
        } else if (rosbag_process_id < 0) {
            // Fork failed
            RCLCPP_ERROR(this->get_logger(), "Failed to fork process!");
            exit(EXIT_FAILURE);
        }
    }

    ~MapsEdgesRecorder() {
        // Send SIGINT (Ctrl+C) to the rosbag process to stop recording
        if (rosbag_process_id != -1) {
            kill(rosbag_process_id, SIGINT);
            waitpid(rosbag_process_id, nullptr, 0); // Wait for the child process to terminate
        }
    }

private:
    void endFlightCallback(const std_msgs::msg::Bool::SharedPtr msg) {
        if (msg->data == true && rosbag_process_id != -1) {
            // Send SIGINT (Ctrl+C) to the rosbag process to stop recording
            kill(rosbag_process_id, SIGINT);
            rosbag_process_id = -1;
            rclcpp::shutdown();
        }
    }

    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr subscriber_;
    pid_t rosbag_process_id;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MapsEdgesRecorder>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
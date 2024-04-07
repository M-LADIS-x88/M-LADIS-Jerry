#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>

#include <cstdlib>
#include <memory>
#include <vector>
#include <string>
#include <signal.h>
#include <sys/wait.h>
#include <ctime>
#include <iostream>
#include <unistd.h>

class MapsEdgesRecorder : public rclcpp::Node {
public:
    MapsEdgesRecorder() : Node("maps_edges_recorder") {
        // Initialize subscriber
        subscriber_ = this->create_subscription<std_msgs::msg::Bool>(
            "/end_flight", 10, std::bind(&MapsEdgesRecorder::endFlightCallback, this, std::placeholders::_1));

        // Start rosbag recording for each topic in a new process
        startRecording("/velodyne_points", "velodyne_bag");
        //startRecording("/walls", "walls_bag");
        //startRecording("/current_posters", "current_posters_bag");
        //startRecording("/posters", "posters_bag");
        //startRecording("/Tom", "Tom_bag");
        //startRecording("/position", "position_bag");
        //startRecording("/yaw", "yaw_bag");
    }

    ~MapsEdgesRecorder() {
        // Send SIGINT (Ctrl+C) to each rosbag process to stop recording
        for (auto& pid : rosbag_process_ids) {
            if (pid != -1) {
                kill(pid, SIGINT);
                waitpid(pid, nullptr, 0); // Wait for the child process to terminate
            }
        }
    }

private:
    void startRecording(const std::string& topic, const std::string& base_bag_name) {
        // Generate a timestamped bag name
        std::string timestamp = std::to_string(std::time(nullptr));
        std::string bag_name = base_bag_name + "_" + timestamp;

        // Fork a new process
        pid_t pid = fork();
        if (pid == 0) { // Child process
            // Construct the command for recording
            std::string command = "ros2 bag record -o " + bag_name + " " + topic;
            // Execute the command
            execl("/bin/bash", "/bin/bash", "-c", command.c_str(), (char *)NULL);
            // If execl returns, it must have failed
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            // Save the child PID
            rosbag_process_ids.push_back(pid);
        } else {
            // Handle fork failure
            RCLCPP_ERROR(this->get_logger(), "Failed to fork process for topic %s!", topic.c_str());
            exit(EXIT_FAILURE);
        }
    }

    void endFlightCallback(const std_msgs::msg::Bool::SharedPtr msg) {
        if (msg->data == true) {
            // Send SIGINT (Ctrl+C) to each rosbag process to stop recording
            for (auto& pid : rosbag_process_ids) {
                if (pid != -1) {
                    kill(pid, SIGINT);
                    pid = -1; // Mark as terminated
                }
            }
            // Shutdown the node
            rclcpp::shutdown();
        }
    }

    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr subscriber_;
    std::vector<pid_t> rosbag_process_ids;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MapsEdgesRecorder>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
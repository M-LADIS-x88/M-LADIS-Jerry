#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <fstream>
#include <vector>

class PoseArrayToFile : public rclcpp::Node {
public:
    PoseArrayToFile()
        : Node("pose_array_to_file_node"), end_flight_received_(false) {
        end_flight_subscription_ = this->create_subscription<std_msgs::msg::Bool>(
            "/end_flight", 10, std::bind(&PoseArrayToFile::endFlightCallback, this, std::placeholders::_1));
        posters_subscription_ = this->create_subscription<geometry_msgs::msg::PoseArray>(
            "/posters", 10, std::bind(&PoseArrayToFile::postersCallback, this, std::placeholders::_1));
    }
private:
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr end_flight_subscription_;
    rclcpp::Subscription<geometry_msgs::msg::PoseArray>::SharedPtr posters_subscription_;
    bool end_flight_received_;
    std::vector<geometry_msgs::msg::Pose> poses_;

    void endFlightCallback(const std_msgs::msg::Bool::SharedPtr msg) {
        if (msg->data) {
            end_flight_received_ = true;
            writePosesToFile();
        }
    }

    void postersCallback(const geometry_msgs::msg::PoseArray::SharedPtr msg) {
        if (!end_flight_received_) {
            // Store poses; only add if orientation.w == 1
            poses_.clear();
            for (const auto& pose : msg->poses) {
                if (pose.orientation.w == 1.0) {
                    poses_.push_back(pose);
                }
            }
        }
    }

    void writePosesToFile() {
        std::ofstream file("image_positions.txt");
        if (file.is_open()) {
            for (const auto& pose : poses_) {
                file << pose.position.x << " " << pose.position.y << " " << pose.position.z << "\n";
            }
            file.close();
            RCLCPP_INFO(this->get_logger(), "Poses written to file.");
            std::string command = "python3 src/classifier/src/classifier.py";
            int result = system(command.c_str());
            if (result != 0) {
              RCLCPP_ERROR(this->get_logger(), "Failed to execute Python script.");
            }
        } else {
            RCLCPP_ERROR(this->get_logger(), "Unable to open file.");
        }
    }
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PoseArrayToFile>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
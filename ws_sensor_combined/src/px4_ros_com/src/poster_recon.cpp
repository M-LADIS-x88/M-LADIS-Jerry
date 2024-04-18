#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <std_msgs/msg/bool.hpp>

#include <cmath>
#include <vector>
#include <algorithm>
using namespace std::placeholders;
using namespace std::chrono_literals;


class EnvironmentReconstructor : public rclcpp::Node {
public:
  EnvironmentReconstructor() : Node("environment_reconstructor") {
    // Poster pose array publisher
    poster_pub_ = this->create_publisher<geometry_msgs::msg::PoseArray>("/posters", 1);

    // End flight publisher
    end_flight_pub_ = this->create_publisher<std_msgs::msg::Bool>("/end_flight", 1);

    // Subscription to current posters
    poster_sub_ = this->create_subscription<geometry_msgs::msg::PoseArray>(
      "/current_posters", 10, std::bind(&EnvironmentReconstructor::poster_callback, this, _1));

    // Subscription to last poster checked
    last_poster_sub_ = this->create_subscription<geometry_msgs::msg::Point>(
      "/captured_poster", 10, std::bind(&EnvironmentReconstructor::last_poster_checked_callback, this, _1));
    
    timer_ = this->create_wall_timer(
      420s, // 7 minutes expressed in seconds
      std::bind(&EnvironmentReconstructor::endFlightTimerCallback, this));
  }

  void endFlightTimerCallback() {
    std_msgs::msg::Bool end_flight_msg;
    end_flight_msg.data = true;
    end_flight_pub_->publish(end_flight_msg);
  }
  
  void poster_callback(const geometry_msgs::msg::PoseArray::SharedPtr posters) {
    std::vector<Poster> current_posters;
    for (const auto& poster_msg : posters->poses) {
      current_posters.push_back(Poster(poster_msg.position.x, poster_msg.position.y, poster_msg.position.z));
    }

    updatePersistentPosters(current_posters);
    publishPosterPoses();
  }

  void last_poster_checked_callback(const geometry_msgs::msg::Point::SharedPtr last_checked_msg) {
    markPosterAsChecked(last_checked_msg->x, last_checked_msg->y);
    // We only check if all posters are checked if there are any posters at all
    if (!persistent_posters_.empty()) {
        bool all_checked = std::all_of(persistent_posters_.begin(), persistent_posters_.end(),
                                       [](const Poster& p) { return p.isChecked; });

        std_msgs::msg::Bool end_flight_msg;
        end_flight_msg.data = all_checked;
        end_flight_pub_->publish(end_flight_msg);

        // Publish the updated poster poses with their checked status
        publishPosterPoses();
    }
}

private:
    struct Poster {
        float x, y, z;
        bool isChecked;
        int notSeenCount;

        Poster(float x, float y, float z, bool isChecked = false)
            : x(x), y(y), z(z), isChecked(isChecked), notSeenCount(0) {}
    };

    rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr poster_pub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr end_flight_pub_;
    rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr last_poster_sub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseArray>::SharedPtr poster_sub_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::vector<Poster> persistent_posters_;
    const float DISTANCE_THRESHOLD = 1.5f; // Threshold distance to consider posters the same

    void updatePersistentPosters(const std::vector<Poster>& current_posters) {
        // Mark all persistent posters as not seen
        for (auto& p : persistent_posters_) {
            p.notSeenCount++;
        }
        
        // Update persistent posters
        for (const auto& current : current_posters) {
            bool found = false;
            for (auto& persisted : persistent_posters_) {
                if (isCloseEnough(persisted, current)) {
                    persisted.notSeenCount = 0; // Reset not seen counter
                    persisted.x = current.x;    // Update coordinates
                    persisted.y = current.y;
                    persisted.z = current.z;
                    found = true;
                    break;
                }
            }

            if (!found) { // If the current poster is new, add it to the persistent list
                persistent_posters_.emplace_back(current);
            }
        }

        // Remove posters that have not been seen for a while
        persistent_posters_.erase(std::remove_if(persistent_posters_.begin(), persistent_posters_.end(),
            [this](const Poster& p) { return p.notSeenCount > MAX_NOT_SEEN_CYCLES; }),
            persistent_posters_.end());
    }

    bool isCloseEnough(const Poster& a, const Poster& b) {
        return (std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2)) <= std::pow(DISTANCE_THRESHOLD, 2);
    }

    void markPosterAsChecked(float x, float y) {
      for (auto& poster : persistent_posters_) {
          if (isCloseEnough(poster, Poster(x, y, poster.z))) {
              poster.isChecked = true;
              break; // Once the poster is found, we do not need to continue the loop
          }
      }

      // Since we have updated the state, we should publish the updated pose array
      publishPosterPoses();
    }

    void publishPosterPoses() {
    geometry_msgs::msg::PoseArray pose_array_msg;
    pose_array_msg.header.frame_id = "map";
    pose_array_msg.header.stamp = this->get_clock()->now();
    int num_checked = 0;

    for (const auto& poster : persistent_posters_) {
        geometry_msgs::msg::Pose pose;
        pose.position.x = poster.x;
        pose.position.y = poster.y;
        pose.position.z = poster.z; // Include the z-coordinate

        pose.orientation.x = 0.0;
        pose.orientation.y = 0.0;
        pose.orientation.z = 0.0;
        pose.orientation.w = poster.isChecked ? 1.0 : 0.0; // Set w to 1 if checked, to 0 otherwise
        if (poster.isChecked) {
          num_checked++;
        }
        pose_array_msg.poses.push_back(pose);
    }

    poster_pub_->publish(pose_array_msg);
    RCLCPP_INFO(this->get_logger(), "%d of %d Tracked Posters Photographed",
              num_checked, static_cast<int>(persistent_posters_.size()));
}

    static constexpr int MAX_NOT_SEEN_CYCLES = 3; // Number of cycles a poster can be unseen before being removed
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<EnvironmentReconstructor>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
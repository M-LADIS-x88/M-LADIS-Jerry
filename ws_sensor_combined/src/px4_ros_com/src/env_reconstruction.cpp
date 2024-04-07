#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <std_msgs/msg/bool.hpp>

#include <cmath>
#include <vector>
#include <algorithm>
#include <limits> 

using namespace std::placeholders;

//std::vector<PolarPoint> persistentPosters = {PolarPoint(100,100,false,true)};

struct PosterInfo {
    geometry_msgs::msg::Pose pose;
    bool isChecked;
};
struct PolarPoint
{
    float r;
    float theta;
    bool isChecked;
    bool isEmpty;

    PolarPoint() : r(0.0f), theta(0.0f), isChecked(false) {}
    PolarPoint(double radius, double angle, bool isChecked) : r(radius), theta(angle), isChecked(isChecked) {}

    PolarPoint(double radius, double angle, bool isChecked, bool isEmpty) : r(radius), theta(angle), isChecked(isChecked), isEmpty(isEmpty) {}
};

bool compareByTheta(const PolarPoint& a, const PolarPoint& b) {
  // Return true if 'a' should go before 'b', which is the case when 'a' has a smaller theta than 'b'
  return a.theta < b.theta;
}

class EnvironmentReconstructor : public rclcpp::Node {
  std::vector<PolarPoint> persistentPosters = {PolarPoint(100,100,false,true)};
public:
  EnvironmentReconstructor() : Node("environment_reconstructor") {

    
    
    // Poster pose array publisher
    poster_pub_ = this->create_publisher<geometry_msgs::msg::PoseArray>("/posters", 10);

    // End flight publisher
    end_flight_pub_ = this->create_publisher<std_msgs::msg::Bool>("/end_flight", 10);

    // Subscription to objects
    //object_sub = this->create_subscription<geometry_msgs::msg::PoseArray>(
     //   "/objects", 10, std::bind(&EnvironmentReconstructor::objects_callback, this, _1));

    // Subscription to last poster checked
    last_poster_sub_ = this->create_subscription<geometry_msgs::msg::Point>(
      "/last_poster_checked", 10, std::bind(&EnvironmentReconstructor::last_poster_checked_callback, this, _1));
    
    poster_sub_ = this->create_subscription<geometry_msgs::msg::PoseArray>(
      "/current_posters", 10, std::bind(&EnvironmentReconstructor::poster_callback, this, _1));

    
  
  };
  void publishPosterPoses() {
      // Create the PoseArray message
      geometry_msgs::msg::PoseArray pose_array_msg;
      pose_array_msg.header.frame_id = "global frame"; // Replace with your actual frame_id
      pose_array_msg.header.stamp = this->get_clock()->now();

      for (const auto& poster : persistentPosters) {
          geometry_msgs::msg::Pose pose;

          // Set position
          pose.position.x = poster.r * std::cos(poster.theta);
          pose.position.y = poster.r * std::sin(poster.theta);
          pose.position.z = 0.0; // Assuming planar movement, set z to zero

          // Set orientation (not used in this case, so keep it default quaternion)
          pose.orientation.x = 0.0;
          pose.orientation.y = 0.0;
          pose.orientation.z = 0.0;
          pose.orientation.w = 1.0;

          // Additional data as orientation for isChecked flag
          // W component can be used if quaternion is known to be (0,0,0,1) otherwise this is misuse of a quaternion.
          pose.orientation.w = poster.isChecked ? 1.0 : 0.0; 

          // Add pose to PoseArray
          pose_array_msg.poses.push_back(pose);
      }

      // Publish the PoseArray
      poster_pub_->publish(pose_array_msg);
  };
    // end_flight_timer = this->create_wall_timer(
    //   std::chrono::seconds(60), std::bind(&EnvironmentReconstructor::check_end_flight_condition, this));
    // }


    
    

private:
  bool flight_ended = false;
  //std::vector<PolarPoint> persistentPosters = {PolarPoint(100,100,false,true)};



  // Poster array in form ((x,y,z,ischecked), (x,y,z,ischecked), ...)
  rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr poster_pub_;

  // bool - 0 is continue flying, 1 is end the flight and land
  rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr end_flight_pub_;

  // most recent poster is (x,y,z) centroid of the most recent poster checked
  rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr last_poster_sub_;
  rclcpp::Subscription<geometry_msgs::msg::PoseArray>::SharedPtr poster_sub_;

  rclcpp::TimerBase::SharedPtr end_flight_timer_;

  //// Callbacks ////

  /* This function takes in a PoseArray of objects and parces it. It calculates the wall bounds of the rectanguar arena
  from all poses labeled 0 for pillar. It also publishes the predator position wrt (0,0) at the center of the arena 
  from the object detected as -1. Finally, it creates a structure to store the posters based on the (x,y) centroids 
  along with whether the poster with that centroid has been checked yet, initializing posters not yet in the data structure
  to have a value of 0 for not checked. Posters that have already been checked (1) are not reinitialized. */


void sortPolarPoints(std::vector<PolarPoint>& polarPoints) {
    std::sort(polarPoints.begin(), polarPoints.end(), compareByTheta);
}


  bool areApproximatelyEqual(float value1, float value2, float tolerance) {
    // Use the absolute value of the difference to determine if it's within the tolerance
    return std::abs(value1 - value2) <= tolerance;
}
  void removeEntryFromVector(std::vector<PolarPoint>& vec, size_t index) {
    vec.erase(vec.begin() + index);
}

  void poster_callback(const geometry_msgs::msg::PoseArray::SharedPtr posters){
    std::vector<PolarPoint> polar_points;
    PolarPoint point;
    for(size_t i = 0; i<posters->poses.size();++i) {
      float x = posters->poses[i].position.x;
      float y = posters->poses[i].position.y;
      float theta = atan2(y,x);
      float r = sqrt(x*x + y*y);

      point = PolarPoint(r,theta,false);

      polar_points.push_back(point);

    }
    
    sortPolarPoints(polar_points);

    if(persistentPosters.empty() || persistentPosters[0].isEmpty){ //check if its empty
      persistentPosters = polar_points;
    }
    else{
      for(size_t i = 0; i<persistentPosters.size();++i) {
        for(size_t j = 0; j<polar_points.size();++j) {
          float x_new_poster = polar_points[j].r * cos(polar_points[j].theta);
          float y_new_poster = polar_points[j].r * sin(polar_points[j].theta);

          float x_old_poster = persistentPosters[i].r * cos(persistentPosters[i].theta);
          float y_old_poster = persistentPosters[i].r * sin(persistentPosters[i].theta);

          if(areApproximatelyEqual(x_old_poster,x_new_poster,0.3) == true && areApproximatelyEqual(y_old_poster,y_new_poster,0.3) == true){
            persistentPosters[i].r = (persistentPosters[i].r + 0.7*polar_points[j].r)/2;
            persistentPosters[i].theta = (persistentPosters[i].theta + 0.5*polar_points[j].theta)/2;
            persistentPosters[i].isChecked = persistentPosters[i].isChecked;

            removeEntryFromVector(polar_points,j);
          }
        }
      }
    }
  }
  bool flightDone = true; //will be true once all posters have pictues
  void last_poster_checked_callback(const geometry_msgs::msg::Point::SharedPtr target){
    for(size_t i = 0; i<persistentPosters.size(); ++i){
      float position_x = persistentPosters[i].r * std::cos(persistentPosters[i].theta);
      float position_y = persistentPosters[i].r * std::sin(persistentPosters[i].theta);

      if(areApproximatelyEqual(position_x,target->x,0.3) == true && areApproximatelyEqual(position_y,target->y,0.3) == true){
        persistentPosters[i].isChecked = true;
      }

      bool checked = persistentPosters[i].isChecked;
      if(checked != true){
        flightDone = false;
      }
      std_msgs::msg::Bool end_flight_msg;
      end_flight_msg.data = flightDone;

    }
    if(flightDone){
      std_msgs::msg::Bool end_flight_msg;
      end_flight_msg.data = flightDone;
      end_flight_pub_->publish(end_flight_msg);
    }
    
  }

};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<EnvironmentReconstructor>();

  
  node->publishPosterPoses();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
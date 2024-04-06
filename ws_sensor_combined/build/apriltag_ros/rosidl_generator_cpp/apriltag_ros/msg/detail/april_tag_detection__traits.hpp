// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from apriltag_ros:msg/AprilTagDetection.idl
// generated code does not contain a copyright notice

#ifndef APRILTAG_ROS__MSG__DETAIL__APRIL_TAG_DETECTION__TRAITS_HPP_
#define APRILTAG_ROS__MSG__DETAIL__APRIL_TAG_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "apriltag_ros/msg/detail/april_tag_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_with_covariance_stamped__traits.hpp"

namespace apriltag_ros
{

namespace msg
{

inline void to_flow_style_yaml(
  const AprilTagDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    if (msg.id.size() == 0) {
      out << "id: []";
    } else {
      out << "id: [";
      size_t pending_items = msg.id.size();
      for (auto item : msg.id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: size
  {
    if (msg.size.size() == 0) {
      out << "size: []";
    } else {
      out << "size: [";
      size_t pending_items = msg.size.size();
      for (auto item : msg.size) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AprilTagDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.id.size() == 0) {
      out << "id: []\n";
    } else {
      out << "id:\n";
      for (auto item : msg.id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.size.size() == 0) {
      out << "size: []\n";
    } else {
      out << "size:\n";
      for (auto item : msg.size) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AprilTagDetection & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace apriltag_ros

namespace rosidl_generator_traits
{

[[deprecated("use apriltag_ros::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const apriltag_ros::msg::AprilTagDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  apriltag_ros::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use apriltag_ros::msg::to_yaml() instead")]]
inline std::string to_yaml(const apriltag_ros::msg::AprilTagDetection & msg)
{
  return apriltag_ros::msg::to_yaml(msg);
}

template<>
inline const char * data_type<apriltag_ros::msg::AprilTagDetection>()
{
  return "apriltag_ros::msg::AprilTagDetection";
}

template<>
inline const char * name<apriltag_ros::msg::AprilTagDetection>()
{
  return "apriltag_ros/msg/AprilTagDetection";
}

template<>
struct has_fixed_size<apriltag_ros::msg::AprilTagDetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<apriltag_ros::msg::AprilTagDetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<apriltag_ros::msg::AprilTagDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // APRILTAG_ROS__MSG__DETAIL__APRIL_TAG_DETECTION__TRAITS_HPP_

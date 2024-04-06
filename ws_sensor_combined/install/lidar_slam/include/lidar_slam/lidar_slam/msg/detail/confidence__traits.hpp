// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lidar_slam:msg/Confidence.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__TRAITS_HPP_
#define LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lidar_slam/msg/detail/confidence__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace lidar_slam
{

namespace msg
{

inline void to_flow_style_yaml(
  const Confidence & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: covariance
  {
    if (msg.covariance.size() == 0) {
      out << "covariance: []";
    } else {
      out << "covariance: [";
      size_t pending_items = msg.covariance.size();
      for (auto item : msg.covariance) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: overlap
  {
    out << "overlap: ";
    rosidl_generator_traits::value_to_yaml(msg.overlap, out);
    out << ", ";
  }

  // member: nb_matches
  {
    out << "nb_matches: ";
    rosidl_generator_traits::value_to_yaml(msg.nb_matches, out);
    out << ", ";
  }

  // member: comply_motion_limits
  {
    out << "comply_motion_limits: ";
    rosidl_generator_traits::value_to_yaml(msg.comply_motion_limits, out);
    out << ", ";
  }

  // member: std_position_error
  {
    out << "std_position_error: ";
    rosidl_generator_traits::value_to_yaml(msg.std_position_error, out);
    out << ", ";
  }

  // member: failure
  {
    out << "failure: ";
    rosidl_generator_traits::value_to_yaml(msg.failure, out);
    out << ", ";
  }

  // member: computation_time
  {
    out << "computation_time: ";
    rosidl_generator_traits::value_to_yaml(msg.computation_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Confidence & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: covariance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.covariance.size() == 0) {
      out << "covariance: []\n";
    } else {
      out << "covariance:\n";
      for (auto item : msg.covariance) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: overlap
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "overlap: ";
    rosidl_generator_traits::value_to_yaml(msg.overlap, out);
    out << "\n";
  }

  // member: nb_matches
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nb_matches: ";
    rosidl_generator_traits::value_to_yaml(msg.nb_matches, out);
    out << "\n";
  }

  // member: comply_motion_limits
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "comply_motion_limits: ";
    rosidl_generator_traits::value_to_yaml(msg.comply_motion_limits, out);
    out << "\n";
  }

  // member: std_position_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "std_position_error: ";
    rosidl_generator_traits::value_to_yaml(msg.std_position_error, out);
    out << "\n";
  }

  // member: failure
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "failure: ";
    rosidl_generator_traits::value_to_yaml(msg.failure, out);
    out << "\n";
  }

  // member: computation_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "computation_time: ";
    rosidl_generator_traits::value_to_yaml(msg.computation_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Confidence & msg, bool use_flow_style = false)
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

}  // namespace lidar_slam

namespace rosidl_generator_traits
{

[[deprecated("use lidar_slam::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lidar_slam::msg::Confidence & msg,
  std::ostream & out, size_t indentation = 0)
{
  lidar_slam::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lidar_slam::msg::to_yaml() instead")]]
inline std::string to_yaml(const lidar_slam::msg::Confidence & msg)
{
  return lidar_slam::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lidar_slam::msg::Confidence>()
{
  return "lidar_slam::msg::Confidence";
}

template<>
inline const char * name<lidar_slam::msg::Confidence>()
{
  return "lidar_slam/msg/Confidence";
}

template<>
struct has_fixed_size<lidar_slam::msg::Confidence>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<lidar_slam::msg::Confidence>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<lidar_slam::msg::Confidence>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__TRAITS_HPP_

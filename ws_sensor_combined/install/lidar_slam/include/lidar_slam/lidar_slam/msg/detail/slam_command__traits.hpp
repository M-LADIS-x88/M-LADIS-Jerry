// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lidar_slam:msg/SlamCommand.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__TRAITS_HPP_
#define LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lidar_slam/msg/detail/slam_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lidar_slam
{

namespace msg
{

inline void to_flow_style_yaml(
  const SlamCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << ", ";
  }

  // member: string_arg
  {
    out << "string_arg: ";
    rosidl_generator_traits::value_to_yaml(msg.string_arg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SlamCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }

  // member: string_arg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "string_arg: ";
    rosidl_generator_traits::value_to_yaml(msg.string_arg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SlamCommand & msg, bool use_flow_style = false)
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
  const lidar_slam::msg::SlamCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  lidar_slam::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lidar_slam::msg::to_yaml() instead")]]
inline std::string to_yaml(const lidar_slam::msg::SlamCommand & msg)
{
  return lidar_slam::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lidar_slam::msg::SlamCommand>()
{
  return "lidar_slam::msg::SlamCommand";
}

template<>
inline const char * name<lidar_slam::msg::SlamCommand>()
{
  return "lidar_slam/msg/SlamCommand";
}

template<>
struct has_fixed_size<lidar_slam::msg::SlamCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lidar_slam::msg::SlamCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lidar_slam::msg::SlamCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__TRAITS_HPP_

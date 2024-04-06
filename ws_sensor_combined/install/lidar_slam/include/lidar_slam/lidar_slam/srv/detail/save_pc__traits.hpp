// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lidar_slam:srv/SavePc.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__SRV__DETAIL__SAVE_PC__TRAITS_HPP_
#define LIDAR_SLAM__SRV__DETAIL__SAVE_PC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lidar_slam/srv/detail/save_pc__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lidar_slam
{

namespace srv
{

inline void to_flow_style_yaml(
  const SavePc_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: output_prefix_path
  {
    out << "output_prefix_path: ";
    rosidl_generator_traits::value_to_yaml(msg.output_prefix_path, out);
    out << ", ";
  }

  // member: format
  {
    out << "format: ";
    rosidl_generator_traits::value_to_yaml(msg.format, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SavePc_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: output_prefix_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "output_prefix_path: ";
    rosidl_generator_traits::value_to_yaml(msg.output_prefix_path, out);
    out << "\n";
  }

  // member: format
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "format: ";
    rosidl_generator_traits::value_to_yaml(msg.format, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SavePc_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace lidar_slam

namespace rosidl_generator_traits
{

[[deprecated("use lidar_slam::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lidar_slam::srv::SavePc_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  lidar_slam::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lidar_slam::srv::to_yaml() instead")]]
inline std::string to_yaml(const lidar_slam::srv::SavePc_Request & msg)
{
  return lidar_slam::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lidar_slam::srv::SavePc_Request>()
{
  return "lidar_slam::srv::SavePc_Request";
}

template<>
inline const char * name<lidar_slam::srv::SavePc_Request>()
{
  return "lidar_slam/srv/SavePc_Request";
}

template<>
struct has_fixed_size<lidar_slam::srv::SavePc_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lidar_slam::srv::SavePc_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lidar_slam::srv::SavePc_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace lidar_slam
{

namespace srv
{

inline void to_flow_style_yaml(
  const SavePc_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SavePc_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SavePc_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace lidar_slam

namespace rosidl_generator_traits
{

[[deprecated("use lidar_slam::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lidar_slam::srv::SavePc_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  lidar_slam::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lidar_slam::srv::to_yaml() instead")]]
inline std::string to_yaml(const lidar_slam::srv::SavePc_Response & msg)
{
  return lidar_slam::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lidar_slam::srv::SavePc_Response>()
{
  return "lidar_slam::srv::SavePc_Response";
}

template<>
inline const char * name<lidar_slam::srv::SavePc_Response>()
{
  return "lidar_slam/srv/SavePc_Response";
}

template<>
struct has_fixed_size<lidar_slam::srv::SavePc_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lidar_slam::srv::SavePc_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lidar_slam::srv::SavePc_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lidar_slam::srv::SavePc>()
{
  return "lidar_slam::srv::SavePc";
}

template<>
inline const char * name<lidar_slam::srv::SavePc>()
{
  return "lidar_slam/srv/SavePc";
}

template<>
struct has_fixed_size<lidar_slam::srv::SavePc>
  : std::integral_constant<
    bool,
    has_fixed_size<lidar_slam::srv::SavePc_Request>::value &&
    has_fixed_size<lidar_slam::srv::SavePc_Response>::value
  >
{
};

template<>
struct has_bounded_size<lidar_slam::srv::SavePc>
  : std::integral_constant<
    bool,
    has_bounded_size<lidar_slam::srv::SavePc_Request>::value &&
    has_bounded_size<lidar_slam::srv::SavePc_Response>::value
  >
{
};

template<>
struct is_service<lidar_slam::srv::SavePc>
  : std::true_type
{
};

template<>
struct is_service_request<lidar_slam::srv::SavePc_Request>
  : std::true_type
{
};

template<>
struct is_service_response<lidar_slam::srv::SavePc_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // LIDAR_SLAM__SRV__DETAIL__SAVE_PC__TRAITS_HPP_

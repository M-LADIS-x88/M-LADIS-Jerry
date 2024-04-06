// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lidar_slam:msg/SlamCommand.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__STRUCT_HPP_
#define LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lidar_slam__msg__SlamCommand __attribute__((deprecated))
#else
# define DEPRECATED__lidar_slam__msg__SlamCommand __declspec(deprecated)
#endif

namespace lidar_slam
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SlamCommand_
{
  using Type = SlamCommand_<ContainerAllocator>;

  explicit SlamCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->string_arg = "";
    }
  }

  explicit SlamCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : string_arg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->string_arg = "";
    }
  }

  // field types and members
  using _command_type =
    uint8_t;
  _command_type command;
  using _string_arg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _string_arg_type string_arg;

  // setters for named parameter idiom
  Type & set__command(
    const uint8_t & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__string_arg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->string_arg = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t DISABLE_SLAM_MAP_UPDATE =
    8u;
  static constexpr uint8_t ENABLE_SLAM_MAP_EXPANSION =
    9u;
  static constexpr uint8_t ENABLE_SLAM_MAP_UPDATE =
    10u;
  static constexpr uint8_t RESET_TRAJECTORY =
    11u;
  static constexpr uint8_t RESET_SLAM =
    12u;
  static constexpr uint8_t SWITCH_ON_OFF =
    13u;
  static constexpr uint8_t SAVE_TRAJECTORY =
    14u;
  static constexpr uint8_t SAVE_LIDAR_TRAJECTORY =
    15u;
  static constexpr uint8_t SAVE_KEYPOINTS_MAPS =
    16u;
  static constexpr uint8_t SAVE_FILTERED_KEYPOINTS_MAPS =
    17u;
  static constexpr uint8_t LOAD_KEYPOINTS_MAPS =
    18u;
  static constexpr uint8_t OPTIMIZE_GRAPH =
    20u;
  static constexpr uint8_t LOAD_LOOP_INDICES =
    23u;
  static constexpr uint8_t SWITCH_SENSOR =
    25u;
  static constexpr uint8_t CALIBRATE_WITH_POSES =
    30u;
  static constexpr uint8_t LOAD_POSES =
    40u;

  // pointer types
  using RawPtr =
    lidar_slam::msg::SlamCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const lidar_slam::msg::SlamCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lidar_slam::msg::SlamCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lidar_slam::msg::SlamCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lidar_slam::msg::SlamCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lidar_slam::msg::SlamCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lidar_slam::msg::SlamCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lidar_slam::msg::SlamCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lidar_slam::msg::SlamCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lidar_slam::msg::SlamCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lidar_slam__msg__SlamCommand
    std::shared_ptr<lidar_slam::msg::SlamCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lidar_slam__msg__SlamCommand
    std::shared_ptr<lidar_slam::msg::SlamCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SlamCommand_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->string_arg != other.string_arg) {
      return false;
    }
    return true;
  }
  bool operator!=(const SlamCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SlamCommand_

// alias to use template instance with default allocator
using SlamCommand =
  lidar_slam::msg::SlamCommand_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::DISABLE_SLAM_MAP_UPDATE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::ENABLE_SLAM_MAP_EXPANSION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::ENABLE_SLAM_MAP_UPDATE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::RESET_TRAJECTORY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::RESET_SLAM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::SWITCH_ON_OFF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::SAVE_TRAJECTORY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::SAVE_LIDAR_TRAJECTORY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::SAVE_KEYPOINTS_MAPS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::SAVE_FILTERED_KEYPOINTS_MAPS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::LOAD_KEYPOINTS_MAPS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::OPTIMIZE_GRAPH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::LOAD_LOOP_INDICES;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::SWITCH_SENSOR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::CALIBRATE_WITH_POSES;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SlamCommand_<ContainerAllocator>::LOAD_POSES;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace lidar_slam

#endif  // LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__STRUCT_HPP_

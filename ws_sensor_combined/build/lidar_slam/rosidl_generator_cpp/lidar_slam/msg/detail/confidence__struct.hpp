// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lidar_slam:msg/Confidence.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__STRUCT_HPP_
#define LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lidar_slam__msg__Confidence __attribute__((deprecated))
#else
# define DEPRECATED__lidar_slam__msg__Confidence __declspec(deprecated)
#endif

namespace lidar_slam
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Confidence_
{
  using Type = Confidence_<ContainerAllocator>;

  explicit Confidence_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 36>::iterator, double>(this->covariance.begin(), this->covariance.end(), 0.0);
      this->overlap = 0.0f;
      this->nb_matches = 0;
      this->comply_motion_limits = false;
      this->std_position_error = 0.0f;
      this->failure = false;
      this->computation_time = 0.0f;
    }
  }

  explicit Confidence_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    covariance(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 36>::iterator, double>(this->covariance.begin(), this->covariance.end(), 0.0);
      this->overlap = 0.0f;
      this->nb_matches = 0;
      this->comply_motion_limits = false;
      this->std_position_error = 0.0f;
      this->failure = false;
      this->computation_time = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _covariance_type =
    std::array<double, 36>;
  _covariance_type covariance;
  using _overlap_type =
    float;
  _overlap_type overlap;
  using _nb_matches_type =
    int16_t;
  _nb_matches_type nb_matches;
  using _comply_motion_limits_type =
    bool;
  _comply_motion_limits_type comply_motion_limits;
  using _std_position_error_type =
    float;
  _std_position_error_type std_position_error;
  using _failure_type =
    bool;
  _failure_type failure;
  using _computation_time_type =
    float;
  _computation_time_type computation_time;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__covariance(
    const std::array<double, 36> & _arg)
  {
    this->covariance = _arg;
    return *this;
  }
  Type & set__overlap(
    const float & _arg)
  {
    this->overlap = _arg;
    return *this;
  }
  Type & set__nb_matches(
    const int16_t & _arg)
  {
    this->nb_matches = _arg;
    return *this;
  }
  Type & set__comply_motion_limits(
    const bool & _arg)
  {
    this->comply_motion_limits = _arg;
    return *this;
  }
  Type & set__std_position_error(
    const float & _arg)
  {
    this->std_position_error = _arg;
    return *this;
  }
  Type & set__failure(
    const bool & _arg)
  {
    this->failure = _arg;
    return *this;
  }
  Type & set__computation_time(
    const float & _arg)
  {
    this->computation_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lidar_slam::msg::Confidence_<ContainerAllocator> *;
  using ConstRawPtr =
    const lidar_slam::msg::Confidence_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lidar_slam::msg::Confidence_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lidar_slam::msg::Confidence_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lidar_slam::msg::Confidence_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lidar_slam::msg::Confidence_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lidar_slam::msg::Confidence_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lidar_slam::msg::Confidence_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lidar_slam::msg::Confidence_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lidar_slam::msg::Confidence_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lidar_slam__msg__Confidence
    std::shared_ptr<lidar_slam::msg::Confidence_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lidar_slam__msg__Confidence
    std::shared_ptr<lidar_slam::msg::Confidence_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Confidence_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->covariance != other.covariance) {
      return false;
    }
    if (this->overlap != other.overlap) {
      return false;
    }
    if (this->nb_matches != other.nb_matches) {
      return false;
    }
    if (this->comply_motion_limits != other.comply_motion_limits) {
      return false;
    }
    if (this->std_position_error != other.std_position_error) {
      return false;
    }
    if (this->failure != other.failure) {
      return false;
    }
    if (this->computation_time != other.computation_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const Confidence_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Confidence_

// alias to use template instance with default allocator
using Confidence =
  lidar_slam::msg::Confidence_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lidar_slam

#endif  // LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__STRUCT_HPP_

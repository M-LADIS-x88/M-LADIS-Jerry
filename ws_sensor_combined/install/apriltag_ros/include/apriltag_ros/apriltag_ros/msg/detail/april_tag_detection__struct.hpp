// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from apriltag_ros:msg/AprilTagDetection.idl
// generated code does not contain a copyright notice

#ifndef APRILTAG_ROS__MSG__DETAIL__APRIL_TAG_DETECTION__STRUCT_HPP_
#define APRILTAG_ROS__MSG__DETAIL__APRIL_TAG_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_with_covariance_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__apriltag_ros__msg__AprilTagDetection __attribute__((deprecated))
#else
# define DEPRECATED__apriltag_ros__msg__AprilTagDetection __declspec(deprecated)
#endif

namespace apriltag_ros
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AprilTagDetection_
{
  using Type = AprilTagDetection_<ContainerAllocator>;

  explicit AprilTagDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    (void)_init;
  }

  explicit AprilTagDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _id_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _id_type id;
  using _size_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _size_type size;
  using _pose_type =
    geometry_msgs::msg::PoseWithCovarianceStamped_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__id(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__size(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->size = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::PoseWithCovarianceStamped_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    apriltag_ros::msg::AprilTagDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const apriltag_ros::msg::AprilTagDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<apriltag_ros::msg::AprilTagDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<apriltag_ros::msg::AprilTagDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      apriltag_ros::msg::AprilTagDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<apriltag_ros::msg::AprilTagDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      apriltag_ros::msg::AprilTagDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<apriltag_ros::msg::AprilTagDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<apriltag_ros::msg::AprilTagDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<apriltag_ros::msg::AprilTagDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__apriltag_ros__msg__AprilTagDetection
    std::shared_ptr<apriltag_ros::msg::AprilTagDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__apriltag_ros__msg__AprilTagDetection
    std::shared_ptr<apriltag_ros::msg::AprilTagDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AprilTagDetection_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->size != other.size) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const AprilTagDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AprilTagDetection_

// alias to use template instance with default allocator
using AprilTagDetection =
  apriltag_ros::msg::AprilTagDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace apriltag_ros

#endif  // APRILTAG_ROS__MSG__DETAIL__APRIL_TAG_DETECTION__STRUCT_HPP_

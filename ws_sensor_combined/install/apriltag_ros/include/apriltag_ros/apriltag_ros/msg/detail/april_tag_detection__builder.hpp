// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from apriltag_ros:msg/AprilTagDetection.idl
// generated code does not contain a copyright notice

#ifndef APRILTAG_ROS__MSG__DETAIL__APRIL_TAG_DETECTION__BUILDER_HPP_
#define APRILTAG_ROS__MSG__DETAIL__APRIL_TAG_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "apriltag_ros/msg/detail/april_tag_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace apriltag_ros
{

namespace msg
{

namespace builder
{

class Init_AprilTagDetection_pose
{
public:
  explicit Init_AprilTagDetection_pose(::apriltag_ros::msg::AprilTagDetection & msg)
  : msg_(msg)
  {}
  ::apriltag_ros::msg::AprilTagDetection pose(::apriltag_ros::msg::AprilTagDetection::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::apriltag_ros::msg::AprilTagDetection msg_;
};

class Init_AprilTagDetection_size
{
public:
  explicit Init_AprilTagDetection_size(::apriltag_ros::msg::AprilTagDetection & msg)
  : msg_(msg)
  {}
  Init_AprilTagDetection_pose size(::apriltag_ros::msg::AprilTagDetection::_size_type arg)
  {
    msg_.size = std::move(arg);
    return Init_AprilTagDetection_pose(msg_);
  }

private:
  ::apriltag_ros::msg::AprilTagDetection msg_;
};

class Init_AprilTagDetection_id
{
public:
  Init_AprilTagDetection_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AprilTagDetection_size id(::apriltag_ros::msg::AprilTagDetection::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_AprilTagDetection_size(msg_);
  }

private:
  ::apriltag_ros::msg::AprilTagDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::apriltag_ros::msg::AprilTagDetection>()
{
  return apriltag_ros::msg::builder::Init_AprilTagDetection_id();
}

}  // namespace apriltag_ros

#endif  // APRILTAG_ROS__MSG__DETAIL__APRIL_TAG_DETECTION__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lidar_slam:msg/Confidence.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__BUILDER_HPP_
#define LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lidar_slam/msg/detail/confidence__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lidar_slam
{

namespace msg
{

namespace builder
{

class Init_Confidence_computation_time
{
public:
  explicit Init_Confidence_computation_time(::lidar_slam::msg::Confidence & msg)
  : msg_(msg)
  {}
  ::lidar_slam::msg::Confidence computation_time(::lidar_slam::msg::Confidence::_computation_time_type arg)
  {
    msg_.computation_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lidar_slam::msg::Confidence msg_;
};

class Init_Confidence_failure
{
public:
  explicit Init_Confidence_failure(::lidar_slam::msg::Confidence & msg)
  : msg_(msg)
  {}
  Init_Confidence_computation_time failure(::lidar_slam::msg::Confidence::_failure_type arg)
  {
    msg_.failure = std::move(arg);
    return Init_Confidence_computation_time(msg_);
  }

private:
  ::lidar_slam::msg::Confidence msg_;
};

class Init_Confidence_std_position_error
{
public:
  explicit Init_Confidence_std_position_error(::lidar_slam::msg::Confidence & msg)
  : msg_(msg)
  {}
  Init_Confidence_failure std_position_error(::lidar_slam::msg::Confidence::_std_position_error_type arg)
  {
    msg_.std_position_error = std::move(arg);
    return Init_Confidence_failure(msg_);
  }

private:
  ::lidar_slam::msg::Confidence msg_;
};

class Init_Confidence_comply_motion_limits
{
public:
  explicit Init_Confidence_comply_motion_limits(::lidar_slam::msg::Confidence & msg)
  : msg_(msg)
  {}
  Init_Confidence_std_position_error comply_motion_limits(::lidar_slam::msg::Confidence::_comply_motion_limits_type arg)
  {
    msg_.comply_motion_limits = std::move(arg);
    return Init_Confidence_std_position_error(msg_);
  }

private:
  ::lidar_slam::msg::Confidence msg_;
};

class Init_Confidence_nb_matches
{
public:
  explicit Init_Confidence_nb_matches(::lidar_slam::msg::Confidence & msg)
  : msg_(msg)
  {}
  Init_Confidence_comply_motion_limits nb_matches(::lidar_slam::msg::Confidence::_nb_matches_type arg)
  {
    msg_.nb_matches = std::move(arg);
    return Init_Confidence_comply_motion_limits(msg_);
  }

private:
  ::lidar_slam::msg::Confidence msg_;
};

class Init_Confidence_overlap
{
public:
  explicit Init_Confidence_overlap(::lidar_slam::msg::Confidence & msg)
  : msg_(msg)
  {}
  Init_Confidence_nb_matches overlap(::lidar_slam::msg::Confidence::_overlap_type arg)
  {
    msg_.overlap = std::move(arg);
    return Init_Confidence_nb_matches(msg_);
  }

private:
  ::lidar_slam::msg::Confidence msg_;
};

class Init_Confidence_covariance
{
public:
  explicit Init_Confidence_covariance(::lidar_slam::msg::Confidence & msg)
  : msg_(msg)
  {}
  Init_Confidence_overlap covariance(::lidar_slam::msg::Confidence::_covariance_type arg)
  {
    msg_.covariance = std::move(arg);
    return Init_Confidence_overlap(msg_);
  }

private:
  ::lidar_slam::msg::Confidence msg_;
};

class Init_Confidence_header
{
public:
  Init_Confidence_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Confidence_covariance header(::lidar_slam::msg::Confidence::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Confidence_covariance(msg_);
  }

private:
  ::lidar_slam::msg::Confidence msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_slam::msg::Confidence>()
{
  return lidar_slam::msg::builder::Init_Confidence_header();
}

}  // namespace lidar_slam

#endif  // LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__BUILDER_HPP_

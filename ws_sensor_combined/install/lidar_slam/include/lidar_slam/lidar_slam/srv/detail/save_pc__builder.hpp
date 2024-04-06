// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lidar_slam:srv/SavePc.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__SRV__DETAIL__SAVE_PC__BUILDER_HPP_
#define LIDAR_SLAM__SRV__DETAIL__SAVE_PC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lidar_slam/srv/detail/save_pc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lidar_slam
{

namespace srv
{

namespace builder
{

class Init_SavePc_Request_format
{
public:
  explicit Init_SavePc_Request_format(::lidar_slam::srv::SavePc_Request & msg)
  : msg_(msg)
  {}
  ::lidar_slam::srv::SavePc_Request format(::lidar_slam::srv::SavePc_Request::_format_type arg)
  {
    msg_.format = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lidar_slam::srv::SavePc_Request msg_;
};

class Init_SavePc_Request_output_prefix_path
{
public:
  Init_SavePc_Request_output_prefix_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SavePc_Request_format output_prefix_path(::lidar_slam::srv::SavePc_Request::_output_prefix_path_type arg)
  {
    msg_.output_prefix_path = std::move(arg);
    return Init_SavePc_Request_format(msg_);
  }

private:
  ::lidar_slam::srv::SavePc_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_slam::srv::SavePc_Request>()
{
  return lidar_slam::srv::builder::Init_SavePc_Request_output_prefix_path();
}

}  // namespace lidar_slam


namespace lidar_slam
{

namespace srv
{

namespace builder
{

class Init_SavePc_Response_success
{
public:
  Init_SavePc_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lidar_slam::srv::SavePc_Response success(::lidar_slam::srv::SavePc_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lidar_slam::srv::SavePc_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_slam::srv::SavePc_Response>()
{
  return lidar_slam::srv::builder::Init_SavePc_Response_success();
}

}  // namespace lidar_slam

#endif  // LIDAR_SLAM__SRV__DETAIL__SAVE_PC__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lidar_slam:srv/Reset.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__SRV__DETAIL__RESET__BUILDER_HPP_
#define LIDAR_SLAM__SRV__DETAIL__RESET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lidar_slam/srv/detail/reset__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lidar_slam
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_slam::srv::Reset_Request>()
{
  return ::lidar_slam::srv::Reset_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace lidar_slam


namespace lidar_slam
{

namespace srv
{

namespace builder
{

class Init_Reset_Response_success
{
public:
  Init_Reset_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lidar_slam::srv::Reset_Response success(::lidar_slam::srv::Reset_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lidar_slam::srv::Reset_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_slam::srv::Reset_Response>()
{
  return lidar_slam::srv::builder::Init_Reset_Response_success();
}

}  // namespace lidar_slam

#endif  // LIDAR_SLAM__SRV__DETAIL__RESET__BUILDER_HPP_

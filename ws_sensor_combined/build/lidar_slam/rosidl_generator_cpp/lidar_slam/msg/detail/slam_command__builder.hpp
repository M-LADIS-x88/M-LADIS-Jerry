// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lidar_slam:msg/SlamCommand.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__BUILDER_HPP_
#define LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lidar_slam/msg/detail/slam_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lidar_slam
{

namespace msg
{

namespace builder
{

class Init_SlamCommand_string_arg
{
public:
  explicit Init_SlamCommand_string_arg(::lidar_slam::msg::SlamCommand & msg)
  : msg_(msg)
  {}
  ::lidar_slam::msg::SlamCommand string_arg(::lidar_slam::msg::SlamCommand::_string_arg_type arg)
  {
    msg_.string_arg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lidar_slam::msg::SlamCommand msg_;
};

class Init_SlamCommand_command
{
public:
  Init_SlamCommand_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SlamCommand_string_arg command(::lidar_slam::msg::SlamCommand::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_SlamCommand_string_arg(msg_);
  }

private:
  ::lidar_slam::msg::SlamCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_slam::msg::SlamCommand>()
{
  return lidar_slam::msg::builder::Init_SlamCommand_command();
}

}  // namespace lidar_slam

#endif  // LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__BUILDER_HPP_

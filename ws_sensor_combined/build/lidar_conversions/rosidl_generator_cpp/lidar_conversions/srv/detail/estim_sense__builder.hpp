// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lidar_conversions:srv/EstimSense.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_SENSE__BUILDER_HPP_
#define LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_SENSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lidar_conversions/srv/detail/estim_sense__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lidar_conversions
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_conversions::srv::EstimSense_Request>()
{
  return ::lidar_conversions::srv::EstimSense_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace lidar_conversions


namespace lidar_conversions
{

namespace srv
{

namespace builder
{

class Init_EstimSense_Response_success
{
public:
  Init_EstimSense_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lidar_conversions::srv::EstimSense_Response success(::lidar_conversions::srv::EstimSense_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lidar_conversions::srv::EstimSense_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_conversions::srv::EstimSense_Response>()
{
  return lidar_conversions::srv::builder::Init_EstimSense_Response_success();
}

}  // namespace lidar_conversions

#endif  // LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_SENSE__BUILDER_HPP_

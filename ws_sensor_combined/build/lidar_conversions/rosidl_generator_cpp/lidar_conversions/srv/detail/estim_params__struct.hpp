// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lidar_conversions:srv/EstimParams.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_PARAMS__STRUCT_HPP_
#define LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_PARAMS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lidar_conversions__srv__EstimParams_Request __attribute__((deprecated))
#else
# define DEPRECATED__lidar_conversions__srv__EstimParams_Request __declspec(deprecated)
#endif

namespace lidar_conversions
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct EstimParams_Request_
{
  using Type = EstimParams_Request_<ContainerAllocator>;

  explicit EstimParams_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit EstimParams_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    lidar_conversions::srv::EstimParams_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const lidar_conversions::srv::EstimParams_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lidar_conversions::srv::EstimParams_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lidar_conversions::srv::EstimParams_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lidar_conversions::srv::EstimParams_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lidar_conversions::srv::EstimParams_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lidar_conversions::srv::EstimParams_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lidar_conversions::srv::EstimParams_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lidar_conversions::srv::EstimParams_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lidar_conversions::srv::EstimParams_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lidar_conversions__srv__EstimParams_Request
    std::shared_ptr<lidar_conversions::srv::EstimParams_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lidar_conversions__srv__EstimParams_Request
    std::shared_ptr<lidar_conversions::srv::EstimParams_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EstimParams_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const EstimParams_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EstimParams_Request_

// alias to use template instance with default allocator
using EstimParams_Request =
  lidar_conversions::srv::EstimParams_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lidar_conversions


#ifndef _WIN32
# define DEPRECATED__lidar_conversions__srv__EstimParams_Response __attribute__((deprecated))
#else
# define DEPRECATED__lidar_conversions__srv__EstimParams_Response __declspec(deprecated)
#endif

namespace lidar_conversions
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct EstimParams_Response_
{
  using Type = EstimParams_Response_<ContainerAllocator>;

  explicit EstimParams_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit EstimParams_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lidar_conversions::srv::EstimParams_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const lidar_conversions::srv::EstimParams_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lidar_conversions::srv::EstimParams_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lidar_conversions::srv::EstimParams_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lidar_conversions::srv::EstimParams_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lidar_conversions::srv::EstimParams_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lidar_conversions::srv::EstimParams_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lidar_conversions::srv::EstimParams_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lidar_conversions::srv::EstimParams_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lidar_conversions::srv::EstimParams_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lidar_conversions__srv__EstimParams_Response
    std::shared_ptr<lidar_conversions::srv::EstimParams_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lidar_conversions__srv__EstimParams_Response
    std::shared_ptr<lidar_conversions::srv::EstimParams_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EstimParams_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const EstimParams_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EstimParams_Response_

// alias to use template instance with default allocator
using EstimParams_Response =
  lidar_conversions::srv::EstimParams_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lidar_conversions

namespace lidar_conversions
{

namespace srv
{

struct EstimParams
{
  using Request = lidar_conversions::srv::EstimParams_Request;
  using Response = lidar_conversions::srv::EstimParams_Response;
};

}  // namespace srv

}  // namespace lidar_conversions

#endif  // LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_PARAMS__STRUCT_HPP_

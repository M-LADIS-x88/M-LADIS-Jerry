// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lidar_slam:srv/SavePc.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__SRV__DETAIL__SAVE_PC__STRUCT_HPP_
#define LIDAR_SLAM__SRV__DETAIL__SAVE_PC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lidar_slam__srv__SavePc_Request __attribute__((deprecated))
#else
# define DEPRECATED__lidar_slam__srv__SavePc_Request __declspec(deprecated)
#endif

namespace lidar_slam
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SavePc_Request_
{
  using Type = SavePc_Request_<ContainerAllocator>;

  explicit SavePc_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output_prefix_path = "";
      this->format = 0l;
    }
  }

  explicit SavePc_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : output_prefix_path(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output_prefix_path = "";
      this->format = 0l;
    }
  }

  // field types and members
  using _output_prefix_path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _output_prefix_path_type output_prefix_path;
  using _format_type =
    int32_t;
  _format_type format;

  // setters for named parameter idiom
  Type & set__output_prefix_path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->output_prefix_path = _arg;
    return *this;
  }
  Type & set__format(
    const int32_t & _arg)
  {
    this->format = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lidar_slam::srv::SavePc_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const lidar_slam::srv::SavePc_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lidar_slam::srv::SavePc_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lidar_slam::srv::SavePc_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lidar_slam::srv::SavePc_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lidar_slam::srv::SavePc_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lidar_slam::srv::SavePc_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lidar_slam::srv::SavePc_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lidar_slam::srv::SavePc_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lidar_slam::srv::SavePc_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lidar_slam__srv__SavePc_Request
    std::shared_ptr<lidar_slam::srv::SavePc_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lidar_slam__srv__SavePc_Request
    std::shared_ptr<lidar_slam::srv::SavePc_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SavePc_Request_ & other) const
  {
    if (this->output_prefix_path != other.output_prefix_path) {
      return false;
    }
    if (this->format != other.format) {
      return false;
    }
    return true;
  }
  bool operator!=(const SavePc_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SavePc_Request_

// alias to use template instance with default allocator
using SavePc_Request =
  lidar_slam::srv::SavePc_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lidar_slam


#ifndef _WIN32
# define DEPRECATED__lidar_slam__srv__SavePc_Response __attribute__((deprecated))
#else
# define DEPRECATED__lidar_slam__srv__SavePc_Response __declspec(deprecated)
#endif

namespace lidar_slam
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SavePc_Response_
{
  using Type = SavePc_Response_<ContainerAllocator>;

  explicit SavePc_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SavePc_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    lidar_slam::srv::SavePc_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const lidar_slam::srv::SavePc_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lidar_slam::srv::SavePc_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lidar_slam::srv::SavePc_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lidar_slam::srv::SavePc_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lidar_slam::srv::SavePc_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lidar_slam::srv::SavePc_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lidar_slam::srv::SavePc_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lidar_slam::srv::SavePc_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lidar_slam::srv::SavePc_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lidar_slam__srv__SavePc_Response
    std::shared_ptr<lidar_slam::srv::SavePc_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lidar_slam__srv__SavePc_Response
    std::shared_ptr<lidar_slam::srv::SavePc_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SavePc_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SavePc_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SavePc_Response_

// alias to use template instance with default allocator
using SavePc_Response =
  lidar_slam::srv::SavePc_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lidar_slam

namespace lidar_slam
{

namespace srv
{

struct SavePc
{
  using Request = lidar_slam::srv::SavePc_Request;
  using Response = lidar_slam::srv::SavePc_Response;
};

}  // namespace srv

}  // namespace lidar_slam

#endif  // LIDAR_SLAM__SRV__DETAIL__SAVE_PC__STRUCT_HPP_

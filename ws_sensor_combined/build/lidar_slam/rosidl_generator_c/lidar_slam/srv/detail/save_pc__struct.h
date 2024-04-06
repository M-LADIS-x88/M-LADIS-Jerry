// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lidar_slam:srv/SavePc.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__SRV__DETAIL__SAVE_PC__STRUCT_H_
#define LIDAR_SLAM__SRV__DETAIL__SAVE_PC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'output_prefix_path'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SavePc in the package lidar_slam.
typedef struct lidar_slam__srv__SavePc_Request
{
  rosidl_runtime_c__String output_prefix_path;
  int32_t format;
} lidar_slam__srv__SavePc_Request;

// Struct for a sequence of lidar_slam__srv__SavePc_Request.
typedef struct lidar_slam__srv__SavePc_Request__Sequence
{
  lidar_slam__srv__SavePc_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_slam__srv__SavePc_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SavePc in the package lidar_slam.
typedef struct lidar_slam__srv__SavePc_Response
{
  bool success;
} lidar_slam__srv__SavePc_Response;

// Struct for a sequence of lidar_slam__srv__SavePc_Response.
typedef struct lidar_slam__srv__SavePc_Response__Sequence
{
  lidar_slam__srv__SavePc_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_slam__srv__SavePc_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_SLAM__SRV__DETAIL__SAVE_PC__STRUCT_H_

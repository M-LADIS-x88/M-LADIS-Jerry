// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lidar_slam:srv/Reset.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__SRV__DETAIL__RESET__STRUCT_H_
#define LIDAR_SLAM__SRV__DETAIL__RESET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Reset in the package lidar_slam.
typedef struct lidar_slam__srv__Reset_Request
{
  uint8_t structure_needs_at_least_one_member;
} lidar_slam__srv__Reset_Request;

// Struct for a sequence of lidar_slam__srv__Reset_Request.
typedef struct lidar_slam__srv__Reset_Request__Sequence
{
  lidar_slam__srv__Reset_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_slam__srv__Reset_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Reset in the package lidar_slam.
typedef struct lidar_slam__srv__Reset_Response
{
  bool success;
} lidar_slam__srv__Reset_Response;

// Struct for a sequence of lidar_slam__srv__Reset_Response.
typedef struct lidar_slam__srv__Reset_Response__Sequence
{
  lidar_slam__srv__Reset_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_slam__srv__Reset_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_SLAM__SRV__DETAIL__RESET__STRUCT_H_

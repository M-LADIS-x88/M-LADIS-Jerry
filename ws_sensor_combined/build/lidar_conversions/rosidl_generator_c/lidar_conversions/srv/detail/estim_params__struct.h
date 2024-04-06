// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lidar_conversions:srv/EstimParams.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_PARAMS__STRUCT_H_
#define LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_PARAMS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/EstimParams in the package lidar_conversions.
typedef struct lidar_conversions__srv__EstimParams_Request
{
  uint8_t structure_needs_at_least_one_member;
} lidar_conversions__srv__EstimParams_Request;

// Struct for a sequence of lidar_conversions__srv__EstimParams_Request.
typedef struct lidar_conversions__srv__EstimParams_Request__Sequence
{
  lidar_conversions__srv__EstimParams_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_conversions__srv__EstimParams_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/EstimParams in the package lidar_conversions.
typedef struct lidar_conversions__srv__EstimParams_Response
{
  bool success;
} lidar_conversions__srv__EstimParams_Response;

// Struct for a sequence of lidar_conversions__srv__EstimParams_Response.
typedef struct lidar_conversions__srv__EstimParams_Response__Sequence
{
  lidar_conversions__srv__EstimParams_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_conversions__srv__EstimParams_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_PARAMS__STRUCT_H_

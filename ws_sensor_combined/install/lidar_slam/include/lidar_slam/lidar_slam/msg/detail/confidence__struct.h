// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lidar_slam:msg/Confidence.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__STRUCT_H_
#define LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/Confidence in the package lidar_slam.
/**
  * The covariance in this message should be specified in the coordinate frame given by header.frame_id.
 */
typedef struct lidar_slam__msg__Confidence
{
  /// See "std_msgs/Header.msg"
  std_msgs__msg__Header header;
  /// Row-major representation of the 6x6 covariance matrix of ICP pose estimation.
  /// In order, the pose elements are:
  /// (x, y, z, rotation angle about X axis, rotation angle about Y axis, rotation angle about Z axis)
  /// Rotation is computed as Rz*Ry*Rx
  double covariance[36];
  /// Overlap estimation
  /// It is contained in [0, 1]
  /// Good values are greater than 0.6
  /// Bad values are lower than 0.4
  /// Jumps in this value can reflect pose estimation failure
  float overlap;
  /// Number of matches between extracted keypoints
  /// and current keypoint maps
  /// Good values are greater than 200
  /// Bad values are lower than 50
  int16_t nb_matches;
  /// This value indicates if the estimated pose
  /// respects the specified physical constraints on velocity and acceleration
  bool comply_motion_limits;
  /// Standard deviation of the position error based on the pose
  /// covariance supplied by the SLAM algorithm
  float std_position_error;
  /// Boolean based on the fusion of the previous estimators
  /// to indicate whether or not the SLAM has failed
  bool failure;
  /// This value indicates the computation time from data reception to pose output
  float computation_time;
} lidar_slam__msg__Confidence;

// Struct for a sequence of lidar_slam__msg__Confidence.
typedef struct lidar_slam__msg__Confidence__Sequence
{
  lidar_slam__msg__Confidence * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_slam__msg__Confidence__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_SLAM__MSG__DETAIL__CONFIDENCE__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lidar_slam:msg/SlamCommand.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__STRUCT_H_
#define LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'DISABLE_SLAM_MAP_UPDATE'.
/**
  * ==============================================================================
  * Commands description :
  * Disable/enable SLAM maps update with new frames keypoints. This can be useful
  * if we want to keep the pose graph optimized SLAM map
  * or any initially loaded map untouched
 */
enum
{
  lidar_slam__msg__SlamCommand__DISABLE_SLAM_MAP_UPDATE = 8
};

/// Constant 'ENABLE_SLAM_MAP_EXPANSION'.
enum
{
  lidar_slam__msg__SlamCommand__ENABLE_SLAM_MAP_EXPANSION = 9
};

/// Constant 'ENABLE_SLAM_MAP_UPDATE'.
enum
{
  lidar_slam__msg__SlamCommand__ENABLE_SLAM_MAP_UPDATE = 10
};

/// Constant 'RESET_TRAJECTORY'.
/**
  * Reset slam trajectory from a trajectory file
 */
enum
{
  lidar_slam__msg__SlamCommand__RESET_TRAJECTORY = 11
};

/// Constant 'RESET_SLAM'.
/**
  * Reset the SLAM state. Clear the maps and the trajectory, set the current pose to origin.
 */
enum
{
  lidar_slam__msg__SlamCommand__RESET_SLAM = 12
};

/// Constant 'SWITCH_ON_OFF'.
/**
  * Enable/Disable the SLAM process
 */
enum
{
  lidar_slam__msg__SlamCommand__SWITCH_ON_OFF = 13
};

/// Constant 'SAVE_TRAJECTORY'.
/**
  * Save the current trajectory tracking base frame as csv file
 */
enum
{
  lidar_slam__msg__SlamCommand__SAVE_TRAJECTORY = 14
};

/// Constant 'SAVE_LIDAR_TRAJECTORY'.
/**
  * Save the current trajectory tracking the main Lidar frame as csv file
 */
enum
{
  lidar_slam__msg__SlamCommand__SAVE_LIDAR_TRAJECTORY = 15
};

/// Constant 'SAVE_KEYPOINTS_MAPS'.
/**
  * Save/Load keypoints maps (edges, planes and blobs if used) to/from disk.
  * Use 'string_arg' to indicate path prefix of maps : "/path/to/slam_map_" will
  * save/load to "/path/to/slam_map_edges.pcd", "/path/to/slam_map_planes.pcd"
  * and "/path/to/slam_map_blobs.pcd".
  * WARNING : this process is not real time.
 */
enum
{
  lidar_slam__msg__SlamCommand__SAVE_KEYPOINTS_MAPS = 16
};

/// Constant 'SAVE_FILTERED_KEYPOINTS_MAPS'.
enum
{
  lidar_slam__msg__SlamCommand__SAVE_FILTERED_KEYPOINTS_MAPS = 17
};

/// Constant 'LOAD_KEYPOINTS_MAPS'.
enum
{
  lidar_slam__msg__SlamCommand__LOAD_KEYPOINTS_MAPS = 18
};

/// Constant 'OPTIMIZE_GRAPH'.
/**
  * Stop the slam and optimize pose graph
  * The pose graph optimization is done via g2o, fusing SLAM, GPS and or landmarks detections.
  * If logging is enabled, SLAM maps will also
  * be updated. This allows to correct SLAM drift and to link more precisely
  * SLAM odometry frame to GPS world/map frame.
  * WARNING : this process is not real time.
 */
enum
{
  lidar_slam__msg__SlamCommand__OPTIMIZE_GRAPH = 20
};

/// Constant 'LOAD_LOOP_INDICES'.
/**
  * Add loop closure indices from an external file
  * containing query frame indices and revisited frame indices
  * The file should be a csv file with fields queryIdx and revisitedIdx
 */
enum
{
  lidar_slam__msg__SlamCommand__LOAD_LOOP_INDICES = 23
};

/// Constant 'SWITCH_SENSOR'.
/**
  * Enable/Disable an external sensor
  * If enabled, sensor data are received and stored to then be processed.
  * External sensor data can be used in the local optimization or in
  * a pose graph optimization in a postprocess manner
  * Use 'string_arg' to tell which sensor should be activated
  * options are :
  *   * WHEEL_ENCODER : "0"
  *   * IMU : "1"
  *   * LANDMARK_DETECTOR : "2"
  *   * GPS : "3"
  *   * POSE : "4"
  *   * CAMERA : "5"
 */
enum
{
  lidar_slam__msg__SlamCommand__SWITCH_SENSOR = 25
};

/// Constant 'CALIBRATE_WITH_POSES'.
/**
  * Launch a calibration process using the current SLAM trajectory
  * and a file containing an external trajectory captured at the same time
  * The file should be a csv file with fields time,x,y,z,x0,y0,z0,x1,y1,z1,x2,y2,z2
  * xi being the first element of the ith column of the rotation matrix
  * and the first line should contain the ID of the frame tracked in the file's trajectory
  * It publishes a static TF between the base frame and the
  * frame tracked by the external trajectory
  * Only an overlapping part of trajectories is necessary to compute
  * the calibration
 */
enum
{
  lidar_slam__msg__SlamCommand__CALIBRATE_WITH_POSES = 30
};

/// Constant 'LOAD_POSES'.
/**
  * Load poses from an external file when using the
  * package in replay (post-process)
  * This command takes an argument as a file path to a file.
  * The file should be CSV with fields : time,x,y,z,x0,y0,z0,x1,y1,z1,x2,y2,z2
  * xi being the first element of the ith column of the rotation matrix
  * These poses can be used for de-skewing the input points,
  * to supply a prior motion to the registration algorithm
  * and as a contraint in the SLAM optimization.
  * It can also be used to optimize a pose graph.
  * The calibration between "ext_pose_sensor" and the
  * SLAM tracked pose should be in the TF tree
  * It can also be estimated using the calibrate command
 */
enum
{
  lidar_slam__msg__SlamCommand__LOAD_POSES = 40
};

// Include directives for member types
// Member 'string_arg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SlamCommand in the package lidar_slam.
/**
  * The ID of the command to run.
 */
typedef struct lidar_slam__msg__SlamCommand
{
  uint8_t command;
  /// Optional string argument
  rosidl_runtime_c__String string_arg;
} lidar_slam__msg__SlamCommand;

// Struct for a sequence of lidar_slam__msg__SlamCommand.
typedef struct lidar_slam__msg__SlamCommand__Sequence
{
  lidar_slam__msg__SlamCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_slam__msg__SlamCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_SLAM__MSG__DETAIL__SLAM_COMMAND__STRUCT_H_

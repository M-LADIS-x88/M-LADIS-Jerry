# Install script for directory: /home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/install/lidar_slam")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/build/lidar_slam/slam/slam_lib/libLidarSlam.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/LidarSlam" TYPE FILE FILES
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/CeresCostFunctions.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/ConfidenceEstimators.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/DenseSpinningSensorKeypointExtractor.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/Enums.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/ExternalSensorManagers.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/InterpolationModels.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/KDTreePCLAdaptor.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/KeypointExtractor.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/KeypointsMatcher.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/LidarPoint.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/LocalOptimizer.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/PointCloudStorage.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/PoseGraphOptimizer.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/RollingGrid.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/Slam.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/SpinningSensorKeypointExtractor.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/State.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/Utilities.h"
    "/home/robmoemac/M-LADIS-Jerry/ws_sensor_combined/src/slam/slam_lib/include/LidarSlam/VoxelGrid.h"
    )
endif()


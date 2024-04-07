cmake_minimum_required(VERSION 3.5)
project(px4_ros_com)

# Default to C99
if(NOT CMAKE_C_STANDARD)
	set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(python_cmake_module REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(px4_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(pcl_ros REQUIRED)


#################
# Setup targets #
#################

include_directories(include)
#include_directories(${Open3D_INCLUDE_DIRS})

# Add frame_transforms lib
#add_library(frame_transforms SHARED src/lib/frame_transforms.cpp)
#ament_target_dependencies(frame_transforms Eigen3 geometry_msgs)
#target_include_directories(frame_transforms PUBLIC
#	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
#	$<INSTALL_INTERFACE:include/${PROJECT_NAME}>
#)

#ament_python_install_package(${PROJECT_NAME})

# examples/listeners/sensor_combined_listener
add_executable(sensor_combined_listener src/examples/listeners/sensor_combined_listener.cpp)
ament_target_dependencies(sensor_combined_listener rclcpp px4_msgs)
install(TARGETS sensor_combined_listener DESTINATION lib/${PROJECT_NAME})

# examples/listeners/vehicle_gps_position_listener
add_executable(vehicle_gps_position_listener src/examples/listeners/vehicle_gps_position_listener.cpp)
ament_target_dependencies(vehicle_gps_position_listener rclcpp px4_msgs)
install(TARGETS vehicle_gps_position_listener DESTINATION lib/${PROJECT_NAME})

# examples/advertisers/debug_vect_advertiser
add_executable(debug_vect_advertiser src/examples/advertisers/debug_vect_advertiser.cpp)
ament_target_dependencies(debug_vect_advertiser rclcpp px4_msgs)
install(TARGETS debug_vect_advertiser DESTINATION lib/${PROJECT_NAME})

# examples/offboard/offboard_control
add_executable(offboard_control src/examples/offboard/offboard_control.cpp)
ament_target_dependencies(offboard_control rclcpp px4_msgs)
install(TARGETS offboard_control DESTINATION lib/${PROJECT_NAME})

# New thing!
add_executable(test_flight_control src/examples/offboard/test_flight_control.cpp)
ament_target_dependencies(test_flight_control rclcpp px4_msgs)
install(TARGETS test_flight_control DESTINATION lib/${PROJECT_NAME})

#lidar ingestion
add_executable(PointCloudProcessor src/PointCloudProcessor.cpp)
ament_target_dependencies(PointCloudProcessor rclcpp sensor_msgs pcl_conversions pcl_ros)
install(TARGETS PointCloudProcessor DESTINATION lib/${PROJECT_NAME})

#GPS localization replacement
add_executable(vis_loc_GPS_spoof src/vis_loc_GPS_spoof.cpp)
ament_target_dependencies(vis_loc_GPS_spoof rclcpp geometry_msgs px4_msgs)
install(TARGETS vis_loc_GPS_spoof DESTINATION lib/${PROJECT_NAME})

# New thing!
#add_executable(lidar_clustering src/computer_viz/lidar_clustering.cpp)
#ament_target_dependencies(lidar_clustering rclcpp px4_msgs)
#ament_target_dependencies(lidar_clustering rclcpp sensor_msgs)
#install(TARGETS lidar_clustering DESTINATION lib/${PROJECT_NAME})



#python setup
#add_executable(PC_ingestion src/obj_detection/PC_ingestion.py)
#ament_target_dependencies(PC_ingestion rclpy px4_msgs)
#install(PROGRAMS
 #   src/obj_detection/PC_ingestion.py
  #  DESTINATION lib/${PROJECT_NAME}
#)

# Additional dependencies for the Python script


############
# Install ##
############

# Export information to downstream packages
ament_export_dependencies(ament_cmake rclcpp rosidl_default_runtime eigen3_cmake_module Eigen3 px4_msgs geometry_msgs sensor_msgs)

#ament_export_targets(export_frame_transforms HAS_LIBRARY_TARGET)

ament_export_include_directories(include)
#ament_export_libraries(frame_transforms)

# Install header files
install(DIRECTORY include/${PROJECT_NAME}/ DESTINATION include/${PROJECT_NAME})

#install(TARGETS frame_transforms
#	EXPORT export_frame_transforms
#	ARCHIVE DESTINATION lib
#	LIBRARY DESTINATION lib
#	RUNTIME DESTINATION bin
#	INCLUDES DESTINATION include
#)

# Install launch files.
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME}/)

# Install tests
install(DIRECTORY test DESTINATION share/${PROJECT_NAME}/)


############
# Testing ##
############

if(BUILD_TESTING)
	find_package(ament_lint_auto REQUIRED)
	# the following line skips the linter which checks for copyrights
	# uncomment the line when a copyright and license is not present in all source files
	#set(ament_cmake_copyright_FOUND TRUE)
	# the following line skips cpplint (only works in a git repo)
	# uncomment the line when this package is not in a git repo
	#set(ament_cmake_cpplint_FOUND TRUE)
	ament_lint_auto_find_test_dependencies()
endif()

ament_package()

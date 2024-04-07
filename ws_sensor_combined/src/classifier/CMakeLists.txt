cmake_minimum_required(VERSION 3.8)
project(classifier)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

# Add the 'pose_array_to_file_node' executable
add_executable(classifier src/classifier_node.cpp)
ament_target_dependencies(classifier rclcpp std_msgs geometry_msgs)
target_compile_features(classifier PUBLIC cxx_std_17)

# Add the 'pose_array_publisher_node' executable
add_executable(pose_array_publisher_node src/fake_posters.cpp)
ament_target_dependencies(pose_array_publisher_node rclcpp std_msgs geometry_msgs)
target_compile_features(pose_array_publisher_node PUBLIC cxx_std_17)

# Install the node targets
install(TARGETS
  classifier
  pose_array_publisher_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
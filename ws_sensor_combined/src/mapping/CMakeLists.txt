cmake_minimum_required(VERSION 3.8)
project(mapping)

# Compile options
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Add executable
add_executable(map_node src/map_node.cpp)
ament_target_dependencies(map_node
  rclcpp
  std_msgs
)

# Include directories
target_include_directories(map_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

# Require C++17
target_compile_features(map_node PUBLIC cxx_std_17)

# Install the executable
install(TARGETS 
  map_node 
  DESTINATION lib/${PROJECT_NAME})

# Linting (optional)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

# Package the project
ament_package()
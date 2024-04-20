cmake_minimum_required(VERSION 3.5)
project(wpgen)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(px4_msgs REQUIRED)
find_package(ament_index_python REQUIRED)
find_package(pandas REQUIRED)

# Install Python package directory
install(DIRECTORY
  wpgen/
  DESTINATION lib/${PROJECT_NAME}
)

# Install other resources like the EXAMPLE directory
install(DIRECTORY
  EXAMPLE/
  DESTINATION share/${PROJECT_NAME}
)


# Additional install commands for launch files, configs, etc. would go here, if necessary

ament_package()

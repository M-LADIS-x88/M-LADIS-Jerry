#----------------------------------------------------------------
# Generated CMake target import file for configuration "release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "lidar_slam::lidar_slam__rosidl_typesupport_fastrtps_c" for configuration "release"
set_property(TARGET lidar_slam::lidar_slam__rosidl_typesupport_fastrtps_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(lidar_slam::lidar_slam__rosidl_typesupport_fastrtps_c PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/liblidar_slam__rosidl_typesupport_fastrtps_c.so"
  IMPORTED_SONAME_RELEASE "liblidar_slam__rosidl_typesupport_fastrtps_c.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS lidar_slam::lidar_slam__rosidl_typesupport_fastrtps_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_lidar_slam::lidar_slam__rosidl_typesupport_fastrtps_c "${_IMPORT_PREFIX}/lib/liblidar_slam__rosidl_typesupport_fastrtps_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

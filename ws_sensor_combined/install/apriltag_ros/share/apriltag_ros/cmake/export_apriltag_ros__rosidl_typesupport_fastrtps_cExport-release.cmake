#----------------------------------------------------------------
# Generated CMake target import file for configuration "release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "apriltag_ros::apriltag_ros__rosidl_typesupport_fastrtps_c" for configuration "release"
set_property(TARGET apriltag_ros::apriltag_ros__rosidl_typesupport_fastrtps_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(apriltag_ros::apriltag_ros__rosidl_typesupport_fastrtps_c PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libapriltag_ros__rosidl_typesupport_fastrtps_c.so"
  IMPORTED_SONAME_RELEASE "libapriltag_ros__rosidl_typesupport_fastrtps_c.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS apriltag_ros::apriltag_ros__rosidl_typesupport_fastrtps_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_apriltag_ros::apriltag_ros__rosidl_typesupport_fastrtps_c "${_IMPORT_PREFIX}/lib/libapriltag_ros__rosidl_typesupport_fastrtps_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

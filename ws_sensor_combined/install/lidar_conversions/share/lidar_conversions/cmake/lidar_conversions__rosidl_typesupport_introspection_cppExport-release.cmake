#----------------------------------------------------------------
# Generated CMake target import file for configuration "release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "lidar_conversions::lidar_conversions__rosidl_typesupport_introspection_cpp" for configuration "release"
set_property(TARGET lidar_conversions::lidar_conversions__rosidl_typesupport_introspection_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(lidar_conversions::lidar_conversions__rosidl_typesupport_introspection_cpp PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/liblidar_conversions__rosidl_typesupport_introspection_cpp.so"
  IMPORTED_SONAME_RELEASE "liblidar_conversions__rosidl_typesupport_introspection_cpp.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS lidar_conversions::lidar_conversions__rosidl_typesupport_introspection_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_lidar_conversions::lidar_conversions__rosidl_typesupport_introspection_cpp "${_IMPORT_PREFIX}/lib/liblidar_conversions__rosidl_typesupport_introspection_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

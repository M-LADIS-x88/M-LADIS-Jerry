#----------------------------------------------------------------
# Generated CMake target import file for configuration "release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "livox_ros_driver::livox_ros_driver__rosidl_typesupport_introspection_cpp" for configuration "release"
set_property(TARGET livox_ros_driver::livox_ros_driver__rosidl_typesupport_introspection_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(livox_ros_driver::livox_ros_driver__rosidl_typesupport_introspection_cpp PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/liblivox_ros_driver__rosidl_typesupport_introspection_cpp.so"
  IMPORTED_SONAME_RELEASE "liblivox_ros_driver__rosidl_typesupport_introspection_cpp.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS livox_ros_driver::livox_ros_driver__rosidl_typesupport_introspection_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_livox_ros_driver::livox_ros_driver__rosidl_typesupport_introspection_cpp "${_IMPORT_PREFIX}/lib/liblivox_ros_driver__rosidl_typesupport_introspection_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

#----------------------------------------------------------------
# Generated CMake target import file for configuration "release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "LidarSlam::LidarSlam" for configuration "release"
set_property(TARGET LidarSlam::LidarSlam APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(LidarSlam::LidarSlam PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libLidarSlam.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS LidarSlam::LidarSlam )
list(APPEND _IMPORT_CHECK_FILES_FOR_LidarSlam::LidarSlam "${_IMPORT_PREFIX}/lib/libLidarSlam.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

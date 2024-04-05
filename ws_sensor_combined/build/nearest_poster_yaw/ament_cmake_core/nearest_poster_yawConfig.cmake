# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_nearest_poster_yaw_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED nearest_poster_yaw_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(nearest_poster_yaw_FOUND FALSE)
  elseif(NOT nearest_poster_yaw_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(nearest_poster_yaw_FOUND FALSE)
  endif()
  return()
endif()
set(_nearest_poster_yaw_CONFIG_INCLUDED TRUE)

# output package information
if(NOT nearest_poster_yaw_FIND_QUIETLY)
  message(STATUS "Found nearest_poster_yaw: 0.0.0 (${nearest_poster_yaw_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'nearest_poster_yaw' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${nearest_poster_yaw_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(nearest_poster_yaw_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${nearest_poster_yaw_DIR}/${_extra}")
endforeach()

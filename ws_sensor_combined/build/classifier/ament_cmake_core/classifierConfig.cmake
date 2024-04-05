# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_classifier_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED classifier_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(classifier_FOUND FALSE)
  elseif(NOT classifier_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(classifier_FOUND FALSE)
  endif()
  return()
endif()
set(_classifier_CONFIG_INCLUDED TRUE)

# output package information
if(NOT classifier_FIND_QUIETLY)
  message(STATUS "Found classifier: 0.0.0 (${classifier_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'classifier' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${classifier_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(classifier_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${classifier_DIR}/${_extra}")
endforeach()

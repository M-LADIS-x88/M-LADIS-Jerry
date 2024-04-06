
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was Config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

if (OFF)
  # Workaround to avoid circular dependency between LidarSlamLib and LidarSlamPlugin
  add_library(vtkLidarSlam SHARED IMPORTED)
endif ()

include("${CMAKE_CURRENT_LIST_DIR}/LidarSlamLib-targets.cmake")

if (OFF)
  include("${CMAKE_CURRENT_LIST_DIR}/LidarSlamLib-paraview-plugin-properties.cmake")
endif ()

include(CMakeFindDependencyMacro)

find_dependency(Boost REQUIRED)

find_dependency(nanoflann REQUIRED)

find_dependency(Eigen3 QUIET)

find_dependency(Ceres REQUIRED)

find_dependency(PCL REQUIRED COMPONENTS common io octree geometry
                OPTIONAL_COMPONENTS )

# Find optional g2o (only used for pose graph optimization)
if ()
  find_dependency(g2o QUIET)
else()
  message(STATUS "LidarSlam: G2O was not found, pose graph API disabled")
endif()

# Find optional gtsam (only used for pose IMU raw data integration)
if ()
  find_dependency(GTSAM QUIET)
else()
  message(STATUS "LidarSlam: GTSAM was not found, IMU preintegration disabled")
endif()

# Find optional OpenMP
if (TRUE)
  find_dependency(OpenMP QUIET)
else()
  message(STATUS "LidarSlam: OpenMP was not found, multi-threading for SLAM disabled")
endif()

# Find optional teaserpp (only used for automatic detection of loop closure)
if ()
  find_dependency(teaserpp QUIET)
else()
  message(STATUS "Lidar SLAM : TEASER++ was not found, automatic loop closure detection disabled")
endif()

check_required_components(LidarSlam)

// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lidar_slam:msg/Confidence.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lidar_slam/msg/detail/confidence__rosidl_typesupport_introspection_c.h"
#include "lidar_slam/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lidar_slam/msg/detail/confidence__functions.h"
#include "lidar_slam/msg/detail/confidence__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lidar_slam__msg__Confidence__init(message_memory);
}

void lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_fini_function(void * message_memory)
{
  lidar_slam__msg__Confidence__fini(message_memory);
}

size_t lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__size_function__Confidence__covariance(
  const void * untyped_member)
{
  (void)untyped_member;
  return 36;
}

const void * lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__get_const_function__Confidence__covariance(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__get_function__Confidence__covariance(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__fetch_function__Confidence__covariance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__get_const_function__Confidence__covariance(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__assign_function__Confidence__covariance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__get_function__Confidence__covariance(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__msg__Confidence, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "covariance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    36,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__msg__Confidence, covariance),  // bytes offset in struct
    NULL,  // default value
    lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__size_function__Confidence__covariance,  // size() function pointer
    lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__get_const_function__Confidence__covariance,  // get_const(index) function pointer
    lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__get_function__Confidence__covariance,  // get(index) function pointer
    lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__fetch_function__Confidence__covariance,  // fetch(index, &value) function pointer
    lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__assign_function__Confidence__covariance,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "overlap",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__msg__Confidence, overlap),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "nb_matches",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__msg__Confidence, nb_matches),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "comply_motion_limits",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__msg__Confidence, comply_motion_limits),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "std_position_error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__msg__Confidence, std_position_error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "failure",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__msg__Confidence, failure),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "computation_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__msg__Confidence, computation_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_message_members = {
  "lidar_slam__msg",  // message namespace
  "Confidence",  // message name
  8,  // number of fields
  sizeof(lidar_slam__msg__Confidence),
  lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_message_member_array,  // message members
  lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_init_function,  // function to initialize message memory (memory has to be allocated)
  lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_message_type_support_handle = {
  0,
  &lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lidar_slam
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam, msg, Confidence)() {
  lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_message_type_support_handle.typesupport_identifier) {
    lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lidar_slam__msg__Confidence__rosidl_typesupport_introspection_c__Confidence_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

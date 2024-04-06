// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from apriltag_ros:msg/AprilTagDetection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "apriltag_ros/msg/detail/april_tag_detection__rosidl_typesupport_introspection_c.h"
#include "apriltag_ros/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "apriltag_ros/msg/detail/april_tag_detection__functions.h"
#include "apriltag_ros/msg/detail/april_tag_detection__struct.h"


// Include directives for member types
// Member `id`
// Member `size`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `pose`
#include "geometry_msgs/msg/pose_with_covariance_stamped.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_with_covariance_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  apriltag_ros__msg__AprilTagDetection__init(message_memory);
}

void apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_fini_function(void * message_memory)
{
  apriltag_ros__msg__AprilTagDetection__fini(message_memory);
}

size_t apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__size_function__AprilTagDetection__id(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_const_function__AprilTagDetection__id(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_function__AprilTagDetection__id(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__fetch_function__AprilTagDetection__id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_const_function__AprilTagDetection__id(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__assign_function__AprilTagDetection__id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_function__AprilTagDetection__id(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__resize_function__AprilTagDetection__id(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__size_function__AprilTagDetection__size(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_const_function__AprilTagDetection__size(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_function__AprilTagDetection__size(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__fetch_function__AprilTagDetection__size(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_const_function__AprilTagDetection__size(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__assign_function__AprilTagDetection__size(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_function__AprilTagDetection__size(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__resize_function__AprilTagDetection__size(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_message_member_array[3] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apriltag_ros__msg__AprilTagDetection, id),  // bytes offset in struct
    NULL,  // default value
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__size_function__AprilTagDetection__id,  // size() function pointer
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_const_function__AprilTagDetection__id,  // get_const(index) function pointer
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_function__AprilTagDetection__id,  // get(index) function pointer
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__fetch_function__AprilTagDetection__id,  // fetch(index, &value) function pointer
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__assign_function__AprilTagDetection__id,  // assign(index, value) function pointer
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__resize_function__AprilTagDetection__id  // resize(index) function pointer
  },
  {
    "size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apriltag_ros__msg__AprilTagDetection, size),  // bytes offset in struct
    NULL,  // default value
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__size_function__AprilTagDetection__size,  // size() function pointer
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_const_function__AprilTagDetection__size,  // get_const(index) function pointer
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__get_function__AprilTagDetection__size,  // get(index) function pointer
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__fetch_function__AprilTagDetection__size,  // fetch(index, &value) function pointer
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__assign_function__AprilTagDetection__size,  // assign(index, value) function pointer
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__resize_function__AprilTagDetection__size  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apriltag_ros__msg__AprilTagDetection, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_message_members = {
  "apriltag_ros__msg",  // message namespace
  "AprilTagDetection",  // message name
  3,  // number of fields
  sizeof(apriltag_ros__msg__AprilTagDetection),
  apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_message_member_array,  // message members
  apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_message_type_support_handle = {
  0,
  &apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_apriltag_ros
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, apriltag_ros, msg, AprilTagDetection)() {
  apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseWithCovarianceStamped)();
  if (!apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_message_type_support_handle.typesupport_identifier) {
    apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &apriltag_ros__msg__AprilTagDetection__rosidl_typesupport_introspection_c__AprilTagDetection_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

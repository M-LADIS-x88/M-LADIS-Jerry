// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lidar_slam:msg/SlamCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lidar_slam/msg/detail/slam_command__rosidl_typesupport_introspection_c.h"
#include "lidar_slam/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lidar_slam/msg/detail/slam_command__functions.h"
#include "lidar_slam/msg/detail/slam_command__struct.h"


// Include directives for member types
// Member `string_arg`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lidar_slam__msg__SlamCommand__init(message_memory);
}

void lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_fini_function(void * message_memory)
{
  lidar_slam__msg__SlamCommand__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_message_member_array[2] = {
  {
    "command",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__msg__SlamCommand, command),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "string_arg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__msg__SlamCommand, string_arg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_message_members = {
  "lidar_slam__msg",  // message namespace
  "SlamCommand",  // message name
  2,  // number of fields
  sizeof(lidar_slam__msg__SlamCommand),
  lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_message_member_array,  // message members
  lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_message_type_support_handle = {
  0,
  &lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lidar_slam
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam, msg, SlamCommand)() {
  if (!lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_message_type_support_handle.typesupport_identifier) {
    lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lidar_slam__msg__SlamCommand__rosidl_typesupport_introspection_c__SlamCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

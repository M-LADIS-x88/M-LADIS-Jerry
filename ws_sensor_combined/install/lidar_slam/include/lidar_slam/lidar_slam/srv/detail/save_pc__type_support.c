// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lidar_slam:srv/SavePc.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lidar_slam/srv/detail/save_pc__rosidl_typesupport_introspection_c.h"
#include "lidar_slam/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lidar_slam/srv/detail/save_pc__functions.h"
#include "lidar_slam/srv/detail/save_pc__struct.h"


// Include directives for member types
// Member `output_prefix_path`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lidar_slam__srv__SavePc_Request__init(message_memory);
}

void lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_fini_function(void * message_memory)
{
  lidar_slam__srv__SavePc_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_message_member_array[2] = {
  {
    "output_prefix_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__srv__SavePc_Request, output_prefix_path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "format",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__srv__SavePc_Request, format),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_message_members = {
  "lidar_slam__srv",  // message namespace
  "SavePc_Request",  // message name
  2,  // number of fields
  sizeof(lidar_slam__srv__SavePc_Request),
  lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_message_member_array,  // message members
  lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_message_type_support_handle = {
  0,
  &lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lidar_slam
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam, srv, SavePc_Request)() {
  if (!lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_message_type_support_handle.typesupport_identifier) {
    lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lidar_slam__srv__SavePc_Request__rosidl_typesupport_introspection_c__SavePc_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "lidar_slam/srv/detail/save_pc__rosidl_typesupport_introspection_c.h"
// already included above
// #include "lidar_slam/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "lidar_slam/srv/detail/save_pc__functions.h"
// already included above
// #include "lidar_slam/srv/detail/save_pc__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lidar_slam__srv__SavePc_Response__init(message_memory);
}

void lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_fini_function(void * message_memory)
{
  lidar_slam__srv__SavePc_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam__srv__SavePc_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_message_members = {
  "lidar_slam__srv",  // message namespace
  "SavePc_Response",  // message name
  1,  // number of fields
  sizeof(lidar_slam__srv__SavePc_Response),
  lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_message_member_array,  // message members
  lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_message_type_support_handle = {
  0,
  &lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lidar_slam
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam, srv, SavePc_Response)() {
  if (!lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_message_type_support_handle.typesupport_identifier) {
    lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lidar_slam__srv__SavePc_Response__rosidl_typesupport_introspection_c__SavePc_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "lidar_slam/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "lidar_slam/srv/detail/save_pc__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers lidar_slam__srv__detail__save_pc__rosidl_typesupport_introspection_c__SavePc_service_members = {
  "lidar_slam__srv",  // service namespace
  "SavePc",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // lidar_slam__srv__detail__save_pc__rosidl_typesupport_introspection_c__SavePc_Request_message_type_support_handle,
  NULL  // response message
  // lidar_slam__srv__detail__save_pc__rosidl_typesupport_introspection_c__SavePc_Response_message_type_support_handle
};

static rosidl_service_type_support_t lidar_slam__srv__detail__save_pc__rosidl_typesupport_introspection_c__SavePc_service_type_support_handle = {
  0,
  &lidar_slam__srv__detail__save_pc__rosidl_typesupport_introspection_c__SavePc_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam, srv, SavePc_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam, srv, SavePc_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lidar_slam
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam, srv, SavePc)() {
  if (!lidar_slam__srv__detail__save_pc__rosidl_typesupport_introspection_c__SavePc_service_type_support_handle.typesupport_identifier) {
    lidar_slam__srv__detail__save_pc__rosidl_typesupport_introspection_c__SavePc_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)lidar_slam__srv__detail__save_pc__rosidl_typesupport_introspection_c__SavePc_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam, srv, SavePc_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam, srv, SavePc_Response)()->data;
  }

  return &lidar_slam__srv__detail__save_pc__rosidl_typesupport_introspection_c__SavePc_service_type_support_handle;
}

// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xr_msgs:msg/Custom.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xr_msgs/msg/detail/custom__rosidl_typesupport_introspection_c.h"
#include "xr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xr_msgs/msg/detail/custom__functions.h"
#include "xr_msgs/msg/detail/custom__struct.h"


// Include directives for member types
// Member `head`
#include "xr_msgs/msg/head.h"
// Member `head`
#include "xr_msgs/msg/detail/head__rosidl_typesupport_introspection_c.h"
// Member `left_controller`
// Member `right_controller`
#include "xr_msgs/msg/controller.h"
// Member `left_controller`
// Member `right_controller`
#include "xr_msgs/msg/detail/controller__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xr_msgs__msg__Custom__init(message_memory);
}

void xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_fini_function(void * message_memory)
{
  xr_msgs__msg__Custom__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_message_member_array[5] = {
  {
    "timestamp_ns",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xr_msgs__msg__Custom, timestamp_ns),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "input",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xr_msgs__msg__Custom, input),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "head",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xr_msgs__msg__Custom, head),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left_controller",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xr_msgs__msg__Custom, left_controller),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_controller",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xr_msgs__msg__Custom, right_controller),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_message_members = {
  "xr_msgs__msg",  // message namespace
  "Custom",  // message name
  5,  // number of fields
  sizeof(xr_msgs__msg__Custom),
  xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_message_member_array,  // message members
  xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_init_function,  // function to initialize message memory (memory has to be allocated)
  xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_message_type_support_handle = {
  0,
  &xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xr_msgs, msg, Custom)() {
  xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xr_msgs, msg, Head)();
  xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xr_msgs, msg, Controller)();
  xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xr_msgs, msg, Controller)();
  if (!xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_message_type_support_handle.typesupport_identifier) {
    xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &xr_msgs__msg__Custom__rosidl_typesupport_introspection_c__Custom_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xr_msgs:msg/Head.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xr_msgs/msg/detail/head__rosidl_typesupport_introspection_c.h"
#include "xr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xr_msgs/msg/detail/head__functions.h"
#include "xr_msgs/msg/detail/head__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xr_msgs__msg__Head__init(message_memory);
}

void xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_fini_function(void * message_memory)
{
  xr_msgs__msg__Head__fini(message_memory);
}

size_t xr_msgs__msg__Head__rosidl_typesupport_introspection_c__size_function__Head__pose(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * xr_msgs__msg__Head__rosidl_typesupport_introspection_c__get_const_function__Head__pose(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * xr_msgs__msg__Head__rosidl_typesupport_introspection_c__get_function__Head__pose(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void xr_msgs__msg__Head__rosidl_typesupport_introspection_c__fetch_function__Head__pose(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    xr_msgs__msg__Head__rosidl_typesupport_introspection_c__get_const_function__Head__pose(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void xr_msgs__msg__Head__rosidl_typesupport_introspection_c__assign_function__Head__pose(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    xr_msgs__msg__Head__rosidl_typesupport_introspection_c__get_function__Head__pose(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_message_member_array[2] = {
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(xr_msgs__msg__Head, pose),  // bytes offset in struct
    NULL,  // default value
    xr_msgs__msg__Head__rosidl_typesupport_introspection_c__size_function__Head__pose,  // size() function pointer
    xr_msgs__msg__Head__rosidl_typesupport_introspection_c__get_const_function__Head__pose,  // get_const(index) function pointer
    xr_msgs__msg__Head__rosidl_typesupport_introspection_c__get_function__Head__pose,  // get(index) function pointer
    xr_msgs__msg__Head__rosidl_typesupport_introspection_c__fetch_function__Head__pose,  // fetch(index, &value) function pointer
    xr_msgs__msg__Head__rosidl_typesupport_introspection_c__assign_function__Head__pose,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xr_msgs__msg__Head, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_message_members = {
  "xr_msgs__msg",  // message namespace
  "Head",  // message name
  2,  // number of fields
  sizeof(xr_msgs__msg__Head),
  xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_message_member_array,  // message members
  xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_init_function,  // function to initialize message memory (memory has to be allocated)
  xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_message_type_support_handle = {
  0,
  &xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xr_msgs, msg, Head)() {
  if (!xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_message_type_support_handle.typesupport_identifier) {
    xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &xr_msgs__msg__Head__rosidl_typesupport_introspection_c__Head_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

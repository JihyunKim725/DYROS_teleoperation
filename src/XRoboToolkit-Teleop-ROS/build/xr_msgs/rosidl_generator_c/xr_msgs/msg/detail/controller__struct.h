// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xr_msgs:msg/Controller.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__CONTROLLER__STRUCT_H_
#define XR_MSGS__MSG__DETAIL__CONTROLLER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Controller in the package xr_msgs.
typedef struct xr_msgs__msg__Controller
{
  float axis_x;
  float axis_y;
  bool axis_click;
  float gripper;
  float trigger;
  bool primary_button;
  bool secondary_button;
  bool menu_button;
  float pose[7];
  int32_t status;
} xr_msgs__msg__Controller;

// Struct for a sequence of xr_msgs__msg__Controller.
typedef struct xr_msgs__msg__Controller__Sequence
{
  xr_msgs__msg__Controller * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xr_msgs__msg__Controller__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XR_MSGS__MSG__DETAIL__CONTROLLER__STRUCT_H_

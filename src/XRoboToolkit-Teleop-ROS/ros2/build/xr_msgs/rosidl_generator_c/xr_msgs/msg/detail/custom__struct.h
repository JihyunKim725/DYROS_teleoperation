// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xr_msgs:msg/Custom.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__CUSTOM__STRUCT_H_
#define XR_MSGS__MSG__DETAIL__CUSTOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'head'
#include "xr_msgs/msg/detail/head__struct.h"
// Member 'left_controller'
// Member 'right_controller'
#include "xr_msgs/msg/detail/controller__struct.h"

/// Struct defined in msg/Custom in the package xr_msgs.
typedef struct xr_msgs__msg__Custom
{
  int64_t timestamp_ns;
  int32_t input;
  xr_msgs__msg__Head head;
  xr_msgs__msg__Controller left_controller;
  xr_msgs__msg__Controller right_controller;
} xr_msgs__msg__Custom;

// Struct for a sequence of xr_msgs__msg__Custom.
typedef struct xr_msgs__msg__Custom__Sequence
{
  xr_msgs__msg__Custom * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xr_msgs__msg__Custom__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XR_MSGS__MSG__DETAIL__CUSTOM__STRUCT_H_

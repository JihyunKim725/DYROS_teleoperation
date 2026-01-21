// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xr_msgs:msg/Controller.idl
// generated code does not contain a copyright notice
#include "xr_msgs/msg/detail/controller__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xr_msgs/msg/detail/controller__struct.h"
#include "xr_msgs/msg/detail/controller__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Controller__ros_msg_type = xr_msgs__msg__Controller;

static bool _Controller__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Controller__ros_msg_type * ros_message = static_cast<const _Controller__ros_msg_type *>(untyped_ros_message);
  // Field name: axis_x
  {
    cdr << ros_message->axis_x;
  }

  // Field name: axis_y
  {
    cdr << ros_message->axis_y;
  }

  // Field name: axis_click
  {
    cdr << (ros_message->axis_click ? true : false);
  }

  // Field name: gripper
  {
    cdr << ros_message->gripper;
  }

  // Field name: trigger
  {
    cdr << ros_message->trigger;
  }

  // Field name: primary_button
  {
    cdr << (ros_message->primary_button ? true : false);
  }

  // Field name: secondary_button
  {
    cdr << (ros_message->secondary_button ? true : false);
  }

  // Field name: menu_button
  {
    cdr << (ros_message->menu_button ? true : false);
  }

  // Field name: pose
  {
    size_t size = 7;
    auto array_ptr = ros_message->pose;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: status
  {
    cdr << ros_message->status;
  }

  return true;
}

static bool _Controller__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Controller__ros_msg_type * ros_message = static_cast<_Controller__ros_msg_type *>(untyped_ros_message);
  // Field name: axis_x
  {
    cdr >> ros_message->axis_x;
  }

  // Field name: axis_y
  {
    cdr >> ros_message->axis_y;
  }

  // Field name: axis_click
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->axis_click = tmp ? true : false;
  }

  // Field name: gripper
  {
    cdr >> ros_message->gripper;
  }

  // Field name: trigger
  {
    cdr >> ros_message->trigger;
  }

  // Field name: primary_button
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->primary_button = tmp ? true : false;
  }

  // Field name: secondary_button
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->secondary_button = tmp ? true : false;
  }

  // Field name: menu_button
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->menu_button = tmp ? true : false;
  }

  // Field name: pose
  {
    size_t size = 7;
    auto array_ptr = ros_message->pose;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: status
  {
    cdr >> ros_message->status;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xr_msgs
size_t get_serialized_size_xr_msgs__msg__Controller(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Controller__ros_msg_type * ros_message = static_cast<const _Controller__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name axis_x
  {
    size_t item_size = sizeof(ros_message->axis_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name axis_y
  {
    size_t item_size = sizeof(ros_message->axis_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name axis_click
  {
    size_t item_size = sizeof(ros_message->axis_click);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gripper
  {
    size_t item_size = sizeof(ros_message->gripper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name trigger
  {
    size_t item_size = sizeof(ros_message->trigger);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name primary_button
  {
    size_t item_size = sizeof(ros_message->primary_button);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name secondary_button
  {
    size_t item_size = sizeof(ros_message->secondary_button);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name menu_button
  {
    size_t item_size = sizeof(ros_message->menu_button);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pose
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->pose;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name status
  {
    size_t item_size = sizeof(ros_message->status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Controller__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xr_msgs__msg__Controller(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xr_msgs
size_t max_serialized_size_xr_msgs__msg__Controller(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: axis_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: axis_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: axis_click
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: gripper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: trigger
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: primary_button
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: secondary_button
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: menu_button
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: pose
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = xr_msgs__msg__Controller;
    is_plain =
      (
      offsetof(DataType, status) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Controller__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_xr_msgs__msg__Controller(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Controller = {
  "xr_msgs::msg",
  "Controller",
  _Controller__cdr_serialize,
  _Controller__cdr_deserialize,
  _Controller__get_serialized_size,
  _Controller__max_serialized_size
};

static rosidl_message_type_support_t _Controller__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Controller,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xr_msgs, msg, Controller)() {
  return &_Controller__type_support;
}

#if defined(__cplusplus)
}
#endif

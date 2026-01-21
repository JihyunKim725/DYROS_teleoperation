// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xr_msgs:msg/Custom.idl
// generated code does not contain a copyright notice
#include "xr_msgs/msg/detail/custom__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xr_msgs/msg/detail/custom__struct.h"
#include "xr_msgs/msg/detail/custom__functions.h"
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

#include "xr_msgs/msg/detail/controller__functions.h"  // left_controller, right_controller
#include "xr_msgs/msg/detail/head__functions.h"  // head

// forward declare type support functions
size_t get_serialized_size_xr_msgs__msg__Controller(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_xr_msgs__msg__Controller(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xr_msgs, msg, Controller)();
size_t get_serialized_size_xr_msgs__msg__Head(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_xr_msgs__msg__Head(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xr_msgs, msg, Head)();


using _Custom__ros_msg_type = xr_msgs__msg__Custom;

static bool _Custom__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Custom__ros_msg_type * ros_message = static_cast<const _Custom__ros_msg_type *>(untyped_ros_message);
  // Field name: timestamp_ns
  {
    cdr << ros_message->timestamp_ns;
  }

  // Field name: input
  {
    cdr << ros_message->input;
  }

  // Field name: head
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, xr_msgs, msg, Head
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->head, cdr))
    {
      return false;
    }
  }

  // Field name: left_controller
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, xr_msgs, msg, Controller
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->left_controller, cdr))
    {
      return false;
    }
  }

  // Field name: right_controller
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, xr_msgs, msg, Controller
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->right_controller, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Custom__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Custom__ros_msg_type * ros_message = static_cast<_Custom__ros_msg_type *>(untyped_ros_message);
  // Field name: timestamp_ns
  {
    cdr >> ros_message->timestamp_ns;
  }

  // Field name: input
  {
    cdr >> ros_message->input;
  }

  // Field name: head
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, xr_msgs, msg, Head
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->head))
    {
      return false;
    }
  }

  // Field name: left_controller
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, xr_msgs, msg, Controller
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->left_controller))
    {
      return false;
    }
  }

  // Field name: right_controller
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, xr_msgs, msg, Controller
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->right_controller))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xr_msgs
size_t get_serialized_size_xr_msgs__msg__Custom(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Custom__ros_msg_type * ros_message = static_cast<const _Custom__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name timestamp_ns
  {
    size_t item_size = sizeof(ros_message->timestamp_ns);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name input
  {
    size_t item_size = sizeof(ros_message->input);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name head

  current_alignment += get_serialized_size_xr_msgs__msg__Head(
    &(ros_message->head), current_alignment);
  // field.name left_controller

  current_alignment += get_serialized_size_xr_msgs__msg__Controller(
    &(ros_message->left_controller), current_alignment);
  // field.name right_controller

  current_alignment += get_serialized_size_xr_msgs__msg__Controller(
    &(ros_message->right_controller), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Custom__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xr_msgs__msg__Custom(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xr_msgs
size_t max_serialized_size_xr_msgs__msg__Custom(
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

  // member: timestamp_ns
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: input
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: head
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_xr_msgs__msg__Head(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: left_controller
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_xr_msgs__msg__Controller(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: right_controller
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_xr_msgs__msg__Controller(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = xr_msgs__msg__Custom;
    is_plain =
      (
      offsetof(DataType, right_controller) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Custom__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_xr_msgs__msg__Custom(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Custom = {
  "xr_msgs::msg",
  "Custom",
  _Custom__cdr_serialize,
  _Custom__cdr_deserialize,
  _Custom__get_serialized_size,
  _Custom__max_serialized_size
};

static rosidl_message_type_support_t _Custom__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Custom,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xr_msgs, msg, Custom)() {
  return &_Custom__type_support;
}

#if defined(__cplusplus)
}
#endif

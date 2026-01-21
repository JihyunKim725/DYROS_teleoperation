// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xr_msgs:msg/Custom.idl
// generated code does not contain a copyright notice
#include "xr_msgs/msg/detail/custom__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xr_msgs/msg/detail/custom__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace xr_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const xr_msgs::msg::Head &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  xr_msgs::msg::Head &);
size_t get_serialized_size(
  const xr_msgs::msg::Head &,
  size_t current_alignment);
size_t
max_serialized_size_Head(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace xr_msgs

namespace xr_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const xr_msgs::msg::Controller &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  xr_msgs::msg::Controller &);
size_t get_serialized_size(
  const xr_msgs::msg::Controller &,
  size_t current_alignment);
size_t
max_serialized_size_Controller(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace xr_msgs

// functions for xr_msgs::msg::Controller already declared above


namespace xr_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xr_msgs
cdr_serialize(
  const xr_msgs::msg::Custom & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: timestamp_ns
  cdr << ros_message.timestamp_ns;
  // Member: input
  cdr << ros_message.input;
  // Member: head
  xr_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.head,
    cdr);
  // Member: left_controller
  xr_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.left_controller,
    cdr);
  // Member: right_controller
  xr_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.right_controller,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xr_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xr_msgs::msg::Custom & ros_message)
{
  // Member: timestamp_ns
  cdr >> ros_message.timestamp_ns;

  // Member: input
  cdr >> ros_message.input;

  // Member: head
  xr_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.head);

  // Member: left_controller
  xr_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.left_controller);

  // Member: right_controller
  xr_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.right_controller);

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xr_msgs
get_serialized_size(
  const xr_msgs::msg::Custom & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: timestamp_ns
  {
    size_t item_size = sizeof(ros_message.timestamp_ns);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: input
  {
    size_t item_size = sizeof(ros_message.input);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: head

  current_alignment +=
    xr_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.head, current_alignment);
  // Member: left_controller

  current_alignment +=
    xr_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.left_controller, current_alignment);
  // Member: right_controller

  current_alignment +=
    xr_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.right_controller, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xr_msgs
max_serialized_size_Custom(
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


  // Member: timestamp_ns
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: input
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: head
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        xr_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Head(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: left_controller
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        xr_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Controller(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: right_controller
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        xr_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Controller(
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
    using DataType = xr_msgs::msg::Custom;
    is_plain =
      (
      offsetof(DataType, right_controller) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Custom__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xr_msgs::msg::Custom *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Custom__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xr_msgs::msg::Custom *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Custom__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xr_msgs::msg::Custom *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Custom__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Custom(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Custom__callbacks = {
  "xr_msgs::msg",
  "Custom",
  _Custom__cdr_serialize,
  _Custom__cdr_deserialize,
  _Custom__get_serialized_size,
  _Custom__max_serialized_size
};

static rosidl_message_type_support_t _Custom__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Custom__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xr_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_xr_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<xr_msgs::msg::Custom>()
{
  return &xr_msgs::msg::typesupport_fastrtps_cpp::_Custom__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xr_msgs, msg, Custom)() {
  return &xr_msgs::msg::typesupport_fastrtps_cpp::_Custom__handle;
}

#ifdef __cplusplus
}
#endif

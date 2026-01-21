// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from xr_msgs:msg/Head.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__HEAD__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define XR_MSGS__MSG__DETAIL__HEAD__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "xr_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "xr_msgs/msg/detail/head__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace xr_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xr_msgs
cdr_serialize(
  const xr_msgs::msg::Head & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xr_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xr_msgs::msg::Head & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xr_msgs
get_serialized_size(
  const xr_msgs::msg::Head & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xr_msgs
max_serialized_size_Head(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xr_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xr_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xr_msgs, msg, Head)();

#ifdef __cplusplus
}
#endif

#endif  // XR_MSGS__MSG__DETAIL__HEAD__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

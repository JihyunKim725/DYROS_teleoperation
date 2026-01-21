// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xr_msgs:msg/Custom.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__CUSTOM__TRAITS_HPP_
#define XR_MSGS__MSG__DETAIL__CUSTOM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xr_msgs/msg/detail/custom__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'head'
#include "xr_msgs/msg/detail/head__traits.hpp"
// Member 'left_controller'
// Member 'right_controller'
#include "xr_msgs/msg/detail/controller__traits.hpp"

namespace xr_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Custom & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp_ns
  {
    out << "timestamp_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp_ns, out);
    out << ", ";
  }

  // member: input
  {
    out << "input: ";
    rosidl_generator_traits::value_to_yaml(msg.input, out);
    out << ", ";
  }

  // member: head
  {
    out << "head: ";
    to_flow_style_yaml(msg.head, out);
    out << ", ";
  }

  // member: left_controller
  {
    out << "left_controller: ";
    to_flow_style_yaml(msg.left_controller, out);
    out << ", ";
  }

  // member: right_controller
  {
    out << "right_controller: ";
    to_flow_style_yaml(msg.right_controller, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Custom & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: timestamp_ns
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp_ns, out);
    out << "\n";
  }

  // member: input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input: ";
    rosidl_generator_traits::value_to_yaml(msg.input, out);
    out << "\n";
  }

  // member: head
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "head:\n";
    to_block_style_yaml(msg.head, out, indentation + 2);
  }

  // member: left_controller
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_controller:\n";
    to_block_style_yaml(msg.left_controller, out, indentation + 2);
  }

  // member: right_controller
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_controller:\n";
    to_block_style_yaml(msg.right_controller, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Custom & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace xr_msgs

namespace rosidl_generator_traits
{

[[deprecated("use xr_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const xr_msgs::msg::Custom & msg,
  std::ostream & out, size_t indentation = 0)
{
  xr_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xr_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const xr_msgs::msg::Custom & msg)
{
  return xr_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<xr_msgs::msg::Custom>()
{
  return "xr_msgs::msg::Custom";
}

template<>
inline const char * name<xr_msgs::msg::Custom>()
{
  return "xr_msgs/msg/Custom";
}

template<>
struct has_fixed_size<xr_msgs::msg::Custom>
  : std::integral_constant<bool, has_fixed_size<xr_msgs::msg::Controller>::value && has_fixed_size<xr_msgs::msg::Head>::value> {};

template<>
struct has_bounded_size<xr_msgs::msg::Custom>
  : std::integral_constant<bool, has_bounded_size<xr_msgs::msg::Controller>::value && has_bounded_size<xr_msgs::msg::Head>::value> {};

template<>
struct is_message<xr_msgs::msg::Custom>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XR_MSGS__MSG__DETAIL__CUSTOM__TRAITS_HPP_

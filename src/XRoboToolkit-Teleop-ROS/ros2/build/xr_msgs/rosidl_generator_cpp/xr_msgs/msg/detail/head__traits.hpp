// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xr_msgs:msg/Head.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__HEAD__TRAITS_HPP_
#define XR_MSGS__MSG__DETAIL__HEAD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xr_msgs/msg/detail/head__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace xr_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Head & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose
  {
    if (msg.pose.size() == 0) {
      out << "pose: []";
    } else {
      out << "pose: [";
      size_t pending_items = msg.pose.size();
      for (auto item : msg.pose) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Head & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pose.size() == 0) {
      out << "pose: []\n";
    } else {
      out << "pose:\n";
      for (auto item : msg.pose) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Head & msg, bool use_flow_style = false)
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
  const xr_msgs::msg::Head & msg,
  std::ostream & out, size_t indentation = 0)
{
  xr_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xr_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const xr_msgs::msg::Head & msg)
{
  return xr_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<xr_msgs::msg::Head>()
{
  return "xr_msgs::msg::Head";
}

template<>
inline const char * name<xr_msgs::msg::Head>()
{
  return "xr_msgs/msg/Head";
}

template<>
struct has_fixed_size<xr_msgs::msg::Head>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xr_msgs::msg::Head>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xr_msgs::msg::Head>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XR_MSGS__MSG__DETAIL__HEAD__TRAITS_HPP_

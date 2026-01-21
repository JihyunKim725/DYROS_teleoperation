// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xr_msgs:msg/Controller.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__CONTROLLER__TRAITS_HPP_
#define XR_MSGS__MSG__DETAIL__CONTROLLER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xr_msgs/msg/detail/controller__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace xr_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Controller & msg,
  std::ostream & out)
{
  out << "{";
  // member: axis_x
  {
    out << "axis_x: ";
    rosidl_generator_traits::value_to_yaml(msg.axis_x, out);
    out << ", ";
  }

  // member: axis_y
  {
    out << "axis_y: ";
    rosidl_generator_traits::value_to_yaml(msg.axis_y, out);
    out << ", ";
  }

  // member: axis_click
  {
    out << "axis_click: ";
    rosidl_generator_traits::value_to_yaml(msg.axis_click, out);
    out << ", ";
  }

  // member: gripper
  {
    out << "gripper: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper, out);
    out << ", ";
  }

  // member: trigger
  {
    out << "trigger: ";
    rosidl_generator_traits::value_to_yaml(msg.trigger, out);
    out << ", ";
  }

  // member: primary_button
  {
    out << "primary_button: ";
    rosidl_generator_traits::value_to_yaml(msg.primary_button, out);
    out << ", ";
  }

  // member: secondary_button
  {
    out << "secondary_button: ";
    rosidl_generator_traits::value_to_yaml(msg.secondary_button, out);
    out << ", ";
  }

  // member: menu_button
  {
    out << "menu_button: ";
    rosidl_generator_traits::value_to_yaml(msg.menu_button, out);
    out << ", ";
  }

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
  const Controller & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: axis_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "axis_x: ";
    rosidl_generator_traits::value_to_yaml(msg.axis_x, out);
    out << "\n";
  }

  // member: axis_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "axis_y: ";
    rosidl_generator_traits::value_to_yaml(msg.axis_y, out);
    out << "\n";
  }

  // member: axis_click
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "axis_click: ";
    rosidl_generator_traits::value_to_yaml(msg.axis_click, out);
    out << "\n";
  }

  // member: gripper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper, out);
    out << "\n";
  }

  // member: trigger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trigger: ";
    rosidl_generator_traits::value_to_yaml(msg.trigger, out);
    out << "\n";
  }

  // member: primary_button
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "primary_button: ";
    rosidl_generator_traits::value_to_yaml(msg.primary_button, out);
    out << "\n";
  }

  // member: secondary_button
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "secondary_button: ";
    rosidl_generator_traits::value_to_yaml(msg.secondary_button, out);
    out << "\n";
  }

  // member: menu_button
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "menu_button: ";
    rosidl_generator_traits::value_to_yaml(msg.menu_button, out);
    out << "\n";
  }

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

inline std::string to_yaml(const Controller & msg, bool use_flow_style = false)
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
  const xr_msgs::msg::Controller & msg,
  std::ostream & out, size_t indentation = 0)
{
  xr_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xr_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const xr_msgs::msg::Controller & msg)
{
  return xr_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<xr_msgs::msg::Controller>()
{
  return "xr_msgs::msg::Controller";
}

template<>
inline const char * name<xr_msgs::msg::Controller>()
{
  return "xr_msgs/msg/Controller";
}

template<>
struct has_fixed_size<xr_msgs::msg::Controller>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xr_msgs::msg::Controller>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xr_msgs::msg::Controller>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XR_MSGS__MSG__DETAIL__CONTROLLER__TRAITS_HPP_

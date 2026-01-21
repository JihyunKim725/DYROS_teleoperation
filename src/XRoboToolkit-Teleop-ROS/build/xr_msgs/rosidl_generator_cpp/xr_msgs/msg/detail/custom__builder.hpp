// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xr_msgs:msg/Custom.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__CUSTOM__BUILDER_HPP_
#define XR_MSGS__MSG__DETAIL__CUSTOM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xr_msgs/msg/detail/custom__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xr_msgs
{

namespace msg
{

namespace builder
{

class Init_Custom_right_controller
{
public:
  explicit Init_Custom_right_controller(::xr_msgs::msg::Custom & msg)
  : msg_(msg)
  {}
  ::xr_msgs::msg::Custom right_controller(::xr_msgs::msg::Custom::_right_controller_type arg)
  {
    msg_.right_controller = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xr_msgs::msg::Custom msg_;
};

class Init_Custom_left_controller
{
public:
  explicit Init_Custom_left_controller(::xr_msgs::msg::Custom & msg)
  : msg_(msg)
  {}
  Init_Custom_right_controller left_controller(::xr_msgs::msg::Custom::_left_controller_type arg)
  {
    msg_.left_controller = std::move(arg);
    return Init_Custom_right_controller(msg_);
  }

private:
  ::xr_msgs::msg::Custom msg_;
};

class Init_Custom_head
{
public:
  explicit Init_Custom_head(::xr_msgs::msg::Custom & msg)
  : msg_(msg)
  {}
  Init_Custom_left_controller head(::xr_msgs::msg::Custom::_head_type arg)
  {
    msg_.head = std::move(arg);
    return Init_Custom_left_controller(msg_);
  }

private:
  ::xr_msgs::msg::Custom msg_;
};

class Init_Custom_input
{
public:
  explicit Init_Custom_input(::xr_msgs::msg::Custom & msg)
  : msg_(msg)
  {}
  Init_Custom_head input(::xr_msgs::msg::Custom::_input_type arg)
  {
    msg_.input = std::move(arg);
    return Init_Custom_head(msg_);
  }

private:
  ::xr_msgs::msg::Custom msg_;
};

class Init_Custom_timestamp_ns
{
public:
  Init_Custom_timestamp_ns()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Custom_input timestamp_ns(::xr_msgs::msg::Custom::_timestamp_ns_type arg)
  {
    msg_.timestamp_ns = std::move(arg);
    return Init_Custom_input(msg_);
  }

private:
  ::xr_msgs::msg::Custom msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xr_msgs::msg::Custom>()
{
  return xr_msgs::msg::builder::Init_Custom_timestamp_ns();
}

}  // namespace xr_msgs

#endif  // XR_MSGS__MSG__DETAIL__CUSTOM__BUILDER_HPP_

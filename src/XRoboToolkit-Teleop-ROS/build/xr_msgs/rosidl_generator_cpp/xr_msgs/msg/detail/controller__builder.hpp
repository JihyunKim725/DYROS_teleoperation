// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xr_msgs:msg/Controller.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__CONTROLLER__BUILDER_HPP_
#define XR_MSGS__MSG__DETAIL__CONTROLLER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xr_msgs/msg/detail/controller__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xr_msgs
{

namespace msg
{

namespace builder
{

class Init_Controller_status
{
public:
  explicit Init_Controller_status(::xr_msgs::msg::Controller & msg)
  : msg_(msg)
  {}
  ::xr_msgs::msg::Controller status(::xr_msgs::msg::Controller::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xr_msgs::msg::Controller msg_;
};

class Init_Controller_pose
{
public:
  explicit Init_Controller_pose(::xr_msgs::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_status pose(::xr_msgs::msg::Controller::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Controller_status(msg_);
  }

private:
  ::xr_msgs::msg::Controller msg_;
};

class Init_Controller_menu_button
{
public:
  explicit Init_Controller_menu_button(::xr_msgs::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_pose menu_button(::xr_msgs::msg::Controller::_menu_button_type arg)
  {
    msg_.menu_button = std::move(arg);
    return Init_Controller_pose(msg_);
  }

private:
  ::xr_msgs::msg::Controller msg_;
};

class Init_Controller_secondary_button
{
public:
  explicit Init_Controller_secondary_button(::xr_msgs::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_menu_button secondary_button(::xr_msgs::msg::Controller::_secondary_button_type arg)
  {
    msg_.secondary_button = std::move(arg);
    return Init_Controller_menu_button(msg_);
  }

private:
  ::xr_msgs::msg::Controller msg_;
};

class Init_Controller_primary_button
{
public:
  explicit Init_Controller_primary_button(::xr_msgs::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_secondary_button primary_button(::xr_msgs::msg::Controller::_primary_button_type arg)
  {
    msg_.primary_button = std::move(arg);
    return Init_Controller_secondary_button(msg_);
  }

private:
  ::xr_msgs::msg::Controller msg_;
};

class Init_Controller_trigger
{
public:
  explicit Init_Controller_trigger(::xr_msgs::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_primary_button trigger(::xr_msgs::msg::Controller::_trigger_type arg)
  {
    msg_.trigger = std::move(arg);
    return Init_Controller_primary_button(msg_);
  }

private:
  ::xr_msgs::msg::Controller msg_;
};

class Init_Controller_gripper
{
public:
  explicit Init_Controller_gripper(::xr_msgs::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_trigger gripper(::xr_msgs::msg::Controller::_gripper_type arg)
  {
    msg_.gripper = std::move(arg);
    return Init_Controller_trigger(msg_);
  }

private:
  ::xr_msgs::msg::Controller msg_;
};

class Init_Controller_axis_click
{
public:
  explicit Init_Controller_axis_click(::xr_msgs::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_gripper axis_click(::xr_msgs::msg::Controller::_axis_click_type arg)
  {
    msg_.axis_click = std::move(arg);
    return Init_Controller_gripper(msg_);
  }

private:
  ::xr_msgs::msg::Controller msg_;
};

class Init_Controller_axis_y
{
public:
  explicit Init_Controller_axis_y(::xr_msgs::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_axis_click axis_y(::xr_msgs::msg::Controller::_axis_y_type arg)
  {
    msg_.axis_y = std::move(arg);
    return Init_Controller_axis_click(msg_);
  }

private:
  ::xr_msgs::msg::Controller msg_;
};

class Init_Controller_axis_x
{
public:
  Init_Controller_axis_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Controller_axis_y axis_x(::xr_msgs::msg::Controller::_axis_x_type arg)
  {
    msg_.axis_x = std::move(arg);
    return Init_Controller_axis_y(msg_);
  }

private:
  ::xr_msgs::msg::Controller msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xr_msgs::msg::Controller>()
{
  return xr_msgs::msg::builder::Init_Controller_axis_x();
}

}  // namespace xr_msgs

#endif  // XR_MSGS__MSG__DETAIL__CONTROLLER__BUILDER_HPP_

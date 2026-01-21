// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xr_msgs:msg/Head.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__HEAD__BUILDER_HPP_
#define XR_MSGS__MSG__DETAIL__HEAD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xr_msgs/msg/detail/head__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xr_msgs
{

namespace msg
{

namespace builder
{

class Init_Head_status
{
public:
  explicit Init_Head_status(::xr_msgs::msg::Head & msg)
  : msg_(msg)
  {}
  ::xr_msgs::msg::Head status(::xr_msgs::msg::Head::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xr_msgs::msg::Head msg_;
};

class Init_Head_pose
{
public:
  Init_Head_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Head_status pose(::xr_msgs::msg::Head::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Head_status(msg_);
  }

private:
  ::xr_msgs::msg::Head msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xr_msgs::msg::Head>()
{
  return xr_msgs::msg::builder::Init_Head_pose();
}

}  // namespace xr_msgs

#endif  // XR_MSGS__MSG__DETAIL__HEAD__BUILDER_HPP_

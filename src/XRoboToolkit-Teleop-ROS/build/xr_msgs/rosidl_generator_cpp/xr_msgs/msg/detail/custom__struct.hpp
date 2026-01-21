// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xr_msgs:msg/Custom.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__CUSTOM__STRUCT_HPP_
#define XR_MSGS__MSG__DETAIL__CUSTOM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'head'
#include "xr_msgs/msg/detail/head__struct.hpp"
// Member 'left_controller'
// Member 'right_controller'
#include "xr_msgs/msg/detail/controller__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__xr_msgs__msg__Custom __attribute__((deprecated))
#else
# define DEPRECATED__xr_msgs__msg__Custom __declspec(deprecated)
#endif

namespace xr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Custom_
{
  using Type = Custom_<ContainerAllocator>;

  explicit Custom_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : head(_init),
    left_controller(_init),
    right_controller(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp_ns = 0ll;
      this->input = 0l;
    }
  }

  explicit Custom_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : head(_alloc, _init),
    left_controller(_alloc, _init),
    right_controller(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp_ns = 0ll;
      this->input = 0l;
    }
  }

  // field types and members
  using _timestamp_ns_type =
    int64_t;
  _timestamp_ns_type timestamp_ns;
  using _input_type =
    int32_t;
  _input_type input;
  using _head_type =
    xr_msgs::msg::Head_<ContainerAllocator>;
  _head_type head;
  using _left_controller_type =
    xr_msgs::msg::Controller_<ContainerAllocator>;
  _left_controller_type left_controller;
  using _right_controller_type =
    xr_msgs::msg::Controller_<ContainerAllocator>;
  _right_controller_type right_controller;

  // setters for named parameter idiom
  Type & set__timestamp_ns(
    const int64_t & _arg)
  {
    this->timestamp_ns = _arg;
    return *this;
  }
  Type & set__input(
    const int32_t & _arg)
  {
    this->input = _arg;
    return *this;
  }
  Type & set__head(
    const xr_msgs::msg::Head_<ContainerAllocator> & _arg)
  {
    this->head = _arg;
    return *this;
  }
  Type & set__left_controller(
    const xr_msgs::msg::Controller_<ContainerAllocator> & _arg)
  {
    this->left_controller = _arg;
    return *this;
  }
  Type & set__right_controller(
    const xr_msgs::msg::Controller_<ContainerAllocator> & _arg)
  {
    this->right_controller = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xr_msgs::msg::Custom_<ContainerAllocator> *;
  using ConstRawPtr =
    const xr_msgs::msg::Custom_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xr_msgs::msg::Custom_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xr_msgs::msg::Custom_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xr_msgs::msg::Custom_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xr_msgs::msg::Custom_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xr_msgs::msg::Custom_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xr_msgs::msg::Custom_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xr_msgs::msg::Custom_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xr_msgs::msg::Custom_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xr_msgs__msg__Custom
    std::shared_ptr<xr_msgs::msg::Custom_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xr_msgs__msg__Custom
    std::shared_ptr<xr_msgs::msg::Custom_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Custom_ & other) const
  {
    if (this->timestamp_ns != other.timestamp_ns) {
      return false;
    }
    if (this->input != other.input) {
      return false;
    }
    if (this->head != other.head) {
      return false;
    }
    if (this->left_controller != other.left_controller) {
      return false;
    }
    if (this->right_controller != other.right_controller) {
      return false;
    }
    return true;
  }
  bool operator!=(const Custom_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Custom_

// alias to use template instance with default allocator
using Custom =
  xr_msgs::msg::Custom_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xr_msgs

#endif  // XR_MSGS__MSG__DETAIL__CUSTOM__STRUCT_HPP_

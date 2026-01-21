// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xr_msgs:msg/Controller.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__CONTROLLER__STRUCT_HPP_
#define XR_MSGS__MSG__DETAIL__CONTROLLER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__xr_msgs__msg__Controller __attribute__((deprecated))
#else
# define DEPRECATED__xr_msgs__msg__Controller __declspec(deprecated)
#endif

namespace xr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Controller_
{
  using Type = Controller_<ContainerAllocator>;

  explicit Controller_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->axis_x = 0.0f;
      this->axis_y = 0.0f;
      this->axis_click = false;
      this->gripper = 0.0f;
      this->trigger = 0.0f;
      this->primary_button = false;
      this->secondary_button = false;
      this->menu_button = false;
      std::fill<typename std::array<float, 7>::iterator, float>(this->pose.begin(), this->pose.end(), 0.0f);
      this->status = 0l;
    }
  }

  explicit Controller_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->axis_x = 0.0f;
      this->axis_y = 0.0f;
      this->axis_click = false;
      this->gripper = 0.0f;
      this->trigger = 0.0f;
      this->primary_button = false;
      this->secondary_button = false;
      this->menu_button = false;
      std::fill<typename std::array<float, 7>::iterator, float>(this->pose.begin(), this->pose.end(), 0.0f);
      this->status = 0l;
    }
  }

  // field types and members
  using _axis_x_type =
    float;
  _axis_x_type axis_x;
  using _axis_y_type =
    float;
  _axis_y_type axis_y;
  using _axis_click_type =
    bool;
  _axis_click_type axis_click;
  using _gripper_type =
    float;
  _gripper_type gripper;
  using _trigger_type =
    float;
  _trigger_type trigger;
  using _primary_button_type =
    bool;
  _primary_button_type primary_button;
  using _secondary_button_type =
    bool;
  _secondary_button_type secondary_button;
  using _menu_button_type =
    bool;
  _menu_button_type menu_button;
  using _pose_type =
    std::array<float, 7>;
  _pose_type pose;
  using _status_type =
    int32_t;
  _status_type status;

  // setters for named parameter idiom
  Type & set__axis_x(
    const float & _arg)
  {
    this->axis_x = _arg;
    return *this;
  }
  Type & set__axis_y(
    const float & _arg)
  {
    this->axis_y = _arg;
    return *this;
  }
  Type & set__axis_click(
    const bool & _arg)
  {
    this->axis_click = _arg;
    return *this;
  }
  Type & set__gripper(
    const float & _arg)
  {
    this->gripper = _arg;
    return *this;
  }
  Type & set__trigger(
    const float & _arg)
  {
    this->trigger = _arg;
    return *this;
  }
  Type & set__primary_button(
    const bool & _arg)
  {
    this->primary_button = _arg;
    return *this;
  }
  Type & set__secondary_button(
    const bool & _arg)
  {
    this->secondary_button = _arg;
    return *this;
  }
  Type & set__menu_button(
    const bool & _arg)
  {
    this->menu_button = _arg;
    return *this;
  }
  Type & set__pose(
    const std::array<float, 7> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__status(
    const int32_t & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xr_msgs::msg::Controller_<ContainerAllocator> *;
  using ConstRawPtr =
    const xr_msgs::msg::Controller_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xr_msgs::msg::Controller_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xr_msgs::msg::Controller_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xr_msgs::msg::Controller_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xr_msgs::msg::Controller_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xr_msgs::msg::Controller_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xr_msgs::msg::Controller_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xr_msgs::msg::Controller_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xr_msgs::msg::Controller_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xr_msgs__msg__Controller
    std::shared_ptr<xr_msgs::msg::Controller_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xr_msgs__msg__Controller
    std::shared_ptr<xr_msgs::msg::Controller_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Controller_ & other) const
  {
    if (this->axis_x != other.axis_x) {
      return false;
    }
    if (this->axis_y != other.axis_y) {
      return false;
    }
    if (this->axis_click != other.axis_click) {
      return false;
    }
    if (this->gripper != other.gripper) {
      return false;
    }
    if (this->trigger != other.trigger) {
      return false;
    }
    if (this->primary_button != other.primary_button) {
      return false;
    }
    if (this->secondary_button != other.secondary_button) {
      return false;
    }
    if (this->menu_button != other.menu_button) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Controller_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Controller_

// alias to use template instance with default allocator
using Controller =
  xr_msgs::msg::Controller_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xr_msgs

#endif  // XR_MSGS__MSG__DETAIL__CONTROLLER__STRUCT_HPP_

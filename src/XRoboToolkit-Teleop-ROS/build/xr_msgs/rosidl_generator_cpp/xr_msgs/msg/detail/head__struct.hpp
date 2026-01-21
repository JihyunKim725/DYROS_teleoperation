// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xr_msgs:msg/Head.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__HEAD__STRUCT_HPP_
#define XR_MSGS__MSG__DETAIL__HEAD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__xr_msgs__msg__Head __attribute__((deprecated))
#else
# define DEPRECATED__xr_msgs__msg__Head __declspec(deprecated)
#endif

namespace xr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Head_
{
  using Type = Head_<ContainerAllocator>;

  explicit Head_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 7>::iterator, float>(this->pose.begin(), this->pose.end(), 0.0f);
      this->status = 0l;
    }
  }

  explicit Head_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 7>::iterator, float>(this->pose.begin(), this->pose.end(), 0.0f);
      this->status = 0l;
    }
  }

  // field types and members
  using _pose_type =
    std::array<float, 7>;
  _pose_type pose;
  using _status_type =
    int32_t;
  _status_type status;

  // setters for named parameter idiom
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
    xr_msgs::msg::Head_<ContainerAllocator> *;
  using ConstRawPtr =
    const xr_msgs::msg::Head_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xr_msgs::msg::Head_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xr_msgs::msg::Head_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xr_msgs::msg::Head_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xr_msgs::msg::Head_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xr_msgs::msg::Head_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xr_msgs::msg::Head_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xr_msgs::msg::Head_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xr_msgs::msg::Head_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xr_msgs__msg__Head
    std::shared_ptr<xr_msgs::msg::Head_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xr_msgs__msg__Head
    std::shared_ptr<xr_msgs::msg::Head_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Head_ & other) const
  {
    if (this->pose != other.pose) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Head_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Head_

// alias to use template instance with default allocator
using Head =
  xr_msgs::msg::Head_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xr_msgs

#endif  // XR_MSGS__MSG__DETAIL__HEAD__STRUCT_HPP_

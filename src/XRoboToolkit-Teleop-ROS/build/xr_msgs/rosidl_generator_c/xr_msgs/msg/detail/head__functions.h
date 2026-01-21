// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from xr_msgs:msg/Head.idl
// generated code does not contain a copyright notice

#ifndef XR_MSGS__MSG__DETAIL__HEAD__FUNCTIONS_H_
#define XR_MSGS__MSG__DETAIL__HEAD__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "xr_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "xr_msgs/msg/detail/head__struct.h"

/// Initialize msg/Head message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * xr_msgs__msg__Head
 * )) before or use
 * xr_msgs__msg__Head__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
bool
xr_msgs__msg__Head__init(xr_msgs__msg__Head * msg);

/// Finalize msg/Head message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
void
xr_msgs__msg__Head__fini(xr_msgs__msg__Head * msg);

/// Create msg/Head message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * xr_msgs__msg__Head__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
xr_msgs__msg__Head *
xr_msgs__msg__Head__create();

/// Destroy msg/Head message.
/**
 * It calls
 * xr_msgs__msg__Head__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
void
xr_msgs__msg__Head__destroy(xr_msgs__msg__Head * msg);

/// Check for msg/Head message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
bool
xr_msgs__msg__Head__are_equal(const xr_msgs__msg__Head * lhs, const xr_msgs__msg__Head * rhs);

/// Copy a msg/Head message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
bool
xr_msgs__msg__Head__copy(
  const xr_msgs__msg__Head * input,
  xr_msgs__msg__Head * output);

/// Initialize array of msg/Head messages.
/**
 * It allocates the memory for the number of elements and calls
 * xr_msgs__msg__Head__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
bool
xr_msgs__msg__Head__Sequence__init(xr_msgs__msg__Head__Sequence * array, size_t size);

/// Finalize array of msg/Head messages.
/**
 * It calls
 * xr_msgs__msg__Head__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
void
xr_msgs__msg__Head__Sequence__fini(xr_msgs__msg__Head__Sequence * array);

/// Create array of msg/Head messages.
/**
 * It allocates the memory for the array and calls
 * xr_msgs__msg__Head__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
xr_msgs__msg__Head__Sequence *
xr_msgs__msg__Head__Sequence__create(size_t size);

/// Destroy array of msg/Head messages.
/**
 * It calls
 * xr_msgs__msg__Head__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
void
xr_msgs__msg__Head__Sequence__destroy(xr_msgs__msg__Head__Sequence * array);

/// Check for msg/Head message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
bool
xr_msgs__msg__Head__Sequence__are_equal(const xr_msgs__msg__Head__Sequence * lhs, const xr_msgs__msg__Head__Sequence * rhs);

/// Copy an array of msg/Head messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_xr_msgs
bool
xr_msgs__msg__Head__Sequence__copy(
  const xr_msgs__msg__Head__Sequence * input,
  xr_msgs__msg__Head__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // XR_MSGS__MSG__DETAIL__HEAD__FUNCTIONS_H_

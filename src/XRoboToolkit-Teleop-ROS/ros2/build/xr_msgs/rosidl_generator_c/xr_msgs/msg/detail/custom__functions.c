// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xr_msgs:msg/Custom.idl
// generated code does not contain a copyright notice
#include "xr_msgs/msg/detail/custom__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `head`
#include "xr_msgs/msg/detail/head__functions.h"
// Member `left_controller`
// Member `right_controller`
#include "xr_msgs/msg/detail/controller__functions.h"

bool
xr_msgs__msg__Custom__init(xr_msgs__msg__Custom * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp_ns
  // input
  // head
  if (!xr_msgs__msg__Head__init(&msg->head)) {
    xr_msgs__msg__Custom__fini(msg);
    return false;
  }
  // left_controller
  if (!xr_msgs__msg__Controller__init(&msg->left_controller)) {
    xr_msgs__msg__Custom__fini(msg);
    return false;
  }
  // right_controller
  if (!xr_msgs__msg__Controller__init(&msg->right_controller)) {
    xr_msgs__msg__Custom__fini(msg);
    return false;
  }
  return true;
}

void
xr_msgs__msg__Custom__fini(xr_msgs__msg__Custom * msg)
{
  if (!msg) {
    return;
  }
  // timestamp_ns
  // input
  // head
  xr_msgs__msg__Head__fini(&msg->head);
  // left_controller
  xr_msgs__msg__Controller__fini(&msg->left_controller);
  // right_controller
  xr_msgs__msg__Controller__fini(&msg->right_controller);
}

bool
xr_msgs__msg__Custom__are_equal(const xr_msgs__msg__Custom * lhs, const xr_msgs__msg__Custom * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp_ns
  if (lhs->timestamp_ns != rhs->timestamp_ns) {
    return false;
  }
  // input
  if (lhs->input != rhs->input) {
    return false;
  }
  // head
  if (!xr_msgs__msg__Head__are_equal(
      &(lhs->head), &(rhs->head)))
  {
    return false;
  }
  // left_controller
  if (!xr_msgs__msg__Controller__are_equal(
      &(lhs->left_controller), &(rhs->left_controller)))
  {
    return false;
  }
  // right_controller
  if (!xr_msgs__msg__Controller__are_equal(
      &(lhs->right_controller), &(rhs->right_controller)))
  {
    return false;
  }
  return true;
}

bool
xr_msgs__msg__Custom__copy(
  const xr_msgs__msg__Custom * input,
  xr_msgs__msg__Custom * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp_ns
  output->timestamp_ns = input->timestamp_ns;
  // input
  output->input = input->input;
  // head
  if (!xr_msgs__msg__Head__copy(
      &(input->head), &(output->head)))
  {
    return false;
  }
  // left_controller
  if (!xr_msgs__msg__Controller__copy(
      &(input->left_controller), &(output->left_controller)))
  {
    return false;
  }
  // right_controller
  if (!xr_msgs__msg__Controller__copy(
      &(input->right_controller), &(output->right_controller)))
  {
    return false;
  }
  return true;
}

xr_msgs__msg__Custom *
xr_msgs__msg__Custom__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xr_msgs__msg__Custom * msg = (xr_msgs__msg__Custom *)allocator.allocate(sizeof(xr_msgs__msg__Custom), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xr_msgs__msg__Custom));
  bool success = xr_msgs__msg__Custom__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
xr_msgs__msg__Custom__destroy(xr_msgs__msg__Custom * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    xr_msgs__msg__Custom__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
xr_msgs__msg__Custom__Sequence__init(xr_msgs__msg__Custom__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xr_msgs__msg__Custom * data = NULL;

  if (size) {
    data = (xr_msgs__msg__Custom *)allocator.zero_allocate(size, sizeof(xr_msgs__msg__Custom), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xr_msgs__msg__Custom__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xr_msgs__msg__Custom__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xr_msgs__msg__Custom__Sequence__fini(xr_msgs__msg__Custom__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xr_msgs__msg__Custom__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xr_msgs__msg__Custom__Sequence *
xr_msgs__msg__Custom__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xr_msgs__msg__Custom__Sequence * array = (xr_msgs__msg__Custom__Sequence *)allocator.allocate(sizeof(xr_msgs__msg__Custom__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = xr_msgs__msg__Custom__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
xr_msgs__msg__Custom__Sequence__destroy(xr_msgs__msg__Custom__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    xr_msgs__msg__Custom__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
xr_msgs__msg__Custom__Sequence__are_equal(const xr_msgs__msg__Custom__Sequence * lhs, const xr_msgs__msg__Custom__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xr_msgs__msg__Custom__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xr_msgs__msg__Custom__Sequence__copy(
  const xr_msgs__msg__Custom__Sequence * input,
  xr_msgs__msg__Custom__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xr_msgs__msg__Custom);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    xr_msgs__msg__Custom * data =
      (xr_msgs__msg__Custom *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xr_msgs__msg__Custom__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          xr_msgs__msg__Custom__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xr_msgs__msg__Custom__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

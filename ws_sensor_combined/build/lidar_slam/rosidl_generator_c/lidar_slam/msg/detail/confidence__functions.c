// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lidar_slam:msg/Confidence.idl
// generated code does not contain a copyright notice
#include "lidar_slam/msg/detail/confidence__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
lidar_slam__msg__Confidence__init(lidar_slam__msg__Confidence * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    lidar_slam__msg__Confidence__fini(msg);
    return false;
  }
  // covariance
  // overlap
  // nb_matches
  // comply_motion_limits
  // std_position_error
  // failure
  // computation_time
  return true;
}

void
lidar_slam__msg__Confidence__fini(lidar_slam__msg__Confidence * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // covariance
  // overlap
  // nb_matches
  // comply_motion_limits
  // std_position_error
  // failure
  // computation_time
}

bool
lidar_slam__msg__Confidence__are_equal(const lidar_slam__msg__Confidence * lhs, const lidar_slam__msg__Confidence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // covariance
  for (size_t i = 0; i < 36; ++i) {
    if (lhs->covariance[i] != rhs->covariance[i]) {
      return false;
    }
  }
  // overlap
  if (lhs->overlap != rhs->overlap) {
    return false;
  }
  // nb_matches
  if (lhs->nb_matches != rhs->nb_matches) {
    return false;
  }
  // comply_motion_limits
  if (lhs->comply_motion_limits != rhs->comply_motion_limits) {
    return false;
  }
  // std_position_error
  if (lhs->std_position_error != rhs->std_position_error) {
    return false;
  }
  // failure
  if (lhs->failure != rhs->failure) {
    return false;
  }
  // computation_time
  if (lhs->computation_time != rhs->computation_time) {
    return false;
  }
  return true;
}

bool
lidar_slam__msg__Confidence__copy(
  const lidar_slam__msg__Confidence * input,
  lidar_slam__msg__Confidence * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // covariance
  for (size_t i = 0; i < 36; ++i) {
    output->covariance[i] = input->covariance[i];
  }
  // overlap
  output->overlap = input->overlap;
  // nb_matches
  output->nb_matches = input->nb_matches;
  // comply_motion_limits
  output->comply_motion_limits = input->comply_motion_limits;
  // std_position_error
  output->std_position_error = input->std_position_error;
  // failure
  output->failure = input->failure;
  // computation_time
  output->computation_time = input->computation_time;
  return true;
}

lidar_slam__msg__Confidence *
lidar_slam__msg__Confidence__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam__msg__Confidence * msg = (lidar_slam__msg__Confidence *)allocator.allocate(sizeof(lidar_slam__msg__Confidence), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lidar_slam__msg__Confidence));
  bool success = lidar_slam__msg__Confidence__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lidar_slam__msg__Confidence__destroy(lidar_slam__msg__Confidence * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lidar_slam__msg__Confidence__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lidar_slam__msg__Confidence__Sequence__init(lidar_slam__msg__Confidence__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam__msg__Confidence * data = NULL;

  if (size) {
    data = (lidar_slam__msg__Confidence *)allocator.zero_allocate(size, sizeof(lidar_slam__msg__Confidence), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lidar_slam__msg__Confidence__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lidar_slam__msg__Confidence__fini(&data[i - 1]);
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
lidar_slam__msg__Confidence__Sequence__fini(lidar_slam__msg__Confidence__Sequence * array)
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
      lidar_slam__msg__Confidence__fini(&array->data[i]);
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

lidar_slam__msg__Confidence__Sequence *
lidar_slam__msg__Confidence__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam__msg__Confidence__Sequence * array = (lidar_slam__msg__Confidence__Sequence *)allocator.allocate(sizeof(lidar_slam__msg__Confidence__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lidar_slam__msg__Confidence__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lidar_slam__msg__Confidence__Sequence__destroy(lidar_slam__msg__Confidence__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lidar_slam__msg__Confidence__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lidar_slam__msg__Confidence__Sequence__are_equal(const lidar_slam__msg__Confidence__Sequence * lhs, const lidar_slam__msg__Confidence__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lidar_slam__msg__Confidence__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lidar_slam__msg__Confidence__Sequence__copy(
  const lidar_slam__msg__Confidence__Sequence * input,
  lidar_slam__msg__Confidence__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lidar_slam__msg__Confidence);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lidar_slam__msg__Confidence * data =
      (lidar_slam__msg__Confidence *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lidar_slam__msg__Confidence__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lidar_slam__msg__Confidence__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lidar_slam__msg__Confidence__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lidar_slam:msg/SlamCommand.idl
// generated code does not contain a copyright notice
#include "lidar_slam/msg/detail/slam_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `string_arg`
#include "rosidl_runtime_c/string_functions.h"

bool
lidar_slam__msg__SlamCommand__init(lidar_slam__msg__SlamCommand * msg)
{
  if (!msg) {
    return false;
  }
  // command
  // string_arg
  if (!rosidl_runtime_c__String__init(&msg->string_arg)) {
    lidar_slam__msg__SlamCommand__fini(msg);
    return false;
  }
  return true;
}

void
lidar_slam__msg__SlamCommand__fini(lidar_slam__msg__SlamCommand * msg)
{
  if (!msg) {
    return;
  }
  // command
  // string_arg
  rosidl_runtime_c__String__fini(&msg->string_arg);
}

bool
lidar_slam__msg__SlamCommand__are_equal(const lidar_slam__msg__SlamCommand * lhs, const lidar_slam__msg__SlamCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (lhs->command != rhs->command) {
    return false;
  }
  // string_arg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->string_arg), &(rhs->string_arg)))
  {
    return false;
  }
  return true;
}

bool
lidar_slam__msg__SlamCommand__copy(
  const lidar_slam__msg__SlamCommand * input,
  lidar_slam__msg__SlamCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  output->command = input->command;
  // string_arg
  if (!rosidl_runtime_c__String__copy(
      &(input->string_arg), &(output->string_arg)))
  {
    return false;
  }
  return true;
}

lidar_slam__msg__SlamCommand *
lidar_slam__msg__SlamCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam__msg__SlamCommand * msg = (lidar_slam__msg__SlamCommand *)allocator.allocate(sizeof(lidar_slam__msg__SlamCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lidar_slam__msg__SlamCommand));
  bool success = lidar_slam__msg__SlamCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lidar_slam__msg__SlamCommand__destroy(lidar_slam__msg__SlamCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lidar_slam__msg__SlamCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lidar_slam__msg__SlamCommand__Sequence__init(lidar_slam__msg__SlamCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam__msg__SlamCommand * data = NULL;

  if (size) {
    data = (lidar_slam__msg__SlamCommand *)allocator.zero_allocate(size, sizeof(lidar_slam__msg__SlamCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lidar_slam__msg__SlamCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lidar_slam__msg__SlamCommand__fini(&data[i - 1]);
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
lidar_slam__msg__SlamCommand__Sequence__fini(lidar_slam__msg__SlamCommand__Sequence * array)
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
      lidar_slam__msg__SlamCommand__fini(&array->data[i]);
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

lidar_slam__msg__SlamCommand__Sequence *
lidar_slam__msg__SlamCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam__msg__SlamCommand__Sequence * array = (lidar_slam__msg__SlamCommand__Sequence *)allocator.allocate(sizeof(lidar_slam__msg__SlamCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lidar_slam__msg__SlamCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lidar_slam__msg__SlamCommand__Sequence__destroy(lidar_slam__msg__SlamCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lidar_slam__msg__SlamCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lidar_slam__msg__SlamCommand__Sequence__are_equal(const lidar_slam__msg__SlamCommand__Sequence * lhs, const lidar_slam__msg__SlamCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lidar_slam__msg__SlamCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lidar_slam__msg__SlamCommand__Sequence__copy(
  const lidar_slam__msg__SlamCommand__Sequence * input,
  lidar_slam__msg__SlamCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lidar_slam__msg__SlamCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lidar_slam__msg__SlamCommand * data =
      (lidar_slam__msg__SlamCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lidar_slam__msg__SlamCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lidar_slam__msg__SlamCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lidar_slam__msg__SlamCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

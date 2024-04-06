// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lidar_conversions:srv/EstimParams.idl
// generated code does not contain a copyright notice
#include "lidar_conversions/srv/detail/estim_params__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
lidar_conversions__srv__EstimParams_Request__init(lidar_conversions__srv__EstimParams_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
lidar_conversions__srv__EstimParams_Request__fini(lidar_conversions__srv__EstimParams_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
lidar_conversions__srv__EstimParams_Request__are_equal(const lidar_conversions__srv__EstimParams_Request * lhs, const lidar_conversions__srv__EstimParams_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
lidar_conversions__srv__EstimParams_Request__copy(
  const lidar_conversions__srv__EstimParams_Request * input,
  lidar_conversions__srv__EstimParams_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

lidar_conversions__srv__EstimParams_Request *
lidar_conversions__srv__EstimParams_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_conversions__srv__EstimParams_Request * msg = (lidar_conversions__srv__EstimParams_Request *)allocator.allocate(sizeof(lidar_conversions__srv__EstimParams_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lidar_conversions__srv__EstimParams_Request));
  bool success = lidar_conversions__srv__EstimParams_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lidar_conversions__srv__EstimParams_Request__destroy(lidar_conversions__srv__EstimParams_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lidar_conversions__srv__EstimParams_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lidar_conversions__srv__EstimParams_Request__Sequence__init(lidar_conversions__srv__EstimParams_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_conversions__srv__EstimParams_Request * data = NULL;

  if (size) {
    data = (lidar_conversions__srv__EstimParams_Request *)allocator.zero_allocate(size, sizeof(lidar_conversions__srv__EstimParams_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lidar_conversions__srv__EstimParams_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lidar_conversions__srv__EstimParams_Request__fini(&data[i - 1]);
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
lidar_conversions__srv__EstimParams_Request__Sequence__fini(lidar_conversions__srv__EstimParams_Request__Sequence * array)
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
      lidar_conversions__srv__EstimParams_Request__fini(&array->data[i]);
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

lidar_conversions__srv__EstimParams_Request__Sequence *
lidar_conversions__srv__EstimParams_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_conversions__srv__EstimParams_Request__Sequence * array = (lidar_conversions__srv__EstimParams_Request__Sequence *)allocator.allocate(sizeof(lidar_conversions__srv__EstimParams_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lidar_conversions__srv__EstimParams_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lidar_conversions__srv__EstimParams_Request__Sequence__destroy(lidar_conversions__srv__EstimParams_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lidar_conversions__srv__EstimParams_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lidar_conversions__srv__EstimParams_Request__Sequence__are_equal(const lidar_conversions__srv__EstimParams_Request__Sequence * lhs, const lidar_conversions__srv__EstimParams_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lidar_conversions__srv__EstimParams_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lidar_conversions__srv__EstimParams_Request__Sequence__copy(
  const lidar_conversions__srv__EstimParams_Request__Sequence * input,
  lidar_conversions__srv__EstimParams_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lidar_conversions__srv__EstimParams_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lidar_conversions__srv__EstimParams_Request * data =
      (lidar_conversions__srv__EstimParams_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lidar_conversions__srv__EstimParams_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lidar_conversions__srv__EstimParams_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lidar_conversions__srv__EstimParams_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
lidar_conversions__srv__EstimParams_Response__init(lidar_conversions__srv__EstimParams_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
lidar_conversions__srv__EstimParams_Response__fini(lidar_conversions__srv__EstimParams_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
lidar_conversions__srv__EstimParams_Response__are_equal(const lidar_conversions__srv__EstimParams_Response * lhs, const lidar_conversions__srv__EstimParams_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
lidar_conversions__srv__EstimParams_Response__copy(
  const lidar_conversions__srv__EstimParams_Response * input,
  lidar_conversions__srv__EstimParams_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

lidar_conversions__srv__EstimParams_Response *
lidar_conversions__srv__EstimParams_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_conversions__srv__EstimParams_Response * msg = (lidar_conversions__srv__EstimParams_Response *)allocator.allocate(sizeof(lidar_conversions__srv__EstimParams_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lidar_conversions__srv__EstimParams_Response));
  bool success = lidar_conversions__srv__EstimParams_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lidar_conversions__srv__EstimParams_Response__destroy(lidar_conversions__srv__EstimParams_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lidar_conversions__srv__EstimParams_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lidar_conversions__srv__EstimParams_Response__Sequence__init(lidar_conversions__srv__EstimParams_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_conversions__srv__EstimParams_Response * data = NULL;

  if (size) {
    data = (lidar_conversions__srv__EstimParams_Response *)allocator.zero_allocate(size, sizeof(lidar_conversions__srv__EstimParams_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lidar_conversions__srv__EstimParams_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lidar_conversions__srv__EstimParams_Response__fini(&data[i - 1]);
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
lidar_conversions__srv__EstimParams_Response__Sequence__fini(lidar_conversions__srv__EstimParams_Response__Sequence * array)
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
      lidar_conversions__srv__EstimParams_Response__fini(&array->data[i]);
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

lidar_conversions__srv__EstimParams_Response__Sequence *
lidar_conversions__srv__EstimParams_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_conversions__srv__EstimParams_Response__Sequence * array = (lidar_conversions__srv__EstimParams_Response__Sequence *)allocator.allocate(sizeof(lidar_conversions__srv__EstimParams_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lidar_conversions__srv__EstimParams_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lidar_conversions__srv__EstimParams_Response__Sequence__destroy(lidar_conversions__srv__EstimParams_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lidar_conversions__srv__EstimParams_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lidar_conversions__srv__EstimParams_Response__Sequence__are_equal(const lidar_conversions__srv__EstimParams_Response__Sequence * lhs, const lidar_conversions__srv__EstimParams_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lidar_conversions__srv__EstimParams_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lidar_conversions__srv__EstimParams_Response__Sequence__copy(
  const lidar_conversions__srv__EstimParams_Response__Sequence * input,
  lidar_conversions__srv__EstimParams_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lidar_conversions__srv__EstimParams_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lidar_conversions__srv__EstimParams_Response * data =
      (lidar_conversions__srv__EstimParams_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lidar_conversions__srv__EstimParams_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lidar_conversions__srv__EstimParams_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lidar_conversions__srv__EstimParams_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

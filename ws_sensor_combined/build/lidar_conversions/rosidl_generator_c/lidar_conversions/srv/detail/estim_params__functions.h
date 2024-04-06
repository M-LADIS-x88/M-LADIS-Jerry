// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from lidar_conversions:srv/EstimParams.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_PARAMS__FUNCTIONS_H_
#define LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_PARAMS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "lidar_conversions/msg/rosidl_generator_c__visibility_control.h"

#include "lidar_conversions/srv/detail/estim_params__struct.h"

/// Initialize srv/EstimParams message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lidar_conversions__srv__EstimParams_Request
 * )) before or use
 * lidar_conversions__srv__EstimParams_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Request__init(lidar_conversions__srv__EstimParams_Request * msg);

/// Finalize srv/EstimParams message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
void
lidar_conversions__srv__EstimParams_Request__fini(lidar_conversions__srv__EstimParams_Request * msg);

/// Create srv/EstimParams message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lidar_conversions__srv__EstimParams_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
lidar_conversions__srv__EstimParams_Request *
lidar_conversions__srv__EstimParams_Request__create();

/// Destroy srv/EstimParams message.
/**
 * It calls
 * lidar_conversions__srv__EstimParams_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
void
lidar_conversions__srv__EstimParams_Request__destroy(lidar_conversions__srv__EstimParams_Request * msg);

/// Check for srv/EstimParams message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Request__are_equal(const lidar_conversions__srv__EstimParams_Request * lhs, const lidar_conversions__srv__EstimParams_Request * rhs);

/// Copy a srv/EstimParams message.
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
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Request__copy(
  const lidar_conversions__srv__EstimParams_Request * input,
  lidar_conversions__srv__EstimParams_Request * output);

/// Initialize array of srv/EstimParams messages.
/**
 * It allocates the memory for the number of elements and calls
 * lidar_conversions__srv__EstimParams_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Request__Sequence__init(lidar_conversions__srv__EstimParams_Request__Sequence * array, size_t size);

/// Finalize array of srv/EstimParams messages.
/**
 * It calls
 * lidar_conversions__srv__EstimParams_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
void
lidar_conversions__srv__EstimParams_Request__Sequence__fini(lidar_conversions__srv__EstimParams_Request__Sequence * array);

/// Create array of srv/EstimParams messages.
/**
 * It allocates the memory for the array and calls
 * lidar_conversions__srv__EstimParams_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
lidar_conversions__srv__EstimParams_Request__Sequence *
lidar_conversions__srv__EstimParams_Request__Sequence__create(size_t size);

/// Destroy array of srv/EstimParams messages.
/**
 * It calls
 * lidar_conversions__srv__EstimParams_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
void
lidar_conversions__srv__EstimParams_Request__Sequence__destroy(lidar_conversions__srv__EstimParams_Request__Sequence * array);

/// Check for srv/EstimParams message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Request__Sequence__are_equal(const lidar_conversions__srv__EstimParams_Request__Sequence * lhs, const lidar_conversions__srv__EstimParams_Request__Sequence * rhs);

/// Copy an array of srv/EstimParams messages.
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
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Request__Sequence__copy(
  const lidar_conversions__srv__EstimParams_Request__Sequence * input,
  lidar_conversions__srv__EstimParams_Request__Sequence * output);

/// Initialize srv/EstimParams message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lidar_conversions__srv__EstimParams_Response
 * )) before or use
 * lidar_conversions__srv__EstimParams_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Response__init(lidar_conversions__srv__EstimParams_Response * msg);

/// Finalize srv/EstimParams message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
void
lidar_conversions__srv__EstimParams_Response__fini(lidar_conversions__srv__EstimParams_Response * msg);

/// Create srv/EstimParams message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lidar_conversions__srv__EstimParams_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
lidar_conversions__srv__EstimParams_Response *
lidar_conversions__srv__EstimParams_Response__create();

/// Destroy srv/EstimParams message.
/**
 * It calls
 * lidar_conversions__srv__EstimParams_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
void
lidar_conversions__srv__EstimParams_Response__destroy(lidar_conversions__srv__EstimParams_Response * msg);

/// Check for srv/EstimParams message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Response__are_equal(const lidar_conversions__srv__EstimParams_Response * lhs, const lidar_conversions__srv__EstimParams_Response * rhs);

/// Copy a srv/EstimParams message.
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
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Response__copy(
  const lidar_conversions__srv__EstimParams_Response * input,
  lidar_conversions__srv__EstimParams_Response * output);

/// Initialize array of srv/EstimParams messages.
/**
 * It allocates the memory for the number of elements and calls
 * lidar_conversions__srv__EstimParams_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Response__Sequence__init(lidar_conversions__srv__EstimParams_Response__Sequence * array, size_t size);

/// Finalize array of srv/EstimParams messages.
/**
 * It calls
 * lidar_conversions__srv__EstimParams_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
void
lidar_conversions__srv__EstimParams_Response__Sequence__fini(lidar_conversions__srv__EstimParams_Response__Sequence * array);

/// Create array of srv/EstimParams messages.
/**
 * It allocates the memory for the array and calls
 * lidar_conversions__srv__EstimParams_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
lidar_conversions__srv__EstimParams_Response__Sequence *
lidar_conversions__srv__EstimParams_Response__Sequence__create(size_t size);

/// Destroy array of srv/EstimParams messages.
/**
 * It calls
 * lidar_conversions__srv__EstimParams_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
void
lidar_conversions__srv__EstimParams_Response__Sequence__destroy(lidar_conversions__srv__EstimParams_Response__Sequence * array);

/// Check for srv/EstimParams message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Response__Sequence__are_equal(const lidar_conversions__srv__EstimParams_Response__Sequence * lhs, const lidar_conversions__srv__EstimParams_Response__Sequence * rhs);

/// Copy an array of srv/EstimParams messages.
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
ROSIDL_GENERATOR_C_PUBLIC_lidar_conversions
bool
lidar_conversions__srv__EstimParams_Response__Sequence__copy(
  const lidar_conversions__srv__EstimParams_Response__Sequence * input,
  lidar_conversions__srv__EstimParams_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_CONVERSIONS__SRV__DETAIL__ESTIM_PARAMS__FUNCTIONS_H_

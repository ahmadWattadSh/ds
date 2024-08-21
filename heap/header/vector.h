/*Name: HRD 32
  Project: Dynamic Vector Implementation
  Reviewer: Liel
  Date: 10/08/2023
  Version: 1.0
*/
/******************************************************************************/
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stddef.h> /*size_t*/
/******************************************************************************/

enum status_ty {FAILURE = 0, SUCCESS = 1};
typedef struct vector vector_ty;

/******************************************************************************/

/*Function that inits the vector struct
  Arguments: capacity of the vector, element size.
  Return value: pointer to the created vector struct
  Undefined B.: element_size = 0, capacity = 0*/
vector_ty *VectorCreate(size_t capacity, size_t element_size);

/*Function that deletes the vector struct
  Arguments: pointer to the vector struct.
  Return value: void.
  Undefined B.: NULL ptr of vector*/
void VectorDestroy(vector_ty *vector);

/*Function that deletes the last element from the vector struct
  Arguments: pointer to the vector struct.
  Return value: void.
  Undefined B.: NULL ptr of vector*/
void VectorPopBack(vector_ty *vector);

/*Function that adds data to the first empty element in the vector struct.
  if it reach the end of the vector, vector will be automatically resized. 
  (by default growth factor).
  Arguments: pointer to the vector struct, data to be added.
  Return value: int success.
  Undefined B.: size of data > element_size, NULL ptr of vector*/
int VectorPushBack(vector_ty *vector, const void *data);

/*Function that gets access to a specific element in the vector struct
  Arguments: pointer to the vector struct, index.
  Return value: void* that represent the element.
  Undefined B.: NULL ptr of vector, index > capacity*/
void *VGetAccessToElement(const vector_ty *vector, size_t index);

/*Function that returns the size of the vector struct
  Arguments: pointer to the vector struct.
  Return value: size of the vector struct.
  Undefined B.: NULL ptr of vector*/
size_t VectorSize(const vector_ty *vector);

/*Function that checks if the vector struct is empty
  Arguments: pointer to the vector struct.
  Return value: TRUE/FALSE.
  Undefined B.: NULL ptr of vector*/
int VectorIsEmpty(const vector_ty *vector);

/*Function that returns the capacity of the vector struct
  Arguments: pointer to the vector struct.
  Return value: capacity of the vector struct.
  Undefined B.: NULL ptr of vector*/
size_t VectorCapacity(const vector_ty *vector);

/*Function that resized the space of the vector with the new capacity.
  If the new_capacity < size, function will do nothing (data will be kept).
  Arguments: pointer to the vector struct, new capacity.
  Return value: int success.
  Undefined B.: NULL ptr of vector*/
int VectorReserve(vector_ty *vector, const size_t new_capacity);

/*Function that shrinks the space of the vector with the default shrink factor.
  If the shrink operation leads to data loss, function will do nothing.
  Arguments: pointer to the vector struct.
  Return value: int success.
  Undefined B.: NULL ptr of vector*/
int VectorShrink(vector_ty *vector);

/******************************************************************************/
#endif /*(__VECTOR_H__)*/

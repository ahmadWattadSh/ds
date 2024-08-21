/******************************** ws5_dc_buff.h  ***************************/
/*
  Name: HRD32
  Project: Work Sheet 8 - Data Structures - Circular Buffer
  Reviewer: HRD32
  Date: 20/08/23
  Version: 1.0
*/

#ifndef __C_BUFFER_H__
#define __C_BUFFER_H__

/******************************** Libraries  *******************************/

#include <stddef.h> /*size_t*/

/******************************** Definitions  ******************************/

typedef enum  {SUCCESS = 0, FAILURE = 1, EMPTY = 0, NOT_EMPTY = 1} status_ty;
typedef struct c_buff c_buff_ty;

/*A function that inits a c_buff struct.
  Argumnets: size_t capacity
  return value: new allocated c_buff struct 
  undefined behaviors: overflow */
c_buff_ty *CbuffCreate(size_t capacity);

/*A function that deletes the c_buff struct
  Arguments: pointer to the c_buff struct.
  Return value: void.
  Undefined B.: NULL ptr of c_buff*/
void CbuffDestroy(c_buff_ty *buffer);

/*A function that reads from the buffer n_bytes to the dest pointer, if there is
  no data to be read, it will return 0, and if requested to read more than the 
  available space, it will only read the available space.
  Arguments: pointer to the c_buff struct,
             dest pointer,
             n_btytes: number of bytes to be read.
  Return value: number of bytes that were successfully read.
  Undefined B.: NULL ptr of c_buff & src */
size_t CbuffRead(c_buff_ty *buffer, void *dest, size_t n_bytes);

/*A function that writes to the buffer n_bytes from the src pointer, if there is
  no data to be written, it will return 0, and if requested to write more than the 
  available space, it will only write to the the available space.
  Arguments: pointer to the c_buff struct,
             source pointer to read from,
             n_btytes: number of bytes to be read.
  Return value: number of bytes that were successfully written.
  Undefined B.: NULL ptr of c_buff & src */
size_t CbuffWrite(c_buff_ty *buffer, void *src, size_t n_bytes);

/*A function that returns the capacity of the c_buff
  Arguments: pointer to the c_buff struct.
  Return value: capacity of the c_buff.
  Undefined B.: NULL ptr of c_buff*/
size_t CbuffSize(const c_buff_ty *buffer);

/*A function that checks if the c_buff is empty
  Arguments: pointer to the c_buff struct.
  Return value: status_ty
  Undefined B.: NULL ptr of c_buff*/
status_ty CbuffIsEmpty(const c_buff_ty *buffer);

/*A function that returns size of the remaining empty space in the buffer.
  Arguments: pointer to the c_buff struct.
  Return value: number of bytes.
  Undefined B.: NULL ptr of c_buff*/
size_t CbuffFreeSpace(const c_buff_ty *buffer);


#endif /*(__C_BUFFER_H__)*/

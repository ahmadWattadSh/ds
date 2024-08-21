/*Name: HRD 32
  Project: Bit Array Functions Implementation
  Reviewer: Liel
  Date: 07/08/2023
  Version: 1.0
*/
/******************************************************************************/

#ifndef __BIT_ARRAY_H__
#define __BIT_ARRAY_H__

#include <stddef.h> /*size_t*/

typedef size_t bit_array_ty; /*array of 64 bits.*/

/*Function that sets all the bits. 
  Arguments: array of 64 bits.
  Return value: It returns the set array.*/
bit_array_ty SetAll(bit_array_ty bit_arr);

/*Function that resets all the bits. 
  Arguments: array of 64 bits.
  Return value: It returns the reset array.*/
bit_array_ty ResetAll(bit_array_ty bit_arr);

/*Function that sets the index bit. 
  Arguments: array of 64 bits, index.
  Return value: It returns the updated array.
  Undefined B.: if index > 63 return the origin array*/
bit_array_ty SetOn(bit_array_ty bit_arr, size_t index);

/*Function that resets the index bit. 
  Arguments: array of 64 bits, index.
  Return value: It returns the updated array.
  Undefined B.: if index > 63 return the origin array*/
bit_array_ty SetOff(bit_array_ty bit_arr, size_t index);

/*Function that sets the index bit with bit_val. 
  Arguments: array of 64 bits, index, bit value.
  Return value: It returns the updated array.
  Undefined B.: if bit_val diff. from 0 or 1 return the origin array
                if index > 63 return the origin array*/
bit_array_ty SetBit(bit_array_ty bit_arr,size_t index, int bit_val);

/*Function that returns the index bit value. 
  Arguments: array of 64 bits, index.
  Return value: It returns the index bit value.
  Undefined B.: if index > 63 return the origin array*/
int GetVal(bit_array_ty bit_arr, size_t index);

/*Function that flips the array. 
  Arguments: array of 64 bits.
  Return value: It returns the flipped array.*/
bit_array_ty Flip(bit_array_ty bit_arr);

/*Function that mirrors the array. 
  Arguments: array of 64 bits.
  Return value: It returns the mirrored array.*/
bit_array_ty Mirror(bit_array_ty bit_arr);

/*Function that rotates the array num_of_shifts times to the right. 
  Arguments: array of 64 bits, num_of_shifts.
  Return value: It returns the rotated array.*/
bit_array_ty RotateRight(bit_array_ty bit_arr, size_t num_of_shifts);

/*Function that rotates the array num_of_shifts times to the left. 
  Arguments: array of 64 bits, num_of_shifts.
  Return value: It returns the rotated array.*/
bit_array_ty RotateLeft(bit_array_ty bit_arr, size_t num_of_shifts);

/*Function that counts the set bits. 
  Arguments: array of 64 bits.
  Return value: It returns the count of the set bits.*/
size_t CountOn(bit_array_ty bit_arr);

/*Function that counts the unset bits. 
  Arguments: array of 64 bits.
  Return value: It returns the count of the unset bits.*/
size_t CountOff(bit_array_ty bit_arr);

/*Function that converts the array into a string. 
  Arguments: array of 65 bits, dest string.
  Return value: It returns the converted string.
  Undefined B.: if the dest is not large enough*/
char *ToString(bit_array_ty bit_arr, char *dest);

/*Function that counts the set bits using lut table. 
  Arguments: array of 64 bits.
  Return value: It returns the count of the set bits.*/
size_t CountOnLut(bit_array_ty bit_arr);

/*Function that mirrors the array using lut. 
  Arguments: array of 65 bits.
  Return value: It returns the mirrored array.*/
bit_array_ty MirrorLut(bit_array_ty bit_arr);


/******************************************************************************/
#endif /*(__BIT_ARRAY_H__)*/


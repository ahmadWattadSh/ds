/*Name: AhmadWattad
  Project: Worksheet11
  Reviewer: Dima
  Date: 31/07/2023
  Version: 1.0: published the program
 	   1.1: apply modifications without malloc
 	   1.2: prepare the prog for reviewing
 	   1.3 reviewed and changed accordingly
  		*/
#include <assert.h> /*assert*/

#include "BitArray.h"

#define EIGHT_BITS_CHUNK 256
#define MAX_SHIFTS_LONG 63
#define ONE_SHIFT 1
#define SIXTY_FOUR_BITS 64
#define BYTE_SHIFT 8

/**************************** Global variables ********************************/
enum status_ty{FALSE_INITIALIZE = 0, TRUE_INITIALIZE = 1};
/************************** Forward Declarations ******************************/
static size_t CountOnLutHelper(unsigned char byte_from_bit_arr);

/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/

/******************************** SET ALL *************************************/

bit_array_ty SetAll(bit_array_ty bit_arr)
{
	return bit_arr | -1;
}

/****************************** RESET ALL *************************************/

bit_array_ty ResetAll(bit_array_ty bit_arr)
{
	return bit_arr & (size_t)0;
}

/******************************** SET ON **************************************/

bit_array_ty SetOn(bit_array_ty bit_arr, size_t index)
{
	if(SIXTY_FOUR_BITS <= index)
	{
		return bit_arr; 
	}
	
	size_t mask = (size_t)1 << (index);
	return bit_arr | mask;
}

/******************************** SET OFF *************************************/

bit_array_ty SetOff(bit_array_ty bit_arr, size_t index)
{
	if(SIXTY_FOUR_BITS <= index)
	{
		return bit_arr; 
	}
	
	size_t mask = (size_t)1 << (index);
	return bit_arr & (~mask);
}

/******************************** SET BIT *************************************/

bit_array_ty SetBit(bit_array_ty bit_arr, size_t index, int bit_val)
{
	if(SIXTY_FOUR_BITS <= index || 1 < bit_val || 0 > bit_val)
	{
		return bit_arr; 
	}
	
	if (0 == bit_val)
	{
		return SetOff(bit_arr, index);
	}
		return SetOn(bit_arr, index);	


}

/******************************** GET VAL *************************************/

int GetVal(bit_array_ty bit_arr, size_t index)
{
	if(SIXTY_FOUR_BITS <= index)
	{
		return bit_arr; 
	}
	
	size_t mask = (size_t)1 << (index) ;
	mask = mask & bit_arr;
	return !!mask;	
}

/********************************* FLIP ***************************************/

bit_array_ty Flip(bit_array_ty bit_arr)
{
	return ~bit_arr;
}

/******************************* MIRROR ***************************************/

bit_array_ty Mirror(bit_array_ty bit_arr)
{
  	bit_arr = (bit_arr & 0xFFFFFFFF00000000) >> 32 | 
  	(bit_arr & 0x00000000FFFFFFFF) << 32;
  	bit_arr = (bit_arr & 0xFFFF0000FFFF0000) >> 16 | 
  	(bit_arr & 0x0000FFFF0000FFFF) << 16;
  	bit_arr = (bit_arr & 0xFF00FF00FF00FF00) >> 8  | 
  	(bit_arr & 0x00FF00FF00FF00FF) << 8;
  	bit_arr = (bit_arr & 0xF0F0F0F0F0F0F0F0) >> 4 | 
  	(bit_arr & 0x0F0F0F0F0F0F0F0F) << 4;
  	bit_arr = (bit_arr & 0xCCCCCCCCCCCCCCCC) >> 2| (
  	bit_arr & 0x3333333333333333) << 2;
 	bit_arr = (bit_arr & 0xAAAAAAAAAAAAAAAA) >> 1 | 
 	(bit_arr & 0x5555555555555555) << 1;
 	 
	return bit_arr;	
}

/**************************** MIRROR LUT **************************************/

bit_array_ty MirrorLut(bit_array_ty bit_arr)
{
	size_t i = 0;
	size_t j = 0;
	size_t mirrored_bit_arr = 0 ;
	static int is_lut_initalized = FALSE_INITIALIZE;
	static size_t lut_table_mirror[EIGHT_BITS_CHUNK];	
	
	if(!is_lut_initalized)
	{
		is_lut_initalized = TRUE_INITIALIZE;
	
	while (EIGHT_BITS_CHUNK > i)
	{

		lut_table_mirror[i] = Mirror(i);
		++i;
	}
	
	}
	
	while (SIXTY_FOUR_BITS > j)
	{
		mirrored_bit_arr |= (lut_table_mirror[bit_arr & 0xFF] >> j);
		bit_arr = bit_arr >> BYTE_SHIFT;
		j += 8;
	}
	
	return  mirrored_bit_arr;
}

/*************************** ROTATE RIGHT *************************************/

bit_array_ty RotateRight(bit_array_ty bit_arr, size_t num_of_shifts)
{
	
	return bit_arr >> num_of_shifts | bit_arr << (SIXTY_FOUR_BITS - num_of_shifts) ;	
}

/*************************** ROTATE LEFT *************************************/

bit_array_ty RotateLeft(bit_array_ty bit_arr, size_t num_of_shifts)
{
	return bit_arr << num_of_shifts | bit_arr >> (SIXTY_FOUR_BITS - num_of_shifts) ;		
}

/***************************** COUNT ON ***************************************/

size_t CountOn(bit_array_ty bit_arr)
{
	size_t counter = 0;

	while (0 != bit_arr)
	{
		bit_arr = bit_arr & (bit_arr-1);
		++counter;
	}

	return counter;

}

/**************************** COUNT ON LUT ************************************/

size_t CountOnLut(bit_array_ty bit_arr)
{
	size_t i = 0;
	size_t counter = 0;
	while (SIXTY_FOUR_BITS > i)
	{	
		counter += CountOnLutHelper((unsigned char)((bit_arr >> i) & 0xFF));
		i += 8;	
	}

	return counter;
}

/*************************** COUNT ON LUT HELPER ******************************/

static size_t CountOnLutHelper(unsigned char byte_from_bit_arr)
{
	size_t i = 0;
	static int is_lut_initalized = FALSE_INITIALIZE;
	static size_t lut_table_for_8bits[EIGHT_BITS_CHUNK];	
	
	if(!is_lut_initalized)
	{
		is_lut_initalized = TRUE_INITIALIZE;
	
	while (EIGHT_BITS_CHUNK > i)
	{
		lut_table_for_8bits[i]= CountOn(i);
		++i;
	}
	
	}
	
	return lut_table_for_8bits[byte_from_bit_arr];
}

/***************************** COUNT OFF **************************************/

size_t CountOff(bit_array_ty bit_arr)
{
	return CountOn(~bit_arr);
}

/***************************** TO STRING **************************************/

char *ToString(bit_array_ty bit_arr, char *dest)
{
	assert(NULL != dest);
	
	size_t i = SIXTY_FOUR_BITS;
	
	while (i > 0)
	{
		dest[i-1] = (bit_arr & (size_t) 1) ? '1' : '0';
		bit_arr = bit_arr >> ONE_SHIFT;
		--i;
	}
			
	dest[SIXTY_FOUR_BITS] = '\0';

	return dest;	
}




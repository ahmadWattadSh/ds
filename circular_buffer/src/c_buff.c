/*Name: AhmadWattad
  Project: Work Sheet 8 - circular buffer
  Reviewer: Agbaria
  Date: 31/07/2023
  Version: 1.0: published the program
 	   1.1: apply modifications without malloc
 	   1.2: prepare the prog for reviewing
 	   1.3 reviewed and changed accordingly
  		*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/
#include <string.h> /*memcpy*/

#include "c_buff.h"


/**************************** Global variables ********************************/

struct c_buff
{
	size_t capacity;
	size_t read_idx;
	size_t size;
	char c_buff_arr[1];
};

/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/


/******************************* CBUFF-CREATE ********************************/

c_buff_ty *CbuffCreate(size_t capacity)
{
	c_buff_ty *c_buff_init = (c_buff_ty*)malloc(sizeof(c_buff_ty) 
	+ sizeof(char)*capacity) - 8;
	
	if(NULL == c_buff_init)
	{
		return NULL;
	}
	
	c_buff_init->capacity = capacity;
	c_buff_init->size = 0;
	c_buff_init->read_idx = 0;
}

/******************************* CBUFF-DESTROY ********************************/

void CbuffDestroy(c_buff_ty *buffer)
{
	assert(NULL != buffer);
	
	free(buffer);
	buffer = NULL;
}

/******************************* CBUFF-READ ***********************************/

size_t CbuffRead(c_buff_ty *buffer, void *dest, size_t n_bytes)
{
	size_t n_bytes_copy = 0;
	size_t free_space_arr = 0;
	
	assert(NULL != buffer);
	assert(NULL != dest);
	
	free_space_arr = buffer->capacity - buffer->read_idx;

	if( n_bytes > buffer->size)
	{
		n_bytes = buffer->size;	
	}
	
	n_bytes_copy = n_bytes;
	
	if(n_bytes > free_space_arr)
	{
		memcpy(dest ,&buffer->c_buff_arr[buffer->read_idx], free_space_arr);		
		buffer->read_idx = 0;
		n_bytes_copy -= free_space_arr; 
		dest += free_space_arr;
	}
			
		memcpy(dest ,&buffer->c_buff_arr[buffer->read_idx], n_bytes_copy);		
		buffer->size -= n_bytes;
		buffer->read_idx += n_bytes;

	return n_bytes;
}

/******************************* CBUFF-WRITE **********************************/

size_t CbuffWrite(c_buff_ty *buffer, void *src, size_t n_bytes)
{
	size_t n_bytes_copy = 0;
	size_t free_space_arr = 0;
	
	assert(NULL != buffer);
	assert(NULL != src);
	
	free_space_arr = buffer->capacity - (buffer->read_idx + buffer->size);
	
	if(n_bytes > CbuffFreeSpace(buffer))
	{
		n_bytes = CbuffFreeSpace(buffer);
	}
	
	n_bytes_copy = n_bytes;
	
	if(n_bytes > free_space_arr)
	{

		memcpy(&buffer->c_buff_arr[(buffer->read_idx + buffer->size)], src, free_space_arr);		
		buffer->size += free_space_arr;
		n_bytes_copy -= free_space_arr; 
		src += free_space_arr;
	}		
		memcpy(&buffer->c_buff_arr[(buffer->read_idx + buffer->size)%buffer->capacity], src, n_bytes_copy);		
		buffer->size += n_bytes_copy;

	return n_bytes;
}

/**************************** CBUFF-CAPACITY **********************************/

size_t CbuffSize(const c_buff_ty *buffer)
{
	assert(NULL != buffer);
	
	return buffer->capacity;
}


/**************************** CBUFF-ISEMPTY ***********************************/

status_ty CbuffIsEmpty(const c_buff_ty *buffer)
{
	assert(NULL != buffer);
	
	return !buffer->size;
}

/**************************** CBUFF-FREESPACE *********************************/

size_t CbuffFreeSpace(const c_buff_ty *buffer)
{
	assert(NULL != buffer);
	
	return (buffer->capacity - buffer->size);
}





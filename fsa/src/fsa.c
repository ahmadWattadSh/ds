/*Name: AhmadWattad
  Project: Work Sheet 11 - Data Structures - FSA
  Reviewer: Idan
  Date: 23/08/2023
  Version: 1.0: published the program

  Overview: Implementation of an FSA Manager. */
  		
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "fsa.h"

#define WORDSIZE sizeof(void *)

  
/******************************* Definitions **********************************/

struct fsa
{
	size_t next_available;
};

/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/

size_t FSA_SuggestedSize(size_t size_of_block, size_t num_of_blocks)
{
	size_t mask  = WORDSIZE - 1;
	size_t sum_of_bytes = 0;
	
	assert(0 != block_size);
   	assert(0 != num_of_blocks);	

	size_of_block = (size_of_block + mask) & (~mask);
	sum_of_bytes = size_of_block * num_of_blocks + sizeof(fsa_t);		
	
	return sum_of_bytes;
}
	
/******************************************************************************/
fsa_t *FSA_Init(void *pool, size_t size_of_block, size_t size_of_pool)
{
	size_t mask  = WORDSIZE - 1;	
	size_t curr_size = 0;
	fsa_t *fsa = NULL;
	char *starting_block = NULL;
	int num_of_blocks = 0;

	
	assert( 0 == ((size_t)pool & mask));
	assert(NULL != pool);		
	assert(0 != size_of_block);

	fsa = (fsa_t*)pool;
	fsa->next_available = sizeof(fsa_t);
	
	size_of_block = size_of_block + (WORDSIZE - (size_of_block %  WORDSIZE));
	curr_size = size_of_block + sizeof(fsa_t);
	num_of_blocks = (size_of_pool - sizeof(fsa_t)) / size_of_block; 	
	starting_block = (char *)pool + sizeof(fsa_t);
	
	while( 0 != num_of_blocks)
	{
		*starting_block = curr_size;
		curr_size += size_of_block;
		starting_block = starting_block + size_of_block ;			
		--num_of_blocks;
	}
	
	/*for last input - invalid*/
	*(starting_block - size_of_block) = 0;
	
	return fsa;
}


/******************************************************************************/
void *FSA_Alloc(fsa_t *fsa)
{
	char* saved_address = NULL;

	assert(NULL != fsa);
		
	if(fsa->next_available == 0)
	{
		return NULL;
	}
	
	saved_address = ((char*)fsa + fsa->next_available);
	fsa->next_available = *((char*)fsa + fsa->next_available);

	return (void*)saved_address;
}

/******************************************************************************/
void FSA_Free(fsa_t *fsa, void *block_to_free)
{
	size_t next_next_avail = 0;
	size_t curr = 0;
	
	assert(NULL != fsa);
	assert(NULL != block_to_free);	
	
	curr = fsa->next_available;
	fsa->next_available = (size_t)(char*)block_to_free - (size_t)(char*)fsa;
	*(size_t *)block_to_free = curr;	
}

/******************************************************************************/
size_t FSA_CountFree(const fsa_t *fsa)
{
	char* add_to_start = NULL;
	size_t counter = 0;
	
	assert(NULL != fsa);
	
	add_to_start = (char*)fsa ;
	
	while (0 != *(size_t*)add_to_start)
	{
		++counter;
		add_to_start = (char*)fsa + add_to_start->next_available;
	}

	return counter;
}



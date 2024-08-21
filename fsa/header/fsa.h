/******************************************************************************/
/*
  Name: Idan Nave
  Project: FSA
  Reviewer: HRD32
  Date: 07/09/23
  Version: 1.0
  
  Overview: Implementation of an FSA Manager.
*/

#ifndef __ILRD_FSA_H__
#define __ILRD_FSA_H__

/******************************** Libraries  **********************************/

#include <stddef.h>         /*size_t*/

/******************************** Definitions *********************************/

typedef struct fsa fsa_t;

/**************************** FSA API Declarations ****************************/

/* Function that suggests the size of the memory pool for a desired 
    number of blocks and block size.
   Arguments:   'size_of_block' - Size of each block.
                'num_of_blocks' - Desired number of blocks.
   Return value: Suggested size of the memory pool for the given parameters.
   Complexity: O(1).
   Undefined Behavior: None. */
size_t FSA_SuggestedSize(size_t size_of_block, size_t num_of_blocks);

/* Function that initializes an FSA (Fixed-Size Allocator).
   
   Arguments:    'pool' - Pointer to the memory pool used by the FSA-
                          allocated by user. should be aligned to system word.
                 'size_of_block' - Size of each block in the pool.
                 'size_of_pool' - Total size of the memory pool.
                                  should supply the return value of FSA_SuggestedSize ().
   Return value: Pointer to the newly initialized FSA. On error, returns NULL.
   Complexity: O(n), where 'n' is the number of blocks in the pool.
   Undefined Behavior: NULL pointer to FSA or zero 'size_of_block' or 'size_of_pool'. */
fsa_t *FSA_Init(void *pool, size_t size_of_block, size_t size_of_pool);


/* Function that allocates a block from the FSA.
   
   Arguments:   'fsa' - FSA pointer.
   Return value: Pointer to the allocated block. On Error- Returns NULL.
   Complexity: O(1).
   Undefined Behavior: NULL pointer to FSA or invalid 'fsa'. */
void *FSA_Alloc(fsa_t *fsa);

/* Function that deallocates a block and returns it to the FSA.
   Arguments:    'fsa' - FSA pointer.
                 'block_to_free' - Pointer to the block to be freed.
   Return value: None.
   Complexity: O(1).
   Undefined Behavior: NULL pointer to FSA, invalid 'fsa', or 'block_to_free' not allocated by the FSA. */
void FSA_Free(fsa_t *fsa, void *block_to_free);

/* Function that retrieves the number of available (free) blocks in the FSA.
   Arguments:   'fsa' - FSA pointer.
   Return value: Number of available (free) blocks in the FSA.
   Complexity: O(1).
   Undefined Behavior: NULL pointer to FSA or invalid 'fsa'. */
size_t FSA_CountFree(const fsa_t *fsa);

#endif /* __FSA_H__ */

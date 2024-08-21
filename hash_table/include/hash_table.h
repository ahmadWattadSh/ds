/******************************************************************************/
/*
  Name: Ahmad Wattad
  Project: Hash Table
  Reviewer: Aya
  Date: 12/12/23
  Version: 1.0
  
  Overview: Implementation of a Hash Table data structure.
*/

#ifndef __ILRD_HASH_TABLE_H__
#define __ILRD_HASH_TABLE_H__

/******************************** Libraries  **********************************/

#include <stddef.h> /*size_t*/

/******************************** Definitions  ******************************/

typedef struct hash hash_ty;

/*
typedef enum  {SUCCESS = 0, FAILURE} status_t;
typedef enum {FALSE = 0, TRUE} boolean_t;
*/
typedef int (*action_func_ty)(void* data, void* param);
typedef int (*match_func_ty)(const void* list_data, void* params);
typedef size_t (*hash_func_ty)(const void* data, void *params);

/*********************** H-Table API Declerations  ****************************/

/*
  Description: Function that creates a new Hash Table.
  Arguments: 'hash_func' - call bask function.
             'params' - params to be passed to 'hash_func'.
             'match_func' - call bask function.
             'capacity' - capacity of the Hash Table.
  Return value: Pointer to a new Hash Table. Returns NULL on failure.
  Complexity: O(1). 
  Undefined B.: capacity 0.
*/
hash_ty* HTableCreate(hash_func_ty hash_func, void* params, size_t capacity, match_func_ty match_func);

/*
  Description: Function that destroys a Hash Table and releases its memory.
  Arguments: 'hash' - Pointer to the Hash Table to be destroyed.
  Return value: None.
  Complexity: O(n). 
  Undefined B.: 'hash' is NULL. 
*/
void HTableDestroy(hash_ty *hash);

/*
  Description: Function that returns the number of elements in the Hash Table.
  Arguments: 'hash' - Pointer to the hash.
  Return value: Number of elements in the hash.
  Complexity: O(n * m).
  Undefined B.: 'hash' is NULL.
*/
size_t HTableSize(const hash_ty *hash);

/*
  Description: Function that checks whether the Hash Table is empty.
  Arguments: 'hash' - Pointer to the hash.
  Return value: Returns TRUE if the hash is empty, FALSE otherwise.
  Complexity: O(n).
  Undefined B.: 'hash' is NULL.
*/
int HTableIsEmpty(const hash_ty *hash);

/*
  Description: Function that inserts a new element to the Hash Table.
  Arguments: 'hash' - Pointer to the hash.
             'data' - Data to be stored in the new element.
  Return value: Returns TRUE if it success, FALSE otherwise.
  Complexity: O(1).
  Undefined B.: 'hash' is NULL.
*/
int HTableInsert(hash_ty *hash, void* data);

/*
  Description: Function that removes the element of the given data from the
                Hash Table.
  Arguments: 'hash' - Pointer to the hash.
             'data' - Data to be removed.
  Return value:  Returns TRUE if it exists, FALSE otherwise.
  Complexity: O(1).
  Undefined B.: 'hash' is NULL.
*/
int HTableRemove(hash_ty *hash, void* data);

/* 
  Description: Function that searches for data in the Hash Table.
  Arguments: 'hash' - Pointer to the hash.
             'data' - data to be passed to 'match_func'.
  Return value: the first found element in the Hash Table.
                Returns NULL if the element is not found.
  Complexity: O(n).
  Undefined B.: 'hash' is NULL.
*/
void* HTableFind
(const hash_ty *hash, void* data);

/* 
 Description: Function that performes the specified action_func for each 
                element in the Hash Table.
 Arguments: 'hash' - Pointer to the hash.
            'action_func' - call back function.
            'params' - params to be passed to 'action_func'.
 Return value: Returns SUCCESS if it success, otherwise FAILURE.
 Complexity: O(n) * complexity of action func.
 Undefined B.: 'hash' is NULL.
*/
int HTableForEach
(hash_ty *hash, action_func_ty action_func, void* params);

/******************************************************************************/

#endif /*(__ILRD_HASH_TABLE_H__)*/

/*
  Name: Ahmad Wattad
  Project: BST
  Reviewer: Aya
  Date: 27/09/23

  Overview: Implementation of an BINARY SEARCH TREE Manager.
  */
  		
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "hash_table.h"
#include "dll.h"


struct hash
{
	hash_func_ty hash_func;
	match_func_ty match_func;
	void *params;
	size_t capacity;
	dll_ty **table;
};


/******************************* Definitions **********************************/


/**************************** Forwarded funcs *********************************/
static int ActionFuncSize(void* data, void* param);
/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/

hash_ty* HTableCreate(hash_func_ty hash_func, void* params, size_t capacity, match_func_ty match_func)
{
	/*allocate*/
	hash_ty *table = (hash_ty *)malloc(sizeof(hash_ty));

	/*hanlde errs*/
	if(NULL  == table)
	{
		return NULL;
	}			

	table->table = calloc(capacity, sizeof(dll_ty*));

	if(NULL  == table->table)
	{
		HTableDestroy(table);
		return NULL;
	}
		
	/*assign the input from the user*/
	table->hash_func = hash_func;
	table->match_func = match_func;
	table->params = params;
	table->capacity = capacity;

	return 	table;		
}

void HTableDestroy(hash_ty *hash)
{
	size_t i = 0;
	
	/*if null return*/
	if (NULL == hash)
	{
		return ;
	}
	
	/*for each one of the linkedlist if found, destroy it*/
	for (i = 0; i < hash->capacity; ++i)
	{
		if (NULL != hash->table[i])		
		{
			DListDestroy(hash->table[i]);
		}	
	}

	/*free the table*/
	free(hash->table);
	free(hash);
}

int HTableInsert(hash_ty *hash, void* data)
{
	size_t index = 0;
	dll_iter_ty iter= 0;
	
	/*assert*/
	assert(NULL != hash);
	
	/*get index*/
	index = hash->hash_func(data, hash->params);
	index = index % hash->capacity ;
	assert(index < hash->capacity);
	/*if there is no list create it*/
	if (NULL == hash->table[index])
	{
		hash->table[index] = DListCreate();
		
		if (NULL  == hash->table[index])
		{
			return FALSE;
		}
	}
	
	/*insert in the linkedlist*/
	iter = DListInsertBefore(DListEnd(hash->table[index]), data, hash->table[index]);

	/*check the insert*/
	if(DListIsSameIter(DListEnd(hash->table[index]), iter))
	{
		return FALSE;
	}
	
	return TRUE;
}

int HTableRemove(hash_ty *hash, void* data)
{
	/*TODO: SAME code, another function if all works*/
	dll_iter_ty iter_to_find = 0;
	dll_iter_ty begin = 0;	
	dll_iter_ty end = 0;
	size_t index = 0;
		
	assert(NULL != hash);
	
	index = hash->hash_func(data, hash->params);
	index = index % hash->capacity ;	
	assert(index < hash->capacity);
	
	if (NULL == hash->table[index])
	{
		return FALSE;
	}
	
	begin = DListBegin(hash->table[index]);
	end = DListEnd(hash->table[index]);
	
	iter_to_find = DListFind(begin, end, hash->match_func, data);

	/*check the find*/
	if(DListIsSameIter(DListEnd(hash->table[index]), iter_to_find))
	{
		return FALSE;
	}
	
	DListRemove(iter_to_find);
	
	if(DListIsEmpty(hash->table[index]))
	{
		DListDestroy(hash->table[index]);	
		hash->table[index] = NULL;
	}
	
	return TRUE;
	
}

size_t HTableSize(const hash_ty *hash)
{	
	size_t size = 0;
	size_t i = 0;

	assert(NULL != hash);
	
	HTableForEach((hash_ty *)hash, ActionFuncSize, &size);		

	return size;
}

static int ActionFuncSize(void* data, void* param)
{
	int *int_ptr = NULL;
	
	assert(NULL != param);

	int_ptr = (int *)param;
	
	data;
	++*int_ptr;
	
	return SUCCESS;
}

int HTableIsEmpty(const hash_ty *hash)
{
	size_t size = 0;
	size_t i = 0;
	
	assert(NULL != hash);
		
	for (i = 0; i < hash->capacity; ++i)
	{
		if (NULL != hash->table[i])		
		{
			return FALSE;
		}	
	}

	return TRUE;
}

void* HTableFind(const hash_ty *hash, void* data)
{
	dll_iter_ty iter_to_find = 0;
	dll_iter_ty begin = 0;	
	dll_iter_ty end = 0;
	size_t index = 0;	
	assert(NULL != hash);
	
	index = hash->hash_func(data, hash->params);
	index = index % hash->capacity ;
	
	assert(index < hash->capacity);
	
	if (NULL == hash->table[index])
	{
		return NULL;
	}
	
	begin = DListBegin(hash->table[index]);
	end = DListEnd(hash->table[index]);
	
	iter_to_find = DListFind(begin, end, hash->match_func, data);

	/*check the find*/
	if(DListIsSameIter(DListEnd(hash->table[index]), iter_to_find))
	{
		return NULL;
	}
	
	return DListGetData(iter_to_find);
}


int HTableForEach(hash_ty *hash, action_func_ty action_func, void* params)
{
	size_t size = 0;
	size_t i = 0;	
	dll_iter_ty begin = 0;	
	dll_iter_ty end = 0;
	int res = 0 ;
		
	assert(NULL != hash);
	assert(NULL != action_func);	
		
	for (i = 0; i < hash->capacity; ++i)
	{
		if (NULL != hash->table[i])		
		{
			begin = DListBegin(hash->table[i]);
			end = DListEnd(hash->table[i]);	
			res = DListForEach(begin, end, action_func, params);
			if (FAILURE == res)
			{	
				return FAILURE;	
			}
		}	
	}

	return SUCCESS;
}















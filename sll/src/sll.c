/*Name: AhmadWattad
  Project: Work Sheet 6 - Data Structures - Singly Linked LIst
  Reviewer: Sahar
  Date: 31/07/2023
  Version: 1.0: published the program
 	   1.1: apply modifications without malloc
 	   1.2: prepare the prog for reviewing
 	   1.3 reviewed and changed accordingly
  		*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "sll.h"



/**************************** Global variables ********************************/

struct node
{
	void *data;
	node_ty *next;
};

struct sll 
{
	iter_ty head;
	iter_ty tail;
};

/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/

/**************************** Slist CREATE ************************************/

sll_ty* SListCreate()
{	
	sll_ty *list_init = (sll_ty *)malloc(sizeof(sll_ty));
	node_ty *dummy_node = NULL;

	if(NULL == list_init)
	{
		return (sll_ty*)0;
	}
	
	dummy_node = (node_ty*)malloc(sizeof(node_ty));
	
	if(NULL == dummy_node)
	{
		free(list_init);
		return (sll_ty*)0;
	}
	
	dummy_node->next = NULL;
	dummy_node->data = list_init;
	
	list_init->tail.node_ptr = dummy_node;		
	list_init->head.node_ptr = dummy_node;

	return list_init;
}

/**************************** Slist INSERT ************************************/

iter_ty SListInsertBefore(iter_ty iter, void* data)
{
	iter_ty new_iter = {0};
	node_ty *new_node = (node_ty*)malloc(sizeof(node_ty));
	
	if(NULL == new_node)
	{
		return;
	}
	
	new_iter.node_ptr = new_node;
	new_iter.node_ptr->next = iter.node_ptr->next;/*dummy*/
	new_iter.node_ptr->data = iter.node_ptr->data;
	
	iter.node_ptr->data = data;	
	iter.node_ptr->next = new_iter.node_ptr;
	

	if(NULL == new_iter.node_ptr->next)
	{
		((sll_ty*)new_iter.node_ptr->data)->tail = new_iter;
	}
	
	return iter;
}

/**************************** SLIST REMOVE ***********************************/

iter_ty SListRemove(iter_ty iter)
{
	if(NULL == iter.node_ptr->next)
	{
		return iter;
	}
	
	node_ty *tmp_next = iter.node_ptr->next;
	iter.node_ptr->data = iter.node_ptr->next->data;
	iter.node_ptr->next = iter.node_ptr->next->next;
	free(tmp_next);
	tmp_next = NULL;
	 
	if(NULL == iter.node_ptr->next)
	{
		((sll_ty*)iter.node_ptr->data)->tail = iter;
	}
	
	return	iter; 
}

/**************************** SLIST DESTROY ***********************************/

void SListDestroy(sll_ty *list)
{
	iter_ty iter = {0};
	iter_ty iter_tmp = {0};
	
	assert(NULL != list);
	
	iter = SListBegin(list);
	
	while (iter.node_ptr != SListEnd(list).node_ptr)
	{
		iter_tmp = iter ;
		iter = SListNext(iter);
		free(iter_tmp.node_ptr);	
		iter_tmp.node_ptr = NULL;	

	}
	
	free(iter.node_ptr);	
	iter.node_ptr = NULL;
	free(list);
	list = NULL;
}

/**************************** SLIST ISEMPTY ***********************************/

int SListIsEmpty(sll_ty *list)
{
	assert(NULL != list);
	
	if(list->head.node_ptr == list->tail.node_ptr)
	{
		return EMPTY;
	}
	
	return NOT_EMPTY;

}

/***************************** SLIST COUNT ************************************/

size_t SListCount(sll_ty *list)
{
	size_t count = 0;

	assert(NULL != list);
		
	iter_ty iter =  SListBegin(list);
	
	while (NULL != iter.node_ptr->next)
	{
		++count;
		iter = SListNext(iter);
	}
	
	return count;
}

/****************************** SLIST FIND ************************************/

iter_ty SListFind(iter_ty from_iter, iter_ty to_iter, 
	void* data, MatchFunc_ty match_func, void* usr_param)
{	
	iter_ty iter = from_iter;
	
	while (iter.node_ptr != to_iter.node_ptr)
	{
		if(MATCHED == match_func(iter.node_ptr->data, data))		
		{
			return iter;
		}
		iter = SListNext(iter);
	}
		
	return iter;
}

/**************************** SLIST FOREACH ***********************************/

int SListForEach(iter_ty from_iter, iter_ty to_iter, 
	ActionFunc_ty action_func, void* usr_param)
{
	iter_ty iter = from_iter;
	
	while (iter.node_ptr != to_iter.node_ptr)
	{
		if(SUCCESS != action_func(iter.node_ptr->data, usr_param))		
		{
			return FAILURE;
		}
	
		iter = SListNext(iter);
	}
	
	return 	SUCCESS;	
}

/****************************** SLIST GET *************************************/

void* SListGetData(iter_ty iter)
{
	return iter.node_ptr->data;
}


/****************************** SLIST SET *************************************/

void SListSetData(iter_ty iter, void* data)
{
	iter.node_ptr->data = data;
}

/***************************** ITER FUNCS *************************************/
iter_ty SListBegin(sll_ty *list)
{
	assert(NULL != list);
	
	return list->head;
}

iter_ty SListEnd(sll_ty *list)
{
	assert(NULL != list);
	
	return list->tail;
}

iter_ty SListNext(iter_ty iter)
{
	iter.node_ptr = iter.node_ptr->next;
	return  iter;
}

int SListIterIsEqual(iter_ty iter1, iter_ty iter2)
{
	if(iter1.node_ptr == iter2.node_ptr)
	{
		return MATCHED;
	}
		return NOT_MATCHED;
}





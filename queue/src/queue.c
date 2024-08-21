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
#include "queue.h"

/**************************** Global variables ********************************/

struct queue
{
    sll_ty* slist;
};

/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/

/**************************** Slist CREATE ************************************/

queue_ty* QueueCreate()
{
	queue_ty *queue_init = (queue_ty*)malloc(sizeof(queue_ty));
	
	if((queue_ty*)0 == queue_init)
	{
		return (queue_ty*)0;
	}
	
	queue_init->slist =  SListCreate();
	
	if((queue_ty*)0 == queue_init->slist)
	{
		return (queue_ty*)0;
	}

	
	return queue_init;
}

/**************************** Slist INSERT ************************************/

void QueueDestroy(queue_ty *queue)
{
	assert(NULL != queue);
	
	SListDestroy(queue->slist);
	free(queue);
}

size_t QueueGetSize(const queue_ty *queue)
{
	assert(NULL != queue);
	
	return SListCount(queue->slist);
}


int QueueIsEmpty(queue_ty *queue)
{
	assert(NULL != queue);
	
	return SListIsEmpty(queue->slist);
}

int Enqueue(queue_ty *queue, void* data)
{
	assert(NULL != queue);
	assert(NULL != data);
		
	iter_ty iter = SListInsertBefore(SListEnd(queue->slist), data);
	
	if(NULL == iter.node_ptr)
	{
		return FAILURE;
	}
	
	return SUCCESS;
}

int Dequeue(queue_ty *queue)
{
	assert(NULL != queue);
	
	iter_ty iter = 	SListRemove(SListBegin(queue->slist));
	
	if(NULL == iter.node_ptr)
	{
		return FAILURE;
	}
	
	return SUCCESS;
}


void *QueuePeek(const queue_ty *queue)
{
	assert(NULL != queue);
	
	return SListGetData(SListBegin(queue->slist));	
}

void QueueAppend(queue_ty *dest, queue_ty *src)
{
	assert(NULL != dest);
	assert(NULL != src);
	
	iter_ty tail_iter = {0};
	iter_ty end_dest = SListEnd(dest->slist);
	iter_ty first_src = SListBegin(src->slist);
	
	Merge(end_dest, first_src);
	SListRemove(end_dest);
	tail_iter = SListEnd(dest->slist);
	tail_iter.node_ptr = SListEnd(src->slist).node_ptr;
					
	free(src->slist);
	free(src);
}



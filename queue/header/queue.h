/******************************** ws7_Q.h  *******************************/
/*
  Name: HRD 32
  Project: Work Sheet 7 - Data Structures - Queue
  Reviewer: Liel
  Date: 16/08/23
  Version: 1.0
*/

#ifndef __QUEUE_H__
#define __QUEUE_H__

/******************************** Libraries  *******************************/

#include <stddef.h> /*size_t*/

/******************************** Definitions  ******************************/

typedef struct queue queue_ty;

/*********************** Queue API Declerations  ****************************/

/*Function that inits the Queue struct
  Return value: pointer of type queue_ty, if unsuccessful malloc(), returns NULL;
  Undefined B.: N.A */
queue_ty* QueueCreate();

/*Function that destroys the Queue struct
  Arguments: Queue pointer
  Return value: N.A
  Undefined B.: NULL queue_ty ptr */
void QueueDestroy(queue_ty *queue);

/*Function that returns queue nodes count
  Arguments: Queue ptr
  Return value: node count
  Undefined B.: NULL queue_ty ptr */
size_t QueueGetSize(const queue_ty *queue);

/*Function that checks whether the queue is empty
  Arguments: Queue ptr
  Return value: EMPTY = 1, NOT_EMPTY = 0
  Undefined B.: NULL queue_ty ptr */
int QueueIsEmpty(queue_ty *queue);

/*Function that appends a node to the rear of the queue.
  Arguments: queue_ty pointer, Data
  Return value: SUCCESS = 1, FAILURE = 0
  Undefined B.: NULL queue_ty pointer */
int Enqueue(queue_ty *queue, void* data);

/*Function that removes the front node from the queue
  Arguments: queue_ty pointer
  Return value: SUCCESS = 1, FAILURE = 0
  Undefined B.: NULL queue_ty pointer */
int Dequeue(queue_ty *queue);

/*Function that retrieves the front node's value
  Arguments: queue_ty pointer 
  Return value: void* data
  Undefined B.: NULL queue_ty pointer */
void *QueuePeek(const queue_ty *queue);

/*Function that appends all elements from src queue, in order, and appends 
 * them to the end of dest queue. The src queue is left empty.
  Arguments: 2 queues
  Return value: apended queue
  Undefined B.: NULL queue pointers */
void QueueAppend(queue_ty *dest, queue_ty *src);

#endif /*(__QUEUE_H__)*/


























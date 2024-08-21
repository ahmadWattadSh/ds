/*Name: AhmadWattad
  Project: Work Sheet 6 - Data Structures - Singly Linked LIst
  Reviewer: Sahar
  Date: 14/08/2023
  Version: 1.0
*/


/******************************************************************************/
#include <stdio.h>/*printf*/

#include "queue.h"
#include "sll.h"
/****************************main test function *******************************/

void TestProgram();

/*********************************** main *************************************/

int main()
{
	TestProgram();
	return 0;
}

/******************************************************************************/

void TestProgram()
{
	int x1 = 1;
	int x2 = 2;
	int x3 = 3;
	int x4 = 4;
	int x11 = 10;
	int x22 = 11;
	int x33 = 12;
	 
	queue_ty *queue = QueueCreate();
	queue_ty *queue2 = QueueCreate();
	
	if(NULL == queue)
	{
		printf("TestCreate didin't pass\n");
	}
	else
	{
	
		printf("TestCreate passed\n");	
	}
	
	/**********************************************/
	
	if(SUCCESS == QueueIsEmpty(queue))
	{
		printf("The queue is empty. Test passed\n");
	}
	else
	{
		printf("IsEmptyTest failed\n");	
	}
	
	/**********************************************/
	

	if(0 == QueueGetSize(queue))
	{
		printf("size is 0. Test passed\n");
	}
	else
	{
		printf("SizeTest failed\n");	
	}
	
	/***********************************************/
	
	Enqueue(queue, &x1);
	Enqueue(queue, &x2);	
	Enqueue(queue, &x3);
	Enqueue(queue, &x4);
	
	if(4 == QueueGetSize(queue))
	{
		printf("EnqueueTest passed\n");
	}
	else
	{
		printf("EnqueueTest failed\n");	
	}		
	/***********************************************/	
	
	if(1 == *(int*)QueuePeek(queue))
	{
		printf("PeekTest passed\n");
	}
	else
	{
		printf("PeekTest failed\n");	
	}
	/***********************************************/	
	
	Dequeue(queue);
	Dequeue(queue);
	
	if(3 == *(int*)QueuePeek(queue))
	{
		printf("PeekTest passed\n");
	}
	else
	{
		printf("PeekTest failed\n");	
	}
	
	if(2 == QueueGetSize(queue))
	{
		printf("DeQueueTest passed\n");
	}
	else
	{
		printf("DeQueueTest failed\n");	
	}
	/***********************************************/	
	
	Enqueue(queue, &x11);	
	Enqueue(queue, &x22);
	Enqueue(queue, &x33);
	
	
	QueueAppend(queue, queue2);
	

	if(5 == QueueGetSize(queue))
	{
		printf("appendTest passed\n");
	}
	else
	{
		printf("appendTest failed\n");	
	}
	
	QueueDestroy(queue);

	
	
}
/******************************************************************************/	



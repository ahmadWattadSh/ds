/*Name: AhmadWattad
  Project: Work Sheet 12 - Data Structures - SL
  Reviewer: Idan
  Date: 23/08/2023
  Version: 1.0
*/


/******************************************************************************/
#include <stdio.h>/*printf*/

#include "heap.h"
#include "vector.h"

#define ErrorMsg(expected, result, name) \
	{\
		if (expected == result)\
		{\
			printf("%s has succeeded\n",  name);\
		}\
		else\
		{\
			printf("%s has failed\n",  name);\
		}\
}

/************************** Forwarded declarations ****************************/

static void UnitTesting();
static void CreateTest();
static void SizeTest();
static void IsEmptyTest();
static void PeekTest();
static void EnqueueTest();
static void DequeueTest();
static void EraseTest();
static void ClearTest();
static int IsMatchTest(const void *data1 , void *data2);



/*********************************** main *************************************/

int main()
{
	UnitTesting();

	return 0;
}

/******************************************************************************/

static void UnitTesting()
{
	CreateTest();
	SizeTest();
	IsEmptyTest();
	PeekTest();
	EnqueueTest();
	DequeueTest();
	ClearTest();
	EraseTest();
}
/******************************************************************************/	

typedef struct data_priority
{
	int data;
	int priority;
}data_priority_ty;

static int CompareFunc(const void *data, void *data2 )
{	
	return ((data_priority_ty*)data2)->priority - ((data_priority_ty*)data)->priority ;
}

static int IsMatch(const void *num1_ptr, void *num2_ptr )
{
	if(*(int*)num1_ptr > 10)
	{
		return TRUE;
	}
	else
	{
	
		return FALSE;
	}
	
}

static void CreateTest()
{

	pq_t *list = PQCreate(CompareFunc);
	
	ErrorMsg(0 , PQSize(list), "CreateTest");
	
	PQDestroy(list);
}


static void SizeTest()
{
	int x = 8;
	int y = 10;
	data_priority_ty data1 = {.data = 10, .priority = 2};
	data_priority_ty data2 ={.data = 3, .priority = 1};
	
	pq_t *list = PQCreate(CompareFunc);
	
	PQEnqueue(list, &data1);
	PQEnqueue(list, &data2);	
	
	ErrorMsg(2 , PQSize(list), "SizeTest");
	
	PQDestroy(list);
}


static void IsEmptyTest()
{

	int x = 8;
	int y = 10;
	data_priority_ty data1 = {.data = 10, .priority = 2};
	data_priority_ty data2 ={.data = 3, .priority = 1};
	
	pq_t *list = PQCreate(CompareFunc);
	
	PQEnqueue(list, &data1);
	PQEnqueue(list, &data2);	
	
	ErrorMsg(FALSE , PQIsEmpty(list), "IsEmptyTest");
	
	PQDestroy(list);
}

static void PeekTest()
{
	int x = 8;
	int y = 10;
	
	int data_res = 0;
	
	data_priority_ty data1 = {.data = 10, .priority = 2};
	data_priority_ty data2 ={.data = 3, .priority = 1};
	data_priority_ty data3 ={.data = 7, .priority = 3};	
	
	pq_t *list = PQCreate(CompareFunc);
	
	PQEnqueue(list, &data1);
	PQEnqueue(list, &data2);
	PQEnqueue(list, &data3);
		
	data_res = ((data_priority_ty*)PQPeak(list))->data;
	
	ErrorMsg(3 , data_res, "PeekTest");
	
	PQDestroy(list);
}


static void EnqueueTest()
{
	int x = 8;
	int y = 10;
	
	int data_res = 0;
	
	data_priority_ty data1 = {.data = 10, .priority = 2};
	data_priority_ty data2 ={.data = 3, .priority = 1};
	data_priority_ty data3 ={.data = 7, .priority = 3};	
	
	pq_t *list = PQCreate(CompareFunc);
	
	PQEnqueue(list, &data1);
	
	data_res = ((data_priority_ty*)PQPeak(list))->data;
	
	if(10 != data_res)
	{
		ErrorMsg(10 , data_res, "EnqueueTest");	 
	}

	PQEnqueue(list, &data2);
	
	data_res = ((data_priority_ty*)PQPeak(list))->data;
	
	if(3 != data_res)
	{
		ErrorMsg(3 , data_res, "EnqueueTest");	 
	}
	
	PQEnqueue(list, &data3);
	
	data_res = ((data_priority_ty*)PQPeak(list))->data;	
	
	ErrorMsg(3 , data_res, "EnqueueTest");
	
	PQDestroy(list);
}

static void DequeueTest()
{
	int x = 8;
	int y = 10;
	
	int data_res = 0;
	
	data_priority_ty data1 = {.data = 10, .priority = 2};
	data_priority_ty data2 ={.data = 3, .priority = 1};
	data_priority_ty data3 ={.data = 7, .priority = 3};	
	
	pq_t *list = PQCreate(CompareFunc);
	
	PQEnqueue(list, &data1);
	PQEnqueue(list, &data2);
	PQEnqueue(list, &data3);
	
	data_res = ((data_priority_ty*)PQDequeue(list))->data;
	
	if(3 != data_res)
	{
		ErrorMsg(3 , data_res, "DequeueTest");	 
	}

	data_res = ((data_priority_ty*)PQPeak(list))->data;	
	
	ErrorMsg(10 , data_res, "DequeueTest");
	
	PQDestroy(list);
}

static void ClearTest()
{	
	data_priority_ty data1 = {.data = 10, .priority = 2};
	data_priority_ty data2 ={.data = 3, .priority = 1};
	data_priority_ty data3 ={.data = 7, .priority = 3};	
	
	pq_t *list = PQCreate(CompareFunc);
	
	PQEnqueue(list, &data1);
	PQEnqueue(list, &data2);
	PQEnqueue(list, &data3);
	
	PQClear(list);
	
	ErrorMsg(TRUE , PQIsEmpty(list), "ClearTest");
	
	PQDestroy(list);
}

static void EraseTest()
{
	int x = 7;
	int data_res = 0;
	data_priority_ty data1 = {.data = 10, .priority = 2};
	data_priority_ty data2 ={.data = 3, .priority = 1};
	data_priority_ty data3 ={.data = 7, .priority = 3};	
	
	pq_t *list = PQCreate(CompareFunc);
	
	PQEnqueue(list, &data1);
	PQEnqueue(list, &data2);
	PQEnqueue(list, &data3);

	PQErase(list, &x, IsMatchTest);
	
	if(3 != data_res)
	{
		ErrorMsg(2 , PQSize(list), "PQErase1");	
	
	}
	
	data_res = ((data_priority_ty*)PQDequeue(list))->data;
	
	ErrorMsg(1 , PQSize(list), "PQErase2");
	
	PQDestroy(list);
}


static int IsMatchTest(const void *data1 , void *data2)
{
	if(((data_priority_ty*)data1)->data == ((data_priority_ty*)data2)->data)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}







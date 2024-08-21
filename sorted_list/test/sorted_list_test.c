/*Name: AhmadWattad
  Project: Work Sheet 12 - Data Structures - SL
  Reviewer: Idan
  Date: 23/08/2023
  Version: 1.0
*/


/******************************************************************************/
#include <stdio.h>/*printf*/

#include "sorted_list.h"


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
static void GetDataTest();
static void InsertTest();
static void RemoveTest();
static void PopFrontTest();
static void PopBackTest();
static void ListFindTest();
static int CounterFunc(void* data, void* param);
static void ForEachTest();
static void FindIFTest();
static void MergeLists();
static int CompareFunc(const void *num1_ptr, void *num2_ptr );
static int IsMatch(const void *num1_ptr, void *num2_ptr );
static MatchFunc(void *data, void *param);

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
	GetDataTest();
	InsertTest();
	RemoveTest();
	PopFrontTest();
	PopBackTest();
	ListFindTest();
	ForEachTest();
	FindIFTest();
	MergeLists();
}
/******************************************************************************/	

static int CompareFunc(const void *num1_ptr, void *num2_ptr )
{	
	return *(int*)num2_ptr - *(int*)num1_ptr ;
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

	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	
	ErrorMsg(0 , SortedListSize(sorted_list), "CreateTest");
	
	SortedListDestroy(sorted_list);
}

static void SizeTest()
{
	int x = 8;
	int y = 10;
	
	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	
	SortedListInsert( sorted_list, &x);
	SortedListInsert( sorted_list, &y);


	ErrorMsg(2 , SortedListSize(sorted_list), "SizeTest");
	
	SortedListDestroy(sorted_list);
}

static void IsEmptyTest()
{

	int x = 8;
	int y = 10;
	
	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	
	SortedListInsert( sorted_list, &x);
	SortedListInsert( sorted_list, &y);

	ErrorMsg(FALSE, SortedListIsEmpty(sorted_list), "IsEmptyTest");
	
	SortedListDestroy(sorted_list);
}

static void GetDataTest()
{
	int x = 8;
	int y = 10;
	
	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	
	SortedListInsert( sorted_list, &x);
	SortedListInsert( sorted_list, &y);

	ErrorMsg(8, *(int*)SortedListGetData(SortedListBegin(sorted_list)), "GetDataTest");
	
	SortedListDestroy(sorted_list);
}


static void InsertTest()
{
	int x = 8;
	int y = 10;
	int z = 5;
	
	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	
	SortedListInsert( sorted_list, &x);
	SortedListInsert( sorted_list, &y);
	
	ErrorMsg(8, *(int*)SortedListGetData(SortedListBegin(sorted_list)), "InsertBeforeTest_HeadInsert");
	
	SortedListInsert( sorted_list, &z);
	
	ErrorMsg(10, *(int*)SortedListGetData(SortedListPrev(SortedListEnd(sorted_list))), "InsertBeforeTest_TailInsert");
	
	SortedListDestroy(sorted_list);
}

static void RemoveTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	
	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	
	SortedListInsert( sorted_list, &x);
	SortedListInsert( sorted_list, &y);
	
	SortedListRemove(SortedListBegin(sorted_list));

	ErrorMsg(10, *(int*)SortedListGetData(SortedListBegin(sorted_list)), "RemoveBeforeTest_Head");
	
	SortedListInsert( sorted_list, &x);
	SortedListInsert( sorted_list, &y);
	
	SortedListRemove(SortedListPrev(SortedListEnd(sorted_list)));
	
	ErrorMsg(10, *(int*)SortedListGetData(SortedListPrev(SortedListEnd(sorted_list))), "RemoveBeforeTest_Tail");
	
	SortedListDestroy(sorted_list);
}

static void PopFrontTest()
{
	int x = 8;
	int y = 10;

	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	
	SortedListInsert( sorted_list, &x);
	SortedListInsert( sorted_list, &y);
	
	SortedListPopFront(sorted_list);

	ErrorMsg(10, *(int*)SortedListGetData(SortedListBegin(sorted_list)), "PopFrontTest");
	
	SortedListDestroy(sorted_list);
}

static void PopBackTest()
{
	int x = 8;
	int y = 10;

	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	
	SortedListInsert( sorted_list, &x);
	SortedListInsert( sorted_list, &y);
	
	SortedListPopBack(sorted_list);

	ErrorMsg(8, *(int*)SortedListGetData(SortedListPrev(SortedListEnd(sorted_list))), "PopBackTest");
	
	SortedListDestroy(sorted_list);
}


static void ListFindTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	int m = 30;
	int n = 40;
	
	sorted_list_iter_t iter_from = {0};
	sorted_list_iter_t iter_to = {0};
	sorted_list_iter_t iter_res = {0};
	
	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	
	SortedListInsert( sorted_list, &x);
	iter_from = SortedListInsert( sorted_list, &y);
	SortedListInsert( sorted_list, &z);
	SortedListInsert( sorted_list, &m);
	iter_to = SortedListInsert( sorted_list, &n);

	iter_res = SortedListFind(iter_from, iter_to, &z, sorted_list);

	ErrorMsg(20, *(int*)SortedListGetData(iter_res), "ListFindTest1");
	
	iter_res = SortedListFind(iter_from, iter_to, &x, sorted_list);
	
	ErrorMsg(40 , *(int*)SortedListGetData(iter_res), "ListFindTest2");
	
	SortedListDestroy(sorted_list);
}

static int CounterFunc(void* data, void* param)
{
	int *int_ptr = NULL;

	int_ptr = param;
	
	data;
	++*int_ptr;
	
	return 0;
}


static void ForEachTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	int m = 30;
	int n = 40;
	
	sorted_list_iter_t iter_from = {0};
	sorted_list_iter_t iter_to = {0};
	size_t counter = 0;
	
	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	
	SortedListInsert( sorted_list, &x);
	iter_from = SortedListInsert( sorted_list, &y);
	SortedListInsert( sorted_list, &z);
	SortedListInsert( sorted_list, &m);
	iter_to = SortedListInsert( sorted_list, &n);
	
	SortedListForEach(iter_from, iter_to, CounterFunc, &counter);

	ErrorMsg(3, counter, "ForEachTest");	

	SortedListDestroy(sorted_list);
}

static void FindIFTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	int m = 30;
	int n = 40;
	
	sorted_list_iter_t iter_from = {0};
	sorted_list_iter_t iter_to = {0};
	sorted_list_iter_t iter_res = {0};
	
	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	
	SortedListInsert( sorted_list, &x);
	iter_from = SortedListInsert( sorted_list, &y);
	SortedListInsert( sorted_list, &z);
	SortedListInsert( sorted_list, &m);
	iter_to = SortedListInsert( sorted_list, &n);
	
	iter_res = SortedListFindIF(iter_from, iter_to, IsMatch, &x);

	ErrorMsg(20, *(int*)SortedListGetData(iter_res), "FindIFTest");	

	SortedListDestroy(sorted_list);
}


static void MergeLists()
{
	int x1 = 8;
	int x2 = 10;
	int x3 = 20;
	int x4 = 30;
	int x5 = 40;
	
	int y1 = 7;
	int y2 = 25;
	int y3 = 28;
	int y5 = 17;	
	
	int arr[10] = {7,8,10,17,20,25,28,30,40};
	int res = 0 ;
	
	sorted_list_t *sorted_list = SortedListCreate(CompareFunc);
	sorted_list_t *sorted_list2 = SortedListCreate(CompareFunc);
	size_t result = 0;
	
	SortedListInsert( sorted_list, &x1);
	SortedListInsert( sorted_list, &x2);
	SortedListInsert( sorted_list, &x3);
	SortedListInsert( sorted_list, &x4);
	SortedListInsert( sorted_list, &x5);
	
	SortedListInsert( sorted_list2, &y1);
	SortedListInsert( sorted_list2, &y2);
	SortedListInsert( sorted_list2, &y3);

	SortedListInsert( sorted_list2, &y5);
	
	SortedListMerge(sorted_list, sorted_list2);

	result = SortedListForEach(SortedListBegin(sorted_list), SortedListEnd(sorted_list), MatchFunc, arr);
	
	ErrorMsg(1, result, "MergeLists");

	SortedListDestroy(sorted_list);
	SortedListDestroy(sorted_list2);	
}

static MatchFunc(void *data, void *param)
{
	static int size = 0;
	
	if(*(int *)data == *(int *)param)
	{
		++size;
		return TRUE;
	}
	
	++size;
	return FALSE;
}








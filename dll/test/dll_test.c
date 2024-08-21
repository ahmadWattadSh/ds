/*Name: AhmadWattad
  Project: Work Sheet 6 - Data Structures - Singly Linked LIst
  Reviewer: Idan
  Date: 23/08/2023
  Version: 1.0
*/


/******************************************************************************/
#include <stdio.h>/*printf*/

#include "dll.h"

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
static void SetDataTest();
static void InsertBeforeTest();
static void RemoveTest();
static void PushFrontTest();
static void PushBackTest();
static void PopFrontTest();
static void PopBackTest();
static void ListFindTest();
static int MatchFuncTest(const void *list_data, void *params);
static void ForEachTest();
static void MultiFindTest();
static void ListSplice();

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
	SetDataTest();
	InsertBeforeTest();
	RemoveTest();
	PushFrontTest();
	PushBackTest();
	PopFrontTest();
	PopBackTest();
	ListFindTest();
	ForEachTest();
	MultiFindTest();
	ListSplice();
}
/******************************************************************************/	


static void CreateTest()
{

	dll_ty *dll = DListCreate();
	
	ErrorMsg(0 , DListSize(dll), "CreateTest");
	
	DListDestroy(dll);
}

static void SizeTest()
{
	int x = 8;
	int y = 10;
	
	dll_ty *dll = DListCreate();
	
	DListInsertBefore( DListBegin(dll), &x, dll);
	DListInsertBefore( DListBegin(dll), &y, dll);

	ErrorMsg(2 , DListSize(dll), "SizeTest");
	
	DListDestroy(dll);
}

static void IsEmptyTest()
{

	int x = 8;
	int y = 10;
	
	dll_ty *dll = DListCreate();
	
	DListInsertBefore( DListBegin(dll), &x, dll);
	DListInsertBefore( DListBegin(dll), &y, dll);

	ErrorMsg( FALSE, DListIsEmpty(dll), "IsEmptyTest");
	
	DListDestroy(dll);
}

static void GetDataTest()
{
	int x = 8;
	int y = 10;
	
	dll_ty *dll = DListCreate();
	
	DListInsertBefore( DListBegin(dll), &x, dll);
	DListInsertBefore( DListBegin(dll), &y, dll);

	ErrorMsg(10, *(int*)DListGetData(DListBegin(dll)), "GetDataTest");
	
	DListDestroy(dll);
}


static void SetDataTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	dll_ty *dll = DListCreate();
	
	DListInsertBefore( DListBegin(dll), &x, dll);
	DListInsertBefore( DListBegin(dll), &y, dll);
	DListSetData((dll_iter_ty)DListBegin(dll), &z);
	
	ErrorMsg(20, *(int*)DListGetData(DListBegin(dll)), "SetDataTest");
	
	DListDestroy(dll);
}



static void InsertBeforeTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	dll_ty *dll = DListCreate();
	
	DListInsertBefore( DListBegin(dll), &x, dll);
	DListInsertBefore( DListBegin(dll), &y, dll);

	ErrorMsg(10, *(int*)DListGetData(DListBegin(dll)), "InsertBeforeTest_HeadInsert");
	
	DListInsertBefore( DListEnd(dll), &z, dll);
	
	ErrorMsg(20, *(int*)DListGetData(DListPrev(DListEnd(dll))), "InsertBeforeTest_TailInsert");
	
	DListDestroy(dll);
}

static void RemoveTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	dll_ty *dll = DListCreate();
	
	DListInsertBefore( DListBegin(dll), &x, dll);
	DListInsertBefore( DListBegin(dll), &y, dll);
	
	DListRemove(DListBegin(dll));

	ErrorMsg(8, *(int*)DListGetData(DListBegin(dll)), "RemoveTest_Head");
	
	DListInsertBefore( DListBegin(dll), &y, dll);
	DListInsertBefore( DListBegin(dll), &z, dll);
	
	DListRemove(DListPrev(DListEnd(dll)));
	
	ErrorMsg(10, *(int*)DListGetData(DListPrev(DListEnd(dll))), "RemoveTest_Before_Tail");
	
	DListDestroy(dll);
}

static void PushFrontTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	dll_ty *dll = DListCreate();
	dll_iter_ty iter = NULL;
	
	DListPushFront( dll, &x);
	DListPushFront( dll, &y);
	iter = DListPushFront( dll, &z);

	ErrorMsg(20, *(int*)DListGetData(iter), "PushFrontTest1");
	ErrorMsg(20, *(int*)DListGetData(DListBegin(dll)), "PushFrontTest2");
	DListDestroy(dll);
}

static void PushBackTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	dll_ty *dll = DListCreate();
	dll_iter_ty iter = NULL;
	
	DListPushBack( dll, &x);
	DListPushBack( dll, &y);
	iter = DListPushBack( dll, &z);

	ErrorMsg(20, *(int*)DListGetData(iter), "PushBackTest1");
	ErrorMsg(8, *(int*)DListGetData(DListBegin(dll)), "PushFrontTest2");
	
	DListDestroy(dll);
}

static void PopFrontTest()
{
	int x = 8;
	int y = 10;

	dll_ty *dll = DListCreate();
	
	DListInsertBefore( DListBegin(dll), &x, dll);
	DListInsertBefore( DListBegin(dll), &y, dll);
	
	DListPopFront(dll);

	ErrorMsg(8, *(int*)DListGetData(DListBegin(dll)), "PopFrontTest");
	
	DListDestroy(dll);
}

static void PopBackTest()
{
	int x = 8;
	int y = 10;

	dll_ty *dll = DListCreate();
	
	DListInsertBefore( DListBegin(dll), &x, dll);
	DListInsertBefore( DListBegin(dll), &y, dll);
	DListInsertBefore( DListBegin(dll), &y, dll);
	
	DListPopBack(dll);

	ErrorMsg(10, *(int*)DListGetData(DListBegin(dll)), "PopBackTest");
	
	DListDestroy(dll);
}


dll_iter_ty DListFind
(dll_iter_ty from, dll_iter_ty to, match_action_ty match_func, void* params);

static void ListFindTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	int m = 30;
	int n = 40;
	dll_iter_ty iter_from = NULL;
	dll_iter_ty iter_to = NULL;
	dll_iter_ty iter_res = NULL;
	
	dll_ty *dll = DListCreate();
	
	DListInsertBefore( DListBegin(dll), &x, dll);
	iter_to = DListInsertBefore( DListBegin(dll), &y, dll);
	DListInsertBefore( DListBegin(dll), &z, dll);
	DListInsertBefore( DListBegin(dll), &m, dll);
	iter_from = DListInsertBefore( DListBegin(dll), &n, dll);

	iter_res = DListFind(iter_from, iter_to, &MatchFuncTest, &z);

	ErrorMsg(20, *(int*)DListGetData(iter_res), "ListFindTest1");
	
	iter_res = DListFind(iter_from, iter_to, &MatchFuncTest, &x);
	
	ErrorMsg(10, *(int*)DListGetData(iter_res), "ListFindTest2");
	DListDestroy(dll);
}

static int MatchFuncTest(const void *list_data, void *params)
{
	if(*(int*)list_data == *(int*)params)
	{
		return 1;
	}
		return 0;
}

static void ForEachTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	int m = 30;
	int n = 40;
	
	dll_ty *dll = DListCreate();
	
	DListInsertBefore( DListBegin(dll), &x, dll);
	DListInsertBefore( DListBegin(dll), &y, dll);
	DListInsertBefore( DListBegin(dll), &z, dll);
	DListInsertBefore( DListBegin(dll), &m, dll);
	DListInsertBefore( DListBegin(dll), &n, dll);

	ErrorMsg(5, DListSize(dll), "ForEachTest");	

	DListDestroy(dll);
}

static void MultiFindTest()
{
	int x = 8;
	int y = 10;
	int z = 20;
	int m = 10;
	int n = 10;
	int f = 11; 
	
	dll_iter_ty iter_from = NULL;
	dll_iter_ty iter_to = NULL;
	size_t result = 0;
	
	dll_ty *dll = DListCreate();
	dll_ty *dll_res = DListCreate();
	dll_ty *dll_res2 = DListCreate();
	
	DListInsertBefore( DListEnd(dll), &x, dll);
	iter_from = DListInsertBefore( DListEnd(dll), &y, dll);
	DListInsertBefore( DListEnd(dll), &z, dll);
	DListInsertBefore( DListEnd(dll), &m, dll);
	DListInsertBefore( DListEnd(dll), &n, dll);
	iter_to = DListInsertBefore( DListEnd(dll), &f, dll);
	
	DListMultiFind(iter_from, iter_to, &MatchFuncTest, &y, dll_res);

	ErrorMsg(3, DListSize(dll_res), "MultiFindTest1");
	
	result = DListMultiFind(iter_from, iter_to, &MatchFuncTest, &x, dll_res2);
	
	ErrorMsg(1, result, "MultiFindTest2");
	
	DListDestroy(dll);
	DListDestroy(dll_res);
	DListDestroy(dll_res2);
}


static void ListSplice()
{
	int x = 8;
	int y = 10;
	int z = 20;
	int m = 30;
	int n = 40;
	int f = 50;
	int s = 60;
	
	dll_iter_ty iter_from = NULL;
	dll_iter_ty iter_to = NULL;
	dll_iter_ty where_iter = NULL;	
	dll_iter_ty iter_tmp = NULL;
	
	dll_ty *dll = DListCreate();
	
	DListInsertBefore( DListEnd(dll), &x, dll);
	iter_from = DListInsertBefore( DListEnd(dll), &y, dll);
	DListInsertBefore( DListEnd(dll), &z, dll);
	iter_to = DListInsertBefore( DListEnd(dll), &m, dll);
	DListInsertBefore( DListEnd(dll), &n, dll);
	where_iter = DListInsertBefore( DListEnd(dll), &f, dll);
	DListInsertBefore( DListEnd(dll), &s, dll);
	
	DListSplice(iter_from, iter_to, where_iter);

	ErrorMsg(30, *(int*)DListGetData(DListNext(DListBegin(dll))), "ListSpliceTest1");

	iter_tmp = DListNext(DListBegin(dll));
	
	ErrorMsg(10, *(int*)DListGetData(DListNext(DListNext(iter_tmp))), "ListSpliceTest2");

	DListDestroy(dll);
}








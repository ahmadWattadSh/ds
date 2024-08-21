/*Name: AhmadWattad
  Project: Work Sheet 6 - Data Structures - Singly Linked LIst
  Reviewer: Sahar
  Date: 14/08/2023
  Version: 1.0
*/
/******************************************************************************/
#include <stdio.h>/*printf*/

#include "sll.h"

/****************************main test function *******************************/

void TestProgram();

/*****************************user functions***********************************/

static int PrintInt(void* data, void* param);

static int MatchFunc(const void* data, void* param);

/*********************************** main *************************************/

int main()
{
	TestProgram();
	return 0;
}

/******************************************************************************/

void TestProgram()
{
	sll_ty *my_list = NULL;
	sll_ty *list_ptr = NULL;
	iter_ty my_iter = {0};
	iter_ty iter_2 = {0};
	iter_ty find_iter = {0};
	int d = 54321;
	int x = 5;
	int p = 4;
	int y = 5;
	int z = 1;
	int res = 0;
	
/******************************************************************************/	
	my_list = SListCreate();
	if(NULL != my_list)
	{
		printf("The function SListCreate() passed the test \n");
	}
	else
	{
		printf("The function SListCreate() didn't passed the test \n");
	}
	
/******************************************************************************/

	my_iter = SListBegin(my_list);
	SListInsertBefore(my_iter,&x);
	
	if(*(int*)SListGetData(my_iter) == x)
	{
		printf("The function SListBegin() passed the test \n");
		printf("The function SListGetData() passed the test \n");
	}
	else
	{
		printf("The function SListBegin() didn't passed the test \n");
		printf("The function SListGetData() didn't passed the test \n");
	}
	
/******************************************************************************/
	
	SListInsertBefore(my_iter,&y);
	
	if(*(float*)SListGetData(my_iter) == y)
	{
		printf("The function SListInsertBefore() passed the test \n");
	}
	else
	{
		printf("The function SListInsertBefore() didn't passed the test \n");
	}
	
/******************************************************************************/
	
	my_iter = SListNext(my_iter);
	
	if(*(int*)SListGetData(my_iter) == x)
	{
		printf("The function SListNext() passed the test \n");
	}
	else
	{
		printf("The function SListNext() didn't passed the test \n");
	}
	
/******************************************************************************/
	
	/* list - y(5.8) , x(5)*/
	my_iter = SListBegin(my_list);
	/*now i try to go to the end*/
	my_iter = SListEnd(my_list);
	/* at the end we insert the d list - y(5.8) , x(5) , d(54321)*/
	SListInsertBefore(my_iter,&d);
	
	/*now we check if the value at the end as d*/
	if(*(double*)SListGetData(my_iter) == d)
	{
		printf("The function SListEnd() passed the test \n");
	}
	else
	{
		printf("The function SListEnd() didn't passed the test \n");
	}
	
/******************************************************************************/

	/*move my_iter to the end*/
	my_iter = SListNext(my_iter);
	/*move iter_2 to the end*/
	iter_2 = SListEnd(my_list);
	
	if(SListIterIsEqual(my_iter, iter_2))
	{
		printf("The function SListIterIsEqual() passed the test \n");
	}
	else
	{
		printf("The function SListIterIsEqual() didn't passed the test \n");
	}
	
/******************************************************************************/

	my_iter = SListBegin(my_list);
	SListSetData(my_iter, &z);
	
	if(*(int*)SListGetData(my_iter) == z)
	{
		printf("The function SListSetData() passed the test \n");
	}
	else
	{
		printf("The function SListSetData() didn't passed the test \n");
	}

/******************************************************************************/

	SListRemove(my_iter);
	if(*(int*)SListGetData(my_iter) == x)
	{
		printf("The function SListRemove() passed the test \n");
	}
	else
	{
		printf("The function SListRemove() didn't passed the test \n");
	}

/******************************************************************************/

	if(SListCount(my_list) == 2)
	{
		printf("The function SListCount() passed the test \n");
	}
	else
	{
		printf("The function SListCount() didn't passed the test \n");
	}

/******************************************************************************/
	
	if(SListIsEmpty(my_list) == NOT_EMPTY)
	{
		printf("The function SListIsEmpty() passed the test \n");
	}
	else
	{
		printf("The function SListIsEmpty() didn't passed the test \n");
	}
	 
/******************************************************************************/
		
	find_iter = SListFind(SListBegin(my_list), SListEnd(my_list), &x,
	 &MatchFunc, &p);
	printf("find: %d\n", *(int*)SListGetData(find_iter));
	
	res = SListForEach(SListBegin(my_list), SListEnd(my_list), &PrintInt, &p);
	if(SUCCESS == res)
	{
		printf("The function SListForEach() passed the test \n");
	}
	else
	{
		printf("The function SListForEach() didn't passed the test \n");
	}
	
	SListDestroy(my_list);	
	
}

/******************************************************************************/

static int PrintInt(void* data, void* param)
{
	printf("%d\n",*(int*)data);
	return SUCCESS;
}

/******************************************************************************/

static int MatchFunc(const void* data, void* param)
{
	if(data == param)
	{	
		return SUCCESS;
	}
	return FAILURE;
}

/******************************************************************************/	



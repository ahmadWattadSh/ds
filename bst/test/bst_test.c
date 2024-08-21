/*
  Name: Ahmad Wattad
  Project: BST
  Reviewer: ??
  Date: 27/09/23
*/


/******************************************************************************/
#include <stdio.h>/*printf*/
#include <stdlib.h> /*	malloc	*/
#include <stdio.h> 

#include "bst.h"

#define ErrorMsgEqual(expected, result, name) \
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
#define ErrorMsgNotEqual(expected, result, name, res) \
	{\
		if (expected != result)\
		{\
			printf("%s has succeeded\n",  name);\
		}\
		else\
		{\
			printf("%s has failed\n",  name);\
			res = 1;\
		}\
}
#define ErrorMsgBiggerThan(expected, result, name, res) \
	{\
		if (expected <= result)\
		{\
			printf("%s has succeeded\n",  name);\
		}\
		else\
		{\
			printf("%s has failed\n",  name);\
			res = 1;\
		}\
}

/************************** Forwarded declarations ****************************/

static void UnitTesting();
static int CompareFunc(void *num1_ptr, void *num2_ptr, void *params );
static void CreateTest();
static void InsertTest();
static void BeginTest();
static void EndTest();
static void NextTest();
static void PrevTest();
static void Size_ForEachTest();
static void RemoveTest();
static void FindTest();
static int PrintFunc(void *data, void *params);
static void ForEachPrintFunc(bst_ty *bst);
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
	InsertTest();
	BeginTest();
	EndTest();
	NextTest();
	PrevTest();
	Size_ForEachTest();
	RemoveTest();
	FindTest();
}
/******************************************************************************/	

static int CompareFunc(void *num1_ptr, void *num2_ptr, void *params )
{	
	return *(int*)num2_ptr - *(int*)num1_ptr ;
}

static void CreateTest()
{
	int x = 20;
	
	bst_ty *bst = BSTCreate(CompareFunc, &x);
	
	ErrorMsgEqual(BSTIsEmpty(bst), TRUE, "CreateTest");
	
	BSTDestroy(bst);
}

static void InsertTest()
{
	int x = 20;
	
	int num1 = 100;
	int num2 = 80;
	int num3 = 110;
	int num4 = 85;
	int num5 = 115;
					
	bst_ty *bst = BSTCreate(CompareFunc, &x);
	
	bst_iter_ty iter = BSTInsert(bst, &num1);
	ErrorMsgEqual(*(int*)BSTGetData(iter), 100, "InsertTest1");
	
	iter = BSTInsert(bst, &num2);
	ErrorMsgEqual(*(int*)BSTGetData(iter), 80, "InsertTest2");	
	
	iter = BSTInsert(bst, &num3);		
	ErrorMsgEqual(*(int*)BSTGetData(iter), 110, "InsertTest3");	
	
	ForEachPrintFunc(bst);		

	BSTDestroy(bst);

}

static void BeginTest()
{
	int x = 20;
	
	int num1 = 100;
	int num2 = 80;
	int num3 = 110;
	int num4 = 70;
	int num5 = 115;
					
	bst_ty *bst = BSTCreate(CompareFunc, &x);

	bst_iter_ty iter = BSTInsert(bst, &num1);	
	iter = BSTInsert(bst, &num2);	
	iter = BSTInsert(bst, &num3);		
	iter = BSTInsert(bst, &num4);		
	iter = BSTInsert(bst, &num5);			

	ErrorMsgEqual(*(int*)BSTGetData(BSTBegin(bst)), 70, "BeginTest");	
		
	BSTDestroy(bst);
}

static void EndTest()
{
	int x = 20;
	
	int num1 = 100;
	int num2 = 80;
	int num3 = 110;
	int num4 = 85;
	int num5 = 115;
					
	bst_ty *bst = BSTCreate(CompareFunc, &x);
	
	bst_iter_ty iter = BSTInsert(bst, &num1);
	iter = BSTInsert(bst, &num2);
	iter = BSTInsert(bst, &num3);		

	ErrorMsgEqual(BSTGetData(BSTEnd(bst)), NULL, "EndTest");	
			
	BSTDestroy(bst);
}


static void NextTest()
{
	int x = 20;
	
	int num1 = 100;
	int num2 = 80;
	int num3 = 110;
	int num4 = 70;
	int num5 = 115;
					
	bst_ty *bst = BSTCreate(CompareFunc, &x);
	
	bst_iter_ty iter = BSTInsert(bst, &num1);	
	iter = BSTInsert(bst, &num2);	
	iter = BSTInsert(bst, &num3);		
	iter = BSTInsert(bst, &num4);		
	iter = BSTInsert(bst, &num5);			
	iter = BSTBegin(bst);
	iter = BSTNext(iter);
	ErrorMsgEqual(*(int*)BSTGetData(iter), 80, "NextTest1");	
	iter = BSTNext(iter);	
	ErrorMsgEqual(*(int*)BSTGetData(iter), 100, "NextTest2");
	iter = BSTNext(iter);	
	ErrorMsgEqual(*(int*)BSTGetData(iter), 110, "NextTest3");	
	iter = BSTNext(iter);
	ErrorMsgEqual(*(int*)BSTGetData(iter), 115, "NextTest4");
	iter = BSTNext(iter);
	ErrorMsgEqual(BSTGetData(iter), NULL, "NextTest5");	
						
	BSTDestroy(bst);
}


static void PrevTest()
{
	int x = 20;
	
	int num1 = 100;
	int num2 = 80;
	int num3 = 110;
	int num4 = 70;
	int num5 = 115;
					
	bst_ty *bst = BSTCreate(CompareFunc, &x);
	
	bst_iter_ty iter = BSTInsert(bst, &num1);	
	iter = BSTInsert(bst, &num2);	
	iter = BSTInsert(bst, &num3);		
	iter = BSTInsert(bst, &num4);		
	iter = BSTInsert(bst, &num5);			
	iter = BSTEnd(bst);
	iter = BSTPrev(iter);
	ErrorMsgEqual(*(int*)BSTGetData(iter), 115, "PrevTest1");	
	iter = BSTPrev(iter);
	ErrorMsgEqual(*(int*)BSTGetData(iter), 110, "PrevTest2");
	iter = BSTPrev(iter);
	ErrorMsgEqual(*(int*)BSTGetData(iter), 100, "PrevTest3");	
	iter = BSTPrev(iter);
	ErrorMsgEqual(*(int*)BSTGetData(iter), 80, "PrevTest4");	
	iter = BSTPrev(iter);	
	ErrorMsgEqual(*(int*)BSTGetData(iter), 70, "PrevTest5");										
	BSTDestroy(bst);
}

static void Size_ForEachTest()
{
	int x = 20;
	
	int num1 = 100;
	int num2 = 80;
	int num3 = 110;
	int num4 = 70;
	int num5 = 115;
					
	bst_ty *bst = BSTCreate(CompareFunc, &x);
	
	ErrorMsgEqual(BSTSize(bst), 0, "Size_ForEachTest1");
	
	bst_iter_ty iter = BSTInsert(bst, &num1);	
	iter = BSTInsert(bst, &num2);	
	iter = BSTInsert(bst, &num3);		
	iter = BSTInsert(bst, &num4);		
	iter = BSTInsert(bst, &num5);			

	ErrorMsgEqual(BSTSize(bst), 5, "Size_ForEachTest2");
										
	BSTDestroy(bst);
}

static void FindTest()
{

	int x = 20;
	int num1 = 100;
	int num2 = 80;
	int num3 = 110;
	int num4 = 70;
	int num5 = 115;
	int num6 = 75 ;
	int num7 = 60;
	int num8 = 77; 									
	int not_find = 50;	 									
	bst_ty *bst = BSTCreate(CompareFunc, &x);
	
	BSTInsert(bst, &num1);	
	BSTInsert(bst, &num2);	
	BSTInsert(bst, &num3);		
	BSTInsert(bst, &num4);		
	BSTInsert(bst, &num5);	
	BSTInsert(bst, &num6);			
	BSTInsert(bst, &num7);			
	BSTInsert(bst, &num8);								

	ErrorMsgEqual(*(int*)BSTGetData(BSTFind(bst, &num8)), 77, "FindTest1");
	ErrorMsgEqual(BSTGetData(BSTFind(bst, &not_find)), BSTGetData(BSTEnd(bst)) , "FindTest2");
											
	BSTDestroy(bst);
}

static void RemoveTest()
{
	int x = 20;
	
	int num1 = 100;
	int num2 = 80;
	int num3 = 110;
	int num4 = 70;
	int num5 = 115;
	int num6 = 110;
	int num7 = 120;	
	int num8 = 113;	
	int num9 = 107;								
	bst_ty *bst = BSTCreate(CompareFunc, &x);
	bst_iter_ty iter2 = 0;

	
	bst_iter_ty iter = BSTInsert(bst, &num1);	
	iter = BSTInsert(bst, &num2);	
	BSTRemove(iter) ;
	ErrorMsgEqual(BSTSize(bst), 1, "RemoveTest1");
	
	iter = BSTInsert(bst, &num3);		
	BSTInsert(bst, &num4);		
	iter2 =BSTInsert(bst, &num5);			
	BSTRemove(iter) ;
	
	ErrorMsgEqual(BSTSize(bst), 3, "RemoveTest2");		

	BSTInsert(bst, &num6);		
	BSTInsert(bst, &num7);
	BSTInsert(bst, &num8);		
	BSTInsert(bst, &num9);	
	BSTRemove(iter2) ;
	ErrorMsgEqual(BSTSize(bst), 6, "RemoveTest3");		
												
	BSTDestroy(bst);
}

static void ForEachPrintFunc(bst_ty *bst)
{
	
	bst_iter_ty begin = BSTBegin(bst);
	bst_iter_ty end = BSTEnd(bst);
	
	BSTForEach(begin, end, PrintFunc, NULL);

}

static int PrintFunc(void *data, void *params)
{
	static i = 0;
	printf("data%d : %d\n", i,*(int*)data);
	
	++i;
	
	return 0;
}



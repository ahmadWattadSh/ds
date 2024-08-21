/*Name: AhmadWattad
  Project: Work Sheet 6 - Data Structures - Singly Linked LIst
  Reviewer: Sahar
  Date: 14/08/2023
  Version: 1.0
*/


/******************************************************************************/
#include <stdio.h>/*printf*/

#include "c_buff.h"

/****************************main test function *******************************/

void TestProgram1();
void TestProgram2();

/*********************************** main *************************************/

int main()
{
	TestProgram1();
	TestProgram2();
	return 0;
}

/******************************************************************************/

void TestProgram1()
{
	int x1 = 1;
	int x2 = 2;
	int x3 = 3;
	int x4 = 4;
	char arr[11] = {0};
	int  i = 0;
	
	c_buff_ty *c_buff = CbuffCreate(10);
	
	printf("\nTEST1: \n\n");
	/************************ CbuffCReate **************************/
	
	if(NULL == c_buff)
	{
		printf("TestCreate didin't pass\n");
	}
	else
	{
	
		printf("TestCreate passed\n");	
	}

	/************************ CbuffIsEmpty **************************/
	
	if(1 == CbuffIsEmpty(c_buff))
	{
		printf("The c_buff is empty. Test passed\n");
	}
	else
	{
		printf("IsEmptyTest failed\n");	
	}

	/************************ bufsize **************************/
		
	if(10 == CbuffSize(c_buff))
	{
		printf("CapacityTest passed\n");
	}
	else
	{
		printf("CapacityTest failed\n");	
	}
	
	/************************ write testing **************************/
	
	if(4 == CbuffWrite(c_buff, &x1, 4))
	{
		printf("WriteTest1 passed\n");
	}
	else
	{
		printf("WriteTest1 failed\n");	
	}
	
	
	if(4 == CbuffWrite(c_buff, &x2, 4))
	{
		printf("WriteTest2 passed\n");
	}
	else
	{
		printf("WriteTest2 failed\n");	
	}
	
	if(2 == CbuffWrite(c_buff, &x3, 4))
	{
		printf("WriteTest3 passed\n");
	}
	else
	{
		printf("WriteTest3 failed\n");	
	}
	
	if(0 == CbuffWrite(c_buff, &x3, 4))
	{
		printf("WriteTest4 passed\n");
	}
	else
	{
		printf("WriteTest4 failed\n");	
	}
	
	/************************ read testing **************************/
	
	if(10 == CbuffRead(c_buff, arr, 10))
	{

		printf("ReadTest1 passed\n");
	}
	else
	{
		printf("ReadTest1 failed\n");	
	}
	
	if(0 == CbuffRead(c_buff, arr, 10))
	{

		printf("ReadTest2 passed\n");
	}
	else
	{
		printf("ReadTest2 failed\n");	
	}
	
	CbuffDestroy(c_buff);
}
/******************************************************************************/	


void TestProgram2()
{
	int x1 = 1;
	int x2 = 2;
	int x3 = 3;
	int x4 = 4;
	char arr[11] = {0};
	char arr2[10] = {0};
	int  i = 0;
	char res_arr[11]={1,0,0,0,2,0,2,3,0,0,'\0'};
	
	c_buff_ty *c_buff = CbuffCreate(10);
	
	printf("\nTEST2: \n\n");
	
	/************************ CbuffCReate **************************/
	
	if(NULL == c_buff)
	{
		printf("TestCreate didin't pass\n");
	}
	else
	{
	
		printf("TestCreate passed\n");	
	}

	/************************ CbuffIsEmpty **************************/
	
	if(1 == CbuffIsEmpty(c_buff))
	{
		printf("The c_buff is empty. Test passed\n");
	}
	else
	{
		printf("IsEmptyTest failed\n");	
	}

	/************************ bufsize **************************/
		
	if(10 == CbuffSize(c_buff))
	{
		printf("CapacityTest passed\n");
	}
	else
	{
		printf("CapacityTest failed\n\n\n");	
	}
	
	/************************ complex testing **************************/
	
	CbuffWrite(c_buff, &x1, 4);
	CbuffRead(c_buff, arr, 4);
	
	CbuffWrite(c_buff, &x2, 2);
	CbuffWrite(c_buff, &x2, 2);
	CbuffRead(c_buff, &arr[4], 3);	
	CbuffRead(c_buff, arr2, 5);
		
	CbuffWrite(c_buff, &x3, 4);
	CbuffRead(c_buff, &arr[7], 3);	
	arr[10] = '\0'; 

	if(0 == strcmp(arr, res_arr))
	{
		printf("ComplexTest passed\n");	
	}
	else
	{
		printf("ComplexTest hasn't passed\n");	
	}

	CbuffDestroy(c_buff);	
}


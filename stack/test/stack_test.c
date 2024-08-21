/*Name: AhmadWattad
  Project: Worksheet11
  Reviewer: Agbaria
  Date: 31/07/2023
  Version: 1.0: published the program
 	   1.1: apply modifications without malloc
 	   1.2: prepare the prog for reviewing
 	   1.3 reviewed and changed accordingly
  		*/
  		
#include <stdio.h>/*printf()*/
#include <string.h> /*memcpy*/

#include "stack.h"

struct stack
{
	size_t capacity;
	size_t size;
	size_t element_size;
	char *stack_arr;
};

typedef struct struct_for_test_ty
{
	char ch;
	int num;
	int num2;
	double num3;
}struct_for_test_ty;

void TestProgram();
/********************************* main ***************************************/

int main()
{

	TestProgram();
	return 0;
}

/******************************************************************************/



void TestProgram()
{	

	stack_ty *example3 = StackCreate((size_t)200 , (size_t)4);
	
	int x1 = 1;
	int x2 = 2;
	int x3 = 3;
	int x4 = 4;
	
	StackPush(example3, (void*)&x1);
	StackPush(example3, (void*)&x2);
	StackPush(example3, (void*)&x3);
	StackPush(example3, (void*)&x4);	
	
	int peeked = *(int*)StackPeek(example3);
	printf("value4 = %d\n", peeked);
	StackPop(example3);
	StackPop(example3);
	
	int peeked2 = *(int*)StackPeek(example3);
	printf("value2 = %ld\n", StackSize(example3));
	printf("size = %d\n", peeked2);
	
	StackDestroy(example3);
	
	stack_ty *example2 = StackCreate((size_t)200 , (size_t)8);
	
	double x11 = 1;
	double x22 = 2;
	double x33 = 3;
	double x44 = 4;
	
	StackPush(example2, (void*)&x11);
	StackPush(example2, (void*)&x22);
	StackPush(example2, (void*)&x33);
	StackPush(example2, (void*)&x44);	
	
	double peeked3 = *(double*)StackPeek(example2);
	printf("\nvalue4 = %d\n", peeked);
	StackPop(example2);
	StackPop(example2);
	
	double peeked4 = *(double*)StackPeek(example2);
	printf("value2 = %ld\n", StackSize(example2));
	printf("size = %d\n\n\n", peeked2);
	
	StackDestroy(example2);
	
	
	
	
	stack_ty *example = StackCreate((size_t)200 , sizeof(struct_for_test_ty));

	struct_for_test_ty struct_for_test1 = {.ch ='a', .num =99, .num2=225, .num3 =11212};
	struct_for_test_ty struct_for_test2 = {.ch ='b', .num =991, .num2=221, .num3 =241212};
	struct_for_test_ty struct_for_test3 = {.ch ='c', .num =992, .num2=222, .num3 =361212};	
	struct_for_test_ty struct_for_test4 = {.ch ='d', .num =92, .num2=224, .num3 =61212};
		
	StackPush(example, (void*)&struct_for_test1);
	StackPush(example, (void*)&struct_for_test2);
	StackPush(example, (void*)&struct_for_test3);
	StackPush(example, (void*)&struct_for_test4);
	
	struct_for_test_ty *struct_for_test5 = (struct_for_test_ty*)StackPeek(example);
	if(0 == memcmp(struct_for_test5, &struct_for_test4, sizeof(struct_for_test_ty)))
	{
	printf("pushing test succeeded\n");
	}
	else
	{
	printf("pushing test failed\n");
	}

	if(0 == StackIsEmpty(example))
	{
	printf("TRUE, IT IS EMPTY\n");	
	}
	else
	{	
	printf("FALSE, IT IS NOT EMPTY\n");		
	}
	printf("stack size now is: %ld\n", StackSize(example));
	printf("stack size now is: %ld\n", StackCapacity(example));
	
	StackPop(example);
	
	struct_for_test_ty *struct_for_test6 = (struct_for_test_ty*)StackPeek(example);
	
	if(0 == memcmp(struct_for_test6, &struct_for_test3, sizeof(struct_for_test_ty)))
	{
	printf("popping test succeeded\n");
	}
	else
	{
	printf("popping test failed\n");
	}
	
	StackDestroy(example);
	
}


/******************************************************************************/


/*Name: AhmadWattad
  Project: Worksheet11
  Reviewer: Agbaria
  Date: 31/07/2023
  Version: 1.0: published the program
 	   1.1: apply modifications without malloc
 	   1.2: prepare the prog for reviewing
 	   1.3 reviewed and changed accordingly
  		*/
#include <assert.h> /*assert*/
#include <string.h> /*memcpy*/
#include <stdlib.h> /*malloc*/

#include "stack.h"



/**************************** Global variables ********************************/
struct stack
{
	size_t capacity;
	size_t size;
	size_t element_size;
	char *stack_arr;
};

/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/

/**************************** STACK CREATE ************************************/

stack_ty *StackCreate(size_t capacity, size_t element_size)
{	

	stack_ty *stack_init = (stack_ty*)malloc(sizeof(stack_ty) + sizeof(char)*capacity*element_size);
	
	if(NULL == stack_init)
	{
		return NULL;
	}
	
	stack_init->capacity = capacity;
	stack_init->size = 0;
	stack_init->element_size = element_size;
	stack_init->stack_arr = (char*)&stack_init[sizeof(size_t)*3];
	
	return stack_init;
}

/*************************** STACK DESTROY ************************************/

void StackDestroy(stack_ty *stack)
{
	assert(NULL != stack);
	
	free(stack);
	stack = NULL;
}

/**************************** STACK PUSH **************************************/

void StackPush(stack_ty *stack, const void *data)
{
	assert(NULL != stack);

	if(stack->size == stack->capacity)
	{
		perror("Can't push, the stack is full");	
		return;
	}
	
	/*copy the data to the stack arra*/
	memcpy(&stack->stack_arr[stack->size*stack->element_size], 
		data, stack->element_size);
	++stack->size;
}

/****************************** STACK POP *************************************/

void StackPop(stack_ty *stack)
{
	assert(NULL != stack);
	
	if(0 == stack->size)
	{
		perror("Can't pop, there is no elements in the stack");
		return;
	}
	
	--stack->size;
}

/****************************** STACK PEEK ************************************/

void *StackPeek(const stack_ty *stack)
{
	assert(NULL != stack);
	
	/*returns the address to the size before last one*/
	return (void*)&stack->stack_arr[(stack->size-1)*stack->element_size];
}


/****************************** STACK SIZE ************************************/

size_t StackSize(const stack_ty *stack)
{
	assert(NULL != stack);
	return stack->size;
}

/**************************** STACK IS_EMPTY **********************************/

int StackIsEmpty(const stack_ty *stack)
{
	assert(NULL != stack);
	
	if(0 == stack->size)
	{
		return FALSE;
	}
	
	return TRUE;
}

/*****************************STACK CAPACITY **********************************/

size_t StackCapacity(const stack_ty *stack)
{
	assert(NULL != stack);
	return stack->capacity;
}

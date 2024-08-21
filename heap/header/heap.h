/*
  Name:
  Project: Binary Heap
  Reviewer: ---
  Date: 24/10/2023

  Project Overview: API for a Binary Heap.
*/

#ifndef __ILRD_HEAP_H__
#define __ILRD_HEAP_H__

/******************************** Libraries  ********************************/

#include <stddef.h> /*size_t*/

/******************************** Definitions  ******************************/

typedef struct heap heap_ty;

typedef enum {SUCCESS = 0, FAILURE} heap_status_ty;
typedef enum {FALSE = 0, TRUE} heap_boolean_ty;

/* returns positive if data1 is after data2, 0 if equal*/
typedef int (*heap_cmp_func_ty)(const void* data1, const void*data2, const void*params);

typedef int (*heap_is_match_func_ty)(const void* data, const void* params);


/************************* heap API Declerations  *****************************/

  /*
  Return: NULL if fails
  Complexity: O(1). 
  Args: never NULL*/
heap_ty *HeapCreate(heap_cmp_func_ty cmp_func, size_t expected_capicity);

/*
  Arguments: NULL alowed.
  Complexity: O(1). */
void HeapDestroy(heap_ty* heap);


/*
  Returns: non zero if fails
  Complexity: θ(log n) amortized. occasionally O(n)
  if your compare function allows it, data can be NULL */
int HeapAdd(heap_ty*, void *data);

/*Returns: removed element. NULL if no match
  Complexity: O(n)*/
void* HeapRemoveMatch(heap_ty* heap, heap_match_func_ty IsMatch, const void* params);

/*Complexity: O(1).
IMPORTANT - never change order influencing values of elements inside the heap
*/
void* HeapGetTop(heap_ty* heap);

/*Complexity: O(Log n).*/
void HeapRemTop(heap_ty* heap);

/*  Complexity: O(1).*/
size_t HeapSize(const heap_ty* heap);

/*  Complexity: O(1).*/
int HeapIsEmpty(const heap_ty* heap);


#endif /*(__ILRD_HEAP_H__)*/          

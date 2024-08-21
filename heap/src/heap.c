/*Name: AhmadWattad
  Project: SortedList
  Reviewer: Sahar
  Date: 28/08/2023
  Version: 1.0: published the program
  		*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/
#include <string.h> /*memcpy*/

#include "heap.h"
#include "vector.h" /*vector_ty*/

#define INITIAL_CAPICITY 10
/*************************** forwarded declarations ***************************/
static void HeapifyUp(heap_ty*heap, index);
static void HeapifyDown(heap_ty*heap, index);
static size_t ToParent(size_t index);
static size_t ToRChild(size_t index);
static size_t ToLChild(size_t index);
static size_t FirstOfThree(Heap_ty *heap, size_t subtree_top);
static void swapVoidPointers(void** a, void** b) ;
static void **ToArr(heap_ty*heap);
/***************************** Definitions ************************************/


struct heap
{
	vector_ty *vector;
	heap_cmp_func_ty cmp_func;
	const void *cmp_params;
}

/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/

/************************** SORTEDLIST CREATE *********************************/


heap_ty *HeapCreate(heap_cmp_func_ty cmp_func, size_t expected_capicity);
{
	/*assert*/
	assert(NULL != cmp_func);
	/*allocate for heap*/
	heap_ty *heap = (heap_ty)calloc(sizeof(heap_ty));
	/*if it fails*/
		/*return failure*/
	if (NULL == heap)
	{
		return NULL;
	}	
	
	/*allocate for vector*/
	heap->vector = VectorCreate(INITIAL_CAPICITY, sizeof(void*));
	/*if it fails*/
		/*free heap allocation*/
		/*return failure*/\
	if (NULL == heap->vector)
	{
		HeapDestroy(heap);
		return NULL;
	}
	/*assign cmp func to its field*/
	heap->cmp_func = cmp_func;
	
	return heap;
}


void HeapDestroy(heap_ty* heap)
{
	/*if NULL*/
		/*return*/
	if(NULL == heap)
	{
		return;
	}
	/*free the allocation of vector*/
	VectorDestroy(heap->vector);
	heap->vector = NULL;
	heap->cmp_func = NULL;
	/*free the allocation of heap itself*/
	free(heap);

}



int HeapAdd(heap_ty *heap, void *data)
{
	int is_success = 0;
	/*assert*/
	assert(NULL != heap);
	/* add to end of array */
	is_success = VectorPushBack(vector_ty *vector, (const void*)data);
	
	if(0 == is_success)
	{
		return FAILURE;
	}
	
	HeapifyUp(heap);
	
	return SUCCESS
}


void* HeapRemoveMatch(heap_ty* heap, heap_match_func_ty IsMatch, const void* params)
{
	/*define i -iterator and intialize it to 0*/
	/*define is_match = 0 - false*/
	/*assert*/
	/*while - is_match is not true && i is smaller than size*/
		/*Compare the current element with the key of params by cmpfunc*/
		/*increment i*/
	/*if not found, return NULL*/	
	/*remove element*/

}

static void RemoveElement(heap_ty* heap, size_t index)
{
	void *element_ = NULL;
	void *last_element_ = NULL;
	assert(NULL != heap);
	/*set the element of index to the last element*/	
	element_ = VGetAccessToElement(heap->vector, index);
	VGetAccessToElement(heap->vector, VectorSize(heap->vector));
	/*remove last element*/
	/*heapifydown*/

}

void* HeapGetTop(heap_ty* heap)
{
	assert(NULL != heap);
	
	return VGetAccessToElement(heap->vector, 0);
}

void HeapRemTop(heap_ty* heap);
{
	/*assert*/
	/*set the first element to the last element*/	
	/*remove last element*/
	/*heapifydown*/

}

size_t HeapSize(const heap_ty* heap);
{
	/*assert*/
	/*return size of vector*/
}

/*  Complexity: O(1).*/
int HeapIsEmpty(const heap_ty* heap);
{
	/*assert*/
	/*return IsEmpty of vector*/
}

/*********************** helper functions *************************************/

static void HeapifyUp(heap_ty*heap)
{
	/*assert*/
	/*while - Should move up && not the end*/
		/*swap the current with parent*/
		/*update the current to be the parent*/

}

static void HeapifyDown(heap_ty*heap)
{
	/*while - not the last index && should move down? (biggest is not the root) */
		/*swap between parent and biggest child*/
		/*update the index  to be equal to the biggest child*/
		
}

static void HeapifyDown(heap_ty*heap, index)
{
	/*while - not the last index && should move down? (biggest is not the root) */
		/*swap between parent and biggest child*/
		/*update the index  to be equal to the biggest child*/
		
}

static size_t ToParent(size_t index)
{
	return index / 2;
}

static size_t ToRChild(size_t index)
{
	return 2 * index + 1;
}

static size_t ToLChild(size_t index)
{
	return 2 * index ;
}

static size_t FirstOfThree(Heap_ty *heap, size_t subtree_top)
{
	size_t chosen = subtree_top;
	size_t left = ToLChild(chosen);
	size_t right = ToRChild(chosen);
	void *pointers = ToArr(heap->vector);
	
	assert(NULL != heap);
	
	
	if ( VectorSize(heap->vector) <= left && heap->cmp_func(pointers[size],
	
	chosen = left;
	/*compare top with right child and update index*/
	/*compare the result with left child and update index*/
	/*return it*/

}

static void swapVoidPointers(void** a, void** b) 
{
	void* temp = *a;
	*a = *b;
	*b = temp;
}

static void **ToArr(heap_ty*heap)
{



}


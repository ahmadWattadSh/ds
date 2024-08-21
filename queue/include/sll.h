/******************************** ws5_dsll.h  ***************************/
/*
  Name: HRD 32
  Project: Work Sheet 6 - Data Structures - Singly Linked LIst
  Reviewer: Liel
  Date: 12/08/23
  Version: 1.0
*/

#ifndef __SLL_H__
#define __SLL_H__

/******************************** Libraries  *******************************/

#include <stddef.h> /*size_t*/

/******************************** Definitions  ******************************/

typedef struct node node_ty; /*decleration*/
typedef struct iter iter_ty; /*for client use*/
typedef struct sll sll_ty;

typedef enum {SUCCESS = 1, FAILURE = 0} status_ty;
typedef enum {EMPTY = 1, NOT_EMPTY = 0} op_res_ty;
typedef enum {MATCHED = 1, NOT_MATCHED = 0} match_ty;

typedef int (*ActionFunc_ty)(void* data, void* param);
typedef int (*MatchFunc_ty)(const void* data, void* param);

/*********************** S-list API Declerations  ****************************/

/*Function that inits the SLL struct
  Return value: pointer of type sll_ty, if unsuccessful malloc(), returns NULL;
  Undefined B.: N.A */
sll_ty* SListCreate();

/*Function that destroys the SLL struct
  Arguments: List pointer
  Return value: N.A
  Undefined B.: NULL sll_ty ptr */
void SListDestroy(sll_ty* list);

/*Function that inserts and sets a node before the indice specified by iter_ty.
  Arguments: Iterator, Data
  Return value: next-place iterator
  Undefined B.: inexistent node specified by iter */
iter_ty SListInsertBefore(iter_ty iter, void* data);

/*Function that removes a node before the indice specified by iter_ty.
  Arguments: Iterator
  Return value: next-place iterator
  Undefined B.: inexistent node specified by iter */
iter_ty SListRemove(iter_ty iter);

/*Function that retrieves a value stired in a node
  Arguments: Iterator 
  before the indice specified by iter_ty.
  Return value: data
  Undefined B.: inexistent node specified by iter */
void* SListGetData(iter_ty iter);

/*Function that sets a node specified by iter_ty.
  Arguments: Iterator, Data
  Return value: N.A
  Undefined B.: inexistent node specified by iter */
void SListSetData(iter_ty iter, void* data);

/*Function that checks list population status
  Arguments: List ptr
  Return value: EMPTY = 1, NOT_EMPTY = 0
  Undefined B.: NULL sll_ty ptr */
int SListIsEmpty(sll_ty *list);

/*Function that returns list nodes count
  Arguments: List ptr
  Return value: node count
  Undefined B.: NULL sll_ty ptr */
size_t SListCount(sll_ty *list);

/*Function that retrieves node data
  Arguments: user function & parameters
  Return value: Iterator
  Undefined B.: NULL sll_ty ptr, NULL function */
iter_ty SListFind
(iter_ty from_iter, iter_ty to_iter,  void* data, MatchFunc_ty match_func,
 void* usr_param);

/*Function that manipulates node data
  Arguments: user function & parameters
  Return value: SUCCESS = 1, FAILURE = 0
  Undefined B.: NULL sll_ty ptr, NULL function */
int SListForEach
(iter_ty from_iter, iter_ty to_iter, ActionFunc_ty action_func, void* usr_param);                

/*SListMerge*/
void Merge(iter_ty first_iter, iter_ty second_iter);  

/********************* Iterator API Declerations  ****************************/

/*Function that checks if two iterators belong to the same list
  Arguments: 2 client iterators
  Return value: SUCCESS = 1, FAILURE = 0
  Undefined B.: NULL iter_ty ptrs */
int SListIterIsEqual(iter_ty iter1, iter_ty iter2);

/*Function that returns an iter to the begining of the list
  Arguments: list
  Return value: iterator
  Undefined B.: NULL sll_ty ptr */
iter_ty SListBegin(sll_ty *list);

/*Function that returns an iter to the end of the list
  Arguments: list
  Return value: iterator
  Undefined B.: NULL sll_ty ptr */
iter_ty SListEnd(sll_ty *list);

/*Function that returns an iter pointing to the next node of node pinted by the input iterator.
  Arguments: iterator
  Return value: iterator
  Undefined B.: NULL iter_ty ptr */
iter_ty SListNext(iter_ty iter);

/*Iterator Definition - Not intended for user. Iterator struct is defined here because evaluation of type iter_ty is mandatory for header file */
struct iter
{
      node_ty* node_ptr;
      #ifndef NDEBUG
      #define DEBUG_ONLY(x) x
      #else 
      #define DEBUG_ONLY(x) 

      # endif
};

#endif /*(__SLL_H__)*/

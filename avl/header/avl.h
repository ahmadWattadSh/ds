/*
  Name: Agbaria ahmad
  Project: Recursive Binary Search Tree
  Reviewer: ---
  Date: 13/12/2023


  Project Overview: API for a Recursive Binary Search Tree.
*/

#ifndef __ILRD_AVL_H__
#define __ILRD_AVL_H__

/******************************** Libraries  ********************************/

#include <stddef.h> /*size_ty*/

/******************************** Definitions  ******************************/

typedef struct avl avl_ty; 

enum {SUCCESS = 0, FAILURE}; 
enum {FALSE = 0, TRUE};
enum {PREORDER = 0, INORDER = 1, POSTORDER = 2, NUM_OF_ORDERS};

typedef int (*avl_action_func_ty)(void* data, void* param);
/*A function must return  -, + , 0*/
typedef int (*avl_cmp_func_ty)(const void* avl_data, const void* data, void *params); 
typedef struct avl avl_ty;

/*
structs in the src file:

typedef struct node node_ty;

enum{LEFT = 0, RIGHT, NUM_OF_CHILDREN};

struct node
{
	void* data;
	node_ty *childrens[NUM_OF_CHILDREN];
	size_t height;
};

struct avl
{
	node_ty *root;
	void* params;
	avl_cmp_func_ty cmp_func;
};

*/

/*********************** AVL API Declerations  ****************************/

/*Function that creats a recursive binary search tree.
  Arguments: 'cmp_func' - user's cmp func for the sake of tree ordering.
             'params' - cmp func parameters.
  Return value: pointer to the binary search tree.
                On Error- returns NULL.
  Complexity: O(1). 
  Undefined B.: NULL pointer to cmp_func, */
avl_ty *AVLCreate(avl_cmp_func_ty cmp_func, void *params);

/*Function that destroys a binary search tree.
  Arguments: 'avl' - pointer to binary search tree.
  Return value: N.A.
  Complexity: O(n). 
  Undefined B.: NULL pointer to a binary search tree, */
void AVLDestroy(avl_ty* avl);

/*Function that inserts a new tree-element without disrupting the sorting.
  the function didn't support duplicated values. 
  Arguments: 'avl' - pointer to a tree, 
             'data' - data to insert.
  Return value: SUCCESS / FAILURE to insert the data.
  Complexity: O(log(n)).
  Undefined B.: NULL pointer to tree, NULL pointer to data*/
int AVLInsert(avl_ty* avl, void *data);

/*Function that removes an element from the tree without disrupting the sorting.
  Arguments: 'data' - the data of the element to be removed.
  Complexity: O(log(n)) .
  Undefined B.: Invalid data*/
void AVLRemove(avl_ty* avl, const void* data);

/*Function that checks if the tree is empty.
  Arguments: 'avl' - pointer to a tree, 
  Return value: if empty = TRUE, othewise = FALSE.
  Complexity: O(1).
  Undefined B.: NULL pointer to tree*/
int AVLIsEmpty(const avl_ty* avl);

/*Function that returns an the height of a given data.
  Arguments: 'data' - the data you want to find its height.
  Return value: the height of the given data.
  Complexity: O(1).
  Undefined B.: NULL pointer to data. */
size_t AVLHeight(const avl_ty* avl);

/*Function that returns the number of current elements in the tree.
  Arguments: 'avl' - pointer to a tree, 
  Return value: Num of elements currently in tree.
  Complexity: O(n).
  Undefined B.: NULL pointer to tree*/
size_t AVLSize(const avl_ty* avl);

/*Function that return status if the element exist in the tree.
  Arguments: 'avl' -  pointer to tree.
             'data' - value to be found.
  Return value: returns the found data.
  Complexity: O(log(n)).
  Undefined B.: NULL pointer to avl, NULL pointer to data. */
void *AVLFind(const avl_ty* avl, const void* data);

/*Function that executes an action func for every element in the tree.
   Arguments: 'avl' -  pointer to tree.
   			  'action_func', 'params' - User function & parameters.
  Return value: returns the return status of the action_func ,
                it's return status in the first FAILURE.
  Complexity: ( O(n) * complexity of action func).
  Undefined B.: NULL pointer to avl, NULL pointer to action_func*/ 
int AVLForEach(avl_ty* avl, avl_action_func_ty action_func ,void* params, int order);

/******************************************************************************/
#endif /*(__ILRD_AVL_H__)*/

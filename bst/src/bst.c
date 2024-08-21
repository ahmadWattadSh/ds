/*
  Name: Ahmad Wattad
  Project: BST
  Reviewer: ??
  Date: 27/09/23

  Overview: Implementation of an BINARY SEARCH TREE Manager. */
  		
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/



#include "bst.h"
#define NUM_OF_NODES 3
#define GETROOT(bst) (&((bst_ty*)bst)->root)

typedef enum {LEFT = 0, RIGHT = 1} neighbors_ty;


/******************************* Definitions **********************************/
	
struct node
{
	void *data;
	node_ty *parent;
	node_ty *neighbors[NUM_OF_NODES];		
};


struct bst
{
	node_ty root;
	void *params;
	bst_cmp_ty cmp_func;	
};

/**************************** Forwarded funcs *********************************/

static node_ty *ConvertFromIterToNode( bst_iter_ty iter);
static bst_iter_ty ConvertFromNodeToIter(node_ty *node);

static node_ty* CreateNode(node_ty* parent, void* data);
static int ActionFuncSize(void* data, void* param);
static node_ty *SearchFunction(bst_ty* bst, void *data_to_find);

static void TraverseLeft(node_ty** current);
static void TraverseRight(node_ty** current);
static void RemoveLeaf(node_ty** current, node_ty* node_to_delete);

static size_t NumOfChildren(node_ty* node);
static void RemoveNodeWithoutChildren(node_ty *current,  node_ty* parent);
static void RemoveNodeWithOneChild(node_ty *current,  node_ty* parent);
static void RemoveNodeWithTwoChildren(node_ty *current, node_ty* parent);

static int HasRightChild(node_ty* node);
static int HasLeftChild(node_ty* node);
static int IsRightChild(node_ty* node);
static int IsLeftChild(node_ty* node);

/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/

/******************************* Create Func **********************************/

bst_ty *BSTCreate(bst_cmp_ty cmp_func, void *params)
{
	bst_ty *bst = NULL;	
	
	assert(NULL != cmp_func);
	
	bst = (bst_ty*)malloc(sizeof(bst_ty)) ;		
	
	if( NULL == bst)
	{
		return NULL;
	}

	bst->root.data = NULL;
	bst->root.parent = NULL;
	bst->root.neighbors[LEFT] = NULL;
	bst->root.neighbors[RIGHT] = NULL;
	
	bst->params = params;
	bst->cmp_func = cmp_func;	
	
	return bst;
}

/**************************** Destroy Helper Func *****************************/

static void RemoveLeaf(node_ty** current, node_ty* node_to_delete)
{

	if((*current)->neighbors[LEFT] == NULL && (*current)->neighbors[RIGHT] == NULL)
	{

		node_to_delete = *current;
		*current = (*current)->parent;
		
		if(IsLeftChild(node_to_delete))
		{
			(*current)->neighbors[LEFT] = NULL;	
		}
		else
		{
			(*current)->neighbors[RIGHT] = NULL;		
		}
		
		free(node_to_delete);
		node_to_delete = NULL;
	}
}

/******************************* Destroy Func *********************************/

void BSTDestroy(bst_ty* bst)
{
	node_ty *current = NULL;
	node_ty *node_to_delete = NULL;
	node_ty *end = NULL;
	
	assert(NULL != bst);
	
	end = ConvertFromIterToNode(BSTEnd(bst));
	current = ConvertFromIterToNode(BSTBegin(bst));
	
	while (current != end)
	{
		TraverseLeft(&current);
		RemoveLeaf(&current, node_to_delete);
		TraverseRight(&current);
	}

	free(bst);
	bst = NULL;
}

/******************************* Insert Func **********************************/

bst_iter_ty BSTInsert(bst_ty* bst, void *data_to_find)
{

	node_ty *node = NULL;
	node_ty *new_node = NULL;
	int res = 0;	
	
	assert(NULL != bst);
	
	/*search for the node*/
	node = SearchFunction(bst, data_to_find);
	
	if(node != GETROOT(bst))
	{
		res = bst->cmp_func(node->data, data_to_find, bst->params);
	}
	
	/*new node*/
	new_node = CreateNode(node, data_to_find);
	
	if(NULL == new_node)
	{
		return BSTEnd(bst);
	}
	
	/*connect nodes */
	if(0 < res)
	{
		node->neighbors[RIGHT] = new_node;
	}
	else
	{
		node->neighbors[LEFT] = new_node;	
	}
	
	return new_node;
}

/************************* Remove helper functions ****************************/


static void RemoveNodeWithoutChildren(node_ty *current,  node_ty* parent)
{
	if(TRUE == IsLeftChild(current))
        {
           	parent->neighbors[LEFT] = NULL;
      	} 
       	else 
       	{
     		parent->neighbors[RIGHT] = NULL;
  	}	
        
      	free(current);
	current = NULL;
}

static void RemoveNodeWithOneChild(node_ty *current,  node_ty* parent)
{
	node_ty *child = NULL;
	
        child = (NULL != current->neighbors[LEFT]) ? current->neighbors[LEFT] : current->neighbors[RIGHT];
        child->parent = parent;
        
        if(TRUE == IsLeftChild(current)) 
        {
        	parent->neighbors[LEFT] = child;
        } 
        else 
       	{
       		parent->neighbors[RIGHT] = child;
       	}
       	
       	free(current);
       	current = NULL;	
}

static void RemoveNodeWithTwoChildren(node_ty *current, node_ty* parent)
{
	node_ty *prev = NULL;
	size_t num_of_children = 0;
	
	prev = ConvertFromIterToNode(BSTPrev(current));
        current->data = prev->data;
        num_of_children = NumOfChildren(prev);
        parent = prev->parent;
	switch(num_of_children)
	{
		case 0:
			RemoveNodeWithoutChildren(prev, parent);
		break;
		
		case 1:
		        RemoveNodeWithOneChild(prev, parent);
		break;
	
		default:
		break;
	}
}

/******************************* Remove Function ******************************/

bst_iter_ty BSTRemove(bst_iter_ty iter)
{
	node_ty *current = ConvertFromIterToNode(iter);
	node_ty *parent = NULL;
	node_ty *next = NULL;
	size_t num_of_children = 0;	

	assert(NULL != current);

	parent  = current->parent;
	next = ConvertFromIterToNode(BSTNext(iter));

	num_of_children = NumOfChildren(current);
	
	switch(num_of_children)
	{
		case 0:
			RemoveNodeWithoutChildren(current, parent);
		break;
		case 1:
			RemoveNodeWithOneChild(current, parent);
		break;
		case 2:
			RemoveNodeWithTwoChildren(current, parent);
		break;	
	}

    	return next;
}

/********************************* GET DATA ***********************************/
void* BSTGetData(bst_iter_ty iter)
{
	node_ty* node = ConvertFromIterToNode(iter);
	
	assert(NULL != node);
	
	return node->data;	
}

/********************************* ISEMPTY DATA *******************************/

int BSTIsEmpty(const bst_ty* bst)
{
	if(NULL == bst->root.neighbors[LEFT])
	{
		return TRUE;
	}

	return FALSE;
}

/**************************** SIZE HELPER FUNC ********************************/
static int ActionFuncSize(void* data, void* param)
{
	int *int_ptr = NULL;
	
	assert(NULL != param);

	int_ptr = param;
	
	data;
	++*int_ptr;
	
	return 0;
}

/********************************* SIZE FUNC **********************************/
size_t BSTSize(const bst_ty* bst)
{
	size_t count  = 0;
	
	assert(NULL != bst);
	
	BSTForEach(BSTBegin((bst_ty *)bst), BSTEnd((bst_ty *)bst), 
		&ActionFuncSize, (void*)&count);

	return count;
}


/********************************* FIND FUNC **********************************/

bst_iter_ty BSTFind(const bst_ty* bst, void* data_to_find)
{
	node_ty *node_from = NULL;
	int res = 0;
		
	assert(NULL != bst);	
	assert(NULL != data_to_find);	

	node_from = bst->root.neighbors[LEFT];
	
	while (NULL != node_from)
	{
		res = bst->cmp_func(node_from->data, data_to_find, bst->params);
		
		if(0 == res)		
		{
			return ConvertFromNodeToIter(node_from);
		}
		
		if(0 < res)		
		{
			node_from = node_from->neighbors[RIGHT];
		}
		else
		{
			node_from = node_from->neighbors[LEFT];
		}				
	
	}	
		return BSTEnd(bst);
	
}

/********************************* FOREACH FUNC *******************************/
int BSTForEach(bst_iter_ty from, bst_iter_ty to, 
	bst_action_ty action_func ,void* params)
{
	node_ty *node_from = ConvertFromIterToNode(from);
	node_ty *node_to = ConvertFromIterToNode(to);
			
	assert(NULL != action_func);
	assert(NULL != node_from);
	assert(NULL != node_to);	
	
	while (node_from != node_to)
	{
	
		if(SUCCESS != action_func(node_from->data, params))		
		{
			return FAILURE;
		}
		
		from = BSTNext(from);
		node_from = ConvertFromIterToNode(from);
	}
	
	return 	SUCCESS;	
}	
	
/***************************** Iterator Api ***********************************/


bst_iter_ty BSTBegin(const bst_ty* bst)
{
	node_ty* curr_node = NULL;
	
	assert(NULL != bst);
	
	curr_node = GETROOT(bst);
	TraverseLeft(&curr_node);
	
	return 	ConvertFromNodeToIter(curr_node); 
}


bst_iter_ty BSTNext(bst_iter_ty iter)
{
	node_ty* curr_node = ConvertFromIterToNode(iter);
	
	assert(NULL != curr_node);
	
	if(TRUE == HasRightChild(curr_node))
	{
		curr_node = curr_node->neighbors[RIGHT];
		TraverseLeft(&curr_node);
		
		return ConvertFromNodeToIter(curr_node);
	}
	
	if(TRUE == IsLeftChild(curr_node))
	{
		return ConvertFromNodeToIter(curr_node->parent);
	}
	
	while(TRUE != IsLeftChild(curr_node))
	{
		curr_node = curr_node->parent;
	}
	
	return ConvertFromNodeToIter(curr_node->parent);
	
}


bst_iter_ty BSTPrev(bst_iter_ty iter)
{
	node_ty* curr_node = ConvertFromIterToNode(iter);
	
	assert(NULL != curr_node);
	
	if(TRUE == HasLeftChild(curr_node))
	{
		curr_node = curr_node->neighbors[LEFT];	
		TraverseRight(&curr_node);
		
		return ConvertFromNodeToIter(curr_node);
	}
	
	if(TRUE == IsRightChild(curr_node))
	{
		return ConvertFromNodeToIter(curr_node->parent);
	}
	
	while(TRUE != IsRightChild(curr_node))
	{
		curr_node = curr_node->parent;
	}
	
	return ConvertFromNodeToIter(curr_node->parent);

}


bst_iter_ty BSTEnd(const bst_ty* bst)
{
	node_ty* curr_node = NULL;

	assert(NULL != bst);
	
	curr_node = GETROOT(bst);
	
	return ConvertFromNodeToIter(curr_node); 
}


int BSTIsSameIter(bst_iter_ty iter, bst_iter_ty iter_to_cmp)
{
	node_ty *node = ConvertFromIterToNode(iter);
	node_ty *node_to_compare = ConvertFromIterToNode(iter_to_cmp);	
	
	assert(NULL != node);
	assert(NULL != node_to_compare);	
	
	if(node == node_to_compare)
	{
		return TRUE;
	}
	
	return FALSE;
}


/****************************** helper functions ******************************/

static node_ty *ConvertFromIterToNode( bst_iter_ty iter)
{
	node_ty *node = (node_ty*)iter ;

	return node;
}


static bst_iter_ty ConvertFromNodeToIter(node_ty *node)
{
	bst_iter_ty iter = (bst_iter_ty)node ;

	return iter;
}
/******************************************************************************/
static void TraverseRight(node_ty** current)
{
	while (NULL != (*current)->neighbors[RIGHT])
	{
		*current = (*current)->neighbors[RIGHT];
	}
}

static void TraverseLeft(node_ty** current)
{
	while (NULL != (*current)->neighbors[LEFT])
	{
		*current = (*current)->neighbors[LEFT];
	}
}

static node_ty* CreateNode(node_ty* parent, void* data)
{
	node_ty *new_node = (node_ty*)malloc(sizeof(node_ty));
	
	if(NULL == new_node)
	{
		return NULL;
	}
	
	new_node->data = data;
	new_node->neighbors[LEFT] = NULL;	
	new_node->neighbors[RIGHT] = NULL;
	new_node->parent = parent;	
	
	return new_node;
}
static node_ty *SearchFunction(bst_ty* bst, void *data_to_find)
{
	node_ty *node_from = NULL;
	node_ty *parent = NULL;
	
	int res = 0;	
	
	node_from = bst->root.neighbors[LEFT];
	parent = GETROOT(bst);
	

	while (NULL != node_from)
	{
		res = bst->cmp_func(node_from->data, data_to_find, bst->params);
		
		assert(0 != res);
		
		if(0 < res)		
		{
			parent = node_from;
			node_from = node_from->neighbors[RIGHT];
		}
		else
		{
			parent = node_from;
			node_from =  node_from->neighbors[LEFT];
		}				
	}

	return parent;
}

/******************************************************************************/
static int IsLeftChild(node_ty* node)
{
	if(node == node->parent->neighbors[LEFT])
	{
		return TRUE;
	}
	
	return FALSE;
}

static int IsRightChild(node_ty* node)
{
	if(node == node->parent->neighbors[RIGHT])
	{
		return TRUE;
	}
	
	return FALSE;
}

static int HasRightChild(node_ty* node)
{
	if(NULL != node->neighbors[RIGHT])
	{
		return TRUE;
	}
	
	return FALSE;
}

static int HasLeftChild(node_ty* node)
{
	if(NULL != node->neighbors[LEFT])
	{
		return TRUE;
	}
	
	return FALSE;
}

static size_t NumOfChildren(node_ty* current)
{
	size_t counter = 0;
	
	if( NULL != current->neighbors[LEFT])
	{
		++counter;
	}
	
	if( NULL != current->neighbors[RIGHT])
	{
		++counter;
	}
	
	return counter;
}







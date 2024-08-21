/*
  Name: Ahmad Wattad
  Project: BST
  Reviewer: ??
  Date: 27/09/23

  Overview: Implementation of an BINARY SEARCH TREE Manager. */
  		
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "avl.h"

typedef struct node node_ty;
enum {LEFT = 0, RIGHT, NUM_OF_CHILDREN};
typedef int (*order_func_ty)(node_ty * node, avl_action_func_ty action_func, void *params);

/******************************* Definitions **********************************/
	
struct node
{
	void* data;
	node_ty *children[NUM_OF_CHILDREN];
	size_t height;
};

struct avl
{
	node_ty *root;
	void* params;
	avl_cmp_func_ty cmp_func;
};

/**************************** Forwarded funcs *********************************/

static node_ty * CreateNode(node_ty* right, node_ty* left, void *data, size_t height);
static void RecDestroy(node_ty *node);

static node_ty* RecInsertIMP(node_ty *tree_node, node_ty *node, avl_cmp_func_ty cmp_func, void *params);
static void UpdateHeight(node_ty *node);
static int MaxTwoNums(int left, int right);
static int GetHeight(node_ty * node);

static node_ty* RecFindIMP(node_ty *node, void *data, avl_cmp_func_ty cmp_func, void *params);

static node_ty* RecRemoveIMP(node_ty *tree_node, void *data, avl_cmp_func_ty cmp_func, void *params);
static node_ty *TraverseLeft(node_ty *curr);
static node_ty * DestroyNodeIMP(node_ty * tree_node);

static int PostOrder(node_ty * node, avl_action_func_ty action_func, void *params);
static int PreOrder(node_ty * node, avl_action_func_ty action_func, void *params);
static int InOrder(node_ty * node, avl_action_func_ty action_func, void *params);

static void CalcSize(node_ty *node, size_t *size);

static int IsLeaf(node_ty *node);
static node_ty* GetLeftChild(node_ty *node);
static node_ty* GetRightChild(node_ty *node);

static void BalanceNode(node_ty *node, avl_cmp_func_ty cmp_func, void *params);
static void LeftRotate(node_ty *node);
static void RightRotate(node_ty *node);
/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/

/******************************* Create Func **********************************/


avl_ty *AVLCreate(avl_cmp_func_ty cmp_func, void *params)
{
	/*Create avl*/
	avl_ty *avl = (avl_ty*)malloc(sizeof(avl_ty));
	
	/*assert*/
	assert(NULL != cmp_func);
	
	/*handle err*/
	if (NULL == avl)
	{
		return NULL;
	}		

	/*assign needed values, no need for root for now*/
	avl->root = NULL; 
	avl->params = params;
	avl->cmp_func = cmp_func;
	
	/*return it*/
	return avl;
}

/*doing it post order, destroy children then parent*/
void AVLDestroy(avl_ty* avl)
{
	/*redirect to another func with sign (RecDestroy(node_ty *node))*/
	RecDestroy(avl->root);
	
	/*destroy the avl*/
	free(avl);
}

/*doing it preorder*/
int AVLInsert(avl_ty* avl, void *data)
{
	assert(NULL != avl);
	assert(NULL != data);
	
	/*create new node*/
	node_ty *new_node = CreateNode(NULL, NULL, data, 0);
	
	/*handle err*/
	if (NULL == new_node)
	{
		return FALSE;
	}
	
	/*search and insert in the right place*/
	avl->root = RecInsertIMP(avl->root, new_node, avl->cmp_func, avl->params);

	return TRUE;
}


void AVLRemove(avl_ty* avl, const void* data)
{
	RecRemoveIMP(avl->root, (void*)data, avl->cmp_func, avl->params);
}

int AVLIsEmpty(const avl_ty* avl)
{
	assert(NULL != avl);
	
	if(NULL == avl->root)
	{
		return TRUE;
	}

	return FALSE;
}

size_t AVLHeight(const avl_ty* avl)
{
	assert(NULL != avl);
	
	return avl->root->height;
}


size_t AVLSize(const avl_ty* avl)
{
	size_t size = 0;
	
	assert(NULL != avl);
		
	CalcSize(avl->root, &size);
	
	return size;
}


void *AVLFind(const avl_ty* avl, const void* data)
{
	node_ty *node = NULL;
	
	assert(NULL != avl);
	
	node = RecFindIMP(avl->root, (void *)data, avl->cmp_func, avl->params);
	
	if(NULL == node)
	{
		return NULL;
	}

	return node->data;
}


int AVLForEach(avl_ty* avl, avl_action_func_ty action_func ,void* params, int order)
{
 	order_func_ty order_funcs[NUM_OF_ORDERS] = {NULL}; /*TODO: maybe static init or switch instead*/
 	order_funcs[PREORDER] = PreOrder;
 	order_funcs[INORDER] = InOrder;
 	order_funcs[POSTORDER] = PostOrder;
 	
 	return order_funcs[order](avl->root, action_func, params);
}


/*----------------------------------------------------------------------------*/

static node_ty * CreateNode(node_ty* right, node_ty* left, void *data, size_t height)
{
	node_ty * new_node = (node_ty *)malloc(sizeof(node_ty));
	
	if (NULL == new_node)
	{
		return NULL;
	}
	
	new_node->data = data;
	new_node->children[LEFT] =  left;
	new_node->children[RIGHT] = right;
	new_node->height = height;
}

static void RecDestroy(node_ty *node)
{

	/*if  NULL*/
	if(NULL  == node)
	{
		/*return*/
		return;
	}
	
	/*recursive function for left*/
	RecDestroy(GetLeftChild(node));
	/*recursive function for right*/	
	RecDestroy(GetRightChild(node));
	
	/*free*/	
	free(node);
}



static node_ty* RecInsertIMP(node_ty *tree_node, node_ty *node, avl_cmp_func_ty cmp_func, void *params)
{	
	int res = 0;
	int side = 0;
	
	/*if NULL*/
	if ( NULL == tree_node)
	{
		return node;
	}
	
	/*cmp data with current*/
	res = cmp_func(tree_node->data, node->data, params);
	
	/*if data is bigger*/
	side = (0 < res) ? LEFT: RIGHT;
	
	/*recur func and return it to the right child or left*/
	tree_node->children[side] = RecInsertIMP(tree_node->children[side],node, cmp_func, params);

	/*balancing for later*/	
	
	/*adjusting height*/
	UpdateHeight(tree_node);
	
	return tree_node;
}
/******************************************************************************/

static void UpdateHeight(node_ty *node)
{
	node->height = 1 + MaxTwoNums(GetHeight(node->children[LEFT]), GetHeight(node->children[RIGHT]));
}

static int GetHeight(node_ty * node)
{
	if (NULL == node)
	{
		return 0;
	}

	return node->height;
}

static int MaxTwoNums(int left, int right)
{
	return left > right? left: right; 

}

/******************************************************************************/

static node_ty * RecRemoveIMP(node_ty *tree_node, void *data, avl_cmp_func_ty cmp_func, void *params)
{
	int side = 0;
	int res = 0;
	
	/*if NULL*/
	if(NULL == tree_node)
	{
		return FALSE;
	}

	/*cmp func*/
	res = cmp_func(tree_node->data, data, params);
	
	if (0 == res)
	{
		return DestroyNodeIMP(tree_node);	
	}
	
	/*side to choose to go to*/
	side = (0 < res) ? LEFT: RIGHT;

	/*keep searching*/
	tree_node->children[side] = RecRemoveIMP(tree_node->children[side], data, cmp_func, params);
	
	/*UpdateHeight*/
	UpdateHeight(tree_node);
}


static node_ty * DestroyNodeIMP(node_ty * tree_node)
{
	node_ty *temp_node = NULL;
	
	/*if one child or no children*/
	if (NULL == tree_node->children[LEFT])
	{
		/*if no children or has right child, free curr return the right(may be NULL) */
		temp_node = tree_node->children[RIGHT];	
		/*free curr*/
		free(tree_node);
		return temp_node;
	}
	else if (NULL == tree_node->children[RIGHT])
	{			
		/*if no children or has left child, free curr return the right(may be NULL) */
		temp_node = tree_node->children[LEFT];	
		/*free curr*/
		free(tree_node);
		return temp_node;	
	}
	else
	{		
	/*two children*/
	temp_node = TraverseLeft(tree_node->children[RIGHT]);
	tree_node->data = temp_node->data;
	DestroyNodeIMP(temp_node);

	}
}


static node_ty *TraverseLeft(node_ty *curr)
{
	
	if (NULL == curr->children[LEFT])
	{
		return curr;
	}
	
	TraverseLeft(curr->children[LEFT]);
}

/******************************************************************************/
static node_ty* RecFindIMP(node_ty *node, void *data, avl_cmp_func_ty cmp_func, void *params)
{
	int res = 0;
	int side = 0;
	
	/*if NULL*/
	if (NULL == node)
	{
		return NULL;
	}
	
	/*cmp data with current*/
	res = cmp_func(node->data, data, params);
	
	if (0 == res)
	{
		/*found*/
		return node;
	}
	
	side = (0 < res) ? LEFT: RIGHT;

	return RecFindIMP(node->children[side], data, cmp_func, params);

}

static void CalcSize(node_ty *node, size_t *size)
{
	if (NULL == node)
	{
		return;
	}
	
	CalcSize(GetLeftChild(node), size);
	++*size;
	CalcSize(GetRightChild(node), size);
		
}



static int PreOrder(node_ty * node, avl_action_func_ty action_func, void* params)
{
	int res = 0;
	
	if (NULL ==  node)
	{
		return SUCCESS;
	} 	

	res = action_func(node->data, params);
	
	if (FAILURE == res )
	{
		return FAILURE;
	}
	
	res = PreOrder(node->children[LEFT], action_func, params);
	
	if (FAILURE == res )
	{
		return FAILURE;
	}
	
	res  == PreOrder(node->children[RIGHT], action_func, params);

	if (FAILURE == res )
	{
		return FAILURE;
	}
		
	return SUCCESS;

}


static int InOrder(node_ty * node, avl_action_func_ty action_func, void* params)
{
	int res = 0;
	
	if (NULL ==  node)
	{
		return SUCCESS;
	} 	

	res = InOrder(node->children[LEFT], action_func, params);
	
	if (FAILURE == res )
	{
		return FAILURE;
	}
	
	res = action_func(node->data, params);
	
	if (FAILURE == res )
	{
		return FAILURE;
	}
	
	res = InOrder(node->children[RIGHT], action_func, params);
	
	if (FAILURE == res )
	{
		return FAILURE;
	}
	
	return SUCCESS;	
}

static int PostOrder(node_ty * node, avl_action_func_ty action_func, void* params)
{
	int res = 0;
	
	if (NULL ==  node)
	{
		return SUCCESS;
	} 	


	res = PostOrder(node->children[LEFT], action_func, params);
	
	if (FAILURE == res )
	{
		return FAILURE;
	}
		
	res = PostOrder(node->children[RIGHT], action_func, params);
	
	if (FAILURE == res )
	{
		return FAILURE;
	}
	
	res = action_func(node->data, params);
	
	if (FAILURE == res )
	{
		return FAILURE;
	}
	
	return SUCCESS;
}



static int IsLeaf(node_ty *node)
{
	if (NULL == node->children[LEFT] && NULL == node->children[LEFT])
	{
		return TRUE;
	}


	return FALSE;
}

static node_ty* GetLeftChild(node_ty *node)
{
	return node->children[LEFT];
}

static node_ty* GetRightChild(node_ty *node)
{
	return node->children[RIGHT];
}

static void BalanceNode(node_ty *node, avl_cmp_func_ty cmp_func, void *params) 
{
	int balanceFactor = GetHeight(node->children[RIGHT]) - GetHeight(node->children[LEFT]);

	if (balanceFactor > 1) 
	{
		if (cmp_func(node->children[RIGHT]->data, node->data, params) > 0)
		{
			LeftRotate(node);
		} 
		else 
		{
			RightRotate(node->children[RIGHT]);
			LeftRotate(node);
		}
    	}
	else if (balanceFactor < -1)
    	{
		if (cmp_func(node->children[LEFT]->data, node->data, params) < 0) 
		{
			RightRotate(node);
		} 
		else 
		{
			LeftRotate(node->children[LEFT]);
			RightRotate(node);
		}
   	}
}

static void LeftRotate(node_ty *node) 
{

}

static void RightRotate(node_ty *node) 
{

}



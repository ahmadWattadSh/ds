/*Name: AhmadWattad
  Project: Work Sheet 11 - Data Structures - DLL
  Reviewer: Idan
  Date: 23/08/2023
  Version: 1.0: published the program
  		*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "bin_trie.h"


/******************************* Definitions **********************************/
typedef struct node node_ty;
enum {LEFT = 0, RIGHT, NUM_OF_CHILDREN};
enum {SUCCESS = 0, FAILURE};

struct bin_trie
{
	node_ty root;
	size_t depth;
};

struct node
{
	int is_full;
	node_ty *children[NUM_OF_CHILDREN];
};

/****************************** static functions ******************************/


/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/

bin_trie_ty *BinTrieCreate(size_t depth)
{
	assert(depth < 65);
	
	bin_trie_ty *trie = (bin_trie_ty*)malloc(sizeof(bin_trie_ty));
	
	if(NULL == trie)
	{
		return NULL;
	}
	
	trie.root = (node_ty*)malloc(sizeof(node_ty));
	
	if(NULL == trie.root)
	{
		BinTrieDestroy(trie);
		return NULL;
	
	}
	
	InitNode(&trie.root);
	
	trie.depth = depth;
		
}


void BinTrieDestroy(bin_trie_ty* trie);
{
	if (NULL ==  trie)
	{
		return;
	}
	
	BinTrieDestroy(trie->root[LEFT]);
	BinTrieDestroy(trie->root[RIGHT]);

	free(root);
}

static BinTrieDestroyImp(node_ty *node)
{
	if (NULL == node)
	{
		return;
	}

	BinTrieDestroyImp(node[LEFT]);
	BinTrieDestroyImp(node[RIGHT]);
	
	free(node);
}

/* requested : 0 if you don't care 
  Returns: may be diffrent from requsted if not available
  			return 0.0.0.0 if all the ips is allocated
  Complexity: O(1).*/
int BinTrieAllocate(bin_trie_ty* trie, ip_ty requsted)
{
	/*assert*/
	assert(NULL != trie);
	/*recurseive func*/
	return BinTrieAllocateImp(&trie->root, requsted, trie->depth);

}

static int BinTrieAllocateImp(node_ty *subtree, ip_ty requsted, size_t depth )
{
	/*calculate the next node*/
	int child = (requsted >> (depth - 1)) & 1;
	
	if (1 == subtree->is_full)
	{
		return FAILURE;
	}
	
	/*if it is a leaf, update that it is full and*/
	/*return success*/
	if (0 == depth)
	{
		subtree->is_full = 1;
		return SUCCESS;
	}
	
	/*create the node if doesn't exist*/
	if (NULL == subtree->children[child])
	{
		subtree->children[child] = (node_ty*)malloc(sizeof(node_ty));
		
		if (NULL == subtree->children[child])
		{
			return FAILURE;
		}
		
		InitNode(subtree->children[child]);
	}
	/*if it exists move to the next left or right according to requested*/
	if(!BinTrieAllocateImp(subtree->children[child], requested, depth - 1))
	{
		
		return FAILURE;
	}
	
	/*update is_full for the other nodes in the tree*/
	if (NULL != subtree->children[LEFT] && NULL != subtree->children[RIGHT] && 
		subtree->children[LEFT]->is_full = 1 && subtree->children[RIGHT]->is_full = 1)
	{
		subtree->is_full = 1;
	}	
	
	return SUCCESS;
		
}	

static void InitNode(node_ty *node)
{
	node->is_full = 0;
	node->children[LEFT] = NULL;
	node->children[Right] = NULL;
}

void BinTrieFree(bin_trie_ty* trie, ip_ty address)
{
	/*assert*/
	assert(NULL != trie);
	/*recurseive func*/
	return BinTrieFreeImp(&trie->root, requsted, trie->depth);

}


static int BinTrieFreeImp(node_ty *subtree, ip_ty address, size_t depth)
{
	int child = (requsted >> (depth - 1)) & 1;
	
	/*if you don't get to the leaf because it doesn't exist, fail it*/
	if (NULL == subtree)
	{
		return FAILURE;
	}
	
	/*if it is a leaf, delete it*/
	if (0 == depth)
	{
		free(subtree);
		return SUCCESS;
	}
	
	/*recursively do that for the next child*/
	BinTrieFreeImp(subtree[child], address, depth - 1);
	
	/*after deleting the theif, check if the node was full*/
		/*then just update it to not full*/
	/*else delete it if it is not the root*/	
	if ( 1 == subtree->is_full)
	{
		subtree->is_full = 0;
	}
	else /*TODO:if not root*/
	{
		free(subtree);
		return SUCCESS;
	}
}


size_t BinTrieCountFree(bin_trie_ty* trie)
{
	






}




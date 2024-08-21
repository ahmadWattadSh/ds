/*
  Name: Agbaria ahmad
  Project: binary trie tree
  Reviewer: ---
  Date: 02/11/2023

  Project Overview: API for binary trie for bits.
*/

#ifndef __ILRD_BIN_TRIE_H__
#define __ILRD_BIN_TRIE_H__

/******************************** Libraries  ********************************/

#include <stddef.h> /*size_t*/

#define STATIC_ASSERT(NAME, SHOULD_BE_TRUE) typedef int NAME[1/(SHOULD_BE_TRUE)]

/******************************** Definitions  ******************************/

typedef unsigned int ip_ty;

typedef struct bin_trie bin_trie_ty ;
/************************* DHCP API Declerations  *****************************/

/*
  args :
  Return: NULL in case of allocation failure
  Complexity: O(1). 
  */ 
bin_trie_ty *BinTrieCreate(size_t num_of_bits);

/*
  Arguments: NULL is allowed (will do nothing).
  Complexity: O(n). */
void BinTrieDestroy(bin_trie_ty* trie);

/* requested : 0 if you don't care 
  Returns: may be diffrent from requsted if not available
  			return 0.0.0.0 if all the ips is allocated
  Complexity: O(1).*/
int BinTrieAllocate(bin_trie_ty* trie, ip_ty requsted);

/*Returns: 
  Complexity: O(1)*/
 /*UNDIFINED if you free an address that is not your's*/
void BinTrieFree(bin_trie_ty* trie, ip_ty address);

/*Complexity: O(?).
*/
size_t BinTrieCountFree(bin_trie_ty* trie);

#endif /*(__ILRD_BIN_TRIE_H__)*/   

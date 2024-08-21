/*Name: AhmadWattad
  Project: SortedList
  Reviewer: Sahar
  Date: 28/08/2023
  Version: 1.0: published the program
  		*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/
#include <string.h> /*memcpy*/

#include "dhcp.h"
#include "bin_trie.h"

/*************************** forwarded declarations ***************************/
static int ActionFuncSize(void* data, void* param);
static int MatchFuncIfSmallerOrEqual(const void *data, void *params);
static int MatchFuncForFIND(const void *data, void *params);

/***************************** Definitions ************************************/


struct dhcp
{
	bin_trie_ty *trie;
	int is_full;
	ip_ty subnet;
	ip_ty mask;
};

/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/

dhcp_ty *CreateDhcp(ip_ty subnet, ip_ty mask);
{
	dhcp_ty *dhcp = NULL;
	bin_trie_ty *trie = NULL;
	
	/*assert that the mask ends with zeros*/
	assert()
	dhcp_ty *dhcp = (dhcp_ty*)malloc(sizeof(dhcp_ty));
	
	if (NULL == dhcp)
	{
		DestroyDhcp(dhcp);
	}
	
	CalculateDepth(mask)
	
	/*create trie*/
	trie = BinTrieCreate(depth);
	
	if (NULL == trie)
	{
		return NULL;
	}
	
	/*init dhecp*/
	dhcp->trie = trie;
	dhcp->subnet = subnet;
	dhcp->mask = mask;
	dhcp->is_full = FALSE;	

}

static int CalculateDepth(unsigned int mask)
{
	while (mask)



}



void DestroyDhcp(dhcp_ty* dhcp)
{
	/*assert*/
	/*if NULL */
	/*return;*/

	/*destroy trie*/
	/*destroy dhcp*/
	
		
}



int AllocateIp(dhcp_ty* dhcp, ip_ty requsted)
{
	/*assert*/
	/*allocate in trie*/
	/*return if successful*/


}

size_t FreeIp(dhcp_ty* dhcp, ip_ty address)
{
	/*assert*/
	/*free from trie*/


}

void* CountFree(dhcp_ty* dhcp)
{
 	return BinTrieCountFree(dhcp->trie);
}


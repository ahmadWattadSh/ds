/*
  Name: Agbaria ahmad
  Project: DHCP
  Reviewer: ---
  Date: 02/11/2023

  Project Overview: API for a DHCP - Dynamic Host Configuration Protocol.
*/

#ifndef __ILRD_DHCP_H__
#define __ILRD_DHCP_H__

/******************************** Libraries  ********************************/

#include <stddef.h> /*size_t*/

#define STATIC_ASSERT(NAME, SHOULD_BE_TRUE) typedef int NAME[1/(SHOULD_BE_TRUE)]

/******************************** Definitions  ******************************/

typedef unsigned int ip_ty;

typedef struct dhcp dhcp_ty ;
/************************* DHCP API Declerations  *****************************/

/*
  args : mask must have consecutive zeros at the end (need assert)
  Return: NULL in case of allocation failure
  Complexity: O(1). 
  Args: never NULL*/
  /*must add assert to the mask - is available mask*/ 
dhcp_ty *CreateDhcp(ip_ty subnet, ip_ty mask);

/*
  Arguments: NULL is allowed (will do nothing).
  Complexity: O(n). */
void DestroyDhcp(dhcp_ty* dhcp);

/* requested : 0 if you don't care 
  Returns: may be diffrent from requsted if not available
  			return 0.0.0.0 if all the ips is allocated
  Complexity: O(1).*/
int AllocateIp(dhcp_ty* dhcp, ip_ty requsted);

/*Returns: free ip from dhcp_
  Complexity: O(1)*/
 /*UNDIFINED if you free an address that is not your's*/
size_t FreeIp(dhcp_ty* dhcp, ip_ty address);

/*Complexity: O(?).
*/
void* CountFree(dhcp_ty* dhcp);

#endif /*(__ILRD_DHCP_H__)*/          

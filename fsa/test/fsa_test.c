/*Name: AhmadWattad
  Project: Work Sheet 6 - Data Structures - Singly Linked LIst
  Reviewer: Idan
  Date: 23/08/2023
  Version: 1.0
*/


/******************************************************************************/
#include <stdio.h>/*printf*/
#include <stdlib.h> /*	malloc	*/
#include <stdio.h> 

#include "fsa.h"

#define ErrorMsg(expected, result, name) \
	{\
		if (expected == result)\
		{\
			printf("%s has succeeded\n",  name);\
		}\
		else\
		{\
			printf("%s has failed\n",  name);\
		}\
}

#define ErrorMsgNotEqual(expected, result, name) \
	{\
		if (expected != result)\
		{\
			printf("%s has succeeded\n",  name);\
		}\
		else\
		{\
			printf("%s has failed\n",  name);\
		}\
}
#define ErrorMsgEqualWithReturn(expected, result, res) \
	{\
		if (expected == result)\
		{\
			res = 0;\
		}\
		else\
		{\
			res = 1;\
		}\
}

#define ErrorMsgNotEqualWithReturn(expected, result, res) \
	{\
		if (expected != result)\
		{\
			res = 0;\
		}\
		else\
		{\
			res = 1;\
		}\
}

/************************** Forwarded declarations ****************************/

static void UnitTesting();
static void CreateTest();
static void SuggestedTest();
static void AllocTest();
static void FreeTest();
static void CountFreeTest();

/*********************************** main *************************************/

int main()
{
	UnitTesting();

	return 0;
}

/******************************************************************************/

static void UnitTesting()
{
	SuggestedTest();
	AllocTest();
	FreeTest();
	CountFreeTest();
	CreateTest();
}
/******************************************************************************/	

static void SuggestedTest()
{
	size_t num_of_bytes_for_alloc = FSA_SuggestedSize(10, 3);
		
	ErrorMsg(56, num_of_bytes_for_alloc, "SuggestedTest");	
}

static void CreateTest()
{
	size_t num_of_bytes_for_alloc = FSA_SuggestedSize(10, 3);	
	char *pool = (char *)malloc(num_of_bytes_for_alloc);	 
	fsa_t *fsa = FSA_Init((void*)pool, 10, num_of_bytes_for_alloc);
	size_t *segment1 = NULL;
	int res = 0;

	segment1 = (size_t *)FSA_Alloc(fsa);
	ErrorMsgNotEqualWithReturn(NULL, segment1, res);
	FSA_Free(fsa, (void*)segment1);	
	ErrorMsgEqualWithReturn(FSA_CountFree(fsa), 3, res)

	ErrorMsg(0 , res, "CreateTest");

	free(pool);
}

static void AllocTest()
{
	size_t num_of_bytes_for_alloc = FSA_SuggestedSize(10, 3);
		
	char *pool = (char *)malloc(num_of_bytes_for_alloc);	 
	
	fsa_t *fsa = FSA_Init((void*)pool, 10, num_of_bytes_for_alloc);
	
	size_t *segment = NULL;	
	
	segment = (size_t *)FSA_Alloc(fsa);
	ErrorMsgNotEqual(NULL , segment, "AllocTest1");	
	
	segment = (size_t *)FSA_Alloc(fsa);	
	ErrorMsgNotEqual(NULL , segment, "AllocTest2");		
	
	segment = (size_t *)FSA_Alloc(fsa);
	ErrorMsgNotEqual(NULL , segment, "AllocTest3");			
	
	segment = (size_t *)FSA_Alloc(fsa);
	ErrorMsg(NULL, segment, "AllocTest4");
			
	free(pool);
}

static void FreeTest()
{
	size_t num_of_bytes_for_alloc = FSA_SuggestedSize(10, 3);
		
	char *pool = (char *)malloc(num_of_bytes_for_alloc);	 
	
	fsa_t *fsa = FSA_Init((void*)pool, 10, num_of_bytes_for_alloc);
	
	size_t *segment1 = NULL;	
	size_t *segment2 = NULL;	
	size_t *segment3 = NULL;		
	
	segment1 = (size_t *)FSA_Alloc(fsa);
	segment2 = (size_t *)FSA_Alloc(fsa);
	segment3 = (size_t *)FSA_Alloc(fsa);
	
	FSA_Free(fsa, (void*)segment2);
	ErrorMsg(1, FSA_CountFree(fsa), "FreeTest1");		
	FSA_Free(fsa, (void*)segment3);
	ErrorMsg(2, FSA_CountFree(fsa), "FreeTest2");		
				
	free(pool);
}

static void CountFreeTest()
{
	size_t num_of_bytes_for_alloc = FSA_SuggestedSize(10, 5);
	char *pool = (char *)malloc(num_of_bytes_for_alloc);	 
	fsa_t *fsa = FSA_Init((void*)pool, 10, num_of_bytes_for_alloc);
	size_t *segment1 = NULL;		
	size_t counter = FSA_CountFree(fsa);	
	
	ErrorMsg(5, counter, "CountFreeTest1");		
	segment1 = (size_t *)FSA_Alloc(fsa);	
	counter = FSA_CountFree(fsa);		
	ErrorMsg(4, counter, "CountFreeTest2");							
	segment1 = (size_t *)FSA_Alloc(fsa);
	counter = FSA_CountFree(fsa);				
	ErrorMsg(3, counter, "CountFreeTest2");								
	FSA_Free(fsa, (void*)segment1);
	counter = FSA_CountFree(fsa);	
	ErrorMsg(4, counter, "CountFreeTest2");								
			
	free(pool);

}







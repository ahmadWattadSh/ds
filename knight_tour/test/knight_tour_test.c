/*
  Name: Ahmad Wattad
  Project: BST
  Reviewer: ??
  Date: 27/09/23
*/


/******************************************************************************/
#include <stdio.h>/*printf*/
#include <stdio.h> 
#include <stdlib.h>

#include "knight_tour.h"


#define ErrorMsgEqual(expected, result, name) \
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
#define ErrorMsgNotEqual(expected, result, name, res) \
	{\
		if (expected != result)\
		{\
			printf("%s has succeeded\n",  name);\
		}\
		else\
		{\
			printf("%s has failed\n",  name);\
			res = 1;\
		}\
}
#define ErrorMsgBiggerThan(expected, result, name, res) \
	{\
		if (expected <= result)\
		{\
			printf("%s has succeeded\n",  name);\
		}\
		else\
		{\
			printf("%s has failed\n",  name);\
			res = 1;\
		}\
}

/************************** Forwarded declarations ****************************/
static void UnitTesting();
static void TestKnightTour();

/*********************************** main *************************************/

int main()
{
	UnitTesting();

	return 0;
}

/******************************************************************************/

static void UnitTesting()
{
	TestKnightTour();
}


static void TestKnightTour()
{

    pos_ty *path = (pos_ty*)malloc(sizeof(pos_ty)*64);
    int status = IsKnightAble(0,0,path);
    int i = 0;

    if(status)
    {
        printf("Success!\n");
    }
    else
    {
        printf("Failed!\n");
    }
    printf("the path is:\n");
    while(64 > i)
    {
        printf("%d , %d\n", path[i].x, path[i].y);
        ++i;
    }
    
    return ;


}

/******************************************************************************/	




/*Name: AhmadWattad
  Project: Data Structures - UID
  Reviewer: Uri
  Date: 06/09/23
*/


/******************************************************************************/
#include <stdio.h>/*printf*/

#include "uid.h"

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

/************************** Forwarded declarations ****************************/

static void UnitTesting();

static void CreateTest();
static void IsSameTest();


/*********************************** main *************************************/

int main()
{
	UnitTesting();

	return 0;
}

/******************************************************************************/

static void UnitTesting()
{
	CreateTest();
	IsSameTest();
	
}
/******************************************************************************/	


static void CreateTest()
{

	uid_ty uid = UIDCreate();

	ErrorMsg(FALSE , UIDIsSame(uid, bad_uid), "CreateTest");
	
}

static void IsSameTest()
{
	uid_ty uid1 = UIDCreate();
	uid_ty uid2 = UIDCreate();
	
	ErrorMsg(FALSE , UIDIsSame(uid1, uid2), "IsSameTest-false");	
	ErrorMsg(TRUE , UIDIsSame(uid1, uid1), "IsSameTest-true");	
}







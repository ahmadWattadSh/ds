#include <stdio.h>/*printf()*/
#include <string.h>/*strcmp()*/

#include "BitArray.h"


/******************************************************************************/

void TestProgram();
void SetAll_test();
void ResetAll_test();
void SetOn_test();
void SetOff_test();
void SetBit_test();
void GetVal_test();
void Flip_test();
void Mirror_test();
void RotateRight_test();
void RotateLeft_test();
void ToString_test();
void CountOn_test();
void CountOff_test();
void CountOnLut_test();
void MirrorLut_test();




/********************************* main ***************************************/

int main()
{

	TestProgram();
	return 0;
}

/******************************************************************************/

void TestProgram()
{	
	SetAll_test();
	ResetAll_test();	
	SetOn_test();
	SetOff_test();
	SetBit_test();
	GetVal_test();
	Flip_test();
	Mirror_test();
	RotateRight_test();
	RotateLeft_test();
	CountOn_test();
	CountOff_test();
	ToString_test();
	CountOnLut_test();
	MirrorLut_test();
}

/******************************************************************************/

void SetAll_test()
{
	bit_array_ty arr_bit = 0;
	
 	if (0xffffffffffffffff == SetAll(arr_bit))
 	{
 		printf("SetAll function passed the test\n");
 	}
 	else
 	{
 		printf("SetAll function not passed the test\n");
 	}
}

/******************************************************************************/
 
void ResetAll_test()
{
	bit_array_ty arr_bit = 0;
	
 	if (0 == ResetAll(arr_bit))
 	{
 		printf("ResetAll function passed the test\n");
 	}
 	else
 	{
 		printf("ResetAll function not passed the test\n");
 	}
}

/******************************************************************************/

void SetOn_test()
{
	bit_array_ty arr_bit = 0;
	
	if (128 == SetOn(arr_bit, 7))
 	{
 		printf("SetOn function passed the test\n");
 	}
 	else
 	{
 		printf("SetOn function not passed the test\n");
 	}
}

void SetOff_test()
{
	bit_array_ty arr_bit = 15;
	
	if (7 == SetOff(arr_bit, 3))
 	{
 		printf("SetOff function passed the test\n");
 	}
 	else
 	{
 		printf("SetOff function not passed the test\n");
 	}
}

void SetBit_test()
{
	bit_array_ty arr_bit = 15;
	
	if (7 == SetBit(arr_bit, 3, 0))
 	{
 		printf("SetBit function passed the test\n");
 	}
 	else
 	{
 		printf("SetBit function not passed the test\n");
 	}
}

void GetVal_test()
{
	bit_array_ty arr_bit = 0xAF;
	
	if (1 == GetVal(arr_bit, 5))
 	{
 		printf("GetVal function passed the test\n");
 	}
 	else
 	{
 		printf("GetVal function not passed the test\n");
 	}
}

void Flip_test()
{
	bit_array_ty arr_bit = 0xffffffff00000000;
	
	if (0x00000000ffffffff == Flip(arr_bit))
 	{
 		printf("Flip function passed the test\n");
 	}
 	else
 	{
 		printf("Flip function not passed the test\n");
 	}
}

void Mirror_test()
{
	bit_array_ty arr_bit = 0x0000000000000001;
	
	if (0x8000000000000000 == Mirror(arr_bit))
 	{
 		printf("Mirror function passed the test\n");
 	}
 	else
 	{
 		printf("Mirror function not passed the test\n");
 	}
}

void RotateRight_test()
{
	bit_array_ty arr_bit = 0x0000000000100001;
	
	if (0x0000100000000001 == RotateRight(arr_bit,20))
	{
 		printf("RotateRight function passed the test\n");
 	}
 	else
 	{
 		printf("RotateRight function not passed the test\n");
 	}
}

void RotateLeft_test()
{
	bit_array_ty arr_bit = 1;
	
	if (0x0000000000100000 == RotateLeft(arr_bit,20))
	{
 		printf("RotateLeft function passed the test\n");
 	}
 	else
 	{
 		printf("RotateLeft function not passed the test\n");
 	}
}

void CountOn_test()
{
	bit_array_ty arr_bit = 0xFF;
	
	if (8 == CountOn(arr_bit))
 	{
 		printf("CountOn function passed the test\n");
 	}
 	else
 	{
 		printf("CountOn function not passed the test\n");
 	}
}

void CountOff_test()
{
	bit_array_ty arr_bit = 0xFFFFFFFFFFFFFFF0;
	
	if (4 == CountOff(arr_bit))
 	{
 		printf("CountOff function passed the test\n");
 	}
 	else
 	{
 		printf("CountOff function not passed the test\n");
 	}
}

void ToString_test()
{
	char str[65] = {0};
	char str2[65] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'
	,'0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','0','0'};
	bit_array_ty arr_bit = 12;	
	

	if (0 == strcmp(ToString(arr_bit, str), str2))
 	{
 		printf("ToString function passed the test\n");
 	}
 	else
 	{
 		printf("ToString function not passed the test\n");
 	}
}
 

void CountOnLut_test()
{
	bit_array_ty arr_bit = 3;
	
	if (2 == CountOnLut(arr_bit))
 	{
 		printf("CountOnLut function passed the test\n");
 	}
 	else
 	{
 		printf("CountOnLut function not passed the test\n");
 	}
}

void MirrorLut_test()
{
	bit_array_ty arr_bit = 0x0000000000000001;
	
	if (0x8000000000000000 == MirrorLut(arr_bit))
 	{
 		printf("MirrorLut function passed the test\n");
 	}
 	else
 	{
 		printf("MirrorLut function not passed the test\n");
 	}
}



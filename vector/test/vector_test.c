#include <stdio.h>/*printf()*/
#include <string.h> /*memcpy*/

#include "vector.h"

struct vector
{
	size_t capacity;
	size_t size;
	size_t element_size;
	void *vector_arr;
};


static void TestProgram();
static int TestDouble();
static int TestInt();
/********************************* main ***************************************/

int main()
{

	TestProgram();
	return 0;
}

/******************************************************************************/



static void TestProgram()
{
	TestInt();
	printf("*************************\n\n");
	TestDouble();
	
}

static int TestInt()
{
	vector_ty *example3 = VectorCreate((size_t)3 , (size_t)4);
	
	int x1 = 1;
	int x2 = 2;
	int x3 = 3;
	int x4 = 4;
	int x5 = 5;
	int x6 = 5;
	int peeked = 0;

	VectorPushBack(example3, (void*)&x1);
	printf("Pushback 1:\n");
	printf("Capacity = %ld\n", VectorCapacity(example3));
	printf("size = %ld\n", VectorSize(example3));
	peeked = *(int*)VGetAccessToElement(example3, 0);
	printf("value = %d\n\n", peeked);	
	
	VectorPushBack(example3, (void*)&x2);
	printf("Pushback 2:\n");
	printf("Capacity = %ld\n", VectorCapacity(example3));
	printf("size = %ld\n", VectorSize(example3));
	peeked = *(int*)VGetAccessToElement(example3, 1);
	printf("value = %d\n\n", peeked);	
	
	VectorPushBack(example3, (void*)&x3);
	printf("Pushback 3:\n");
	printf("Capacity = %ld\n", VectorCapacity(example3));
	printf("size = %ld\n", VectorSize(example3));
	peeked = *(int*)VGetAccessToElement(example3, 2);
	printf("value = %d\n\n", peeked);
	
	VectorPushBack(example3, (void*)&x4);
	printf("Pushback 4:\n");
	printf("Capacity = %ld\n", VectorCapacity(example3));
	printf("size = %ld\n", VectorSize(example3));
	peeked = *(int*)VGetAccessToElement(example3, 3);
	printf("value = %d\n\n", peeked);

	VectorPopBack(example3);
	printf("Popback 1:\n");
	printf("Capacity = %ld\n", VectorCapacity(example3));
	printf("size = %ld\n\n", VectorSize(example3));

	
	VectorPopBack(example3);
	printf("Popback 1:\n");
	printf("Capacity = %ld\n", VectorCapacity(example3));
	printf("size = %ld\n\n", VectorSize(example3));
	
	if(FAILURE == VectorReserve(example3, 3))
	{
		printf("FAIlED TO RESERVE\n");
		return FAILURE;
	}

	VectorDestroy(example3);
	printf("Vector was destroyed\n\n");
}

static int TestDouble()
{
	
	vector_ty *example2 = VectorCreate((size_t)3 , (size_t)8);;

	double x11 = 1;
	double x22 = 2;
	double x33 = 3;
	double x44 = 4;
	double x55 = 5;
	double x66 = 5;
	double peeked2 = 0;
	
	VectorPushBack(example2, (void*)&x11);
	printf("Pushback 1:\n");
	printf("Capacity = %ld\n", VectorCapacity(example2));
	printf("size = %ld\n", VectorSize(example2));
	peeked2 = *(double*)VGetAccessToElement(example2, 0);
	printf("value = %lf\n\n", peeked2);	
	
	VectorPushBack(example2, (void*)&x22);
	printf("Pushback 2:\n");
	printf("Capacity = %ld\n", VectorCapacity(example2));
	printf("size = %ld\n", VectorSize(example2));
	peeked2 = *(double*)VGetAccessToElement(example2, 1);
	printf("value = %lf\n\n", peeked2);	
	
	VectorPushBack(example2, (void*)&x33);
	printf("Pushback 3:\n");
	printf("Capacity = %ld\n", VectorCapacity(example2));
	printf("size = %ld\n", VectorSize(example2));
	peeked2 = *(double*)VGetAccessToElement(example2, 2);
	printf("value = %lf\n\n", peeked2);	
	
	VectorPushBack(example2, (void*)&x44);
	printf("Pushback 4:\n");
	printf("Capacity = %ld\n", VectorCapacity(example2));
	printf("size = %ld\n", VectorSize(example2));
	peeked2 = *(double*)VGetAccessToElement(example2, 3);
	printf("value = %lf\n\n", peeked2);	
		
	VectorPopBack(example2);
	printf("Popback 1:\n");
	printf("Capacity = %ld\n", VectorCapacity(example2));
	printf("size = %ld\n\n", VectorSize(example2));
	
	VectorPopBack(example2);
	printf("Popback 2:\n");
	printf("Capacity = %ld\n", VectorCapacity(example2));
	printf("size = %ld\n\n", VectorSize(example2));
	
	if(FAILURE == VectorReserve(example2, 3))
	{
		printf("FAIlED TO RESERVE\n");
		return FAILURE;
	}
	VectorPushBack(example2, (void*)&x55);	
	VectorPushBack(example2, (void*)&x66);
	
	VectorDestroy(example2);
	printf("Vector was destroyed\n\n");	
}



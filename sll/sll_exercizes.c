#include <stddef.h> /*NULL*/
#include <stdlib.h> /*malloc*/
#include <stdio.h> /*printf*/
#include <assert.h> /*assert*/

typedef struct node
{
	void *data;
	struct node *next;
}node_ty;

#define SUCCESS 1
#define FAILURE 0

static PrintLinkedList(node_ty *head);
static freeAll(node_ty *head);


static node_ty *Flip(node_ty *head);
static int HasLoop(node_ty *head);
static node_ty *FindIntersection(node_ty *head_1, node_ty *head2);

static void FlipTest();
static void HasLoopTest();
static void FindIntersectionTest();

int main()
{
	FlipTest();
	HasLoopTest();
	FindIntersectionTest();
	
	return 0;
}


/********************************** TESTING ***********************************/

static void FlipTest()
{
	int x1 = 2;
	int x2 = 4;
	int x3 = 6;
	int x4 = 8;
	int x5 = 10;
	
	node_ty *head = (node_ty*)malloc(sizeof(node_ty));
	node_ty *node1 = (node_ty*)malloc(sizeof(node_ty));
	node_ty *node2 = (node_ty*)malloc(sizeof(node_ty));
	node_ty *node3 = (node_ty*)malloc(sizeof(node_ty));
	node_ty *tail = (node_ty*)malloc(sizeof(node_ty));


	head->data = &x1;
	head->next = node1;
	node1->data = &x2;
	node1->next = node2;
	node2->data = &x3;
	node2->next = node3;
	node3->data = &x4;
	node3->next = tail;	
	tail->data = &x5;
	tail->next = NULL;
	
	head = Flip(head);
	
	if( *(int*)head->data == 10)
	{
		printf("Flip passed the test!\n");
	}
	else
	{
		printf("Flip didn't pass the test!\n");
	}
	
	freeAll(head);
}

static void HasLoopTest()
{
	int x1 = 2;
	int x2 = 4;
	int x3 = 6;
	int x4 = 8;
	int x5 = 10;
	
	node_ty *head = (node_ty*)malloc(sizeof(node_ty));
	node_ty *node1 = (node_ty*)malloc(sizeof(node_ty));
	node_ty *node2 = (node_ty*)malloc(sizeof(node_ty));
	node_ty *node3 = (node_ty*)malloc(sizeof(node_ty));
	node_ty *tail = (node_ty*)malloc(sizeof(node_ty));


	head->data = &x1;
	head->next = node1;
	node1->data = &x2;
	node1->next = node2;
	node2->data = &x3;
	node2->next = node3;
	node3->data = &x4;
	node3->next = tail;	
	tail->data = &x5;
	tail->next = node2;
	
	if(HasLoop(head))
	{
		printf("HasLoopTest1 passed the test!\n");
	}
	else
	{
		printf("HasLoopTest2 didn't pass the test!\n");
	}
	

	tail->next = NULL;
	
	
	if( !HasLoop(head))
	{
		printf("Flip passed the test!\n");
	}
	else
	{
		printf("Flip didn't pass the test!\n");
	}
	
	freeAll(head);
}

static void FindIntersectionTest()
{
	int x1 = 2;
	int x2 = 4;
	int x3 = 6;
	int x4 = 8;
	int x5 = 10;
	int y1 = 12;
	int y2 = 14;

	node_ty *head = (node_ty*)malloc(sizeof(node_ty));
	node_ty *node1 = (node_ty*)malloc(sizeof(node_ty));
	node_ty *node2 = (node_ty*)malloc(sizeof(node_ty));
	node_ty *node3 = (node_ty*)malloc(sizeof(node_ty));
	node_ty *tail = (node_ty*)malloc(sizeof(node_ty));
	
	node_ty *head2 = (node_ty*)malloc(sizeof(node_ty));
	node_ty *node1_2 = (node_ty*)malloc(sizeof(node_ty));
	node_ty *res_node = head;	
	
	head->data = &x1;
	head->next = node1;
	node1->data = &x2;
	node1->next = node2;
	node2->data = &x3;
	node2->next = node3;
	node3->data = &x4;
	node3->next = tail;	
	tail->data = &x5;
	tail->next = NULL;
	
	head2->data = &y1;
	head2->next = node1_2;
	node1_2->data = &y2;
	node1_2->next = node3;
	
	res_node = FindIntersection(head, head2);
	
	if(res_node == node3)
	{
		printf("FindIntersectionTest passed the test!\n");
	}
	else
	{
		printf("FindIntersectionTest didn't pass the test!\n");
	}
	
	
	node1_2->next = NULL;
	freeAll(head);
	freeAll(head2);
}	

/*************************** Flip function ************************************/

static node_ty *Flip(node_ty *head)
{

	node_ty *previous = NULL;
	node_ty *current = NULL;
	node_ty *next = NULL;
	
	assert(head);
	
	current = head;
	
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;	
		previous = current;
		current = next;	
	}
	
	return previous;
}

/****************************** Has Loop **************************************/

static int HasLoop(node_ty *head)
{
	node_ty *slow = NULL;
	node_ty *fast = NULL;
	
	assert(head);
	
	slow = head;
	fast = head;
		
	while (NULL != fast->next && NULL != fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
		{
			return SUCCESS;
		}
	}
	return FAILURE;
}

/************************** FIND INTERSECTION *********************************/

static node_ty *FindIntersection(node_ty *head_1, node_ty *head_2)
{
	node_ty *iter1 = head_1;
	node_ty *iter2 = head_2;
	
	if(head_1 == head_2)
	{
		return head_1;
	
	}
	
	while (NULL != head_2->next && NULL != head_1->next )
	{
		iter1 = iter1->next ;
		iter2 = iter2->next ;
		
		if(NULL == iter1->next  && NULL != iter2->next)
		{
			iter1 = head_2;
		}
		
		if(NULL == iter2->next  && NULL != iter1->next)
		{
			iter2 = head_1;
		}  
		
		if(iter1 == iter2)
		{
		  return iter1;
		}
	}
	
	return NULL;
}


/******************************Helper functions********************************/

static PrintLinkedList(node_ty *head)
{
	while (head->next != NULL)
	{
		printf("%d\n", *(int *)head->data);
		head = head->next;
	}
		printf("%d\n", *(int *)head->data);
	
	printf("//*********************//\n\n");
}


static freeAll(node_ty *head)
{
	node_ty *tmp_free = NULL;	
	while (head->next != NULL)
	{
		tmp_free = head;
		head = head->next;
		free(tmp_free);
		tmp_free =NULL;
	}
	free(head);	
	head = NULL;
}



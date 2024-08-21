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


int main()
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
	node1_2->next = tail;
	
	
	/*freeAll(head);*/
	
	return 0;
}




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
	}	
}




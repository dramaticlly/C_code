#include <stdio.h>
#include <stdlib.h>

/* int x;
 int *p;  // p is integer pointer

 x = 0;   // now x == 0
 p = &x;  // & takes the address of x
          // now p == &x, so *p == x
 *p = 1;  // equivalent to x = 1, since *p == x
 */




typedef struct nodeStruct{
	int data;
	struct nodeStruct *next;
} node;

void push(int _data, node **head) 
{
	/* data */
	node *temp = malloc(sizeof(node));
	temp->data = _data;
	temp->next = *head;
	*head = temp;
}

void printNode(node* _head)
{
	while(_head != NULL)
	{
		printf("%d ", _head->data);
		_head = _head->next;
	}
	printf("\n");
}

int main()
{
	printf("Hello World. \n");
	node *head = NULL;
	push(&head,2);
	push(&head,4);
	push(&head,6);
	push(&head,7);
	push(&head,8);
	printNode(head);

	return 0;
}
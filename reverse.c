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

void push(node **head, int _data)   
{
	/* data */
	node *temp = malloc(sizeof(node));
	temp->data = _data;
	temp->next = *head;   // this would make newest element to be the head
	*head = temp;
}

void printNode(node* _head)
{
	node* new = _head;
	while(new != NULL)
	{
		printf("%d ", new->data);
		new = new->next;
	}
	printf("\n");
}

void reverse1(node** head)
{
    node* prev = NULL;
    node* curr = *head;
    node* next;
    while (curr != NULL)
    {
    	next = curr->next;
    	curr->next = prev;
    	prev = curr;
    	curr = next;
    }
    *head = prev;
}

void reverse2(node** head)
{
	if (head == NULL)
		return;

	node* first = head;
	node* rest = first->next;
	if (rest == NULL)
	{	
		return;
	}
	reverse2(&rest);       //always forget to get its addr!
	first->next->next = first;
	first->next = NULL;
	
	*head = rest               
	// so rest always remian the last element, intrigue!
	// b/c the rest is pass by reference, so it actually change to last element! 
	// jump out of inner recursive call does not change that!
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
	printf("Now here's iterative reverse\n");
	reverse1(&head);
	printNode(head);
	return 0;
}

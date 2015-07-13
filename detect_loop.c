#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	/* data */
};

void push(struct node **head, int new_data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node;
}

int loop(struct node *l)
{
	struct node *first = l, *second = l;

	while(first && second && second->next)
	{
		first = first->next;
		second = first->next->next;

		if(first == second)
		{
			printf("Got the loop.");
			return 1;
		}
	}

	return 0;
}

int main()
{
	struct node *head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	head->next->next->next->next = head;
	loop(head);

	return 0;
}

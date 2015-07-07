#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void print(struct node *n)
{
	/* data */
	while(n != NULL)
	{
		printf("%d ", n->data);
		n = n->next;
	}
}

int main()
{
	struct node *head = NULL;
	struct node *second = NULL;
	struct node *third = NULL;

	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	print(head);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void rev1(struct node *h)
{
	if(h == NULL)
		return;

	printf("%d ", h->data);

	if(h->next != NULL)
		rev1(h->next->next);

	printf("%d ", h->data);
}

void rev(struct node *n)
{
	if(n == NULL)
		return;

	rev(n->next);
	printf("%d ", n->data);
}

void push(struct node** n_head, int n_data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	new_node->data = n_data;
	new_node->next = (*n_head);

	(*n_head) = new_node;
}

int main()
{
	struct node *head = NULL;

	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("rev1(): \n");
	rev1(head);

	printf("rev(): \n");
	rev(head);

	return 0;
}

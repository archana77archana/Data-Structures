#include <stdio.h>
#include <stdlib.h>

struct node 
{
	struct node *left, *right;
	int data;
};

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->data = key;
	temp->left = temp->right = NULL;

	return temp;
}

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

struct node *insert(struct node *node, int key)
{
	if(node == NULL)
		return newNode(key);

	if(key < node->data)
	{
		node->left = insert(node->left, key);
	}

	else
	{
		node->right = insert(node->right, key);
	}

	return node;
}

struct node *minValue(struct node *node)
{
	struct node *current = node;

	while(node != NULL)
	{
		current = current->left;
	}

	return current;
}

struct node *deleteNode(struct node *root, int key)
{
	if(root == NULL)
	{
		return root;
	}

	if(key < root->data)
		root->left = deleteNode(root->left, key);

	if(key > root->data)
		root->right = deleteNode(root->right, key);

	else
	{
		if(root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}

		if(root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		struct node *temp = minValue(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}

	return root;
}

int main()
{
	struct node *root = NULL;

	root = insert(root, 50);
	root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);

    printf("\nDeleting 70.\n");
    root = deleteNode(root, 70);
    inorder(root);

    return 0;
}

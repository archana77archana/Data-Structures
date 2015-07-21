
#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left, *right;
	int key;
};

struct node *search(struct node* root, int key)
{
	if(root == NULL || root->key == key)
	{
		return root;
	}
	if(root->key < key)
	{
		return search(root->right, key);
	}
	return search(root->left, key);
}

struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->key = item;
	temp->left = temp->right = NULL;

	return temp;
}

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

struct node *insert(struct node *node, int key)
{
	if(node == NULL)
		return newNode(key);

	if(key < node->key)
	{
		node->left = insert(node->left, key);
	}

	if(key > node->key)
		node->right = insert(node->right, key);

	return node;
}


int main()
{
	struct node *temp;
	struct node *root = NULL;

	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
   	insert(root, 40);
    	insert(root, 70);
    	insert(root, 60);
    	insert(root, 80);

	inorder(root);

	//found case
	printf("\nSearching for 30 in the BST.");
	temp = search(root, 30);
	if(temp)
	{
		printf("\nSearched node = %d\n", temp->key);
	}
	else
	{
		printf("\nNot found.\n");
	}

	//Not found case
	printf("\nSearching for 81 in the BST");
	temp = search(root, 91);
	if(temp)
	{
		printf("\nSearched node = %d\n", temp->key);
	}
	else
	{
		printf("\nNot found.\n");
	}	

	return 0;
}

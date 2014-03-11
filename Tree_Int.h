#ifndef TREE_INT_H
#define TREE_INT_H

#include <iostream>
#include "Node.h"

using std::ostream;
using std::cout;

class Tree_Int
{
	private:
		Node *root;
		size_t tree_size;
		/*deletion_flag is used in the deletion() when we
		have to toggle between predecessor and successor ()'s*/
		static int deletion_flag;

	public:
		Tree_Int():root(NULL), tree_size(0){}

		//~Tree_Int()//call the clear() function

		void insert(int x);

		Node* get_root()
		{
			return root;
		}

		size_t size() //number if elements in the tree
		{
			return tree_size;
		}

		bool empty()
		{
			return (tree_size == 0);
		}

		//Traversing the tree functions. Can traverse from any particular node
		void inorder(Node *node_ptr, ostream& out = cout);
		void preorder(Node *node_ptr, ostream& out = cout);
		void postorder(Node *node_ptr, ostream& out = cout);
		void levelorder(Node *node_ptr, ostream& out = cout);

		//Traverses the tree from the root
		void inorder(ostream& out = cout);
		void preorder(ostream& out = cout);
		void postorder(ostream& out = cout);
		void levelorder(ostream& out = cout);

		//Search
		Node* search(int key);

		//Delete
		bool delete_node(int value);
		bool delete_node(Node* node);

		//To check if it is a leaf node, provided the pointer to it is given
		bool is_leaf(Node* node);
		
		//To check whether a given node is a leaf node, provided the value of the node
		bool is_leaf(int value);
		
		/*To check whether the given node is the parent 
		node, provided the pointer to it is given*/
		bool is_root(Node* node);'

		/*To check whether the given node is the parent
		node, provided the value of the node*/
		bool is_root(int value);

		/*checks whether if it is a left child. If it is a root 
		then it returns false. Checks by node and the value*/
		bool is_left_child(Node* node);
		bool is_left_child(int value);

		/*Find the parent node, provided the pointer to 
		the node or the value of the node*/
		Node* get_parent(Node* node);
		Node* get_parent(int value);

		/*checks whether if it is a left child. If it is a root 
		then it returns false. Checks by node and the value*/
		bool is_right_child(Node* node);
		bool is_right_child(int value);

		/*checks whether a node has only one child. Checks by node and the value*/
		bool has_only_one_sibling(Node* node);
		bool has_only_one_sibling(int value);

		/*checks whether a node has two sinlings. 
		Checks by node and the value*/
		bool has_two_siblings(Node* node);
		bool has_two_siblings(int value);

		/*find inorder successor provided value or 
		pointer to the node*/
		Node* get_inorder_successor(Node* node);
		Node* get_inorder_successor(int value);

		/*find inorder predeccessor provided value or 
		pointer to the node*/
		Node* get_inorder_predeccessor(Node* node);
		Node* get_inorder_predeccessor(int value);

};

#endif

#include "Tree_Int.h"

#include <iostream>
#include <queue>

using std::ostream;
using std::endl;
using std::queue;

void Tree_Int::insert(int x)
{
	if(tree_size == 0) //if there is nothing in the tree
	{
		Node *node = new Node(x);
		root = node;
		++tree_size;
	}
		
	else
	{
		Node *node = new Node(x);
		Node *temp = root;
		while(1)
		{
			if(temp->get_data() > x) //using Node class
			{	
				//traverse the left sub-tree
				if(temp->get_left_ptr() == NULL)
				{
					temp->set_left_ptr(node); //left sub-tree is empty. Now we can insert the new node
					break;
				}

				else //left sub-tree is not null
				{
					temp = temp->get_left_ptr();
				}
			}

			else
				if(temp->get_data() < x)
				{
					//Traverse the right sub-tree
					if(temp->get_right_ptr() == NULL)
					{
						//Right sub-tree is empty. Insert the node
						temp->set_right_ptr(node);
						break;
					}

					else //right sub-tree is not null
					{
						temp = temp->get_right_ptr();
					}
				}

				else //data is already there. 
				{
					return;
				}
		}

		++tree_size;
	}
	return;
}

void Tree_Int::inorder(Node *node_ptr, ostream &out)
{
	if(node_ptr == NULL)
	{
		return;
	}

	else
	{
		inorder(node_ptr->get_left_ptr(), out);
		out << node_ptr->get_data() << " ";
		inorder(node_ptr->get_right_ptr(), out);
	}

	return;
}

void Tree_Int::inorder(ostream &out)
{
	inorder(get_root(), out);
	
	return;
}

void Tree_Int::preorder(Node *node_ptr, ostream& out)
{
	if(node_ptr == NULL)
	{
		return;
	}

	else
	{
		out << node_ptr->get_data() << " ";
		preorder(node_ptr->get_left_ptr(), out);
		preorder(node_ptr->get_right_ptr(), out);
	}
	return;
}

void Tree_Int::preorder(ostream &out)
{
	preorder(get_root(), out);
	return;
}

void Tree_Int::postorder(Node *node_ptr, ostream &out)
{
	if(node_ptr == NULL)
	{
		return;
	}

	else
	{
		postorder(node_ptr->get_left_ptr(), out);
		postorder(node_ptr->get_right_ptr(), out);
		out << node_ptr->get_data() << " ";
	}

	return;
}

void Tree_Int::postorder(ostream &out)
{
	postorder(get_root(), out);
	return;
}

void Tree_Int::levelorder(Node *node_ptr, ostream &out)
{
	if(node_ptr == NULL)
		return;

	queue<Node*> q;
	Node* next_node;
	
	q.push(node_ptr);
	
	while(!q.empty())
	{
		next_node = q.front(), q.pop();
		out << next_node->get_data() << " ";

		if(next_node->get_left_ptr() != NULL)
			q.push(next_node->get_left_ptr());
		
		if(next_node->get_right_ptr() != NULL)
			q.push(next_node->get_right_ptr());
	}

	return;
}

void Tree_Int::levelorder(ostream &out)
{
	levelorder(get_root(), out);
	return;
}

Node* Tree_Int::search(int value)
{
	Node* curr_node = get_root();

	while(curr_node != NULL)
	{
		if(value == curr_node->get_data())
			return curr_node;

		else
			if(value < curr_node->get_data())
				curr_node = curr_node->get_left_ptr();

		else
			if(value > curr_node->get_data())
				curr_node = curr_node->get_right_ptr();
	}

	return NULL;
}

bool Tree_Int::delete_node(int value)
{
	Node* node = search(value);
	return delete_node(node);
}

bool Tree_Int::delete_node(Node *node)
{
	if(node == NULL)
	{
		return false;
	}

	else //what if it is a leaf node
	{
		if(is_leaf(node))
		{
			/*So it is a leaf node. Now we only need to 
			delete it. So we have to set this pointer to
			the parent node. For that we need to know 
			whether it is a left child or right child*/

			if(is_root(node))
			{
				/*it is a root and it is the only node in
				the tree*/
				root = NULL;
			}

			else
				if(is_left_child(node))
					get_parent(node)->set_left_ptr(NULL);

			else 
			{
				assert(is_right_child(node));
				get_parent(node)->set_right_ptr(NULL);
			}

			delete node;
			--tree_size;
			return true;
		}

		else
		{
			/*Then it is not a leaf node. Check whether it
			is an only child*/
			if(has_only_one_sibling(node))
			{
				if(node->get_left_ptr() != NULL)
				{
					if(is_left_child(node))
						get_parent(node)->set_left_ptr(node->get_left_ptr());

					else 
						if(is_right_child(node))
							get_parent(node)->set_right_ptr(node->get_left_ptr());

					else
					{
						assert(is_root(node));
						root = node->get_left_ptr();
					}
					delete node;
					--tree_size;
					return true;
				}
				
				else
				{
					//it should be having a right child
					assert(node->get_right_ptr() != NULL);

					if(is_left_child(node))
						get_parent(node)->set_left_ptr(node->get_right_ptr());
					else
						if(is_right_child(node))
							get_parent(node)->set_right_ptr(node->get_right_ptr());
					else
					{
						assert(is_root(node));
						root = node->get_right_ptr();
					}
					delete node;
					--tree_size;
					return true;

				}

				else
				{
					assert(is_root(node));
					root = node->get_right_ptr();
				}
				delete node;
				--tree_size;
				return true;

			}

		}

		else
		{
			/*This means that it has two siblings.
			So I have to find inorder predecessor or 
			inorder successor. Always using only one of 
			them results in an unbalanced tree. So we have
			to alternate between them.*/

			assert(has_two_siblings(node));
			Node* inorder_successor_or_inorder_predecessor = NULL;
			
			if(deletion_flag == 0)
			{
				deletion_flag = 1;
				inorder_successor_or_inorder_predecessor = get_inorder_successor(node);
			}

			else
			{
				
			}
		}
	}
}

bool Tree_Int::is_leaf(Node* node)
{
	if(node == NULL)
		return false;

	return( (node->get_left_ptr() == NULL) && (node->get_right_ptr() == NULL) );
}

bool Tree_Int::is_leaf(int value)
{
	Node* node = search(value);
	return is_leaf(node);
}

bool Tree_Int::is_root(Node *node)
{
	if(node == NULL) 
		return false;

	return (get_root() == node);
}

bool Tree_Int::is_root(int value)
{
	return (get_root()->get_data() == value);
}

bool Tree_Int::is_left_child(Node *node)
{
	if(node == NULL)
		return false;

	if(is_root(node))
		return false;

	else
		return (get_parent(node)->get_left_ptr() == node);
}

bool Tree_Int::is_left_child(int value)
{
	Node* node = search(value);
	return is_left_child(node);
}

Node* Tree_Int::get_parent(Node *node)
{
	if(node == NULL)
		return NULL;

	Node* curr_node = get_root(), *prev_node = NULL;
	
	while(curr_node != NULL)
	{
		if(node->get_data() == curr_node->get_data())
			return prev_node;

		else
		{
			prev_node = curr_node;

			if(node->get_data() < curr_node->get_data())
				curr_node = curr_node->get_left_ptr();

			else
				if(node->get_data() > curr_node->get_data())
					curr_node = curr_node->get_right_ptr();
		}
	}
	return NULL;
}

Node* Tree_Int::get_parent(int value)
{
	Node* node = search(value); 
	
	return get_parent(node);
}

bool Tree_Int::is_right_child(Node *node)
{
	if(node == NULL)
		return false;

	if(is_root(node))
		return false;

	else 
		return (get_parent(node)->get_right_ptr() == node);
}

bool Tree_Int::is_right_child(int value)
{
	Node* node = search(value);

	return is_right_child(node);
}

bool Tree_Int::has_only_one_sibling(Node *node)
{
	if(node == NULL)
		return false;
	
	return (((node->get_left_ptr() != NULL) && (node->get_right_ptr() == NULL)) || 
		((node->get_left_ptr() == NULL) && (node->get_right_ptr() != NULL)));
}

bool Tree_Int::has_only_one_sibling(int value)
{
	Node* node = search(value);

	return has_only_one_sibling(node);
}


bool Tree_Int::has_two_siblings(Node *node)
{
	if(node == NULL)
		return false;

	return ((node->get_left_ptr() != NULL) && (node->get_right_ptr() != NULL));
}

bool Tree_Int::has_two_siblings(int value)
{
	Node* node = search(value);
	return has_two_siblings(node);
}

Node* Tree_Int::get_inorder_successor(Node *node)
{
	/*returns NULL if not found.*/
	if(node == NULL)
	{
		return NULL;
	}

	else
	{
		/*Node ia present*/
		if(node->get_right_ptr() != NULL)
		{
			/*right subtree is not NULL.Return the left 
			most child*/
			Node* curr_node = node->get_right_ptr();

			while(curr_node->get_left_ptr() != NULL)
				curr_node = curr_node->get_left_ptr();
		}
		return curr_node;

	}

	else
	{
		/*Right subtree is NULL. Start from root and move 
		down the tree. Save node when moving left. 
		Inorder successor can be NULL*/

		/*inorder successor of the greatest node of 
		the tree will be NULL*/
		Node* succ_node = NULL;
		Node* curr_node = get_root();
		while(curr_node != NULL)
		{
			if(node->get_data() < curr_node->get_data())
			{
				/*Save curr_node, it might be the answer*/
				succ_node = curr_node;
				curr_node = curr_node->get_left_ptr();
			}

			else 
				if(node->get_data() > curr_node ->get_data())
					curr_node = curr_node->get_right_ptr();

			else
				break; //found node
		}
		return succ_node;
	}
}

Node* Tree_Int::get_inorder_successor(int value)
{
	Node* node_ptr = search(value);
	return get_inorder_successor(node_ptr);
}

Node* Tree_Int::get_inorder_predeccessor(Node *node)
{
	if(node == NULL)
		return NULL;

	else
	{
		if(node->get_left_ptr() != NULL)
		{
			Node* curr_node = node->get_left_ptr();

			while(curr_node->get_right_ptr() != NULL)
				curr_node = curr_node->get_right_ptr();

			return curr_node;
		}

		else
		{
			Node* succ_node = NULL;
			Node* curr_node = get_root();

			while(curr_node != NULL)
			{
				if(node->get_data() < curr_node->get_data())
				{
					curr_node = curr_node->get_left_ptr();
				}

				else if(node->get_data() )
			}
		}

	}
}

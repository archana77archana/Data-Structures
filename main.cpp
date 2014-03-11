#include "Tree_Int.h"
#include <iostream>

using namespace std;

int main()
{
	Tree_Int t;

	t.insert(4);
	t.insert(2);
	t.insert(1);
	t.insert(3);
	t.insert(6);
	t.insert(5);
	t.insert(7);
	t.insert(8);

	cout << "Different kinds of traversals: " << endl;
	cout << endl;

	cout << "Inorder : ", t.inorder(), cout << endl; //depth-first
	cout << "Preorder : ", t.preorder(), cout << endl; //depth-first
	cout << "Postorder : ", t.postorder(), cout << endl; //depth-first
	cout << "Levelorder : ", t.levelorder(), cout << endl; //breadth-first
	cout << endl;
	//Search
	cout << "Searching tree for specific nodes: " << endl;
	cout << endl;

	cout << "10: " << ((t.search(10) == NULL) ? "Not found" : "Found") << endl;
	cout << "4: " << ((t.search(4) == NULL) ? "Not found" : "Found") << endl;
	cout << "7: " << ((t.search(7) == NULL) ? "Not found" : "Found") << endl;
	cout << "11: " << ((t.search(11) == NULL) ? "Not found" : "Found") << endl;
	cout << endl;

	return 0;
}

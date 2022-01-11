// bt.C - Binary Tree class
#include "Btree.h"
#include "String.h"

void print_info(String & s) {
	cout << s << '\t' << s.length() << ", first letter = " << s[0] << endl;
}

const int max = 3;

int main()
{
	static const String brothers[] = { "groucho", "chico", "harpo" };
	BinaryTree<String> tree1;

	for (int i = 0; i < max; i++)
		tree1.insert(brothers[i]);					// append to Tree

	tree1.trace();
	tree1.apply(print_info);

	cout << "Copy initialization" << endl;
	BinaryTree<String> tree2 = tree1;			// Tree copy initialization
	tree2.trace();

	cout << "Assignment" << endl;
	BinaryTree<String> tree3;
	tree3 = tree2;									// Tree assignment
	tree3.trace();
	return 0;
}

/***************************************************************************

$ bt
chico
groucho
harpo
chico	5, first letter = c
groucho	7, first letter = g
harpo	5, first letter = h
Copy initialization
chico
groucho
harpo
Assignment
chico
groucho
harpo

*/

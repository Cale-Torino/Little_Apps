// mutable.c - mutable with structures
#include <iostream.h>

struct node {
	int data;								// integer data
	node *fwd;								// pointer to next node
	mutable node *last;					// pointer to last node accessed
	node *find_node(int d) const;		// constant member function
};

node *node::find_node(int d) const {	// constant member function
	node *p;
	for (p = last; p != 0; p = p->fwd)
		if (p->data == d) break;
	return last = p;							// remember last node
}

node *access(const node *list, int d)
{
	return list->find_node(d);
}

int main()
{
	return 0;
}

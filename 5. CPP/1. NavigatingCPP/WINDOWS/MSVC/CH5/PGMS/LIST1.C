// List1.C - List implementation
#include <iostream.h>
#include "List1.h"

void List::append(const char *p) {						// append at end of List
	Node *pn = new Node(p);									// create new Node
	if (len) {													// List not empty?
		pn->back = tail;
		tail->fwd = pn;
		tail = pn;
	}
	else 
		head = tail = pn;										// List is empty
	len++;														// increment List length
}

List::~List() {												// destructor
	Node *t1, *t2; 
	for (t1 = head; len--; t1 = t2 ) {
		t2 = t1->fwd;
		delete t1;
	}
}

void List::print() const {									// display the List
	for (Node *p = head; p != 0; p = p->fwd)
		cout << p->pd << ' ';
	cout << endl;
}

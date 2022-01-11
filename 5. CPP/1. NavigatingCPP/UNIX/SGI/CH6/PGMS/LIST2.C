// List2.C - List implementation
#include <iostream.h>
#include <string.h>
#include "List2.h"

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

const char *List::remove(Node *nodeptr) {				// remove node
	if (nodeptr) {
		if (nodeptr->fwd == 0)								// end
			tail = nodeptr->back;
		else
			nodeptr->fwd->back = nodeptr->back;
		if (nodeptr->back == 0)								// front
			head = nodeptr->fwd;
		else														// middle
			nodeptr->back->fwd = nodeptr->fwd;
		len--;
		const char *pdata = nodeptr->pd;
		delete nodeptr;										// delete Node
		return pdata;											// return data pointer
	} else 
		return 0;
}

const char *List::remove(const char *pt) {
	for (Node *p = head; p != 0; p = p->fwd)
		if (strcmp(p->pd, pt) == 0)
			return remove(p);									// remove Node
	return 0;													// Node not found
}

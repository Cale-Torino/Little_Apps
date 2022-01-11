// Listn2.C - List implementation, nested class, extended scope operator
#include <iostream.h>
#include "Listn2.h"

bool List::Node::flag = false;					// initialize Node static

List::Node::Node(const char *pdata) {			// extended scope operator
	pd = pdata; fwd = back = 0;
};

void List::Node::reset(List & lp) {				// reset List
	//head = 0;												// illegal
	//lp.head = 0;											// illegal
	cout << get_flag() << endl;					// legal - static
	//List::ListStatus = 0;								// illegal - not static
	lp.ListStatus = 0;								// legal
}

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

void List::print() {											// display the List
	for (Node *p = head; p; p = p->fwd)
		cout << p->pd << ' ';
	cout << endl;
}

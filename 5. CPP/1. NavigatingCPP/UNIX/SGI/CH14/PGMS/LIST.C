// List.C - List object implementation with Iterator
#include "List.h"

template <class TYPE>
Iterator<TYPE>::Iterator(const List<TYPE> & list, place p) :
			listref(list), startpoint(p) {
	restart();
	pos = middle;
}

template <class TYPE>
TYPE Iterator<TYPE>::operator()() const { 
	if (current == 0) 
		throw ListError("Iterator is off List");
	return current->data;
}

template <class TYPE>
void Iterator<TYPE>::operator++() {						// prefix ++
	if (current) { 
		current = current->fwd;								// next Node
		if (current == 0) 
			pos = last;											// off the end
	} 
	else if (pos == first) { 
		current = listref.head;								// first Node
		pos = middle;											// middle of List
	}
}

template <class TYPE>
void Iterator<TYPE>::operator--() {						// prefix --
	if (current) {
		current = current->back;							// previous Node
		if (current == 0) 
			pos = first;										// off the front
	}
	else if (pos == last) {
		current = listref.tail;								// last Node	
		pos = middle;											// middle of List
	}
}

template <class TYPE>
void Iterator<TYPE>::adjust() {						// adjust iterator
	if (current) {
		if (current == listref.head)					// at front
			operator++();									// move to next Node
		else if (current == listref.tail)			// at end
			operator--();									// move to previous Node
		else {												// at middle
			if (startpoint == front)					// starting from front?
				operator--();								// move to previous Node
			else
				operator++();								// move to next Node
		}
	}
}

template <class TYPE>
void List<TYPE>::free() {								// free Nodes
	while (length() > 0)
		removeNode(head);										// remove Node 
}

template <class TYPE>
void List<TYPE>::copy(const List<TYPE> & list) {		// copy List
	for (Iterator<TYPE> iter(list); !iter; iter++)
		append(iter());									// make copy of TYPE
}

template <class TYPE>
TYPE List<TYPE>::removeNode(Node<TYPE> *nodeptr) {
	if (!nodeptr)
		throw ListError("Pointer to List data is zero");
  	TYPE d = nodeptr->data;
  	if (nodeptr->fwd == 0)							// end
	  	tail = nodeptr->back;
  	else
	  	nodeptr->fwd->back = nodeptr->back;
  	if (nodeptr->back == 0)							// front
	  	head = nodeptr->fwd;
  	else
	  	nodeptr->back->fwd = nodeptr->fwd;
  	delete nodeptr;									// delete Node
  	len--;												// decrease length
  	return d;											// return data
}

template <class TYPE>
TYPE List<TYPE>::remove(Iterator <TYPE> & iterator) {
	if (this != &iterator.listref) 				// correct List?
		throw ListError("List and Iterator are not attached");

	Node<TYPE> *nodeptr = iterator.current;
	if (nodeptr == 0)
		throw ListError("Iterator is off List");

	iterator.adjust();					// put iterator in known state
	return removeNode(nodeptr);		// remove Node, return data TYPE
}

template <class TYPE>
void List<TYPE>::append(const TYPE & somedata) {	// end of List
	Node<TYPE> *pn = new Node<TYPE>(somedata);		// new Node
	if (len) { 													// List not empty?
		pn->back = tail;
		tail->fwd = pn;
		tail = pn;
	} else
		head = tail = pn; 									// List is empty
	len++;
}

template <class TYPE>
void List<TYPE>::insert(const TYPE & somedata, Iterator<TYPE> & iterator) {
	if (this != &iterator.listref) 				// correct List?
		throw ListError("List and Iterator are not attached");
	Node<TYPE> *oldnode = iterator.current;
	if (oldnode == 0)
		throw ListError("Iterator is off List");
	Node<TYPE> *newnode = new Node<TYPE>(somedata);
	newnode->fwd = oldnode->fwd;				// newnode after oldnode
	oldnode->fwd = newnode;
	newnode->back = oldnode;
	if (newnode->fwd) 
		newnode->fwd->back = newnode;
	else 
		tail = newnode;
	len++;
}

template <class TYPE>
void List<TYPE>::prepend(const TYPE & somedata) {	// start of List
	Node<TYPE> *pn = new Node<TYPE>(somedata);		// new Node
	if (len) { 													// List not empty?
		pn->fwd = head;
		head->back = pn;
		head = pn;
	} else
		head = tail = pn;										// List is empty
	len++;
}

template <class TYPE>
ostream & operator<<(ostream & os, const List<TYPE> & list) {
	for (Iterator<TYPE> iter(list); !iter; iter++)
		os << iter() << ' ';									// display TYPE
	return os;
}

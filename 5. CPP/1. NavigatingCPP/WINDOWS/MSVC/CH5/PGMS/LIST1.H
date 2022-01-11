#ifndef LISTH
#define LISTH
// List1.h - List class Description with friend class
#include <stdio.h>

class Node {
	friend class List;									// List may access Node
private:
	const char *pd;										// pointer to const string
	Node *fwd;												// forward pointer 
	Node *back;												// backward pointer
	Node(const char *pdata) { pd = pdata; fwd = back = 0; }
};

class List {
private:
	Node *head;												// List head
	Node *tail;												// List tail
	int len;													// List length
public:
// Constructor
	List() { head = tail = 0; len = 0; }
// Destructor
	~List();
// Member functions
	void append(const char *);							// append at end of List
	int length() const { return len; }				// length of the List
	void print() const;									// display the List
};
#endif

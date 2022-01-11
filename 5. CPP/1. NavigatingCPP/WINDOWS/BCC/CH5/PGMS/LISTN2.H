#ifndef LISTH
#define LISTH
// Listn2.h - List class Description with nested class, extended scope operator
#include <stdio.h>

class List {
private:
	class Node {									// Nested class
	public:
		const char *pd;										// pointer to const string
		Node *fwd;												// forward pointer 
		Node *back;												// backward pointer
		Node(const char *);									// constructor
		static bool flag;										// static data member
		void reset(List &);									// Node member function
	};
	Node *head;													// List head
	Node *tail;													// List tail
	int len;														// List length
public:
	// static member function
	static bool get_flag() { return Node::flag; }
	int ListStatus;
// Constructor
	List() { head = tail = 0; len = 0; }
// Destructor
	~List();
// Member functions
	void append(const char *);								// append at end of List
	int length() const { return len; }					// length of the List
	void print();												// display the List
};
#endif

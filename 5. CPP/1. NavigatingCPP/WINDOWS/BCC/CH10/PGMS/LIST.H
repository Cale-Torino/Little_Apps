#ifndef LISTH
#define LISTH
// List.h - List object with Iterator (value semantics)
#include <iostream.h>
#include <stdio.h>

template <class TYPE> class List;			// forward reference
template <class TYPE> class Iterator;		// forward reference

template <class TYPE>
class Node {										// Node object
	friend class List<TYPE>;					// List may access Node
	friend class Iterator<TYPE>;				// Iterator may access Node
private:
	TYPE data;										// data item
	Node<TYPE> *fwd;								// forward pointer to Node 
	Node<TYPE> *back;								// backward pointer to Node
	Node(const TYPE & d) : data(d) { fwd = back = 0; }
};

template <class TYPE>
class List {												// List object
	friend class Iterator<TYPE>;						// Iterator may access List
private:
	Node<TYPE> *head;												// List head 
	Node<TYPE> *tail;												// List tail
	int len;															// List length
	void copy(const List<TYPE> &);							// copy List
	void init() { head = tail = 0; len = 0; }				// initialize List
	void free();													// free List
	TYPE removeNode(Node<TYPE> *);							// remove Node
public:
// Constructors
	List() { init(); }											// initialize List
	List(const List<TYPE> & list) {	init(); copy(list); }
// Destructor
	~List() { free(); }											// destroy List
// Modifiers
	List<TYPE> & operator=(const List<TYPE> & list) {			// assignment
		if (this != &list) {
			free();
			copy(list);
		}
		return *this;
	}
	void append(const TYPE &);							// data at end
	void prepend(const TYPE &);						// data at front
	void insert(const TYPE &, Iterator<TYPE> &);	// after Iterator
	TYPE remove(Iterator<TYPE> &);					// remove at Iterator
// Selectors
	int length() const { return len; }				// length of List
};

class ListError {											// List exception object
private:
	char buf[80];
public:
	ListError(const char *msg) { sprintf(buf, "List: %s", msg); }
	void response() const { cerr << buf << endl; }
};

template <class TYPE>
class Iterator {										// List Iterator
	friend class List<TYPE>;						// List may access Iterator
private:
	const List<TYPE> & listref;					// reference to List
	Node<TYPE> *current;								// current pointer to Node
	enum position {first, last, middle};
	position pos;										// position of Iterator
	void operator=(const Iterator<TYPE> &);	// disable assignment
	Iterator(const Iterator<TYPE> &);			// disable copy initialization
	void adjust();										// adjust during List::remove()
public: 
	enum place { front, end };
private:
	const place startpoint;							// iterator starting point
public:
// Constructor
	Iterator(const List<TYPE> &, place p = front);
	~Iterator() { }
// Modifiers
	void operator++();								// prefix ++
	void operator++(int) { operator++(); }		// postfix ++
	void operator--();								// prefix --
	void operator--(int) { operator--(); }		// postfix --
	void restart() {									// restart List
		current = (startpoint == front) ?
			listref.head : listref.tail;
	}
// Selectors
	TYPE operator()() const;						// data item
	bool operator!() const { return (current) ? true : false; }
};
#include "List.C"
#endif

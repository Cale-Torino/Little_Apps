#ifndef STACKINTH
#define STACKINTH
// StackInt.h - Integer Stack interface
#include <stdio.h>

class Stack {												// integer Stack
private:
	int *v;													// pointer to integer data
	int top;													// top of Stack
	int len;													// length of Stack
	Stack(const Stack &);								// disable copy constructor
	Stack & operator=(const Stack &);				// disable assignment
	enum { maxlen = 80 };								// default length
public:
// Constructor
	explicit Stack(int size = maxlen);
// Destructor
	~Stack() { delete [] v; }
// Modifiers
	void push(int d) { v[top++] = d; }
	int pop() { return v[--top]; }
// Selectors
	bool empty() const { return top == 0; }
	bool full() const { return top == len; }
	int length() const { return len; }
	int nitems() const { return top; }
};

class StackError {										// Stack exception object
private:
	char buf[80];
public:
	StackError(int sizerr) {								// Stack length error
		sprintf(buf, "Stack: %d is an illegal length", sizerr);
	}
	void response() const { cerr << buf << endl; }
};

Stack::Stack(int size) { 
	if (size <= 0)
		throw StackError(size);
	v = new int[len = size];
	top = 0;
}
#endif

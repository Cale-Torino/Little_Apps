#ifndef STACKH
#define STACKH
// Stack2.h - Generic Stack interface, Array containment
#include <stdio.h>
#include "Array.h"

template <class TYPE>
class Stack {												// Generic Stack
private:
	Array<TYPE> sv;										// contains Array object
	int top;													// top of Stack
	enum { maxlen = 80 };								// default length
public:
// Constructors
	explicit Stack(int size = maxlen) : sv(size) { top = 0; }
// Modifiers
	void push(const TYPE & d) { sv[top++] = d; }
	TYPE pop() { return sv[--top]; }
// Selectors
	bool empty() const { return top == 0; }
	bool full() const { return top == length(); }
	int length() const { return sv.length(); }
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
#endif

#ifndef STACKH
#define STACKH
// Stack1.h - Generic Stack interface, constructor initializer
#include <stdio.h>

template <class TYPE>
class Stack {												// Generic Stack
private:
	TYPE *v;													// pointer to generic data
	int top;													// top of Stack
	int len;													// length of Stack
	static TYPE ival;										// initial value
	void copy(const Stack<TYPE> &);
	void free() { delete [] v; }
	enum { maxlen = 80 };								// default length
public:
// Constructors
	explicit Stack(int size = maxlen, const TYPE & value = ival);
	Stack(const Stack<TYPE> & s) { copy(s); }				// copy constructor
// Destructor
	~Stack() { free(); }
// Modifiers
	void push(const TYPE & d) { v[top++] = d; }
	TYPE pop() { return v[--top]; }
	Stack<TYPE> & operator=(const Stack<TYPE> & s);				// assignment
// Selectors
	bool empty() const { return (top == 0); }
	bool full() const { return (top == len); }
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

template <class TYPE>
Stack<TYPE>::Stack(int size, const TYPE & value) {
	if (size <= 0)
		throw StackError(size);
	v = new TYPE [len = size];
	top = 0;
	if (value != ival)
		push(value);							// push initial value
}

template <class TYPE>
void Stack<TYPE>::copy(const Stack<TYPE> & s) {
	v = new TYPE [len = s.len];
	top = s.top;
	for (int i = 0; i < len; i++)
		v[i] = s.v[i];
}

template <class TYPE>
Stack<TYPE> & Stack<TYPE>::operator=(const Stack<TYPE> & s) {
	if (this != &s) {
		free();
		copy(s);
	}
	return *this;
}
#endif

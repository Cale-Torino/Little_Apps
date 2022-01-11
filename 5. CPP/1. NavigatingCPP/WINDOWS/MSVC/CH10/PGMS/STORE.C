// store.c - instantiations of class Stack
#include <iostream.h>
#include "Stack.h"
#include "String.h"

Stack<double> d(10);							// Stack of 10 doubles
Stack<String> s(20);							// Stack of 20 Strings
Stack<int> *ps = new Stack<int>(30);	// Stack of 30 integers

template <class TYPE>
void store(const TYPE *b, int len) {
	Stack<TYPE> s(len);						// Stack of TYPE
	s.push(b[0]);
}

int main()
{
	double buf[10];	String title[20];
	store(buf, 10);
	store(title, 20);
	return 0;
}

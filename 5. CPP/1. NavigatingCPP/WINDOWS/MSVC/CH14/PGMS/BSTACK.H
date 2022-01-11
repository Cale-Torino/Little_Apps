#ifndef BSTACKH
#define BSTACKH
// BStack.h - Bounded Stack, value semantics
#include "Stack.h"
#include "Array.h"

template <class TYPE>
class BStack : public Stack<TYPE>, private Array<TYPE> {
public:
// Constructor
	explicit BStack(int size) : Array<TYPE>(size) { }
// Modifiers
	void push(const TYPE & n) { (*this)[top++] = n; }
	TYPE pop() { return (*this)[--top]; }
// Selectors
	bool full() const { return top == length(); }
	int length() const { return Array<TYPE>::length(); }
};
#endif

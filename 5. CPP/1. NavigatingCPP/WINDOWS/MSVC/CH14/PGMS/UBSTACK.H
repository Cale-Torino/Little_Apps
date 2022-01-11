#ifndef UBSTACK
#define UBSTACK
// UBStack.h - Unbounded Stack, value semantics
#include "Stack.h"
#include "List.h"

template <class TYPE>
class UBStack : public Stack<TYPE>, private List<TYPE> {
public:
// Modifiers
	void push(const TYPE & n) { prepend(n); top++; }
	TYPE pop() { top--; return removeNode(getStart()); }
// Selectors
	bool full() const { return false; }
};
#endif

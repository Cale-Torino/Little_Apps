#ifndef BPTRSTACKH
#define BPTRSTACKH
// BPStack.h - Bounded Stack (Pointer Semantics)
#include "PtrStack.h"
#include "Array.h"

template <class TYPE>
class BPtrStack : public PtrStack<TYPE>, private Array<TYPE *> {
private:
	BPtrStack(const BPtrStack<TYPE> &);						// disallow copy
	void operator=(const BPtrStack<TYPE> &);				// disallow assignment
public:
// Constructor
   explicit BPtrStack(int size) : Array<TYPE *>(size) { }
// Modifiers
   void push(TYPE *ptr) { (*this)[top++] = ptr; }
   TYPE *pop() { return (*this)[--top]; }
// Selectors
   bool full() const { return top == length(); }
   int length() const { return Array<TYPE *>::length(); }
};
#endif

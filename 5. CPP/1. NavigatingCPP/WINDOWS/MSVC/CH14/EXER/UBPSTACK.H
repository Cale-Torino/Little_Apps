#ifndef UBPTRSTACK
#define UBPTRSTACK
// UBPStack.h - Unbounded Stack (pointer semantics)
#include "PtrStack.h"
#include "PtrList.h"

template <class TYPE>
class UBPtrStack : public PtrStack<TYPE>, private PtrList<TYPE> {
public:
// Modifiers
   void push(TYPE *ptr) { prepend(ptr); top++; }
   TYPE *pop() { top--; return removeNode(getStart()); }
// Selectors
   bool full() const { return false; }
};
#endif

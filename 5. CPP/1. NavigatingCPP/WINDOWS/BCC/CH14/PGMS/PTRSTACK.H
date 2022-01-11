#ifndef PTRSTACKH
#define PTRSTACKH
// PtrStack.h - Abstract Stack, pointer semantics

template <class TYPE>
class PtrStack {
protected:
	int top;								// derived classes may access
public:
// Constructor
	PtrStack() { top = 0; }
// Destructor
	virtual ~PtrStack() { freedata(); }
// Modifiers
	virtual void push(TYPE *) = 0;
	virtual TYPE *pop() = 0;
	void freedata();
// Selectors
	bool empty() const { return (top == 0); }
	int elements() const { return top; }
	virtual bool full() const = 0;
};

template <class TYPE>
void PtrStack<TYPE>::freedata() {
	while (!empty()) 
		delete pop();					// delete TYPE 
}
#endif

#ifndef STACKH
#define STACKH
// Stack.h - Abstract Stack - value semantics

template <class TYPE>
class Stack {
protected:
	int top;									// derived classes may access
public:
// Constructor
	Stack() { top = 0; }
// Destructor
	virtual ~Stack() { }
// Modifiers
	virtual void push(const TYPE &) = 0;
	virtual TYPE pop() = 0;
// Selectors
	bool empty() const { return (top == 0); }
	int elements() const { return top; }
	virtual bool full() const = 0;
};
#endif

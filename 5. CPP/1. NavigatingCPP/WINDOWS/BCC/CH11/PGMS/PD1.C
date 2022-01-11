// pd1.c - private derivation
#include <iostream.h>

class Base {
public:
	virtual void f();							// virtual in Base
};

class Derived : private Base {			// private inheritance
public:
	void f();									// overriden in Derived
};

void Base::f() { cout << "Base::f()" << endl; }
void Derived::f() { cout << "Derived::f()" << endl; }

int main() 
{
	//Base *p = new Derived;				// illegal
	Base *q = new Base;						// OK
	q->f();										// always calls Base::f()
	return 0;
}

/**********************************************************************

$ pd1 
Base::f()

*/

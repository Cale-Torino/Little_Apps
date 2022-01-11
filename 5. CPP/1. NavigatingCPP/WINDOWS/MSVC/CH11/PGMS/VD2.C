// vd2.C - virtual destructors - correct
#include "Base2.h"
#include "Array.h"

void run(const Array<Base *> & a) {
	for (int i = 0; i < a.length(); i++)
		a[i]->f();									// virtual call
}

int main() {
	Array<Base *> pb(2);							// array of Base pointers

	pb[0] = new Base(10);						// pointer to Base object
	pb[1] = new Derived(100);					// pointer to Derived object
	run(pb);											// call virtual functions

	delete pb[0];									// release Base object
	delete pb[1];									// release Derived object
	return 0;
}

/******************************************************************

$ vd2
Base constructor: 10
Base constructor: 100
Derived constructor: 100
Base::f()
Derived::f()
Base destructor: 10
Derived destructor: 100
Base destructor: 100

*/

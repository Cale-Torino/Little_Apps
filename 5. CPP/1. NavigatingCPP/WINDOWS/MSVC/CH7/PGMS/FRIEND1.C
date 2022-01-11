// friend1.C - external static for internal linkage
#include <iostream.h>

class A;										// forward reference
static void f(A &);						// forward reference

class A {
friend void f(A &) { cout << "f(A &) called" << endl; }
};

int main()
{
	A a;
	f(a);
	return 0;
}

/************************************************************************

$ friend1
f(A &) called

*/

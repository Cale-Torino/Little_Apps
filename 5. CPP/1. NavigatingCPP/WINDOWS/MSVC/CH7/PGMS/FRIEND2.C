// friend2.C - unnamed namespace for internal linkage
#include <iostream.h>

namespace {									// unnamed namespace
	class A {
	friend void f(A &);					// friend function
	};
	void f(A &) { cout << "unnamed f(A &) called" << endl; }
}												// end of namespace

int main()
{
	A a;
	f(a);
	return 0;
}

/************************************************************************

$ friend2
unnamed f(A &) called

*/

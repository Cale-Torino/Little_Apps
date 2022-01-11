// pm2.C - pointers to member functions
#include <iostream.h>

void f () { cout << "f() called" << endl; }

class X {
public:
	void f() { cout << "X::f() called" << endl; }
};

int main()
{
	X a;
	void (*p)() = f;								// ptr to function
	void (X::*q)() = X::f;						// ptr to X member function

	p();												// call f()
	(a.*q)();										// call X::f()
	return 0;
}

/*************************************************************************

$ pm2
f() called
X::f() called

*/

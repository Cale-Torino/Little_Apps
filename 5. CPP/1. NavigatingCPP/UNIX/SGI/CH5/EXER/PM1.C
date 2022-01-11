// pm1.C - pointers to member functions
#include <iostream.h>

class W {
public:
	void f() const { cout << "W::f() called" << endl; }
	void g() { cout << "W::g() called" << endl; }
};

int main()
{
	W a;
	void (W::*p)() const = W::f;				// ptr to const member function
	void (W::*const q)() = W::g;				// const ptr to member function
	void (W::*const s)() const = W::f;		// const ptr to const member function

	(a.*p)();										// call W::f()
	(a.*q)();										// call W::g()
	(a.*s)();										// call W::f()
	return 0;
}

/*************************************************************************

$ pm1
W::f() called
W::g() called
W::f() called

*/

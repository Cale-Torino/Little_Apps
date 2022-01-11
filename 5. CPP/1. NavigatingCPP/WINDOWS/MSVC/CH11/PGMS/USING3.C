// using3.c - access rules with inhertiance
#include <iostream.h>
#include "String.h"

namespace Red {
	void n() { }
}

class Base {
private:
	void m() { cout << "Base::m()" << endl; }
protected:
	void f(int) { cout << "Base::f(int)" << endl; }
public:
	void g() { cout << "Base::g()" << endl; }
};

class Derived : public Base {
protected:
	using Base::f;					// OK, f is protected in Base
	void f(int m, const String &) { 
		cout << "Derived::f(int, const String &)" << endl;
	}
public:
	//using Base::m;				// illegal, m is private in Base
	using Base::g;					// OK, g is public in Base
	//using Red::n;				// illegal, n is not in Base
	void h(int m, const String & s) { f(m); f(m, s); }
};

void sub() {
	Derived d;
	//d.f(3);						// illegal, not accessible
	d.h(3, "abc");					// OK
}

int main()
{
	sub();
	return 0;
}

/******************************************************************

$ using3
Base::f(int)
Derived::f(int, const String &)

*/

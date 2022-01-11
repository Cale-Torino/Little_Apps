// dom1.c - dominance
#include <iostream.h>
#include "String.h"

class Base {
public:
	void f(int) { cout << "Base::f(int)" << endl; }
	void f(char) { cout << "Base::f(char)" << endl; }
	void f(const String &) { cout << "Base::f(const String &)" << endl; }
};

class Derived : public Base {
public:
	void f(const String &) {				// hides all Base::f()'s
		cout << "Derived::f(const String &)" << endl;
	}
};

int main()
{
	Derived d;
	//d.f(5);								// error, Base::f(int) is hidden
	//d.f('x');								// error, Base::f(char) is hidden
	d.f("abc");								// OK, calls Derived::f(const String&);
	return 0;
}

/**********************************************************************

$ dom1 
Derived::f(const String &)

*/

// scope.c - scope rules for function overloading, dominance
#include <iostream.h>
#include "String.h"

class Base {
private:
	String name;
public:
	Base(const String & s) : name(s) { }			// constructor
	void f(double);
};

class Derived : public Base {
public:
	Derived(const String & s) : Base(s) { }		// constructor
	void f(const String &);								// hides f(double)
	void f(double d) { Base::f(d); }					// forward to Base
};

void Base::f(double d ) { cout << "Base: " << d << endl; }
void Derived::f(const String & s) { cout << "Derived: " << s << endl; }

int main()
{
	Derived d("sara");
	d.Base::f(3.5);					// legal, calls Base::f(double)
	d.f(3.5);							// legal, forwards to Base::f(double)
	d.f("kellen");						// legal, calls Derived::f(const String &)
	return 0;
}

/************************************************************************

$ scope
Base: 3.5
Base: 3.5
Derived: kellen

*/

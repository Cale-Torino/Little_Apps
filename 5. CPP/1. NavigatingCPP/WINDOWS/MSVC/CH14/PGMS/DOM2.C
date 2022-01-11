// dom2.c - dominance
#include <iostream.h>
#include "String.h"

class A {
public:
	void f(int) { cout << "A::f(int)" << endl; }
};

class B {
public:
	void f(const String &) {
		cout << "B::f(const String &)" << endl;
	}
};

class C : public A, public B {
public:
	void f(int i) { A::f(i); }
	void f(const String & s) { B::f(s); }
};

int main()
{
	C c;
	c.f(5);
	return 0;
}

/**********************************************************************

$ dom2 
A::f(int)

*/

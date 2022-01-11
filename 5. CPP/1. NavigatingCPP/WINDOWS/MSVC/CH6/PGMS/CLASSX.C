// x.c - global/member function overloading
#include <iostream.h>

void f(double);								// legal, global function

class X { 
public:
	X();											// constructor
	void f(double);							// legal, member function
	void f(double) const;					// legal, const member function
	void f(double) volatile;				// legal, volatile member function
	void f(double) const volatile;		// legal, const volatile member function
};

void f(double d) { cout << "global: " << d << endl; }

X::X() { ::f(4.5); }
void X::f(double d) { cout << "X: " << d << endl; }
void X::f(double d) const { cout << "X const: " << d << endl; }
void X::f(double d) volatile { cout << "X volatile: " << d << endl; }
void X::f(double d) const volatile { cout << "X const volatile: " << d << endl; }

int main()
{
	double m = 3.4;
   X a;
	const X b;
	volatile X c;
	const volatile X d;
	a.f(m);
	b.f(m);
	c.f(m);
	d.f(m);
	return 0;
}

/**********************************************************************

$ classx 
global: 4.5
global: 4.5
global: 4.5
global: 4.5
X: 3.4
X const: 3.4
X volatile: 3.4
X const volatile: 3.4

*/

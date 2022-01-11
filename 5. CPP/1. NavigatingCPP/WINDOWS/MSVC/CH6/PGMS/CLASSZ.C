// z.c - global/static/member function overloading with const and volatile
#include <iostream.h>

void f(double);								// legal, global function
//void f(double &);								// illegal, same as global f()
//static void f(double &);					// illegal, same as f(double)

class Z { 
public:
	Z();											// constructor
	void f(double);							// legal, member function
	//void f(double &);							// illegal, same as above
	void f(double &) const;					// legal, const objects
	//void f(double) const;					// illegal, same as above
	void f(double &) volatile;				// legal, volatile objects
	//void f(double) volatile;				// illegal, same as above
	void f(double &) const volatile;		// legal, const volatile objects
	//void f(double) const volatile;		// illegal, same as above
};

void f(double d) { cout << "global: " << d << endl; }
//void f(double & d) { cout << "double &: " << d << endl; }
//void f(double & d) { cout << "double &: " << d << endl; }

Z::Z() { }
void Z::f(double d) { cout << "Z: double " << d << endl; }
//void Z::f(double & d) { cout << "Z: double & " << d << endl; }
void Z::f(double & d) const { cout << "Z: double & const " << d << endl; }
//void Z::f(double d) const { cout << "Z: double const " << d << endl; }
void Z::f(double & d) volatile { cout << "Z: double & volatile " << d << endl; }
//void Z::f(double d) volatile { cout << "Z: double volatile " << d << endl; }
void Z::f(double & d) const volatile { cout << "Z: double & const volatile " << d << endl; }
//void Z::f(double d) const volatile { cout << "Z: double const volatile " << d << endl; }

int main()
{
	double m = 3.4;
   Z a;
	const Z b;
	volatile Z c;
	const volatile Z d;
	a.f(m);
	b.f(m);
	c.f(m);
	d.f(m);
	return 0;
}

/**********************************************************************

$ classz 
Z: double 3.4
Z: double & const 3.4
Z: double & volatile 3.4
Z: double & const volatile 3.4

*/

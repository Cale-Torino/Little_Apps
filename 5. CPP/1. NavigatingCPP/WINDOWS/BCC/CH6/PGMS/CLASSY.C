// classy.c - global/static/member function overloading
#include <iostream.h>

void f(double);								// legal, global function
//static void f(double);					// illegal with above signature
static void f(int);							// legal, different signature

class Y { 
public:
	Y();											// constructor
	static void f(double);					// legal, overrides global ::f(double)
	//void f(double);							// illegal with above signature
	static void f(int);						// legal, overrides static ::f(int)
};

void f(double d) { cout << "global: " << d << endl; }
//static void f(double d) { cout << "static double: " << d << endl; }
static void f(int d) { cout << "static int: " << d << endl; }

Y::Y() { ::f(4.5); ::f(100); Y::f(4.5); }
void Y::f(double d) { cout << "Y: static double " << d << endl; }
void Y::f(int d) { cout << "Y: static int " << d << endl; }
//void Y::f(double d) { cout << "Y: double " << d << endl; }

int main()
{
	double m = 3.4;
	int i = 12;
   Y a;
	a.f(m);
	a.f(i);
	Y::f(4.5);
	Y::f(22);
	return 0;
}

/**********************************************************************

$ classy 
global: 4.5
static int: 100
Y: static double 4.5
Y: static double 3.4
Y: static int 12
Y: static double 4.5
Y: static int 22

*/

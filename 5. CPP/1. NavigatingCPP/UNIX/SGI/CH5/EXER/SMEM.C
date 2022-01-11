// smem.C - static data members
#include <iostream.h>

class X {
private:
	double m;
	static double n;
	//X member1;										// illegal (nested defintion)
	static X member2;									// legal
public:
	//X(double d = m);								// illegal ( m is on stack)
	X(int, double d = n);							// legal
	void f(double v = n);							// legal
};

X::X(int i, double d) { cout << "X constr: " << i << ' ' << d << endl; }
void X::f(double v) { cout << "X::f(): " << v << endl; }

double X::n = 1.1;									// initialize static data member

int main()
{
	X a(10);
	a.f(5.5);

	X b(10, 3.3);
	b.f(6.6);
	return 0;
}

/*************************************************************************

$ smem
X constr: 10 1.1
X::f(): 5.5
X constr: 10 3.3
X::f(): 6.6

NOTES:

1.  Inside class X, member1 is on the stack and member2 is in the data
	 area (static).  Nested definitions allow static data members, but
	 not auto members on the stack.

2.  The same rules for default arguments apply to constructors as well
	 as for function arguments.  You may use a static in a default argument
	 but not a local variable.

*/

// bci.c - base class initialization
#include <iostream.h>

class A {													// base class
public:
	A(int) { cout << "A constr" << endl; }			// constructor with args
	~A() { cout << "A destr" << endl; }				// destructor
};

class B {													// base class
public:
	B() { cout << "B constr" << endl; }				// constructor with no args
	~B() { cout << "B destr" << endl; }				// destructor
};

class C {													// base class
public:
	C(double) { cout << "C constr" << endl; }		// constructor with args
	~C() { cout << "C destr" << endl; }				// destructor
};

class D : public A, public B, public C {			// multiple inheritance
public:
	D(int i, double m) : A(i), C(m) {				// constructs A,B,C,D
		cout << "D constr " << endl;
	}
	~D() { cout << "D destr" << endl; }				// destroys D,C,B,A
};

int main()
{
	D var(12, 4.5);
	return 0;
}

/**********************************************************************

$ bci 
A constr
B constr
C constr
D constr 
D destr
C destr
B destr
A destr

*/

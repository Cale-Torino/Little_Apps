// pro1.C - Protected access level
#include <iostream.h>

class Base {
private:
	int len;						// hidden from derived classes and users
protected:
	int sum;						// accessible to publicly derived classes
	void calc() const;		// accessible to publicly derived classes
	void xqt();					// accessible to publicly derived classes
public:
	int length() const;		//  accessible to everyone
};

class Derived : public Base {			// public inheritance
public:
	void f(int);
	void g(int) const;					// constant member function
};

void Derived::f(int n) {
	//len = n;								// illegal (private in Base)
	sum = n;									// OK (protected in Base)
	calc();									// OK (protected in Base)
	xqt();									// OK (protected in Base)
	n += length();							// OK (public in Base)
}

void Derived::g(int n) const {
	//len = n;								// illegal (private in Base)
	//sum = n;								// illegal (cannot modify protected in Base)
	calc();									// OK (protected in Base)
	//xqt();									// illegal, not const function
	n += length();							// OK (public in Base)
}

void w(const Base & b, const Derived & d, int n) {
	//b.len = n;							// illegal (private in Base)
	//b.sum = n;							// illegal (protected in Base)
	//d.calc();								// illegal (protected in Base)
	//d.sum = n;							// illegal (protected in Base)
	//d.calc();								// illegal (protected in Base)
	n += b.length();						// OK (public in Base)
	d.g(n);									// OK (public in Derived)
}

class DD : public Derived {
public:
	void h(int);
};

void DD::h(int n) {
	//len = n;								// illegal (private in Base)
	sum = n;									// OK (protected in Base)
	calc();									// OK (protected in Base)
	n += length();							// OK (public in Base)
}

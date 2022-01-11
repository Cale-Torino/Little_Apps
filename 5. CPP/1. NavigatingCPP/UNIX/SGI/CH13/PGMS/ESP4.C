// esp4.c - exception specifications, virtual functions
#include <iostream.h>
#include <stdlib.h>
#include <exception.h>

void uncaught() {									// function throws any exception
	cerr << "uncaught called" << endl;
}

void init() throw (int) {						// function throws integer
	cerr << "init called" << endl;
}

class Base {
public:
	virtual void f() throw (char *);			// throws char *
	virtual void g();								// throws any exception
	virtual void h() const throw ();			// throws no exceptions
};

class Derived : public Base {
public:
	//void f();										// illegal, less restrictive
	void g() throw (int);						// OK, more restrictive
	void h() const throw ();					// OK, exact match
};

int main()
{
	return 0;
}

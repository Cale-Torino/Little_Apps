#ifndef BASE2H
#define BASE2H
// Base2.h - with virtual destructor
#include <iostream.h>

class Base {
private:
	int *p; 
	int len;
public:
	Base(int size) { p = new int[len = size];
		cout << "Base constructor: " << len << endl; }
	virtual ~Base() { 
		cout << "Base destructor: " << len << endl; delete [] p;
	}
	virtual void f() const { cout << "Base::f()" << endl; }
};

class Derived : public Base {
private:
	double *q; 
	int len;
public:
	Derived(int size) : Base(size) { q = new double[len = size];
		cout << "Derived constructor: " << len << endl; }
	~Derived() { 
		cout << "Derived destructor: " << len << endl; delete [] q;
	}
	void f() const { cout << "Derived::f()" << endl; }
};
#endif

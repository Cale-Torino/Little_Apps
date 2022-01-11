#ifndef BASEH
#define BASEH
// Base.h - Base and Derived hierarchy
#include <iostream.h>

class B {
public:
	B() { }
	virtual void f1() { cout << "B::f1()" << endl; }
	virtual void f2() const { cout << "B::f2()" << endl; }
	void f3() { cout << "B::f3()" << endl; }
};

class D : public B {
public:
	D() { }
	void f1() { cout << "D::f1()" << endl; }
	void f2() const { cout << "D::f2()" << endl; }
	void f3() { cout << "D::f3()" << endl; }
};
#endif

#ifndef BASEH
#define BASEH
// Base4.h - virtual functions
#include <iostream.h>

class B {
public:
	B() { }
	virtual void f1() { cout << "B::f1()" << endl; }
	virtual void f2() { cout << "B::f2()" << endl; }
	virtual void f3() { cout << "B::f3()" << endl; }
};

class D : public B {
public:
	D() { }
	void f2() { cout << "D::f2()" << endl; }
	virtual void f4() { cout << "D::f4()" << endl; }
};

class DD : public D {
public:
	DD() { }
	void f2() { cout << "DD::f2()" << endl; }
};
#endif

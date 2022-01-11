#ifndef MULTIH
#define MULTIH
// Multi4.h - dominance with combinations of virtual/nonvirtual
#include <iostream.h>

class Base1 {
public:
	virtual ~Base1() { }							// virtual destructor
	virtual void f1() const { cout << "Base1::f1()" << endl; }
	void f2() const { cout << "Base1::f2()" << endl; }
};

class Derived1 : virtual public Base1 {
public:
	void f1() const { cout << "Derived1::f1()" << endl; }
	void f2() const { cout << "Derived1::f2()" << endl; }
};

class DB : public Derived1, virtual public Base1 {
public:
};
#endif

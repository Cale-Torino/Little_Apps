#ifndef MULTIH
#define MULTIH
// Multi3.h - Base1 is a virtual base
#include <iostream.h>

class Base1 {
private:
	int base1int;
public:
	Base1(int i) : base1int(i) { }
	virtual ~Base1() { }							// virtual destructor
	virtual void f1() const = 0;
	virtual void f2() const = 0;
	void f3() { cout << "Base1::f3(): " << base1int << endl; }
};

class Derived1 : virtual public Base1 {
public:
	Derived1(int i) : Base1(i) { }
	void f1() const { cout << "Derived1::f1()" << endl; }
	void f2() const { cout << "Derived1::f2()" << endl; }
};

class Derived2 : virtual public Base1 {
public:
	Derived2(int i) : Base1(i) { }
	void f1() const { cout << "Derived2::f1()" << endl; }
	void f2() const { cout << "Derived2::f2()" << endl; }
};

class D1_D2 : public Derived1, public Derived2 {
public:
	D1_D2(int i) : Derived1(i), Derived2(i+i), Base1(i*i) { }
	void f1() const { cout << "D1_D2::f1()" << endl; }
	void f2() const { Derived1::f2(); Derived2::f2(); }
};
#endif

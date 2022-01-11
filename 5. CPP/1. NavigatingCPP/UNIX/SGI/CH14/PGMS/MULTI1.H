#ifndef MULTIH
#define MULTIH
// Multi1.h - MI with Base and Derived
#include <iostream.h>

class Base1 {
private:
	int base1int;
public:
	Base1(int i) : base1int(i) { }
	virtual ~Base1() { }							// virtual destructor
	virtual void f1() const = 0;
	virtual void f2() const = 0;
	void f3(int i) { base1int = i; cout << "Base1::f3()" << endl; }
};

class Derived1 : public Base1 {
public:
	Derived1(int i) : Base1(i) { }
	void f1() const { cout << "Derived1::f1()" << endl; }
	void f2() const { cout << "Derived1::f2()" << endl; }
};

class Base2 {
public:
	virtual ~Base2() { }							// virtual destructor
	virtual void g1() const = 0;
	virtual void g2() const = 0;
	void f3() { cout << "Base2::f3()" << endl; }
};

class Derived2 : public Base2 {
public:
	void g1() const { cout << "Derived2::g1()" << endl; }
	void g2() const { cout << "Derived2::g2()" << endl; }
};

class D1_D2 : public Derived1, public Derived2 {
public:
	D1_D2(int i) : Derived1(i) { }
	void f1() const { cout << "D1_D2::f1()" << endl; }
	void g2() const { cout << "D1_D2::g2()" << endl; }
};
#endif

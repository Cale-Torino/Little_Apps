// v2.h - multiple inheritance with virtual functions
#ifndef V2H
#define V2H
#include <iostream.h>
#include <typeinfo.h>

class A {
public:
	A() { f(); } 
	virtual void f() { cout << "(this = " << this << ")" << endl; 
			cout << "I am a ";
			cout << typeid(*this).name() << endl; }
	A & operator=(const A & a) {
		if (this != &a) {
			cout << "Do assignment" << endl;
		}
		else {
			cout << "Don't do assignment" << endl;
		}
		return *this;
	}
};

class B {
public:
	B() { f(); }
	virtual void f() { cout << "(this = " << this << ")" << endl; 
			cout << "I am a ";
			cout << typeid(*this).name() << endl; }
	virtual void g() { 
			cout << "B::g(): this = " << this << endl;
			cout << "I am a ";
			cout << typeid(*this).name() << endl; }
	B & operator=(const B & b) {
		if (this != &b) {
			cout << "Do assignment" << endl;
		}
		else {
			cout << "Don't do assignment" << endl;
		}
		return *this;
	}
};

class C : public A, public B {
public:
	C() { f(); }
	void f() { cout << "(this = " << this << ")" << endl; 
			cout << "I am a ";
			cout << typeid(*this).name() << endl; }
	virtual void h() { cout << "C::h(): this = " << this << endl;
			cout << "I am a ";
			cout << typeid(*this).name() << endl; }
	C & operator=(const C & c) {
		if (this != &c) {
			cout << "Do assignment" << endl;
		}
		else {
			cout << "Don't do assignment" << endl;
		}
		return *this;
	}
};

#endif

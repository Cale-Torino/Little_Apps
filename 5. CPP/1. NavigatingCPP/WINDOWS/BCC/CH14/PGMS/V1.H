#ifndef V1H
#define V1H
// V1.h - multiple inheritance with virtual functions
#include <iostream.h>
#include <typeinfo.h>

class A {
public:
	virtual void f() {
		cout << "A::f(): this = " << this << endl; 
		cout << "I am a ";
		cout << typeid(*this).name() << endl; }
};

class B {
public:
	virtual void f() {
		cout << "B::f(): this = " << this << endl; 
		cout << "I am a ";
		cout << typeid(*this).name() << endl; }
	virtual void g() { 
		cout << "B::g(): this = " << this << endl;
		cout << "I am a ";
		cout << typeid(*this).name() << endl; }
};

class C : public A, public B {
public:
	void f() {
		cout << "C::f(): this = " << this << endl; 
		cout << "I am a ";
		cout << typeid(*this).name() << endl; }
	virtual void h() {
		cout << "C::h(): this = " << this << endl;
		cout << "I am a ";
		cout << typeid(*this).name() << endl; }
};
#endif

// vfi1.C - virtual function implementation
#include <iostream.h>

class Base {
public:
	Base() { }
	virtual void f1() { cout << "Base::f1()" << endl; }
	virtual void f2() { cout << "Base::f2()" << endl; }
	virtual void f3() { cout << "Base::f3()" << endl; }
};

class Derived : public Base {
public:
	Derived() { }
	void f2() { cout << "Derived::f2()" << endl; }
	virtual void f4() { cout << "Derived::f4()" << endl; }
};

int main()
{
	Base b1;
	Base *pb = &b1;
	pb->f2();
	Derived d1;
	pb = &d1;
	pb->f2();

	Base *p = new Derived;						// Base class pointer
	//p->f4();										// illegal
	p->f2();

	Derived *q = new Derived;					// Derived class pointer
	q->f4();											// legal
	return 0;
}

/**********************************************************************

$ vfi1 
Base::f2()
Derived::f2()
Derived::f2()
Derived::f4()

*/

// multi3.C  - Multiple Inheritance, virtual base class
#include "Multi3.h"

int main()
{
	void info1(Base1 &);
	void info2(Derived1 &);
	void info3(D1_D2 &);

	D1_D2 a(4);										// create a D1_D2 object
	info1(a);										// D1_D2 to Base1 (not ambiguous)
	cout << "*****" << endl;
	info2(a);										// D1_D2 to Derived1
	cout << "*****" << endl;
	info3(a);										// no conversion
	return 0;
}

void info1(Base1 & b1) {
	b1.f1();											// virtual call
	b1.f2();											// virtual call
	b1.f3();										// Derived1's Base1::f3()
}

void info2(Derived1 & d1) {
	d1.f1();											// virtual call
	d1.f2();											// virtual call
	d1.f3();										// Derived1's Base1::f3()
}

void info3(D1_D2 & d) {
	d.f1();											// virtual call
	d.f2();											// virtual call
	d.f3();											// not ambiguous
}

/**********************************************************************

$ multi3
D1_D2::f1()
Derived1::f2()
Derived2::f2()
Base1::f3(): 16
*****
D1_D2::f1()
Derived1::f2()
Derived2::f2()
Base1::f3(): 16
*****
D1_D2::f1()
Derived1::f2()
Derived2::f2()
Base1::f3(): 16

*/

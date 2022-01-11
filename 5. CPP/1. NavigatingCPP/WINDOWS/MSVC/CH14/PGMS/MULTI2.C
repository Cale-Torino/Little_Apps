// multi2.C  - Multiple Inheritance, multiple inclusion
#include "Multi2.h"

int main()
{
	void info1(Base1 &);
	void info2(Derived1 &);
	void info3(D1_D2 &);

	D1_D2 a(1);										// create a D1_D2 object
	info1(dynamic_cast<Derived1 &>(a));		// D1_D2 to Derived1's Base1
	cout << "*****" << endl;
	info2(a);										// D1_D2 to Derived1
	cout << "*****" << endl;
	info3(a);										// no conversion
	return 0;
}

void info1(Base1 & b1) {
	b1.f1();											// virtual call
	b1.f2();											// virtual call
	b1.f3(5);										// Derived1's Base1::f3()
}

void info2(Derived1 & d1) {
	d1.f1();											// virtual call
	d1.f2();											// virtual call
	d1.f3(6);										// Derived1's Base1::f3()
}

void info3(D1_D2 & d) {
	d.f1();											// virtual call
	d.f2();											// virtual call
	//d.f3(8);										// ambiguous, which Base1?
	d.Derived1::f3(8);							// use scope operator to disambiguate
}

/**********************************************************************

$ multi2
D1_D2::f1()
Derived1::f2()
Derived2::f2()
Base1::f3(): 5
*****
D1_D2::f1()
Derived1::f2()
Derived2::f2()
Base1::f3(): 6
*****
D1_D2::f1()
Derived1::f2()
Derived2::f2()
Base1::f3(): 8

*/

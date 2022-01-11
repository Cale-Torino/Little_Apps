// multi1.C  - Multiple Inheritance, distinct base classes
#include "Multi1.h"

int main()
{
	void info1(Base1 &);
	void info2(Base2 &);
	void info3(D1_D2 &);

	D1_D2 a(1);							// create a D1_D2 object with value 1
	info1(a);							// D1_D2 to Base1 reference conversion
	cout << "*****" << endl;
	info2(a);							// D1_D2 to Base2 reference conversion
	cout << "*****" << endl;
	info3(a);							// no conversion
	return 0;
}

void info1(Base1 & b) {
	b.f1();								// virtual call
	b.f2();								// virtual call
	b.f3(5);								// nonambiguous call, Base1::f3()
}

void info2(Base2 & b) {
	b.g1();								// virtual call
	b.g2();								// virtual call
	b.f3();								// nonambiguous call, Base2::f3()
}

void info3(D1_D2 & d) {
	d.f1();								// virtual call
	d.f2();								// virtual call
	//d.f3(8);							// error - ambiguous call
	d.Base1::f3(8);					// use scope operator to disambiguate
	d.g1();								// virtual call
	d.g2();								// virtual call
}

/**********************************************************************

$ multi1
D1_D2::f1()
Derived1::f2()
Base1::f3()
*****
Derived2::g1()
D1_D2::g2()
Base2::f3()
*****
D1_D2::f1()
Derived1::f2()
Base1::f3()
Derived2::g1()
D1_D2::g2()

*/

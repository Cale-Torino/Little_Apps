// multi4.C  - Multiple Inheritance, virtual base class, dominance
#include "Multi4.h"

int main()
{
	void info1(DB &);
	void info2(Base1 &);

	DB b;												// create DB object
	info1(b);										// no conversion
	info2(b);										// DB & to Base1, standard conversion
	return 0;
}

void info1(DB & d) {
	cout << "info1()" << endl;
	d.f1();									// f1() is virtual, Derived1::f1()
	d.f2();									// Derived1 dominates Base1, Derived1::f2()
}

void info2(Base1 & b) {
	cout << "info2()" << endl;
	b.f1();									// f1() is virtual, Derived1::f1()
	b.f2();									// f2() has static binding, Base1::f2()
}

/**********************************************************************

$ multi4
info1()
Derived1::f1()
Derived1::f2()
info2()
Derived1::f1()
Base1::f2()

*/

// polym.c - polymorphism
#include <iostream.h>

class Base1 { };
class Base2 { };

class Derived : public Base1, public Base2 { };

void f(Base1 &) { cout << "Base1 &" << endl; }
void g(Base2 &) { cout << "Base2 &" << endl; }

void w(Base1 *) { cout << "Base1 *" << endl; }
void v(Base2 *) { cout << "Base2 *" << endl; }

int main()
{
	Derived d;
	f(d);					w(&d);
	g(d);					v(&d);
	return 0;
}

/**********************************************************************

$ polym 
Base1 &
Base1 *
Base2 &
Base2 *

*/

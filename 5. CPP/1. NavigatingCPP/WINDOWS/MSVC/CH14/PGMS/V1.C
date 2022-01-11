// v1.C - Multiple Inheritance Virtual Function implementaion
#include <iostream.h>
#include "V1.h"

int main()
{
	C c;
	B *bp = &c;						// initialize B pointer to C object
	C *cp = &c;						// initialize C pointer to C object

	cout << "Calling with B ptr bp = " << bp << endl;
	bp->f();
	bp->g();
	cout << endl;

	cout << "Calling with C ptr cp = " << cp << endl;
	cp->f();
	cp->g();
	cout << endl;
	return 0;
}

/**********************************************************************

$ v1 
Calling with B ptr bp = 0x0064FDF0
C::f(): this = 0x0064FDEC
I am a class C
B::g(): this = 0x0064FDF0
I am a class C

Calling with C ptr cp = 0x0064FDEC
C::f(): this = 0x0064FDEC
I am a class C
B::g(): this = 0x0064FDF0
I am a class C


*/

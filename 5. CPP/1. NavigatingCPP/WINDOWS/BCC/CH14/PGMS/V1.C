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
Calling with B ptr bp = 0x332f0ffe
C::f(): this = 0x332f0ffc					// this pointer adjusted
I am a C
B::g(): this = 0x332f0ffe					// this pointer correct
I am a C

Calling with C ptr cp = 0x332f0ffc
C::f(): this = 0x332f0ffc					// this pointer correct
I am a C
B::g(): this = 0x332f0ffe					// this pointer adjusted
I am a C

*/

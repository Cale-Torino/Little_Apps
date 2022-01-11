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
I am a class C
B::g(): this = 0x332f0ffe					// this pointer correct
I am a class C

Calling with C ptr cp = 0x332f0ffc
C::f(): this = 0x332f0ffc					// this pointer correct
I am a class C
B::g(): this = 0x332f0ffe					// this pointer adjusted
I am a class C


NOTES:
	1. This is the output on our machine.  On your machine, the addresses
		may be different, but their values should be relatively the same.
			
	2. If the addresses are all the same on your output, the compiler 
		placed the B part BEFORE the A part in FIgure 14.16.  
		This means the addresses of bp and cp through B and C's vtbl 
		will be the same.
		
*/

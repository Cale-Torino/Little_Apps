// bit2.c - Bit object slices
#include <iostream.h>
#include "Bit.h"

int main()
{
	try {
		Bit a(16, 0xff);
		cout << "a = " << a << endl;
		cout << "a(7,2) = " << a(7,2) << endl;
		Bit b(16);
		//b(0,2) = a(7,2);
		b(12,2) = a(7,2);
		cout << "b = " << b << endl;
	}
	catch (const BitError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/***************************************************************************

$ bit2
a = 0000000011111111
a(7,2) = 01
b = 0000000000000000

*/

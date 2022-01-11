// bit1.c - Bit objects
#include <iostream.h>
#include "Bit.h"

int main()
{
	try {
		Bit a;
		cout << "a = " << a << endl;
		Bit b(16, 255);
		cout << "b = " << b << endl;
		Bit c(32, 0x77);
		cout << "c = " << c << endl;
		const Bit d = c;
		cout << "d = " << d << endl;
		a = d;
		cout << "a = " << a << endl;
		c[31] = b[0];
		c[30] = true;
		cout << "c = " << c << endl;
		cout << "c[31] = " << c[31] << endl;
	}
	catch (const BitError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/***************************************************************************

$ bit1
a = 0000000000000000
b = 0000000011111111
c = 00000000000000000000000001110111
d = 00000000000000000000000001110111
a = 00000000000000000000000001110111
c = 11000000000000000000000001110111
c[31] = 1

*/

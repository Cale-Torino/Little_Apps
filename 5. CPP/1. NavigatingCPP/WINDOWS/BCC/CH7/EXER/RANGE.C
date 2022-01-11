// range.C - Range Integer program
#include <iostream.h>
#include "Rint.h"

int main()
{
	try {
		 Rint i(100, -1000, 1000);
		 Rint j;
		 Rint k(1985, 1980, 1990);
		 Rint w(33, -10, -5);								// illegal declaration

		 cout << "Input a range int: ";
		 cin >> j;
		 cout << "i = " << i << endl;
		 cout << "j = " << j << endl;
		 cout << "k = " << k << endl;
		 cout << "w = " << w << endl;

		 cout << "i = " << i++ << ' ' << "k = " << k++ << endl;		// postfix
		 cout << "i = " << ++i << ' ' << "k = " << ++k << endl;		//prefix

		 Rint m(0, 0, 3000);
		 m = i + k;
		 if (m > 2000) cout << "m = " << m << endl;
		 if (m == 2089) cout << "same" << endl;
		 cout << "m = " << (m += i) << endl;
		 if (m > k) cout << "m = " << m << endl;
		 cout << "m % 100 = " << (m % 100) << endl;
		 cout << "m % k = " << (m % k) << endl;
		 cout << "m %= k = " << (m %= k) << endl;
		 cout << "m <<= k = " << (m <<= k) << endl;
		 cout << "m >>= k = " << (m >>= k) << endl;
		 cout << "m & k = " << (m & k) << endl;
	}
	catch (const RintError & b ) {
		b.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ range 
Rint: Integer out of range (value = 33, min = -10, max = -5)

NOTES:
1. With the overloaded cast operator already in the Rint class, there is
	NO code required to make operators >>, <<, &, |, and ^ work properly
	with Rint objects.

2. The overloaded functions for >>=, <<=, &=, |=, and ^= follow the
	same approach shown in the chapter.

*/

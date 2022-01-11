// a1d.C - 1D Array objects
#include <iostream.h>
#include <stdlib.h>
#include "Array.h"

int main(int argc, const char *argv[]) 
{
	try {
		if (argc == 1) {
			 cerr << argv[0] << " length" << endl;
			 return 1;
		}
		int len = atoi(argv[1]); 
		int i, ival = 1;	double dval = .1;

		Array<int> a(len), b(len);						// Arrays of ints
		for (i = 0; i < a.length(); i++)
			a[i] = ival++;									// fill with integers
		cout << a << endl;

		b = a;												// Array assignment
		cout << b << endl;

		Array<double> c(len);							// Array of doubles
		for (i = 0; i < a.length(); i++)
			c[i] = dval++;									// fill with doubles

		const Array<double> d = c;						// const Array of doubles
		cout << d << endl;
		cout << d[len] << endl;							// range error
	}
	catch (const ArrayError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/****************************************************************************

$ a1d 10
1 2 3 4 5 6 7 8 9 10 
1 2 3 4 5 6 7 8 9 10 
0.1 1.1 2.1 3.1 4.1 5.1 6.1 7.1 8.1 9.1 
Array: subscript 10 out of bounds, max subscript = 9

*/

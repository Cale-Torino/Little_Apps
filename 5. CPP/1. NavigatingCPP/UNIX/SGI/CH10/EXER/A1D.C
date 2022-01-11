// a1d.C - 1D Array objects with resize()
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
		int i, ival = 1;

		Array<int> a(len);								// Arrays of ints
		for (i = 0; i < a.length(); i++)
			a[i] = ival++;									// fill with integers
		cout << a << endl;

		cout << "make it larger" << endl;
		a.resize(len+2);									// make Array bigger
		a[len] = ival++;
		a[len+1] = ival++;
		cout << a << endl;

		cout << "make it smaller" << endl;
		a.resize(len-2);									// make Array bigger
		cout << a << endl;
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
make it larger
1 2 3 4 5 6 7 8 9 10 11 12 
make it smaller
1 2 3 4 5 6 7 8 

*/

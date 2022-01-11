// na1.C - 1D integer array with recursive design
#include <iostream.h>
#include <stdlib.h>
#include "nArray.h"

template <class TYPE>
void display(const nArray<TYPE> & a) {				// one dimensional display
	for (int i = 0; i < a.getdim(1); i++)
		cout << a[i] << ' ';
	cout << endl;
}

int main(int argc, const char *argv[])
{
	try {
		if (argc != 2) {
			cerr << argv[0] << " length" << endl;
			return 1;
		}
		int length = atoi(argv[1]);

		nArray<int> a(1, length);						// 1D array of integers

		int inum = 1;
		for (int i = 0; i < a.getdim(1); i++)
			a[i] = inum++;									// fill array with integers
		display(a);
		cout << endl;

		nArray<int> b = a;								// copy initialization
		display(b);
		cout << endl;

		nArray<int> c;
		c = a;												// assignment
		display(c);
	}
	catch (const nArrayError<int> & e) {			// nArray exceptions
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ na1 10 
1 2 3 4 5 6 7 8 9 10 

1 2 3 4 5 6 7 8 9 10 

1 2 3 4 5 6 7 8 9 10 

*/

// na2.C - 2D integer array with recursive design
#include <iostream.h>
#include <stdlib.h>
#include "nArray.h"

template <class TYPE>
void display(const nArray<TYPE> & a) {					// two dimensional display
	for (int i = 0; i < a.getdim(1); i++) {
		for (int j = 0; j < a.getdim(2); j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
}

int main(int argc, const char *argv[])
{
	try {
		if (argc != 3) {
			cerr << argv[0] << " rows cols" << endl;;
			return 1;
		}
		int rows = atoi(argv[1]);
		int cols = atoi(argv[2]);

		nArray<int> a(2, rows, cols);						// 2D array of integers

		int inum = 1;
		for (int i = 0; i < a.getdim(1); i++)
			for (int j = 0; j < a.getdim(2); j++)
				a[i][j] = inum++;								// fill array with integers
		display(a);
		cout << endl;

		nArray<int> b = a;									// copy initialization
		display(b);
		cout << endl;

		nArray<int> c;
		c = a;													// assignment
		display(c);
	}
	catch (const nArrayError<int> & e) {				// nArray exceptions
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ na2 3 4
1 2 3 4 
5 6 7 8 
9 10 11 12 

1 2 3 4 
5 6 7 8 
9 10 11 12 

1 2 3 4 
5 6 7 8 
9 10 11 12 

*/

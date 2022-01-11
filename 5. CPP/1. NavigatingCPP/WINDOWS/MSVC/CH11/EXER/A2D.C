// a2d.C - 2D Array objects, resize()
#include <iostream.h>
#include <stdlib.h>
#include "Array2d.h"

int main(int argc, const char *argv[]) 
{
	try {
		if (argc != 3) { 
			cerr << argv[0] << " rows cols" << endl; 
			return 1;
		}
		int rows = atoi(argv[1]);	 int cols = atoi(argv[2]);
		int i, j, ival = 1;

		Array2d<int> a(rows, cols);						// 2D int Arrays
		for (i = 0; i < a.rows(); i++)
			for (j = 0; j < a.cols(); j++)
				a[i][j] = ival++;								// fill with integers
		cout << a << endl;

		cout << "make it larger" << endl;
		a.resize(rows+1, cols+1);							// resize Array2d object
		for (i = 0; i < a.rows(); i++)
			a[i][cols] = 0;
		for (i = 0; i < a.cols(); i++)
			a[rows][i] = 0;
		cout << a << endl;

		cout << "make it smaller" << endl;
		a.resize(rows-1, cols-1);							// resize Array2d object
		cout << a << endl;
	}
	catch (const ArrayError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/*****************************************************************************

$ a2d 3 4
1 2 3 4 
5 6 7 8 
9 10 11 12 

make it larger
1 2 3 4 0 
5 6 7 8 0 
9 10 11 12 0 
0 0 0 0 0 

make it smaller
1 2 3 
5 6 7 

NOTES:
1. In Array2d.h, we call the resize() function in the Array class to
	scale Array2d objects for resizing.

2. resize() does not have to be virtual because its signatures are
	different.  In Array, you call resize() with a length and in
	Array2d, you call resize() with rows and columns.

*/

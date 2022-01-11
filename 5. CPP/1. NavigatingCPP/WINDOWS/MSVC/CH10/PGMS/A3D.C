// a3d.C - 3D Array objects
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include "Array3d.h"

int main(int argc, const char *argv[])
{
	try {
		if (argc != 4) {
			cerr << argv[0] << " grids rows cols" << endl;
			return 1;
		}
		int grids = atoi(argv[1]);
		int rows = atoi(argv[2]);
		int cols = atoi(argv[3]);
		int i, j, k, ival = 1;	double dval = .1;

		Array3d<int> a(grids, rows, cols), b(grids, rows, cols);
		for (i = 0; i < a.grids(); i++)
			for (j = 0; j < a.rows(); j++)
				for (k = 0; k < a.cols(); k++)
					a[i][j][k] = ival++;					// fill 3D Array
		cout << a << endl;
		b = a;												// 3D Array assignment
		cout << b << endl;

		Array3d<double> c(grids, rows, cols);		// 3D Array of doubles
		for (i = 0; i < c.grids(); i++)
			for (j = 0; j < c.rows(); j++)
				for (k = 0; k < c.cols(); k++)
					c[i][j][k] = dval++;					// fill 3D Array

		const Array3d<double> d = c;					// constant 3D Array of doubles
		cout << d << endl;
		cout << d[grids][0][0] << endl;				// range error
	}
	catch (const ArrayError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/****************************************************************************

$ a3d 2 2 5
1 2 3 4 5 
6 7 8 9 10 

11 12 13 14 15 
16 17 18 19 20 


1 2 3 4 5 
6 7 8 9 10 

11 12 13 14 15 
16 17 18 19 20 


0.1 1.1 2.1 3.1 4.1 
5.1 6.1 7.1 8.1 9.1 

10.1 11.1 12.1 13.1 14.1 
15.1 16.1 17.1 18.1 19.1 


Array: subscript 2 out of bounds, max subscript = 1

*/

// g1.C - Grid objects
#include <iostream.h>
#include <stdlib.h>
#include "Grid.h"

int main(int argc, const char *argv[]) 
{
	try {
		if (argc != 3) { 
			cerr << argv[0] << " rows cols" << endl; 
			return 1;
		}
		int rows = atoi(argv[1]);	 int cols = atoi(argv[2]);
		int i, j, ival = 1;	double dval = .1;

		Grid<int> a(rows, cols), b(rows, cols);		// 2D int Grids
		for (i = 0; i < a.rows(); i++)
			for (j = 0; j < a.cols(); j++)
				a(i,j) = ival++;								// fill with integers
		cout << a << endl;
		b = a;													// Grid assignment
		cout << b << endl;

		Grid<double> c(rows, cols);						// Grid of doubles
		for (i = 0; i < c.rows(); i++)
			for (j = 0; j < c.cols(); j++)
				c(i,j) = dval++;								// fill with doubles
		const Grid<double> d = c;							// const 2D Grid of doubles
		cout << d << endl;
		cout << d(rows,0) << endl;							// range error
	}
	catch (const ArrayError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/*****************************************************************************

$ g1 3 4
1 2 3 4 
5 6 7 8 
9 10 11 12 

1 2 3 4 
5 6 7 8 
9 10 11 12 

0.1 1.1 2.1 3.1 
4.1 5.1 6.1 7.1 
8.1 9.1 10.1 11.1 

Array: subscript 3 out of bounds, max subscript = 2

*/

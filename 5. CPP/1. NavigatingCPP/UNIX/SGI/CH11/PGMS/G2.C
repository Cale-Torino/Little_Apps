// g2.C - Square Grid objects
#include <iostream.h>
#include <stdlib.h>
#include "SGrid.h"

int main(int argc, const char *argv[]) 
{
	try {
		if (argc != 2) { 
			cerr << argv[0] << " size" << endl; 
			return 1;
		}
		int size = atoi(argv[1]);
		int i, j, ival = 1;	double dval = .1;

		SGrid<int> a(size), b(size);						// 2D int Grids
		for (i = 0; i < a.rows(); i++)
			for (j = 0; j < a.cols(); j++)
				a(i,j) = ival++;								// fill with integers
		cout << a << endl;
		b = a;													// Grid assignment
		cout << b << endl;

		SGrid<double> c(size);								// Grid of doubles
		for (i = 0; i < c.rows(); i++)
			for (j = 0; j < c.cols(); j++)
				c(i,j) = dval++;								// fill with doubles
		const SGrid<double> d = c;							// const 2D Grid of doubles
		cout << d << endl;
		cout << d(size,0) << endl;							// range error
	}
	catch (const ArrayError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/*****************************************************************************

$ g2 5
1 2 3 4 5 
6 7 8 9 10 
11 12 13 14 15 
16 17 18 19 20 
21 22 23 24 25 

1 2 3 4 5 
6 7 8 9 10 
11 12 13 14 15 
16 17 18 19 20 
21 22 23 24 25 

0.1 1.1 2.1 3.1 4.1 
5.1 6.1 7.1 8.1 9.1 
10.1 11.1 12.1 13.1 14.1 
15.1 16.1 17.1 18.1 19.1 
20.1 21.1 22.1 23.1 24.1 

Array: subscript 5 out of bounds, max subscript = 4

*/

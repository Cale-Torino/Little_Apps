// a2d.C - 2D Array objects
#include <iostream.h>
#include <stdlib.h>
#include "Array2d.h"

template <class TYPE>
void fill(Array2d<TYPE> & a, TYPE val) {
	for (int i = 0; i < a.rows(); i++)
		for (int j = 0; j < a.cols(); j++)
			a[i][j] = val++;
}

int main(int argc, const char *argv[]) 
{
	try {
		 if (argc != 3) { 
			 cerr << argv[0] << " rows cols" << endl; 
			 return 1;
		 }
		 int rows = atoi(argv[1]);	 int cols = atoi(argv[2]);

		 Array2d<int> a(rows, cols), b(rows, cols);		// 2D Array of ints
		 fill(a, 1);												// fill with integers
		 cout << a << endl;
		 b = a;														// 2D Array assignment
		 cout << b << endl;

		 Array2d<double> c(rows, cols);					// 2D Array of doubles
		 fill(c, .1);											// fill with doubles
		 const Array2d <double> d = c;					// const 2D Array of doubles
		 cout << d << endl;
		 cout << d[rows][0] << endl;						// range error
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

1 2 3 4 
5 6 7 8 
9 10 11 12 

0.1 1.1 2.1 3.1 
4.1 5.1 6.1 7.1 
8.1 9.1 10.1 11.1 

Array: subscript 3 out of bounds, max subscript = 2

*/

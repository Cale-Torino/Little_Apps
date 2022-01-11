// g3.C - Grid and Sgrid objects
#include <iostream.h>
#include <stdlib.h>
#include "SGrid.h"

template <class TYPE>
void fill(Grid<TYPE> & a, const TYPE *val) {
	int idx = 0;
	for (int i = 0; i < a.rows(); i++)
		for (int j = 0; j < a.cols(); j++)
			a(i,j) = val[idx++];				// fill Grid with integers
}

template <class TYPE>
void fill(SGrid<TYPE> & a, const TYPE *val) {
	int idx = 0;
	for (int i = 0; i < a.rows(); i++)
		for (int j = 0; j < a.cols(); j++)
			a(i,j) = val[idx++];				// fill SGrid with integers
}

int main() 
{
	try {
		 Grid<int> a(2, 3), b(2, 3);						// Grid objects
		 static int inums[] = { 1, 2, 3, 4, 5, 6 };
		 fill(a, inums);
		 cout << a << endl;
		 b = a;													// Grid assignment
		 cout << b << endl;

		 SGrid<double> c(3);									// SGrid object
		 static double dnums[] = { 1.1, 2.1, 3.1, 4.1, 5.1, 6.1,
		 									7.1, 8.1, 9.1 };
		 fill(c, dnums);

		 SGrid<double> d = c;								// Grid of doubles
		 cout << d << endl;
		 cout << d(7,0) << endl;							// range error
	}
	catch (const ArrayError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/*****************************************************************************

$ g3
1 2 3 
4 5 6 

1 2 3 
4 5 6 

1.1 2.1 3.1 
4.1 5.1 6.1 
7.1 8.1 9.1 

Array: subscript 7 out of bounds, max subscript = 2

*/

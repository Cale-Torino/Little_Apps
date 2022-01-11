// transp.C - transpose Array2d objects
#include <iostream.h>
#include <stdlib.h>
#include "transpos.h"

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

		cout << "before transpose" << endl;
		cout << a << endl;
		transpose(a);											// tranpose Array2d object
		cout << "after transpose" << endl;
		cout << a << endl;
	}
	catch (const ArrayError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/*****************************************************************************

$ transp 3 3
before transpose
1 2 3 
4 5 6 
7 8 9 

after transpose
1 4 7 
2 5 8 
3 6 9 

$ transp 3 4
before transpose
1 2 3 4 
5 6 7 8 
9 10 11 12 

after transpose
1 5 9 
2 6 10 
3 7 11 
4 8 12 

*/

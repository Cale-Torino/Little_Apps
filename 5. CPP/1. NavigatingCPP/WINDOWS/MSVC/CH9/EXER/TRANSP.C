// transp.C - transpose two-dimensional arrays of any data type at run-time
#include "String.h"
#include "transpos.h"

int main()
{
	try {
		int **a;												// pointer to 2D array 
		int irows = 3, icols = 3;						// integer rows and cols
		dim2(a, irows, icols);							// create 2D array of integers
		static int ivals[] = { 							// integer initializers
			1, 2, 3, 
			4, 5, 6, 
			7, 8, 9
		};
		fill(a, irows, icols, ivals);					// fill with integers
		transpose(a, irows, icols);					// transpose array
		display(a, irows, icols);						// display elements
		free2(a);											// deallocate 2D array

		double **b;											// pointer to 2D array 
		int drows = 3, dcols = 4;						// double rows and cols
		dim2(b, drows, dcols);							// create 2D array of doubles
		static double dvals[] = { 						// double initializers
			 1.1,  2.1,  3.1,  4.1,
			 5.1,  6.1,  7.1,  8.1,
			 9.1, 10.1, 11.1, 12.1
		};
		fill(b, drows, dcols, dvals);					// fill with doubles
		transpose(b, drows, dcols);					// transpose array
		display(b, drows, dcols);						// display elements
		free2(b);											// deallocate 2D array

		String **c;											// pointer to 2D array 
		int srows = 2, scols = 3;						// String rows and cols
		dim2(c, srows, scols);							// create 2D array of Strings
		static String svals[] = {						// String initializers
			"one", "two", "three",
			"four", "five", "six"
		};
		fill(c, srows, scols, svals);					// fill 2 X 3 with Strings
		bool noswap = false;
		transpose(c, srows, scols, noswap);			// transpose array, no swap
		display(c, scols, srows);						// display 3 X 2 elements
		free2(c);											// deallocate 2D array
	}
	catch (char *msg) {									// catch handler
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/********************************************************************

$ transp
1 4 7 
2 5 8 
3 6 9 
1.1 5.1 9.1 
2.1 6.1 10.1 
3.1 7.1 11.1 
4.1 8.1 12.1 
one four 
two five 
three six 

*/

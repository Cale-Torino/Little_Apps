// dim2.C - two-dimensional arrays of any data type at run-time
#include <iostream.h>
#include <stdlib.h>
#include "dim2.h"

int main(int argc, const char *argv[])
{
	try {
		int i, j; 
		if (argc != 3) {
			cerr <<  "Usage: " << argv[0] << " rows cols" << endl; 
			return 1;
		}
		int rows = atoi(argv[1]);						// number of rows
		int cols = atoi(argv[2]);						// number of columns

		int **a;												// pointer to 2D array 
		dim2(a, rows, cols);								// create 2D array of integers
		int inum = 1;
		for (i = 0; i < rows; i++)
			for (j = 0; j < cols; j++)
	  			a[i][j] = inum++;							// fill 2D array with integers
		display(a, rows, cols);							// display elements
		free2(a);											// deallocate 2D array

		double **b;											// pointer to 2D array 
		dim2(b, rows, cols);								// create 2D array of doubles
		double dnum = 1.1;
		for (i = 0; i < rows; i++)
			for (j = 0; j < cols; j++)
	  			b[i][j] = dnum++;							// fill 2D array with doubles
		display(b, rows, cols);							// display elements
		free2(b);											// deallocate 2D array
	}
	catch (char *msg) {									// catch handler
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/*************************************************************************

$ dim2 3 4
1 2 3 4 
5 6 7 8 
9 10 11 12 
1.1 2.1 3.1 4.1 
5.1 6.1 7.1 8.1 
9.1 10.1 11.1 12.1 

*/

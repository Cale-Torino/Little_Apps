// dim3.C - three-dimensional arrays of any data type at run-time
#include <iostream.h>
#include <stdlib.h>
#include "dim3.h"

int main(int argc, const char *argv[])
{
	try {
		int i, j, k; 
		int grids, rows, cols;

		if (argc != 4) {
			cerr <<  "Usage: " << argv[0] << " grids rows cols" << endl; 
			return 1;
		}
		grids = atoi(argv[1]);							// number of grids
		rows = atoi(argv[2]);							// number of rows
		cols = atoi(argv[3]);							// number of columns

		int ***a;											// pointer to 3D array 
		dim3(a, grids, rows, cols);					// create 3D array of integers
		int inum = 1;
		for (i = 0; i < grids; i++)
			for (j = 0; j < rows; j++)
				for (k = 0; k < cols; k++)
	  				a[i][j][k] = inum++;					// fill 3D array with integers
		display(a, grids, rows, cols);				// display elements
		free3(a);											// deallocate 3D array

		double ***b;										// pointer to 3D array 
		dim3(b, grids, rows, cols);					// create 3D array of doubles
		double dnum = 1.1;
		for (i = 0; i < grids; i++)
			for (j = 0; j < rows; j++)
				for (k = 0; k < cols; k++)
	  				b[i][j][k] = dnum++;					// fill 3D array with doubles
		display(b, grids, rows, cols);				// display elements
		free3(b);											// deallocate 3D array
	}
	catch (char *msg) {									// catch handler
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/*************************************************************************

$ dim3 2 3 4
Grid 0
1 2 3 4
5 6 7 8
9 10 11 12
Grid 1
13 14 15 16
17 18 19 20
21 22 23 24

Grid 0
1.1 2.1 3.1 4.1
5.1 6.1 7.1 8.1
9.1 10.1 11.1 12.1
Grid 1
13.1 14.1 15.1 16.1
17.1 18.1 19.1 20.1
21.1 22.1 23.1 24.1

*/

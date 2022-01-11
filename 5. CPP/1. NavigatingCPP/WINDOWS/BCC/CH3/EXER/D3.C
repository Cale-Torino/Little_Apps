// d3.C - Three dimensional driver for ndim() and nfree()
#include <iostream.h>
#include <stdlib.h>
#include "ndim.h"

int main(int argc, char *argv[])
{
	try {
   	if (argc != 4) {
      	cerr << argv[0] << " grids rows cols" << endl;
      	return 1;
   	}
   	int grids = atoi(argv[1]);
   	int rows = atoi(argv[2]);
   	int cols = atoi(argv[3]);

		// 3D array
   	int ***a;
   	ndim(&a, 3, grids, rows, cols, sizeof(int));

   	register int k;
   	register int j;
   	register int i;
   	int v = 1;

   	for (i = 0; i < grids; i++)
      	for (j = 0; j < rows; j++)
	 			for (k = 0; k < cols; k++)
	    			a[i][j][k] = v++;

   	for (i = 0; i < grids; i++) {         // display 3D array elements
      	cout << "Grid " << i << ": " << endl;
      	for (j = 0; j < rows; j++) {
         	for (k = 0; k < cols; k++)
					cout << '\t' << a[i][j][k];
				cout << endl;
			}
   	}
		nfree(a, 3);											// free 3D array
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/*************************************************************************

$ d3 2 3 4
Grid 0: 
    1     2     3     4
    5     6     7     8
    9     10    11    12
Grid 1: 
    13    14    15    16
    17    18    19    20
    21    22    23    24

*/

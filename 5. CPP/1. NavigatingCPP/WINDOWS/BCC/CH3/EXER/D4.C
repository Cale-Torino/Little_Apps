// d4.C - Four dimensional driver for ndim() and nfree()
#include <iostream.h>
#include <stdlib.h>
#include "ndim.h"

int main(int argc, char *argv[])
{
	try {
   	if (argc != 5) {
      	cerr << argv[0] << " solids grids rows cols" << endl;
      	return 1;
   	}
   	int solids = atoi(argv[1]);
   	int grids = atoi(argv[2]);
   	int rows = atoi(argv[3]);
   	int cols = atoi(argv[4]);

		// 4D array
   	int ****a;
   	ndim(&a, 4, solids, grids, rows, cols, sizeof(int));

   	register int m;
   	register int k;
   	register int j;
   	register int i;
   	int v = 1;

   	for (i = 0; i < solids; i++)
      	for (j = 0; j < grids; j++)
	 			for (k = 0; k < rows; k++)
	 				for (m = 0; m < cols; m++)
	    				a[i][j][k][m] = v++;

   	for (i = 0; i < solids; i++) {     			// display 4D array elements
      	cout << "Solid " << i << ": " << endl;
      	for (j = 0; j < grids; j++) {
      		cout << "   Grid " << j << ": " << endl;
         		for (k = 0; k < rows; k++) {
         			for (m = 0; m < cols; m++)
							cout << '\t' << a[i][j][k][m];
					cout << endl;
				}
			}
   	}
		nfree(a, 4);											// free 4D array
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/*************************************************************************

$ d4 2 2 3 4
Solid 0: 
   Grid 0: 
        1     2     3     4
        5     6     7     8
        9     10    11    12
   Grid 1: 
        13    14    15    16
        17    18    19    20
        21    22    23    24
Solid 1: 
   Grid 0: 
        25    26    27    28
        29    30    31    32
        33    34    35    36
   Grid 1: 
        37    38    39    40
        41    42    43    44
        45    46    47    48

*/

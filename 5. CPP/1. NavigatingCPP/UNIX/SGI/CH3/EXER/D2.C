// d2.C - Two dimensional driver for ndim() and nfree()
#include <iostream.h>
#include <stdlib.h>
#include "ndim.h"

int main(int argc, char *argv[])
{
	try {
   	if (argc != 3) {
      	cerr << argv[0] << " rows cols" << endl;
      	return 1;
   	}
   	int rows = atoi(argv[1]);
   	int cols = atoi(argv[2]);

		// 2D array
   	int **a;
   	ndim(&a, 2, rows, cols, sizeof(int));

   	register int j; 
   	register int i; 
   	int inum = 1;

   	for (i = 0; i < rows; i++)
      	for (j = 0; j < cols; j++)
          	a[i][j] = inum++;                 // fill 2D array with integers
	
   	for (i = 0; i < rows; i++) {
      	for (j = 0; j < cols; j++)
         	cout << '\t' << a[i][j];
      	cout << endl;
		}
		nfree(a, 2);									// free 2D array
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/*************************************************************************

$ d2 3 4
    1    2     3     4
    5    6     7     8
    9    10    11    12

*/

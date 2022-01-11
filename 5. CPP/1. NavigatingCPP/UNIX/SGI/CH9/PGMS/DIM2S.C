// dim2s.C - two-dimensional arrays of Complex objects
#include <iostream.h>
#include "Complex.h"
#include "dim2.h"

int main()
{
	try {
		int i, j; 
		Complex **a;									// pointer to 2D array of Complex
		dim2(a, 3, 4);			 						// create 2D array of Complex

		for (i = 0; i < 3; i++)						// fill with Complex data
			for (j = 0; j < 4; j++) {
				a[i][j].real(1.1);
				a[i][j].imag(2.2);
			}
		display(a, 3, 4);								// display elements
		free2(a);										// deallocate 2D array of complex
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/******************************************************************

$ dim2s
(1.1, 2.2) (1.1, 2.2) (1.1, 2.2) (1.1, 2.2) 
(1.1, 2.2) (1.1, 2.2) (1.1, 2.2) (1.1, 2.2) 
(1.1, 2.2) (1.1, 2.2) (1.1, 2.2) (1.1, 2.2) 

*/

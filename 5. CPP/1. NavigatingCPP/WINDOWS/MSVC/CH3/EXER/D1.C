
#include <iostream.h>
#include <stdlib.h>
#include "ndim.h"

int main(int argc, char *argv[])
{
	try {
		if (argc != 2) {
			cerr << argv[0] << " length" << endl;
			return 1;
		}
		int length = atoi(argv[1]);

		// 1D array
		int *a;
		ndim(&a, 1, length, sizeof(int));

		register int i; 
		int inum = 1;
		for (i = 0; i < length; i++)
			a[i] = inum++;								// fill 1D array with integers

		for (i = 0; i < length; i++) 
			cout << '\t' << a[i];
		cout << endl;
	
		nfree(a, 1);									// free 1D array
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/*************************************************************************

$ d1 4
    1    2    3    4

*/

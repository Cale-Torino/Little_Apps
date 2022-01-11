// na3.C - 3D integer array with recursive design
#include <iostream.h>
#include <stdlib.h>
#include "nArray.h"

template <class TYPE>
void display(const nArray<TYPE> & a) {				// three dimensional display
	for (int i = 0; i < a.getdim(1); i++) {
		cout << "Grid " << i << ": " << endl;
		for (int j = 0; j < a.getdim(2); j++) {
			for (int k = 0; k < a.getdim(3); k++)
				cout << '\t' << a[i][j][k];
			cout << endl;
		}
	}
}

int main(int argc, const char *argv[])
{
	try {
		if (argc != 4) {
			cerr << argv[0] << " grids rows cols" << endl;
			return 1;
		}
		int grids = atoi(argv[1]);
		int rows = atoi(argv[2]);
		int cols = atoi(argv[3]);

		nArray<int> a(3, grids, rows, cols);		// 3D array of integers

		int inum = 1;
		for (int i = 0; i < a.getdim(1); i++)
			for (int j = 0; j < a.getdim(2); j++)
				for (int k = 0; k < a.getdim(3); k++)
					a[i][j][k] = inum++;					// fill 3D array with integers 
		display(a);
		cout << endl;

		nArray<int> b = a;								// copy initialization
		display(b);
		cout << endl;

		nArray<int> c;
		c = a;												// assignment
		display(c);
	}
	catch (const nArrayError<int> & e) {			// nArray exceptions
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ na3 2 3 4
Grid 0: 
	1	2	3	4
	5	6	7	8
	9	10	11	12
Grid 1: 
	13	14	15	16
	17	18	19	20
	21	22	23	24

Grid 0: 
	1	2	3	4
	5	6	7	8
	9	10	11	12
Grid 1: 
	13	14	15	16
	17	18	19	20
	21	22	23	24

Grid 0: 
	1	2	3	4
	5	6	7	8
	9	10	11	12
Grid 1: 
	13	14	15	16
	17	18	19	20
	21	22	23	24

*/

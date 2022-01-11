#ifndef DIM2H
#define DIM2H
// dim2.h - template 2D array allocation
#include <iostream.h>

template <class TYPE>
void dim2(TYPE **& prow, int rows, int cols) {		// create 2D array
	if (rows <= 0 || cols <= 0)
		throw "dim2(): rows, cols must be greater than zero";

	TYPE *pdata;											// pointer to data
	pdata = new TYPE [rows * cols];					// allocate memory for data
	prow = new TYPE * [rows];							// allocate row pointers

	for (int i = 0; i < rows; i++) {
		prow[i] = pdata;									// store pointers to rows
		pdata += cols;										// move to next row
	}
}

template <class TYPE>
void free2(TYPE **pa) {									// free 2D heap storage
	delete [] *pa;											// free data 
	delete [] pa;											// free row pointers 
}

template <class TYPE>
void fill(TYPE **& a, int rows, int cols, const TYPE *val) {
	int idx = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			a[i][j] = val[idx++];
}

template <class TYPE>
void display(TYPE **a, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
}
#endif

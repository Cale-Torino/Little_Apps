#ifndef TRANSPOSH
#define TRANSPOSH
// transpos.h - template transpose function
#include <iostream.h>
#include "dim2.h"

template <class TYPE>
inline void swap(TYPE & a, TYPE & b)
{
	TYPE tmp = a;
	a = b;
	b = tmp;
}

template <class TYPE>										// transpose
void transpose(TYPE **& a, int & rows, int & cols) {
	if (rows <= 0 || cols <= 0)
		throw "transpose(): rows, cols must be greater than zero";
	if (rows == cols) {										// transpose in place
		for (int i = 0; i < rows; i++)
			for (int j = i+1; j < cols; j++)
				swap(a[i][j], a[j][i]);						// swap elements
		return;
	}
	TYPE **b;
	dim2(b, cols, rows);										// build cols x rows array
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			b[j][i] = a[i][j];								// copy elements
	free2(a);													// free old array
	a = b;														// assign to new one
	swap(rows, cols);											// swap rows and cols	
}
#endif

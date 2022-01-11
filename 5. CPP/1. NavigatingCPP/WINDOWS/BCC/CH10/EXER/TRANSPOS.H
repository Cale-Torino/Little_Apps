#ifndef TRANSPOSH
#define TRANSPOSH
// transpos.h - transpose Array2d objects
#include <iostream.h>
#include "Array2d.h"

template <class TYPE>
inline void swap(TYPE & a, TYPE & b)
{
	TYPE tmp = a;
	a = b;
	b = tmp;
}

template <class TYPE>
void transpose(Array2d<TYPE> & a) {
	if (a.rows() == a.cols()) {							// transpose in place
		for (int i = 0; i < a.rows(); i++)
			for (int j = i+1; j < a.cols(); j++)
				swap(a[i][j], a[j][i]);						// swap elements
		return;
	}
	Array2d<TYPE> b = a;										// make copy
	a.resize(a.cols(), a.rows());							// resize cols x rows array
	for (int i = 0; i < a.rows(); i++)
		for (int j = 0; j < a.cols(); j++)
			a[i][j] = b[j][i];								// copy elements
}
#endif

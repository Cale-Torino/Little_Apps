// nArray.C - n-dimensional array class implementation
#include <iostream.h>
#include <memory.h>
#include <stdarg.h>
#include "nArray.h"

template <class TYPE>
void nArray<TYPE>::range(int i) const {		// subscript range checking
	if (i < 0 || i >= len)
		throw nArrayError<TYPE>(i, len);			// length subscript out of range
}

template <class TYPE>
nArray<TYPE>::nArray(int n, ...) {				// variable argument list
	va_list args;
	va_start(args, n);
	ndimensions = n;									// save number of dimensions
	if (ndimensions > max)
		throw nArrayError<TYPE>("no. of dimensions too large");
	for (int i = 0; i < n; i++)					// pop remaining args from stack
		dimensions[i] = va_arg(args, int);
	dim = n - 1;										// reduce dimension by 1
	len = dimensions[0];								// get first dimension
	subscript = -1;

	dimcalc(dimensions);								// allocate nArray structures
	va_end(args);
}

template <class TYPE>
nArray<TYPE>::nArray(int n, int *psize) {
	dim = n - 1;										// reduce dimension by 1
	len = *++psize;									// get length of next dimension
	subscript = -1;
	dimcalc(psize);									// allocate nArray structures
}

template <class TYPE>
void nArray<TYPE>::dimcalc(int *psize) {
	if (dim > 0) {
		subv = new nArray<TYPE> * [len];
		for (int i = 0; i < len; i++) 
			subv[i] = new nArray<TYPE>(dim, psize);	// recursive constr
	} else  
		pdata = new TYPE [len];						// allocate data
}

template <class TYPE>
void nArray<TYPE>::free() {
	if (dim > 0) {
		for (int i = 0; i < len; i++)
			delete subv[i];							// recursive call to destr
		delete [] subv;
	} else
		delete [] pdata;								// deallocate data
}

template <class TYPE>
void nArray<TYPE>::copy(const nArray<TYPE> & b) {
	len = b.len;
	ndimensions = b.ndimensions;
	memcpy(dimensions, b.dimensions, max*sizeof(int));
	dim = b.dim;
	if (dim > 0) {
		subv = new nArray<TYPE> * [len];
		for (int i = 0; i < len; i++) 			// recursive call to copy constr
			subv[i] = new nArray<TYPE>(*b.subv[i]);
	} else {
		pdata = new TYPE [len];						// allocate data
		for (int i = 0; i < len; i++) 
			pdata[i] = b.pdata[i];
	}
}

template <class TYPE>								// assignment
nArray<TYPE> & nArray<TYPE>::operator=(const nArray<TYPE> & a) {
	if (this != &a) {
		free();
		copy(a);
	}
	return *this;
}

template <class TYPE>
nArray<TYPE> & nArray<TYPE>::operator=(const TYPE & object) {
	if (subscript < 0)
		throw nArrayError<TYPE>("illegal assignment");
	pdata[subscript] = object;						// store data
	return *this;
}

template <class TYPE>
ostream & operator<<(ostream & os, const nArray<TYPE> & a) {
	return os << a.pdata[a.subscript];			// display data
}

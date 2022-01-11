// Array.C - Array Object implementation
#include <iostream.h>
#include "Array.h"

template <class TYPE>
void Array<TYPE>::range(int i) const {
	if (i < 0 || i >= len)
		throw ArrayError(i, len);					// length subscript out of range
}

template <class TYPE>
void Array<TYPE>::copy(const Array<TYPE> & v1) {
	v = new TYPE [len = v1.len];
	for (int i = 0; i < len; i++)
		v[i] = v1.v[i];
}

template <class TYPE>
void Array<TYPE>::free() { delete [] v; }

template <class TYPE>								// Constructor
Array<TYPE>::Array(int length) { 
	if (length <= 0)
		throw ArrayError(length);					// illegal length
	v = new TYPE [len = length];
}

template <class TYPE>								// assignment
Array<TYPE> & Array<TYPE>::operator=(const Array<TYPE> & a) {
	if (this != &a) {
		free();
		copy(a);
	}
	return *this;
}

template <class TYPE>							 	// iostream output
ostream & operator<<(ostream & os, const Array<TYPE> & v1) {
	for (int i = 0; i < v1.length(); i++)
		os << v1[i] << ' ';							// output TYPE element
	return os;
}

// Arrays.C - Array Object implementation with specialization
#include <iostream.h>
#include <memory.h>
#include "Arrays.h"

template <class TYPE>
void Array<TYPE>::range(int i) const {
	if (i < 0 || i >= len)
		throw ArrayError(i, len);					// length subscript out of range
}

template <class TYPE>
void Array<TYPE>::copy(const Array<TYPE> & v1) {
	cout << "Array<TYPE> copy" << endl;
	v = new TYPE [len = v1.len];
	for (int i = 0; i < len; i++)
		v[i] = v1.v[i];
}

void Array<int>::copy(const Array<int> & v1) {			// specialize for ints
	cout << "Array<int> copy" << endl;
	v = new int [len = v1.len];
	memcpy(v, v1.v, len*sizeof(int));
}

template <class TYPE>
void Array<TYPE>::free() { delete [] v; }

template <class TYPE>								// constructor
Array<TYPE>::Array(int length) { 
	if (length <= 0)
		throw ArrayError(length);					// illegal length
	len = length;										// store length
	v = new TYPE [len];
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

// Array.C - Array Object implementation
#include <iostream.h>
#include "Array.h"

template <class TYPE>
void Array<TYPE>::range(int i) const {
	if (i < 0) 
		throw LowerBoundError(i, len);
	else if (i >= len) 
		throw UpperBoundError(i, len);
}

template <class TYPE>
void Array<TYPE>::copy(const Array<TYPE> & v1) {
	v = new TYPE [len = v1.len];
	if (v == 0) 
		throw NoMemory(len);							// exception
	for (int i = 0; i < len; i++)
		v[i] = v1.v[i];
}

template <class TYPE>								// constructor
Array<TYPE>::Array(int length) { 
	if (length <= 0) 
		throw SizeError(length);					// exception
	v = new TYPE [len = length];
	if (v == 0) 
		throw NoMemory(len);							// exception
}

template <class TYPE>								// assignment
Array<TYPE> & 
Array<TYPE>::operator=(const Array<TYPE> & a) {
	if (this != &a) {
		free();
		copy(a);
	}
	return *this;
}

template <class TYPE>								// iostream output
ostream & 
operator<<(ostream & os, const Array<TYPE> & v1) {
	for (int i = 0; i < v1.length(); i++)
		os << v1[i] << ' ';							// output TYPE element
	return os;
}

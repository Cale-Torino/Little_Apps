// Arrayp.C - Array Object implementation, protected access
#include <iostream.h>
#include "Arrayp.h"

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

template <class TYPE>							 	// display Array object
void Array<TYPE>::print(ostream & os) const {
	for (int i = 0; i < len; i++)
		os << v[i] << ' ';							// output TYPE element
}

template <class TYPE>							 	// iostream output
ostream & operator<<(ostream & os, const Array<TYPE> & v1) {
	v1.print(os);										// virtual call
	return os;
}

template <class TYPE>								// resize Array object
void Array<TYPE>::resize(int newlen) {
	TYPE *newp = new TYPE [newlen];				// allocate new memory
	int minlen = len < newlen ? len : newlen;
	for (int i = 0; i < minlen; i++)				// copy data
		newp[i] = v[i];
	delete [] v;										// delete old memory
	v = newp;											// set new memory address
	len = newlen;										// set new length
}

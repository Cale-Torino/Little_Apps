#ifndef ARRAY2DH
#define ARRAY2DH
// Array2d.h - 2D Array Object interface
#include <iostream.h>
#include "Array.h"

template <class TYPE>
class Array2d {
private:
	Array< Array<TYPE> > v2d;					// Array of Array
public:
// Constructors
	explicit Array2d(int rows = 1, int cols = 1);
// Modifiers
	Array<TYPE> & operator[](int i) { return v2d[i]; }
// Selectors
	const Array<TYPE> & operator[](int i) const { return v2d[i]; }
	int rows() const { return v2d.length(); }
	int cols() const { return v2d[0].length(); }
};

template <class TYPE>							// constructor
Array2d<TYPE>::Array2d(int rows, int cols) : v2d(rows) { 
	Array<TYPE> a(cols);							// local Array
	for (int i = 0; i < rows; i++)
		v2d[i] = a;
}

template <class TYPE>							// iostream output
ostream & operator<<(ostream & os, const Array2d<TYPE> & v1) {
	for (int i = 0; i < v1.rows(); i++)
		os << v1[i] << endl;						// output Array<TYPE> object
	return os;
}
#endif

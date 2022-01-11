#ifndef ARRAY3DH
#define ARRAY3DH
// Array3d.h - 3D Array Object interface
#include <iostream.h>
#include "Array2d.h"

template <class TYPE>
class Array3d {
private:
	Array< Array2d<TYPE> > v3d;				// Array of Array2d
public:
// Constructors
	explicit Array3d(int grids = 1, int rows = 1, int cols = 1);
// Modifiers
	Array2d<TYPE> & operator[](int i) { return v3d[i]; }
// Selectors
	const Array2d<TYPE> & operator[](int i) const { return v3d[i]; }
	int grids() const { return v3d.length(); }
	int rows() const { return v3d[0].rows(); }
	int cols() const { return v3d[0].cols(); }
};

template <class TYPE>							// Constructor
Array3d<TYPE>::Array3d(int grids, int rows, int cols) : v3d(grids) { 
	Array2d<TYPE> a(rows, cols);				// local Array2d
	for (int i = 0; i < grids; i++)
		v3d[i] = a;
}

template <class TYPE>							// iostream output
ostream & operator<<(ostream & os, const Array3d<TYPE> & v1) {
	for (int i = 0; i < v1.grids(); i++)
		os << v1[i] << endl;						// output Array2d<TYPE> object
	return os;
}
#endif

#ifndef ARRAY4DH
#define ARRAY4DH
// Array4d.h - 4D Array Object interface, resize()
#include <iostream.h>
#include "Array3d.h"

template <class TYPE>
class Array4d {
private:
	Array< Array3d<TYPE> > v4d;				// Array of Array3d
public:
// Constructors
	explicit Array4d(int solids = 1, int grids = 1, int rows = 1, int cols = 1);
// Modifiers
	Array3d<TYPE> & operator[](int i) { return v4d[i]; }
	void resize(int, int, int, int);			// resize Array4d object
// Selectors
	const Array3d<TYPE> & operator[](int i) const { return v4d[i]; }
	int solids() const { return v4d.length(); }
	int grids() const { return v4d[0].grids(); }
	int rows() const { return v4d[0].rows(); }
	int cols() const { return v4d[0].cols(); }
};

template <class TYPE>									// Constructor
Array4d<TYPE>::Array4d(int solids, int grids, int rows, int cols) 
	: v4d(solids) { 
		Array3d<TYPE> a(grids, rows, cols);			// local Array3d
		for (int i = 0; i < solids; i++)
			v4d[i] = a;
}

template <class TYPE>
void Array4d<TYPE>::resize(int solids, int grids, int rows, int cols) { 
	v4d.resize(solids);							// resize grid Array4d
	for (int i = 0; i < solids; i++)
		v4d[i].resize(grids, rows, cols);	// resize grid x row x col Array3d
}

template <class TYPE>							// iostream output
ostream & operator<<(ostream & os, const Array4d<TYPE> & v1) {
	for (int i = 0; i < v1.grids(); i++)
		os << v1[i] << endl;						// output Array3d<TYPE> object
	return os;
}
#endif

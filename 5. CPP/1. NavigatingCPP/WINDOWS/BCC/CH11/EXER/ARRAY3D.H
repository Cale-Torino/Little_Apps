#ifndef ARRAY3DH
#define ARRAY3DH
// Array3d.h - 3D Array Object interface
#include <iostream.h>
#include "Array2d.h"

template <class TYPE>
class Array3d : public Array< Array2d<TYPE> > {
private:
	int nrows;
	int ncols;
public:
// Constructors
	explicit Array3d(int grids = 1, int rows = 1, int cols = 1);
	void resize(int, int, int);						// resize Array3d object
// Selectors
	int grids() const { return length(); }
	int rows() const { return nrows; }
	int cols() const { return ncols; }
	void print(ostream &) const;						// virtual 
};

template <class TYPE>									// constructor
Array3d<TYPE>::Array3d(int grids, int rows, int cols) :
		Array< Array2d<TYPE> >(grids), nrows(rows), ncols(cols) { 
	Array2d<TYPE> a(rows, cols);						// local Array2d
	for (int i = 0; i < grids; i++)
		v[i] = a;											// write to base Array2d
}

template <class TYPE>
void Array3d<TYPE>::resize(int grids, int rows, int cols) { 
	Array< Array2d<TYPE> >::resize(rows);			// resize grid Array2d
	for (int i = 0; i < grids; i++)
		(*this)[i].resize(rows, cols);				// resize row x col Array2d
}

template <class TYPE>									// iostream output
void Array3d<TYPE>::print(ostream & os) const {
	for (int i = 0; i < grids(); i++)
		os << v[i] << endl;								// display Array2d<TYPE> elements
}
#endif

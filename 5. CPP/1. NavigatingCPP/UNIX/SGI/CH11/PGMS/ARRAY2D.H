#ifndef ARRAY2DH
#define ARRAY2DH
// Array2d.h - 2D Array Object interface
#include <iostream.h>
#include "Arrayp.h"

template <class TYPE>
class Array2d : public Array< Array<TYPE> > {
private:
	int ncols;
public:
// Constructors
	explicit Array2d(int rows = 1, int cols = 1);
// Selectors
	int rows() const { return length(); }
	int cols() const { return ncols; }
	void print(ostream &) const;						// virtual 
};

template <class TYPE>									// constructor
Array2d<TYPE>::Array2d(int rows, int cols) :
		Array< Array<TYPE> >(rows), ncols(cols) { 
	Array<TYPE> a(cols);									// local Array
	for (int i = 0; i < rows; i++)
		v[i] = a;											// write to base Array
}

template <class TYPE>									// iostream output
void Array2d<TYPE>::print(ostream & os) const {
	for (int i = 0; i < rows(); i++)
		os << v[i] << endl;								// display Array<TYPE> elements
}
#endif

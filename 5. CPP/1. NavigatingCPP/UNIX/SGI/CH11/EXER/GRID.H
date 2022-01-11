#ifndef GRIDH
#define GRIDH
// Grid.h - Grid Object interface
#include <iostream.h>
#include "Array2d.h"

template <class TYPE>
class Grid : protected Array2d<TYPE> {
public:
// Constructors
	Grid(int nrows, int ncols) : Array2d<TYPE>(nrows, ncols) { }
// Modifiers
	TYPE & operator()(int i, int j) { return (*this)[i][j]; }
// Selectors
	const TYPE & operator()(int i, int j) const { return (*this)[i][j]; }
// Using declarations
	using Array2d<TYPE>::rows;
	using Array2d<TYPE>::cols;
};

template <class TYPE>							// iostream output
ostream & operator<<(ostream & os, const Grid<TYPE> & g) {
	for (int i = 0; i < g.rows(); i++) {
		for (int j = 0; j < g.cols(); j++)
			os << g(i,j) << ' ';					// output Grid object
		cout << endl;
	}
	return os;
}
#endif

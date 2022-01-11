#ifndef SGRIDH
#define SGRIDH
// SGrid.h - Square Grid Object interface
#include <iostream.h>
#include "Grid.h"

template <class TYPE>
class SGrid : protected Grid<TYPE> {
public:
// Constructors
	explicit SGrid(int size) : Grid<TYPE>(size, size) { }
// Modifiers
	TYPE & operator()(int i, int j) { return v2d[i][j]; }
// Selectors
	const TYPE & operator()(int i, int j) const { return v2d[i][j]; }
// Using declarations
	using Grid<TYPE>::rows;
	using Grid<TYPE>::cols;
};

template <class TYPE>							// iostream output
ostream & operator<<(ostream & os, const SGrid<TYPE> & sg) {
	for (int i = 0; i < sg.rows(); i++) {
		for (int j = 0; j < sg.cols(); j++)
			os << sg(i,j) << ' ';				// output Sgrid object
		cout << endl;
	}
	return os;
}
#endif

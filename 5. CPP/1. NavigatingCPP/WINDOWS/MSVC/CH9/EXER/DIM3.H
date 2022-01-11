#ifndef DIM3H
#define DIM3H
// dim3.h - template 3D array allocation

template <class TYPE>
void dim3(TYPE ***& pgrid, int grid, int row, int col) {		// create 3D array
	TYPE *pdata;										// pointer to data
	TYPE **prow;										// pointer to rows
	pdata = new TYPE [grid * row * col];		// allocate memory for data
	prow = new TYPE * [grid * row];				// allocate row pointers

	for (int j = 0; j < grid * row; j++) {
  		prow[j] = pdata;								// store pointers to rows
  		pdata += col;									// move to next row
	}

	pgrid = new TYPE ** [grid];					// allocate grid pointers
	for (int i = 0; i < grid; i++) {
  		pgrid[i] = prow;								// store pointers to grids
  		prow += row;									// move to next grid
	}
}

template <class TYPE>
void free3(TYPE ***pa)								// free 3D heap storage
{
   delete [] **pa;									// free data 
   delete [] *pa;										// free row pointers 
   delete [] pa;										// free grid pointers 
}

template <class TYPE>
void fill(TYPE ***& a, int grids, int rows, int cols, const TYPE *val) {
	int idx = 0;
	for (int i = 0; i < grids; i++)
		for (int j = 0; j < rows; j++)
			for (int k = 0; k < cols; k++)
				a[i][j][k] = val[idx++];
}

template <class TYPE>
void display(TYPE ***a, int grids, int rows, int cols) {
	for (int i = 0; i < grids; i++) {			// display array elements
		cout << "Grid " << i << endl;
		for (int j = 0; j < rows; j++)
			for (int k = 0; k < cols; k++)
				cout << a[i][j][k] << ((k+1) % cols ? ' ' : '\n');
	}
	cout << endl;
}
#endif

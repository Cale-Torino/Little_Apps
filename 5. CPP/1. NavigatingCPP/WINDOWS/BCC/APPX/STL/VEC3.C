// vec3.C - STL 3D vector container
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <vector>

using namespace std;

template <class TYPE>
ostream & operator<<(ostream & out, const vector<TYPE> & v) {
	copy(v.begin(), v.end(), ostream_iterator<TYPE>(out," "));
	return out << endl;
}

int main(int argc, const char *argv[])
{
	if (argc != 4) {
		cerr << argv[0] << " grids rows cols" << endl;
		return 1;
	}
	int grids = atoi(argv[1]);
	int rows = atoi(argv[2]);
	int cols = atoi(argv[3]);
	int i, j, k, ival = 1;	double dval = .1;

	vector< vector< vector<int> > > a(grids, rows, cols), b;
	for (i = 0; i < a.size(); i++)
		for (j = 0; j < a[0].size(); j++)
			for (k = 0; k < a[0][0].size(); k++)
				a[i][j][k] = ival++;					// fill 3D Array
	cout << a << endl;
	b = a;												// 3D Array assignment
	cout << b << endl;

	vector< vector< vector<double> > > c(grids, rows, cols);
	for (i = 0; i < c.size(); i++)
		for (j = 0; j < c[0].size(); j++)
			for (k = 0; k < c[0][0].size(); k++)
				c[i][j][k] = dval++;					// fill 3D Array
	
	const vector< vector< vector<double> > > d = c;
	cout << d << endl;
	return 0;
}

/****************************************************************************

$ a3d 2 2 5
1 2 3 4 5 
6 7 8 9 10 

11 12 13 14 15 
16 17 18 19 20 


1 2 3 4 5 
6 7 8 9 10 

11 12 13 14 15 
16 17 18 19 20 


0.1 1.1 2.1 3.1 4.1 
5.1 6.1 7.1 8.1 9.1 

10.1 11.1 12.1 13.1 14.1 
15.1 16.1 17.1 18.1 19.1 

*/

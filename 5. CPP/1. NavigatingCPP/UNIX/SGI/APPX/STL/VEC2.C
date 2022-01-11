// vec2.C - STL 2D vector container
#include <iostream.h>
#include <stdlib.h>
#include <vector.h>

//using namespace std;

template <class TYPE>
ostream & operator<<(ostream & os, const vector<TYPE> & v) {
	for (int i = 0; i < v.size(); i++)
		os << ' ' << v[i];					// recursive call for 2d vectors
	os << endl;
	return os;
}

int main(int argc, const char *argv[]) 
{
	if (argc != 3) { 
		cerr << argv[0] << " rows cols" << endl; 
		return 1;
	}
	int rows = atoi(argv[1]);	 int cols = atoi(argv[2]);
	int i, j, ival = 1;	double dval = .1;

	vector< vector<int> > a(rows, cols), b(rows, cols);
	for (i = 0; i < a.size(); i++)
		for (j = 0; j < a[0].size(); j++)
			a[i][j] = ival++;				// fill with integers
	cout << a << endl;
	b = a;									// 2D vector assignment
	cout << b << endl;

	vector< vector<double> > d(rows, cols);
	for (i = 0; i < d.size(); i++)
		for (j = 0; j < d[0].size(); j++)
			d[i][j] = dval++;				// fill with doubles
	cout << d << endl;
	return 0;
}

/***************************************************************************

$ vec2 3 4
  1 2 3 4
  5 6 7 8
  9 10 11 12


  1 2 3 4
  5 6 7 8
  9 10 11 12


  0.1 1.1 2.1 3.1
  4.1 5.1 6.1 7.1
  8.1 9.1 10.1 11.1



*/

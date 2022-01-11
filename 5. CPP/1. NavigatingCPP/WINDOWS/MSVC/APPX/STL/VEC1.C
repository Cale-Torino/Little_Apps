// vec1.C - STL vector container 
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template <class TYPE>
ostream & operator<<(ostream & os, const vector<TYPE> & v) {
	copy(v.begin(), v.end(), ostream_iterator<TYPE>(os," "));
	return os;
}

int main(int argc, const char *argv[]) 
{
	if (argc == 1) {
		cerr << argv[0] << " length" << endl;
		return 1;
	}
	int len = atoi(argv[1]); 
	int i, ival = 1;	double dval = .1;

	vector<int> a(len), b;						// vector of ints

	for (i = 0; i < a.size(); i++)
		a[i] = ival++;								// fill with integers
	cout << "vector a has " << a.size() << " elements" << endl;
	cout << a << endl;

	b = a;											// vector assignment
	cout << b << endl;

	vector<double> c(len);						// vector of doubles
	for (i = 0; i < c.size(); i++)
		c[i] = dval++;								// fill with doubles

	const vector<double> d = c;				// const vector
	cout << "vector d has " << d.size() << " elements" << endl;
	cout << d << endl;
	return 0;
}

/*********************************************************************

$ vec1 10
vector a has 10 elements
1 2 3 4 5 6 7 8 9 10 
1 2 3 4 5 6 7 8 9 10 
vector d has 10 elements
0.1 1.1 2.1 3.1 4.1 5.1 6.1 7.1 8.1 9.1 

*/

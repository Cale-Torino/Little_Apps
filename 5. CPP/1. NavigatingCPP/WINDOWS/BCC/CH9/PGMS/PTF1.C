// ptf1.c - pointers to template functions
#include <iostream.h>

template <class TYPE>
inline TYPE max(const TYPE & a, const TYPE & b) {
	return a > b ? a : b;
}

template <class TYPE>
inline TYPE min(const TYPE & a, const TYPE & b) {
	return a < b ? a : b;
}

int main()
{
	int m = 43, n = 56;
	int (*p)(const int &, const int &) = max;			// initialization
	cout << p(m, n) << endl;								// displays 56

	p = min;														// assignment
	cout << p(m, n) << endl;								// displays 43
	return 0;
}

/**********************************************************************

$ ptf1 
56
43

*/

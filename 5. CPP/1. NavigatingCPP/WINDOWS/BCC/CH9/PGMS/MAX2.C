// max2.c - max() template function
#include <iostream.h>
#include "String.h"

template <class TYPE>
inline TYPE max(const TYPE & a, const TYPE & b) {
	return a > b ? a : b;
}

int main()
{
	int m = 43, n = 56;
	cout << max(m, n) << endl;					// displays 56 (CORRECT)

	double x = 4.3, y = 5.6;
	cout << max(x, y) << endl;					// displays 5.6 (CORRECT)

	String s = "abc", t = "xyz";
	cout << max(s, t) << endl;					// displays xyz (CORRECT)
	return 0;
}

/**********************************************************************

$ max2 
56
5.6
xyz

*/

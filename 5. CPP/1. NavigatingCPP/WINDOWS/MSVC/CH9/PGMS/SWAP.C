// swap.c - swap function
#include <iostream.h>
#include "String.h"

template <class TYPE>
inline void swap(TYPE & a, TYPE & b)
{
	TYPE tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int m = 12, n = 34;
	float x = 4.5, y= 6.7;
	String s = "abc", t = "xyz";

	swap(m, n);											// swap integers
	swap(x, y);											// swap floats
	swap(s, t);											// swap Strings
	cout << m << ' ' << n << endl;				// displays 34 12
	cout << x << ' ' << y << endl;				// displays 6.7 4.5
	cout << s << ' ' << t << endl;				// displays xyz abc
	return 0;
}

/**********************************************************************

$ swap 
34 12
6.7 4.5
xyz abc

*/

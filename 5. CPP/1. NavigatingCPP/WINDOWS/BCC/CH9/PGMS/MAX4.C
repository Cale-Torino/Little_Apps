// max4.c - overloading max() template function
#include <iostream.h>
#include "String.h"

template <class TYPE>
inline TYPE max(const TYPE & a, const TYPE & b) {
	return a > b ? a : b;
}

template <class TYPE>
TYPE max(const TYPE *array, int size) {
	TYPE maxv = array[0];
	for (int i = 1; i < size; i++)
		if (array[i] > maxv)
			maxv = array[i];
	return maxv;
}

int main()
{
	int m = 43, n = 56;
	cout << max(m, n) << endl;					// displays 56

	static double b[6] = { 3.4, -12.7, 88.6, 13.9, 44.8, 68.22 };
	cout << max(b, 6) << endl;					// displays 88.6

	String s = "uno", t = "dos";
	cout << max(s, t) << endl;					// displays uno

	static String c[4] = { "one", "two", "three", "four" }; 
	cout << max(c, 4) << endl;					// displays two
	return 0;
}

/**********************************************************************

$ max4 
56
88.6
uno
two

*/

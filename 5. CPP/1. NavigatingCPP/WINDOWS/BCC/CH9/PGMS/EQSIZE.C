// eqsize.c - equal size template function
#include <iostream.h>
#include "String.h"

template <class TYPE1, class TYPE2>
inline bool eqsize(const TYPE1 & a, const TYPE2 & b) {
	return sizeof(a) == sizeof(b);
}

int main()
{
	long i = 12;  float f = 1.2;  double d = 3.4;
	String a = "abc", b = "xyz";
	cout << eqsize(i, f) << endl;					// displays 1
	cout << eqsize(i, d) << endl;					// displays 0
	cout << eqsize(a, d) << endl;					// displays 1
	cout << eqsize(a, b) << endl;					// displays 1
	return 0;
}

/**********************************************************************

$ eqsize 
1
0
1
1

*/

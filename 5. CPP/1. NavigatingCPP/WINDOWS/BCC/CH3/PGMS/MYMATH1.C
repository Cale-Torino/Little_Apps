// mymath1.C
#include <iostream.h>
#include "geo1.h"

Point origin = { 10, 10 };

int main()
{
	try {
		Point a = { 3, 5 };
		Point b = { 6, 10 };
		cout << "Line a_b has slope " << slope(a, b) << endl;
	}
	catch (char *msg) {						// catch handler
		cout << msg << endl;
		return 1;
	}
	return 0;
}

/************************************************************************

$ mymath1
Error: _origin defined in module mymath.c is duplicated in module geometry.c

*/

// mymath2.C - using declarations
#include <iostream.h>
#include "geo2.h"

math_lib::Point origin = { 5, 5 };		// global declaration

void sub1() {
	using math_lib::Point;					// Point from math_lib
	using geo_lib::Line;						// Line from geo_lib
	using geo_lib::origin;					// origin from geo_lib
	using math_lib::slope;					// slope() from math_lib
	//using math_lib::origin;				// error, multiple declaration
	cout << "origin = (" << origin.x << ", " << origin.y << ")" << endl;
	cout << "::origin = (" << ::origin.x << ", " << ::origin.y << ")" << endl;
}

void sub2() {
	using math_lib::max;						// all max functions
	cout << max(10, 20) << endl;			// max(int, int)
	cout << max(5.6, 7.8) << endl;		// max(double, double)
}

int main()
{
	try {
		sub1();
		sub2();
	}
	catch (char *msg) {						// catch handler
		cout << msg << endl;
		return 1;
	}
	return 0;
}

/************************************************************************

$ mymath2
origin = (10, 10)
::origin = (5, 5)
max(int, int)
20
max(double, double)
7.8

*/

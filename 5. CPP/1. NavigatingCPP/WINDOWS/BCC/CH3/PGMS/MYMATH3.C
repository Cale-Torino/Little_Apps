// mymath3.C - namespaces with program development
#include <iostream.h>
#include "geometry.h"

namespace Geo = Geometry;					// alias

using Geo::Point;								// using declaration
using Geo::slope;								// using declaration

namespace {										// unnamed namespace
	Point origin = { 10, 10 };
}

int main()
{
	try {
		Point a = { 3, 5 };
		Point b = { 6, 10 };
		cout << "Line a_b has slope " << slope(a, b) << endl;
		cout << "Line origin_a has slope " << slope(origin, a) << endl;
	}
	catch (char *msg) {						// catch handler
		cout << msg << endl;
		return 1;
	}
	return 0;
}

/************************************************************************

$ mymath3
Line a_b has slope 1.66667
Line origin_a has slope 0.714286

*/

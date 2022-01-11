// slope.C - Line objects with slopes
#include <iostream.h>
#include "Line.h"

int main()
{
	try {
		Point a(3, 5);
		Point b(6, 10);
		Point c(3, 10);

		Line s(a, b);
		Line t(a, c);

		double s_slope = s.slope();
		cout << "Line s has slope " << s_slope << endl;

		double t_slope = t.slope();		// throws exception
		cout << "Line t has slope " << t_slope << endl;
	}
	catch (const exception & e) {
		cout << e.what() << endl;
		return 1;
	}
	return 0;
}

/************************************************************************

$ slope
Line s has slope 1.66667
Line: undefined slope for xcoords (3, 3)

*/

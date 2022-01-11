// vc2.c - virtual constructor
#include "Window2.h"

double Point::originx = 0;					// initialize originx
double Point::originy = 0;					// initialize originy

int main()
{
	Point::setorigin(1, 1);					// set Point defaults
	Point t1(10, 10), b1(15, 5);
	Point t2(5, 15), b2(10, 5);

	Window w1;									// create Window
	w1.resize(t1, b1);						// resize Window, create Frame(yes)

	XWindow w2;									// create XWindow
	w2.resize(t2, b2);						// resize XWindow, create XFrame(yes)
	return 0;
}

/******************************************************************

$ vc2
Window constr
Frame constr
Frame draw()
Window constr
XWindow constr
Frame constr
XFrame constr
XFrame draw()

*/

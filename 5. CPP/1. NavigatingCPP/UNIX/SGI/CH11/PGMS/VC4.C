// vc4.c - virtual copy constructors (clone)
#include "Window3.h"

double Point::originx = 0;						// initialize originx
double Point::originy = 0;						// initialize originy

void debug(const Window & w) {
	cout << "debug called" << endl;
	Point m1(0, 80), m2(80, -80);
	Window *wsave = w.clone();					// clone operation, virtual call
	wsave->resize(m1, m2);						// virtual call
	delete wsave;
}

int main()
{
	Point::setorigin(1, 1);						// set Point defaults
	Point t1(10, 10), b1(15, 5);

	Window w1;										// create Window
	w1.resize(t1, b1);							// resize Window
	debug(w1);										// pass Window, copy is correct

	XWindow w2;										// create XWindow
	w2.resize(t1, b1);							// resize XWindow							
	debug(w2);										// pass XWindow, copy is correct
	return 0;
}

/******************************************************************

$ vc4
Window constr
Frame constr
Frame draw()
debug called								... with Window
Frame constr
Frame draw()								... correct
Window constr
XWindow constr
Frame constr
XFrame constr
XFrame draw()
debug called								... with XWindow
Frame constr
XFrame constr
XFrame draw()								... correct

*/

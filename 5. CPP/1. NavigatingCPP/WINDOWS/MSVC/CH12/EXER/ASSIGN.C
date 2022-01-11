// assign.c - assignments with Base and Derived
#include "Window3.h"

int main()
{
	try {
		Window w1, w2;									// create Windows
		XWindow xw1, xw2;								// create XWindows

		w1 = w2;											// (1) Window = Window (OK)
		xw1 = xw2;										// (2) XWindow = XWindow (OK)

		w1 = xw1;										// (3) Window = XWindow (illegal)
		//xw1 = w1;										// (4) XWindow = Window (illegal)
	}
	catch (const WindowError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/******************************************************************

$ assign
assign: class Window = class Window
assign: class XWindow = class XWindow
Window: class Window = class XWindow is illegal

NOTES:
	1. The Window class has copy semantics but the XWindow class does not.
		Consequently, an overloaded operator=() is only necessary in Window.

	2. Assigning a Window object to an XWindow object is illegal at compile
		time because there is no overloaded operator=() in XWindow.

	3. Assigning an XWindow object to a Window object (case (3)) is not a 
		compilation error because the compiler allows an XWindow object through 
		the signature of Window::operator(const Window &). 

	4. To make this illegal, you can generate errors either at run time or 
		compile time. In this program, we throw a WindowError object to generate 
		run time errors.

	5. Inside Window::operator=(), we use typeid() to check for case (3).  Note
		that dynamic casts will NOT work here, because XWindow is a subtype of
		Window. If the types differ, we throw a WindowError exception object.

	6. To generate a compilation error instead of a run-time error, include the
		following prototype in the private section of Window.

			class XWindow;											// forward reference

			class Window {
			private:
				. . .
				Window & operator=(const XWindow & a);		// disallow assignment
			public:
				. . .
			};
	
		This disables assignments of XWindow objects to Window objects and
		generates errors at compile time.

*/

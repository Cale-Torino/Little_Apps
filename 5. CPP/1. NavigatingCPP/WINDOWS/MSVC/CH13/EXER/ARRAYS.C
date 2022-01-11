// arrays.C - auto_ptr_array
#include <iostream.h>
#include "autoptr.h"

class Widget { 
public:
	Widget() { cout << "Widget constr" << endl; }
	~Widget() { cout << "Widget destr" << endl; }
	int f(int s = 0) {
		if (s == 0)
			throw "exception";
	return s;
	}
};

int main()
{
	try {
		auto_ptr_array<Widget> pd(new Widget[3]);			// manages resource
		cout << pd[0].f() << endl;								// throws exception
	}
	catch (char *msg) {
		cout << msg << endl;
		return 1;
	}
	return 0;
}

/**********************************************************************

$ arrays
Widget constr
Widget constr
Widget constr
Widget destr
Widget destr
Widget destr
exception

*/

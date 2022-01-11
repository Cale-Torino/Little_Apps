// ste.C - standard exceptions
#include <iostream.h>
#include "exception.h"

void run_system(int s = 0) {
	if (s == 0)
		throw logic_error("logic error");
}

int main()
{
	try {
		run_system();
	}
	catch (const exception & e) {
		cout << e.what() << endl;
		return 1;
	}
	return 0;
}

/***********************************************************************

$ ste
logic error

*/

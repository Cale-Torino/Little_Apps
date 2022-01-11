// catch1.c - catch(...) clause
#include <iostream.h>

void process(int value) {
	if (value == 0)
		throw "value is zero";					// throw point
	else
		throw value;								// throw integer
}

void do_process(int m) {
	try {
		process(m);
	}
	catch (char *msg) {
		cerr << msg << endl;
		return;
	}
	catch (...) {									// catch any exception
		cerr << "Error in do_process" << endl;
		throw;										// rethrow
	}
}

int main()
{
	try {
		int val = 0;
		do_process(val);
	}
	catch (int v) {
		cerr << "value is " << v << endl;
		return 1;
	}
	return 0;
}

/**********************************************************************

$ catch1 
value is zero

*/

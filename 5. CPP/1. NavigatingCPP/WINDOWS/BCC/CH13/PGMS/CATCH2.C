// catch2.c - catch by value and address
#include <iostream.h>

int f() { return 0; }

void do_process() {
	int value = f();
	try {
		if (value < 0)
			throw value;							// throw integer
		if (value == 0)
			throw "zero value";					// throw char string
	}
	catch (int badvalue) {						// catch by value
		cerr << "value = " << badvalue << endl;
	}
	catch (char *msg) {							// catch by address
		cerr << msg << endl;
	}
	cerr << "end of do_process()" << endl;
}

int main()
{
	do_process();
	return 0;
}

/**********************************************************************

$ catch2 
zero value
end of do_process()

*/

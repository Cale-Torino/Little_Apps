// catch6.c - conversions with catch handlers
#include <iostream.h>
#include "String.h"

void do_process() {
	try {
		throw static_cast<String>("error message");		// throw String
	}
	catch (const String & err) {								// catch by reference
		cerr << err << endl;
	}
}

int main()
{
	do_process();
	return 0;
}

/**********************************************************************

$ catch6 
error message

*/

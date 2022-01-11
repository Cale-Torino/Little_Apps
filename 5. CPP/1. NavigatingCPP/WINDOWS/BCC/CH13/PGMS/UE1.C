// ue1.c - unexpected exceptions
#include <iostream.h>
#include <stdlib.h>
#include <except.h>
#include "String.h"

void surprise() {
	cerr << "surprise exception" << endl;
	exit(1);
}

void do_pgm() throw (String) {			// throws String exception
	char *msg = "error message";
	throw msg;									// wrong type, calls unexpected()
}	

int main()
{
	set_unexpected(surprise);
	try {
		do_pgm();
	}
	catch (const String & msg) {
		cerr << msg << endl;
	}
	return 0;
}

/*******************************************************************

$ ue1
surprise exception

*/

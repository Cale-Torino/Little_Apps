// ue2.c - unexpected exceptions, conversion on throw
#include <iostream.h>
#include <stdlib.h>
#include <excpt.h>
#include <eh.h>
#include "String.h"

void surprise() {
	cerr << "surprise exception" << endl;
	exit(1);
}

void do_pgm() throw (String) {				// String exception
	char *msg = "error message";
	throw static_cast<String>(msg);			// throw String
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

$ ue2
error message

*/

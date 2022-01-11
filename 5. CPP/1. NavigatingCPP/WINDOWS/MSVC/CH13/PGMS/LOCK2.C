// lock2.c - exceptions in destructors, recovers, displays errors
#include <iostream.h>
#include "Record2.h"

int main()
{
	try {
		Record r1;
		r1.status();								// throws exception
	}
	catch (char *msg) {							// catch handler
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/***********************************************************************

$ lock2
locking record 0
unlocking record 0
Record: Can't unlock record 0
status_error

*/

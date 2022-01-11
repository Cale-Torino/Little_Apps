// lock4.c - exceptions in destructors, recovers, discards exception, audits
#include <iostream.h>
#include "Record4.h"

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

/**********************************************************************

$ lock4
start_audit
locking record 0
unlocking record 0
stop_audit
status_error

*/

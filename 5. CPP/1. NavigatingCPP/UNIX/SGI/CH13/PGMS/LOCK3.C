// lock3.c - exceptions in destructors, recovers, discards exception
#include <iostream.h>
#include "Record3.h"

int main()
{
	try {
		Record r1;
		r1.status();								// throws exception
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/**********************************************************************

$ lock3
locking record 0
unlocking record 0
status_error

*/

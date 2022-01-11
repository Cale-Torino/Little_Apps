// lock1.c - exceptions in destructors, terminates
#include <iostream.h>
#include "Record1.h"

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

/******************************************************************

$ lock1
locking record 0
unlocking record 0
Abnormal program termination

*/

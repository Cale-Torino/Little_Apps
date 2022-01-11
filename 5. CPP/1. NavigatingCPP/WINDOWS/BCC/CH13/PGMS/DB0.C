// db0.c - resource allocation, resource leak
#include <iostream.h>
#include "Dbase1.h"

int main()
{
	try {
		Dbase *pd = new Dbase;						// allocate Dbase object
		cout << pd->read() << endl;				// throws exception
		delete pd;										// release Dbase object
	}
	catch (const DbaseError & err) {				// base class reference
		err.response();								// virtual call
		return 1;
	}
	return 0;
}

/**********************************************************************

$ db0
Dbase constr
DbaseReadError

*/

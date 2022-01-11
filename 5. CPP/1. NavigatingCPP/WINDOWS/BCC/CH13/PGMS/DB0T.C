// db0t.c - resource allocation, nested try blocks to plug resource leak
#include <iostream.h>
#include "Dbase1.h"

int main()
{
	try {
		Dbase *pd = new Dbase;						// allocate Dbase object
		try {
			cout << pd->read() << endl;			// throws exception
		}
		catch (...) {									// catch any exception
			delete pd;									// release Dbase object
			throw;										// rethrow exception
		}	
		delete pd;										// release Dbase object
	}
	catch (const DbaseError & err) {				// base class reference
		err.response();								// virtual call
		return 1;
	}
	return 0;
}

/**********************************************************************

$ db0t
Dbase constr
Dbase destr
DbaseReadError

*/

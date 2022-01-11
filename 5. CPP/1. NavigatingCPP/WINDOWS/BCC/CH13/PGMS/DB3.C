// db3.c - resource allocation, no resource leak
#include <iostream.h>
#include "Dbase3.h"
#include "autoptr.h"

int main()
{
	try {
		auto_ptr<Dbase> pd(new Dbase);			// manages resource
		cout << pd->read() << endl;				// throws exception
	}
	catch (const DbaseError & err) {				// base class reference
		err.response();								// virtual call
		return 1;
	}
	return 0;
}

/**********************************************************************

$ db3
Base constr
FileTbl constr
ProcessTbl constr
Dbase constr
ProcessTbl destr							// should be here ...
FileTbl destr							
Base destr
DbaseOpenError

*/

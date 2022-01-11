// db2.c - resource allocation, resource leaks
#include <iostream.h>
#include "Dbase2.h"
#include "autoptr.h"

int main()
{
	try {
		auto_ptr<Dbase> pd(new Dbase);			// manages resource
		cout << pd->read() << endl;				// throws exception
	}
	catch (const DbaseError & err) {				// catch exception
		err.response();								// virtual call
		return 1;
	}
	return 0;
}

/**********************************************************************

$ db2
Base constr
Dbase constr
FileTbl constr
ProcessTbl constr
Base destr
DbaseOpenError

*/

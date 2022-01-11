// db4.c - resource allocation, no abstract bases, catch by value (BAD)
#include <iostream.h>
#include "Dbase4.h"
#include "autoptr.h"

int main()
{
	try {
		auto_ptr<Dbase> pd(new Dbase);			// manages resource
		cout << pd->read() << endl;				// throws exception
	}
	catch (const DbaseError err) {				// catch by value (BAD)
		err.response();								// virtual call
		return 1;
	}
	return 0;
}

/**********************************************************************

$ db4
Base constr
FileTbl constr
ProcessTbl constr
Dbase constr
ProcessTbl destr
FileTbl destr
Base destr
DbaseError

*/

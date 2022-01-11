// db1.c - resource allocation, no resource leak
#include <iostream.h>
#include "Dbase1.h"
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

$ db1
Dbase constr
Dbase destr
DbaseReadError

*/

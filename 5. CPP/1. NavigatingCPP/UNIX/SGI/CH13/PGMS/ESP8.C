// esp8.c - exception specifications, violations
#include <iostream.h>
#include <stdlib.h>
#include <exception.h>
#include "Dbase4.h"

void w(int n = 0) throw (DbaseError) {
	if (n == 0)
		throw DbaseError();
}

void u(int m = 0) throw (DbaseWriteError)	{
	w();													// throws DbaseWriteError
	if (m == 0)
		throw DbaseWriteError();
}

int main()
{
	try {
		u();
	}
	catch (const DbaseError & err ) {
		err.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ esp8
Abnormal program termination

*/

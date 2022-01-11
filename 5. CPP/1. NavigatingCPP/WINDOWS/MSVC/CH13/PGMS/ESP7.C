// esp7.c - exception specifications, violations
#include <iostream.h>
#include <stdlib.h>
#include <excpt.h>
#include <eh.h>
#include "Dbase4.h"

void w(int n = 0) throw (DbaseWriteError) {
	if (n == 0)
		throw DbaseWriteError();
}

void u(int m = 0) throw (DbaseError)	{
	w();													// throws DbaseWriteError
	if (m == 0)
		throw DbaseError();
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

$ esp7
DbaseWriteError

*/

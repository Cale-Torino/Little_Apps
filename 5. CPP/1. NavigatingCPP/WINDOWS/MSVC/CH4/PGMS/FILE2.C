// file2.C - File exception objects
#include <iostream.h>
#include "File2.h"

int main()
{
	try {
		File dbase("taxes", "r");
		File records;
	}
	catch (const FileError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ file2 
File: can't open taxes for mode (r)

*/

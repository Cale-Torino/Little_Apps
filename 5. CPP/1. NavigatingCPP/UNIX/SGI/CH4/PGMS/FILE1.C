// file1.C - File objects
#include <iostream.h>
#include "File1.h"

int main()
{
	try {
		File f("test1");								// open test1, read and write
		File g("test2", "w");						// open test2, write only
		File h;											// open temp file, read and write

		File *p = new File;							// open temp file, read and write
		File *q = new File("dbase");				// open dbase for read and write
		File *r = new File("records", "r");		// open records for read only

		delete p;										// close temp file
		delete q;										// close dbase
		delete r;										// close records
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

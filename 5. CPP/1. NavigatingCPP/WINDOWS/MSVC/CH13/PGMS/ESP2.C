// esp2.c - exception specifications, syntax check
#include <iostream.h>
#include <stdlib.h>
#include <excpt.h>
#include <eh.h>

void uncaught() {
	cerr << "uncaught exception" << endl;
	exit(1);
}

class DbaseError { };

class FileError { };

class GridError { };

/*
void g(int x, int y) throw (FileError, DbaseError) {
	if (x == 0) throw FileError();				// OK
	if (y == 0) throw DbaseError();				// OK
	if (x < 0) throw GridError();					// calls unexpected()
}
*/

void g(int x, int y) {
	try {
		if (x == 0) throw FileError();				// OK
		if (y == 0) throw DbaseError();				// OK
		if (x < 0) throw GridError();					// calls unexpected()
	}
	catch (FileError) {
		throw;												// rethrow
	}
	catch (DbaseError) {
		throw;												// rethrow
	}
	catch (...) {
		unexpected();										// illegal exception
	}
}

int main(int argc, const char *argv[])
{
	if (argc != 3) {
		cerr << argv[0] << " x y" << endl;
		return 1;
	}
	set_terminate(uncaught);
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	try {
		g(x, y);
	}
	catch (const FileError &) { 
		cerr << "FileError caught" << endl;
	}
	catch (const DbaseError &) { 
		cerr << "DbaseError caught" << endl;
	}
	return 0;
}

/**********************************************************************

$ esp2 0 1 
FileError caught

$ esp2 1 0 
DbaseError caught

$ esp2 -1 1 
uncaught exception

*/

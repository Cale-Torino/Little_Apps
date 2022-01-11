// esp1.c - exception specifications
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

void f() throw (DbaseError) { }						// OK

void g() throw (FileError, DbaseError)	{ }		// OK

class GridError {
private:
	int num;
public:
	GridError(int n = 0) throw() : num(n) { }		// OK, no throws
	virtual void response() const throw (); 		// OK, no throws
};

class ChartError : public GridError {
public:
	ChartError(int m = 0) throw() : GridError(m) { }	// OK, no throws
	void response() const throw (); 							// OK, no throws
};

void GridError::response() const throw () { 
	cout << "GridError caught" << endl;
}

void ChartError::response() const throw () {
	cout << "ChartError caught" << endl;
}

void h(int x, int y) throw (GridError) {
	if (x == 0) throw GridError();					// OK
	if (y == 0) throw ChartError();					// OK
	if (x < 0) throw DbaseError();					// calls unexpected()
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
		h(x, y);
	}
	catch (const GridError & err) { 
		err.response();
	}
	return 0;
}

/**********************************************************************

$ esp1 0 1 
GridError caught

$ esp1 1 0 
ChartError caught

$ esp1 -1 1 
uncaught exception

*/

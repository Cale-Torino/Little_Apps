// dbase.c - exception hierarchies
#include <iostream.h>

class DbaseError {									// abstract base
public:
	DbaseError() { }
	virtual ~DbaseError() { }						// virtual destructor
	virtual void response() const  = 0;			// pure virtual
};

class DbaseReadError : public DbaseError {
public:
	void response() const { cout << "DbaseReadError" << endl; }
};

class DbaseWriteError : public DbaseError {
public:
	void response() const { cout << "DbaseWriteError" << endl; }
};

class DbaseOpenError : public DbaseError {
public:
	void response() const { cout << "DbaseOpenError" << endl; }
};

class Dbase { };

void process(Dbase &) {
	throw DbaseReadError();							// throw point
	//throw DbaseWriteError();						// throw point
	//throw DbaseOpenError();						// throw point
}

void do_process(Dbase & m) {
	try {
		process(m);
	}
	catch (const DbaseError & err) {				// base class reference
		err.response();								// virtual call
	}
}

int main()
{
	Dbase d;
	do_process(d);
	return 0;
}

/*********************************************************************

$ dbase
DbaseReadError

*/

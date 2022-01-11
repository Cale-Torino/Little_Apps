// dba.c - catch exceptions by address
#include <iostream.h>

class DbaseError {
public:
	DbaseError() { }
	virtual void response() const { cout << "DbaseError" << endl; }
};

class ReadError : public DbaseError {
public:
	void response() const { cout << "ReadError" << endl; }
	~ReadError() { cout << "ReadError destr" << endl; }
};

class Dbase { };

void process(Dbase &) {
	DbaseError *perr = new ReadError();			// Exception object
	throw perr;											// throw address
}

void do_process(Dbase & m) {
	try {
		process(m);
	}
	catch (const DbaseError *perr) {						// catch by address
		perr->response();								// virtual call
	}
}

int main()
{
	Dbase d;
	do_process(d);
	return 0;
}

/*********************************************************************

$ dba
ReadError

*/

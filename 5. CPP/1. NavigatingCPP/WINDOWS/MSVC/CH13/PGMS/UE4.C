// ue4.c - unexpected exceptions with STC class, replace with Bogus
#include <iostream.h>
#include <stdlib.h>
#include <excpt.h>
#include <eh.h>
#include "String.h"
#include "STC.h"

void uncaught() {
	cerr << "uncaught exception" << endl;
	exit(1);
}

void surprise() {
	cerr << "surprise exception" << endl;
	exit(1);
}

void network() {
	cerr << "network exception" << endl;
	exit(1);
}

class Bogus {
public:
	Bogus() { }
	void response() const { cerr << "Bogus exception" << endl; }
};

void gotcha() {
	cerr << "unexpected exception" << endl;
	throw Bogus();								// replace with Bogus exception
}

void process() throw (String, Bogus) {
	char *msg = "error message";
	throw msg;									// wrong type, calls unexpected()
	//throw;										// rethrow, calls terminate()
}

void do_process() {							// throws any exception
	STC<Unexpected> g(gotcha);				// call gotcha() for unexpected()
	STC<Terminate> n(network);				// call network() for terminate()
	process();
}	

int main()
{
	set_unexpected(surprise);
	set_terminate(uncaught);
	try {
		do_process();
	}
	catch (const String & msg) {
		cerr << msg << endl;
	}
	catch (const Bogus & err) {
		err.response();
	}
	return 0;
}

/*******************************************************************

$ ue4
network exception

*/

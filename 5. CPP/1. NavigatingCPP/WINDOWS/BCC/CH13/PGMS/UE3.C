// ue3.c - unexpected exceptions with STC class, exit on unexpected
#include <iostream.h>
#include <stdlib.h>
#include <except.h>
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

void gotcha() {
	cerr << "unexpected exception" << endl;
	exit(1);
}

void process() throw (String) {
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
	return 0;
}

/*******************************************************************

$ ue3
unexpected exception

*/

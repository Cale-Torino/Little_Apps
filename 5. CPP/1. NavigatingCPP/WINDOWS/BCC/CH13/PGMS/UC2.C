// uc2.c - uncaught exceptions with Terminate class
#include <iostream.h>
#include <stdlib.h>
#include <except.h>
#include "Terminat.h"

void uncaught() {
	cerr << "uncaught exception" << endl;
	exit(1);
}

void network() {
	cerr << "network exception" << endl;
	exit(1);
}

void do_pgm() {
	Terminate t(network);				// call network() for terminate()

	throw;									// rethrow, calls terminate()
}	

int main()
{
	set_terminate(uncaught);
	do_pgm();
	return 0;
}

/***********************************************************************

$ uc2
network exception

*/

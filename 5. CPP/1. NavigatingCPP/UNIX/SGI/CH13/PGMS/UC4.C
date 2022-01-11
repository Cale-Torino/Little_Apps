// uc4.c - uncaught exceptions with Terminate class, for Tip
#include <iostream.h>
#include <stdlib.h>
#include <exception.h>
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

	throw "error";							// throw exception
}	

int main()
{
	Terminate t(uncaught);				// incorrect
	do_pgm();
	return 0;
}

/***********************************************************************

$ uc4
network exception

*/

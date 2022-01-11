// esp3.c - exception specifications, pointers to functions
#include <iostream.h>
#include <stdlib.h>
#include <except.h>

//typedef void (*PTRF)() throw (char *);			// illegal

void process() {									// function throws any exception
	cerr << "process called" << endl;
}

void init() throw (int) {						// function throws integer
	cerr << "init called" << endl;
}

int main()
{
	void (*p1)();						// ptr to function throwing any exception
	void (*p2)() throw (int);		// ptr to function throwing integer

	p1 = process;						// OK, exact match
	p1 = init;							// OK, init() is more restrictive

	//p2 = process;					// illegal, process() less restrictive
	p2 = init;							// OK, exact match

	p1();									// call function
	p2();									// call function
	return 0;
}

/**********************************************************************

$ esp3
init called
init called

*/

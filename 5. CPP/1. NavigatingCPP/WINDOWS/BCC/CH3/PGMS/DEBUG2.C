// debug2.C - tests error() for default args (extended)
#include <iostream.h>
#include "error2.h"

int Debug;

int main() 
{
	Debug = 1;

	error("start process");		// legal - msg = "start process", dlevel = 0
	error("bad token",1);		// legal - msg = "bad token", dlevel = 1
	error("no value", 2);		// legal - msg = "no value", dlevel = 2
	error();							// legal - msg = "fatal error", dlevel = 0
	//error(1);						// illegal - no msg specified
	error("no memory", 1, true);	// legal - msg = no memory", 
											// dlevel = 1, kill = 1
	//error(2,1);						// illegal - no msg specified
	return 0;
}

/*******************************************************************

$ debug2
start process
bad token
fatal error
no memory

*/

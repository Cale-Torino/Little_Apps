// debug.C - tests error() for default args
#include <iostream.h>
#include "error.h"

int Debug;

int main() 
{
	Debug = 1;

	error("start process");			// legal - msg = "start process", dlevel = 0
	error("bad token",1);			// legal - msg = "bad token", dlevel = 1
	error("no value", 2);			// legal - msg = "no value", dlevel = 2
	error();								// legal - msg = "fatal error", dlevel = 0
	//error(1);							// illegal - no msg specified
	return 0;
}

/*******************************************************************

$ debug
start process
bad token
fatal error

*/

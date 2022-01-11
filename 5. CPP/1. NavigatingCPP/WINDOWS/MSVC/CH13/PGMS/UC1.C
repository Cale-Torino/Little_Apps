// uc1.c - uncaught exceptions
#include <iostream.h>
#include <stdlib.h>
#include <excpt.h>
#include <eh.h>

void uncaught() {
	cerr << "uncaught exception" << endl;
	exit(1);
}

void do_pgm() {
	throw;								// rethrow, calls terminate()
}	

int main()
{
	set_terminate(uncaught);
	do_pgm();
	return 0;
}

/*******************************************************************

$ uc1
uncaught exception

*/

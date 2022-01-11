// error2.C - default arguments
#include <iostream.h>
#include <stdlib.h>

void error(const char *msg, int dlevel, bool kill)
{
	extern int Debug;

	if (dlevel == 0 || Debug >= dlevel)
		cerr << msg << endl;
	if (kill)
		exit(1);
}

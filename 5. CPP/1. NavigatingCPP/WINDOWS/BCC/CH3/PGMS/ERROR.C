// error.C - default arguments
#include <iostream.h>

void error(const char *msg, int dlevel)
{
	extern int Debug;
	if (dlevel == 0 || Debug >= dlevel)
		cerr << msg << endl;
}

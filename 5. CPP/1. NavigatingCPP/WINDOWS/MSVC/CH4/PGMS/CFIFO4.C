// cfifo4.C - character Fifos
#include <iostream.h>
#include <string.h>
#include "Fifo4.h"

int main()
{
	try {
		 Fifo f;													// declare a Fifo
		 const char *p = "data bytes";
		 int i, nc;
		 nc = strlen(p);

		 f.init();												// initialize Fifo

		 for (i = 0; i < nc; i++)
			 f.write(*p++);										// write chars to Fifo

		 cout << f.nitems() << " characters in fifo" << endl;

		 for (i = 0; i < nc; i++)
			 cout << f.read();									// read chars from Fifo
		 cout << endl;
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/**********************************************************************

$ cfifo4
10 characters in fifo
data bytes

*/

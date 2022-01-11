// cfifo2.C - character Fifos
#include <iostream.h>
#include <string.h>
#include "Fifo2.h"

int main()
{
	Fifo f;													// declare a Fifo
	const char *p = "data bytes";
	int i, nc;
	nc = strlen(p);

	f.init();												// initialize Fifo

	for (i = 0; i < nc && !f.full(); i++)
		f.write(*p++);										// write chars to Fifo

	cout << f.nitems() << " characters in fifo" << endl;

	for (i = 0; i < nc && !f.empty(); i++)
		cout << f.read();									// read chars from Fifo
	cout << endl;
	return 0;
}

/**********************************************************************

$ cfifo2
10 characters in fifo
data bytes

*/

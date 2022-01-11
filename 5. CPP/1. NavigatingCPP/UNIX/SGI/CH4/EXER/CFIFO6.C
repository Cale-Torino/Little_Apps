// cfifo6.C - character Fifos - grows short Fifo
#include <iostream.h>
#include "Fifo6.h"

int main()
{
	try {
		Fifo f(10);									// short char Fifo
	
		for (const char *p = "more data bytes"; *p != '\0'; p++)
			f.write(*p);								// write chars to Fifo f
	
		while (!f.empty())
			cout << f.read();					// read chars from Fifo f
		cout << endl;
	}
	catch (const FifoError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ cfifo6
more data bytes

NOTE:
	You should NOT eliminate the full() method from Fifo, since users
	may still want to test to see if a Fifo is full.

*/

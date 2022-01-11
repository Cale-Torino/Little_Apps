// efifo.C - character Fifos with explicit
#include <iostream.h>
#include "Fifo5.h"

void debug(const Fifo &) { }

int main()
{
	try {
		Fifo f;									// default 80 char Fifo
		Fifo g(1024);							// 1024 char Fifo
		Fifo h("abc");							// 80 char Fifo, initialized to "abc"
		cout << f.length() << endl;
		cout << g.length() << endl;
		cout << h.length() << endl;

		//debug(10);							// illegal, no conversion
		//debug("abc");						// illegal, no conversion
		//Fifo h = 1024;						// illegal
		//Fifo w = "abc";						// illegal
	}
	catch (const FifoError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/*****************************************************************

$ efifo
80
1024
80

*/

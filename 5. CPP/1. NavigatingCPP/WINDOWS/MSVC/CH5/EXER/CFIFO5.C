// cfifo5.C - character Fifos
#include <iostream.h>
#include "Fifo5.h"

namespace ASG = Anderson_Software_Group;
using namespace ASG;

int main()
{
	try {
		Fifo f;											// default 80 char Fifo
		Fifo g(1024);									// 1024 char Fifo
		const Fifo h("data bytes");				// const 80 char Fifo with data
		const Fifo s("small fifo", 20);			// const 20 char Fifo with data
	
		for (const char *p = "more data bytes"; *p != '\0'; p++) {
			f.write(*p);								// write chars to Fifo f
			g.write(*p);								// write chars to Fifo g
		}
	
		h.print();								// display chars from const Fifo h
		s.print();								// display chars from const Fifo s
		f.print();								// display chars from Fifo f
	
		while (!f.empty())
			cout << f.read();					// read chars from Fifo f
		cout << endl;

		while (!s.empty())
			cout << s.read();					// read chars from constant Fifo s
		cout << endl;
	}
	catch (const FifoError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**************************************************************************

$ cfifo5
data bytes
small fifo
more data bytes
more data bytes
small fifo

*/

// cfifo.C - Character Fifos
#include <iostream.h>
#include "Fifo.h"

int main()
{
	try {
		 Fifo f;												// default 80 char Fifo
		 Fifo g(1024);										// 1024 char Fifo
		 const Fifo h("data bytes");					// const 80 char Fifo with data
		 const Fifo s("small fifo", 20);				// const 20 char Fifo with data
	
		 for (const char *p = "more data bytes"; *p != '\0'; p++)
			 g.write(*p);									// write chars to Fifo g
	
		 cout << h << endl;								// display const Fifo h
		 cout << s << endl;								// display const Fifo s
		 f = g;												// Fifo assignment
		 cout << f << endl;								// display Fifo f
		 Fifo w = s;										// copy initialization
		 cout << w << endl;								// display Fifo w
	
		 while (!f.empty())
			 cout << f.read();							// read chars from Fifo f
		 cout << endl;

		 while (!g.empty())
			 cout << g.read();							// read chars from Fifo g
		 cout << endl;
	}
	catch (const FifoError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ cfifo 
data bytes
small fifo
more data bytes
small fifo
more data bytes
more data bytes

NOTES:
1. copy() and free() are necessary because Fifo has a pointer state
	variable and its constructor allocates free store memory.
	This means we'll need the copy constructor, destructor, and overloaded
	assignment from the boilerplate.

2. Note that the overloaded operator<< for ostream calls print(ostream &) 
	for output. This approach works for calls to either cout or cerr 
	with Fifo objects.

3. You could overload operator>> to input characters into Fifo objects.
	(We do not do this here...)

*/

// gfifo.C - generic Fifos
#include <iostream.h>
#include "Fifo.h"
#include "String.h"

int main()
{
	try {
		const int max = 3;
		static String brothers[3] = { "groucho", "chico", "harpo" };

		Fifo<String> f(10);							// 10 String Fifo
		for (int i = 0; i < max; i++)
			f.write(brothers[i]);					// write Strings to Fifo f

		Fifo<String> g;								// default (80) String Fifo
		g = f;											// Fifo assignment
		Fifo<String> h = g;							// Fifo copy initialization

		cout << "Fifo has " << h.nitems() << " objects" << endl;
		while (!h.empty())
			cout << h.read() << ' ';				// read Strings from Fifo h
		cout << endl;
	}
	catch (const FifoError & e) {					// Fifo errors
		e.response();
		return 1;
	}
	catch (const ArrayError & e) {				// Array errors
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ gfifo 
Fifo has 3 objects
groucho chico harpo 

*/

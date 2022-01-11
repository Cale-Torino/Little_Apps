// gfifo3.C - generic Fifos, List containment
#include <iostream.h>
#include "Fifo2.h"
#include "String.h"

int main()
{
	try {
		const int max = 3;
		static String brothers[3] = { "groucho", "chico", "harpo" };

		Fifo<String> f;								// Fifo String
		for (int i = 0; i < max; i++)
			f.write(brothers[i]);					// write Strings to Fifo f

		Fifo<String> g;								// default String Fifo
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
	catch (const ListError & e) {					// List errors
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ gfifo3 
Fifo has 3 objects
groucho chico harpo 

NOTES:
1. Because the List class manages memory for an unbounded Fifo, the
	Fifo class does NOT require the full boilerplate.

2. This design is simpler than the Array containment version, because
	there is no need for front, rear, or count. (List maintains all
	these for you). A full() method is also not necessary.

3. This version is an unbounded Fifo; hence, no length is needed when
	creating Fifo objects.

*/

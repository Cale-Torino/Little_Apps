// gfifo1.C - Character Fifos
#include <iostream.h>
#include "FifoChr.h"

int main()
{
	try {
		const int max = 3;
		static char *brothers[3] = { "groucho", "chico", "harpo" };

		Fifo<char> f(80);							// 80 char Fifo
		for (int i = 0; i < max; i++) {
			char *p = brothers[i];
			while(*p)
				f.write(*p++);						// write chars to Fifo f
			f.write(' ');							// write blank separator
		}
		Fifo<char> g;								// default (80) char Fifo
		g = f;										// Fifo assignment
		Fifo<char> h = g;							// Fifo copy initialization

		cout << "Fifo has " << h.nitems() << " characters" << endl;
		while (!h.empty())
			cout << h.read();						// read chars from Fifo h
		cout << endl;
	}
	catch (const FifoError & e) {				// Fifo errors
		e.response();
		return 1;
	}
	catch (const ArrayError & e) {			// Array errors
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ gfifo1 
Fifo has 20 characters
groucho chico harpo 

*/

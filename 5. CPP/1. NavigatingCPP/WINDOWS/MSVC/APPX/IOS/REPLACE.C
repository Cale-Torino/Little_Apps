// replace.c - random access I/O
#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include "Hue.h"

int main(int argc, const char *argv[])
{
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " colorfile" << endl;
		return 1;
	}

	fstream iofile(argv[1], ios::in | ios::out);		// open file for i/o
	if (!iofile) {												// unable to open
		cerr << "Can't open " << argv[1] << endl;
		return 2;
	}

	Hue newcolor =  { "violet", 22, 7.28 };			// new values

	Hue color;
	streampos start = iofile.tellg();					// starting position
	streampos mark;											// current position

	do {															// read records
		mark = iofile.tellg();								// save current pos
		iofile >> color;										// extract Hue record
	} while ((strcmp(color.name, newcolor.name) != 0) && 
			!iofile.eof());

	if (iofile.eof()) {
		cerr << "Can't find record '" << newcolor.name << "'." << endl;
		return 3;
	}

	iofile.seekp(mark);									// seek to previous record
	if (start != mark)									// check for first record
		iofile << endl;
	iofile << newcolor;									// write new record
	return 0;
}

/***************************************************************************

$ replace colors
$ cat colors
     red      3       6.2
    blue      2       4.4
   green      6       3.6
  orange      2       1.2
  yellow      4       5.3
  violet     22       7.3
  indigo      1       2.3

*/

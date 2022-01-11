// writef.c - write records to disk
#include <iostream.h>
#include <fstream.h>
#include "Hue.h"

const int ncolors = 7;

Hue colors[ncolors] = {
	{ "red", 3, 6.2 },
	{ "blue", 2, 4.4 },
	{ "green", 6, 3.6 },
	{ "orange", 2, 1.2 },
	{ "yellow", 4, 5.3 },
	{ "violet", 5, 4.7 },
	{ "indigo", 1, 2.3 }
};

int main(int argc, const char *argv[])
{
	if (argc == 1) {
		cerr << "Usage: " << argv[0] << " colorfile" << endl;
		return 1;
	}

	ofstream outfile(argv[1], ios::out);			// open file for output
	if (!outfile) {										// unable to open
		cerr << "Can't open " << argv[1] << endl;
		return 2;
	}

	for (int i = 0; i < ncolors; i++)
		outfile << colors[i] << endl;					// insert Hue data value
	return 0;
}

/************************************************************************

$ writef colors
$ cat colors
     red      3       6.2
    blue      2       4.4
   green      6       3.6
  orange      2       1.2
  yellow      4       5.3
  violet      5       4.7
  indigo      1       2.3

*/

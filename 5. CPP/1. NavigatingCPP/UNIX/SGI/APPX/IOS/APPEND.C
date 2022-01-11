// append.c - open a file for appending
#include <iostream.h>
#include <fstream.h>
#include "Hue.h"

const int ncolors = 2;

Hue newcolors[ncolors] = {
	{ "gray", 11, 6.5 },
	{ "black", 13, 8.4 }
};

int main(int argc, const char *argv[])
{
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " colorfile" << endl;
		return 1;
	}

	ofstream outfile(argv[1], ios::app | ios::nocreate);	// open for append
	if (!outfile) {													// unable to open
		cerr << "Can't open " << argv[1] << endl;
		return 2;
	}

	for (int i = 0; i < ncolors; i++)
		outfile << newcolors[i] << endl;
	return 0;
}

/************************************************************************

$ append colors
$ cat colors
     red      3       6.2
    blue      2       4.4
   green      6       3.6
  orange      2       1.2
  yellow      4       5.3
  violet     22       7.3
  indigo      1       2.3
    gray     11       6.5
   black     13       8.4

*/

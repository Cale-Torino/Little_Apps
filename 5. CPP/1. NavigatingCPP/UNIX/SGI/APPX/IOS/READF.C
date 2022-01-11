// readf.c - read records from disk
#include <iostream.h>
#include <fstream.h>
#include "Hue.h"

int main(int argc, const char *argv[])
{
	if (argc == 1) {
		cerr << "Usage: " << argv[0] << " colorfile" << endl;
		return 1;
	}

	ifstream infile(argv[1], ios::in);				// open file for input
	if (!infile) {											// unable to open
		cerr << "Can't open " << argv[1] << endl;
		return 2;
	}

	Hue color;
	while (infile >> color) 							// stops on EOF
		cout << color << endl;
	return 0;
}

/************************************************************************

$ readf colors
     red      3       6.2
    blue      2       4.4
   green      6       3.6
  orange      2       1.2
  yellow      4       5.3
  violet      5       4.7
  indigo      1       2.3

*/

// ex4.C - I/O formatting
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>

int main()
{
	int i;

	fstream numfile("numbers.out", ios::in | ios::out);
	if (!numfile) {
		cerr << "File open failed" << endl;
		return 1;
	}

	numfile << setfill('0');
	for (i = 0; i < 10; i++) {
		numfile << setw(3) << i << endl;
	}
	numfile << setfill('*');
	numfile << setiosflags(ios::showpoint | ios::showpos 
					| ios::internal);
	numfile << setprecision(3);
	float f;
	for (i = 0; i < 10; i++) {
		f = i;
		numfile << setw(8) << f << endl;
	}

	numfile.seekg(0);					// get pointer is at beginning
	cout << numfile.rdbuf();		// dump filebuf to standard output
	return 0;
}

/*************************************************************************

$ ex4
000
001
002
003
004
005
006
007
008
009
+**0.000
+***1.00
+***2.00
+***3.00
+***4.00
+***5.00
+***6.00
+***7.00
+***8.00
+***9.00

*/

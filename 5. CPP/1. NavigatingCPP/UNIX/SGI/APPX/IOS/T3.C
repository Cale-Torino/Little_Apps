// t3.c - file input and output
#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>

int main()
{
	const int bufsize = 100;
	char buf[bufsize];
	ofstream outfile("data.txt");
	if (outfile) {
		outfile << "            This is a shortline." << endl;
		outfile.close();
	}
	else {
		cerr << "could not open 'data.txt' for output" << endl;
		return 1;
	}
	ifstream infile ("data.txt");
	if (infile) {
		infile >> ws;				// "eat" white space
		infile.getline(buf, bufsize);
		cout << buf << endl;
	}
	else {
		cerr << "could not open 'data.txt' for input" << endl;
		return 2;
	}
	return 0;
}

/************************************************************************

$ t3
This is a shortline.

*/

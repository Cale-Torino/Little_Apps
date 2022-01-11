// t4.c - open file for read/write
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>

int main()
{
	fstream iofile ("data.txt", ios::in | ios::out);
	if (!iofile) {
		cerr << "Cannot open file 'data.txt'" << endl;
		return 1;
	}
	iofile.seekp(0);
	iofile << "This is at the beginning" << endl;
	iofile.seekp(0, ios::end);
	iofile << "This is at the end" << endl;
	return 0;
}

/***************************************************************************

$ t4
(no output)

$ cat data.txt
This is at the beginning
This is at the end

*/

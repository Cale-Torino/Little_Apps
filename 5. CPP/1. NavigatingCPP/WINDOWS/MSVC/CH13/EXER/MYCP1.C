//  mycp1.C - File object copy semantics
#include <iostream.h>
#include "File1.h"

int main(int argc, const char *argv[])
{
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << 
			" source_file destination_file" << endl;
		return 1;
	}

	try {
		File infile(argv[1], "r");
		File outfile(argv[2], "w");
		File in = infile;						// copy initialization
		File out("dummy", "w");				// dummy file
		out = outfile;							// assignment

		int c;
		while ((c = fgetc(in)) != EOF)
			fputc(c, out);						// copy files
	}
	catch (const FileError & err) {
		err.response();
		return 1;
	}
	catch (const exception & e) {
		cout << e.what() << endl;
		return 1;
	}
	return 0;
}

/*****************************************************************

$ mycp1 myfile newfile

NOTES:
	1. See FilePtr.h

*/

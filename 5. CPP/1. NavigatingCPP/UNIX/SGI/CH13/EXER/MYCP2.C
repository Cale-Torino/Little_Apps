//  mycp2.C - File object copy semantics
#include <iostream.h>
#include "File2.h"

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

$ mycp2 file1 file2
Unable to open file file1 for access "r"
(File not readable or does not exist)

$ mycp2 myfile /etc/passwd
Unable to open file /etc/passwd for access "w"
(File not writable)

$ mycp2 myfile newfile

NOTES:
	1. In File2.h, we derive FBadRead and FBadWrite from FBadOpen to
		distinguish failed opens for reads from failed opens for writes.
		The File constructor throws these exception objects when an
		fopen() fails.

	2. Because response() is virtual for FileError exception objects,
		there are NO changes to the application, even through the try
		block is throwing different exceptions now.

*/

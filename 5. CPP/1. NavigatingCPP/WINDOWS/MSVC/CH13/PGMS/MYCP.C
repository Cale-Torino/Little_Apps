//  mycp.c - copy files with FilePtr objects
#include <iostream.h>
#include "File.h"

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
		int c;
		while ((c = fgetc(infile)) != EOF)
			fputc(c, outfile);
	}

	catch (const FileError & err) {
		err.response();
		return 1;
	}
	return 0;
}

/*****************************************************************

$ mycp file1 file2
Unable to open file file1 for access "r"

$ mycp myfile /etc/passwd
Unable to open file /etc/passwd for access "w"

$ mycp myfile newfile

*/

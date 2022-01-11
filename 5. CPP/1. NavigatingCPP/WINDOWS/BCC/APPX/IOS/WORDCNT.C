// wordcnt.c - count words, lines, bytes in text files
#include <iostream.h>
#include <fstream.h>
#include <strstrea.h>
#include <iomanip.h>

int main(int argc, const char *argv[])
{
	if (argc == 1) {
		cerr << "Usage: " << argv[0] << " filename(s)" << endl;
		return 1;
	}
	int total_bytes = 0;
	int total_lines = 0;
	int total_words = 0;
	int lines = 0;

	for (int i = 1; i < argc; i++) {
		ifstream infile(argv[i], ios::in);		// open file for input
		if (!infile) {									// unable to open
			cerr << "Can't open " << argv[i] << endl;
			continue;									// try next file
		}

		const int Size = 1024;
		char buf[Size];
		char word[Size];
		lines = 0;
		int bytecount = 0;
		int wordcnt = 0;

		while (infile.getline(buf, Size)) {
			bytecount += infile.gcount();			// number of chars read
			lines++;
			istrstream in_mem(buf);					// initialize in_mem
			while (in_mem >> setw(Size) >> word) 		// now count words
				wordcnt++;
		}

		cout << setw(7) << lines << setw(8) << wordcnt 
				<< setw(8) << bytecount << "    " << argv[i] << endl;
		total_bytes += bytecount;
		total_lines += lines;
		total_words += wordcnt;
	}

	if (total_lines != lines) {					// more than one file
		cout << setw(7) << total_lines << setw(8) << total_words
				<< setw(8) << total_bytes << "    Total" << endl;
	}
	return 0;
}

/************************************************************************

$ wordcnt *.c 
    193     925    6068    STRING.C
     25      60     474    ioprec.c
     52     152     996    readf.c
     89     338    2304    seekf.c
     65     251    1763    wordcnt.c
     51     180    1138    writef.c
    475    1906   12743    Total

NOTES:
	1. Your output may vary from wc because of gcount().
	   If it does, try 

			bytecount += infile.gcount() + 1;	// number of chars read
			
*/

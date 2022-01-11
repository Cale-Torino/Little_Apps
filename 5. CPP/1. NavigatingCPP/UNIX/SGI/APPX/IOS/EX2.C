// ex2.C - I/O using files
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>

const int MaxWord = 10;

int main()
{
	char word[MaxWord];
	int i;
	float f;

	ifstream infile("data.in");					// input stream file

	ofstream outfile("data.out");					// output stream file

	if (infile.fail() || outfile.fail()) {		// files opened OK?
		cerr << "File open failed" << endl;
		return 1;
	}

	infile >> i;										// extract integer
	infile >> setw(MaxWord) >> word;				// extract character string
	infile >> f;										// extract float

	outfile << "Contents of file 'data.in':" << endl;
	outfile << i << ' ' << word << ' ' << f << endl;
	cout << "Your file contained:" << endl;
	cout << i << ' ' << word << ' ' << f << endl;
	return 0;
}

/*************************************************************************

$ ex2
Your file contained:
8 music 33.3

$ cat data.out
Contents of file 'data.in':
8 music 33.3

*/

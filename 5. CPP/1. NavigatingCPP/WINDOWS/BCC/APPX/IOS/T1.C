// t1.c - opening files
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>

const int MaxWord = 10;
const int MaxSz = 80;
char buf[MaxSz];

int main()
{
	char word[MaxWord] = "testing";
	int i = 5;
	float f = 98.6;

	clog << i << ' ' << word << ' ' << f << endl;
	fstream iofile;
	iofile.open("myfile.txt", ios::in | ios::out);  
	if (!iofile) {
		cerr << "iofile open failed" << endl;
	}
	iofile.seekp(0, ios::end);				// put pointer at end
	streampos mark = iofile.tellp();
	if (iofile.good()) iofile << word << endl;
	else cerr << "word not written" << endl;
	
	iofile.seekp(0);			// beginning

	if (iofile.good()) iofile << "       i = " << i << endl;
	else cerr << "integer not written" << endl;
	iofile.seekp(mark);
	iofile << "new word = testing2" << endl;
	iofile.close();
	ifstream infile("myfile.txt");			// open for reading
	if (!infile) cerr << "problem with infile" << endl;
	do {
		infile.read(buf, MaxSz);
		cout << infile.gcount() << " bytes read" << endl;
	} while (!infile.eof());
   
	// to read the file a line at a time, use:
	infile.clear();
	infile.seekg(0);
	while (infile.getline(buf, MaxSz))
		cout << buf << endl;
	
	// to read the file a line at a time, use:
	cout << "\n \tNow processing with get: " << endl;
	char ch;
	infile.clear();
	infile.seekg(0);
	while (infile.get(buf, MaxSz)) {
		cout << buf << endl;
		infile.get(ch);
	}
	
	cout << "\n \tNow processing with single-char get: " << endl;
	infile.clear();
	infile.seekg(0);
	while (infile.get(ch)) {
		if (ch == '\n') cout << "\t(End of line)";
		cout << ch;
	}
	
	cout << "\n \tNow processing with single-int get: " << endl;
	infile.clear();
	infile.seekg(0);
	while ((i = infile.get()) != EOF) {
		if (i == '\n') cout << "\t(End of line)";
		cout << static_cast<char>(i);
	}
	infile.clear();
	infile.seekg(0);
	char ch1, ch2;
	while (infile.get(ch)) {
		if (ch == '\n') cout << "\t(End of line)";
		if (ch == 'r') {
			infile.get(ch1);  // next one 'e'?
			if (ch1 == 'e') {
				 ch2 = infile.peek();
				 if (ch2 == 'd') {
					  infile.ignore(MaxSz, '\n');
					  cout << "\t(red found, ignore rest of line)" << endl;
				 }
			}
			else {									// not an 'e'
				cout << ch;							// display the 'r'
				infile.putback(ch1);				// put back the char
			}
		}
		//if (ch == 'g') {
			//infile.ignore(MaxSz, '\n');
			//cout << "\t(g found, ignore rest of line)" << endl;
		//}
		else cout << ch;
	}
	return 0;
}

/****************************************************************************

80 bytes read
34 bytes read
       i = 5

new word = testing2
new word = testing2
new word = testing2
new word = testing2
new word = testing2

 	Now processing with get: 
       i = 5

new word = testing2
new word = testing2
new word = testing2
new word = testing2
new word = testing2

 	Now processing with single-char get: 
       i = 5	(End of line)
	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)

 	Now processing with single-int get: 
       i = 5	(End of line)
	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)
       i = 5	(End of line)
	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)
new word = testing2	(End of line)

*/

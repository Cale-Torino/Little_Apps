// ex3.c - string input stream
#include <iostream.h>
#include <strstream.h>
#include <mstring.h>
#define istringstream istrstream

const int MaxWord = 10;

int main()
{
	char word[MaxWord];
	int i;
	float f;
	string s("8 music 33.3");

	istringstream memory(s.data());

	memory >> i;									// extract an integer
	memory >> word;								// extract a character string
	memory >> f;									// extract a float
	cout << "string contained:" << endl;
	cout << i << ' ' << word << ' ' << f << endl;
	return 0;
}

/************************************************************************

$ ex3
string contained:
8 music 33.3

*/

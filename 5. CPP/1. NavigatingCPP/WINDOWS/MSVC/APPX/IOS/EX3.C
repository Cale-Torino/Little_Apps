// ex3.c - string input stream
#include <iostream.h>
#include <strstrea.h>
#include "String.h"
#define istringstream istrstream

const int MaxWord = 10;

int main()
{
	char word[MaxWord];
	int i;
	float f;
	String s("8 music 33.3");

	istringstream memory(const_cast<char *>(static_cast<const char *>(s)));

	memory >> i;									// extract an integer
	memory >> word;								// extract a character string
	memory >> f;									// extract a float
	cout << "String contained:" << endl;
	cout << i << ' ' << word << ' ' << f << endl;
	return 0;
}

/************************************************************************

$ ex3
String contained:
8 music 33.3

*/

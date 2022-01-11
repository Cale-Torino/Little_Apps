// ex1.c - I/O using standard input and output
#include <iostream.h>
#include <iomanip.h>

const int MaxWord = 10;

int main()
{
	char word[MaxWord];
	int i;
	float f;

	cout << "Type in an integer: ";
	cin >> i;										// extract an integer
	cout << "Type in a word: ";
	cin >> setw(MaxWord) >> word;				// extract a character string
	cout << "Type in a float: ";
	cin >> f;										// extract a float
	cout << "You typed: ";
	cout << i << ' ' << word << ' ' << f << endl;
	return 0;
}

/************************************************************************

$ ex1
Type in an integer: 8
Type in a word: music
Type in a float: 33.3
You typed: 8 music 33.3

*/

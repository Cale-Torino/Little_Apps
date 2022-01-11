// pitems.c - published items
#include <iostream.h>
#include "Publish.h"

int main()
{
	Book b1("Where Is Joe Merchant?");
	Book b2("Jurassic Park");
	Vhs v1("Jurassic Park");
	Laserdisc v2("Jurassic Park");

	cout << b1 << endl << b2;
	if (b1 == b2)									// Book and Book
		cout << " (same)" << endl;
	else
		cout << " (different)" << endl;
	cout << v1 << endl << b2;
	if (v1 == b2)									// Vhs and Book
		cout << " (same)" << endl;
	else
		cout << " (different)" << endl;
	cout << v1 << endl << v2;
	if (v1 == v2)									// Vhs and Laserdisc
		cout << " (same)" << endl;
	else
		cout << " (different)" << endl;
	return 0;
}

/********************************************************************

$ pitems
I am a Book: Where Is Joe Merchant?
I am a Book: Jurassic Park (different)
I am a Vhs: Jurassic Park
I am a Book: Jurassic Park (different)
I am a Vhs: Jurassic Park
I am a Laserdisc: Jurassic Park (same)

*/

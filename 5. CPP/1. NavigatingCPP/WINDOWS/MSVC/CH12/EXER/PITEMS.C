// pitems.c - published items
#include <iostream.h>
#include "Publish.h"

int main()
{
	Book b1("Where Is Joe Merchant?");
	Book b2("Jurassic Park");
	Vhs v1("Jurassic Park");
	Laserdisc v2("Jurassic Park");
	SuperVhs v3("Jurassic Park");

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
	cout << v1 << endl << v3;
	if (v1 == v3)									// Vhs and SuperVhs
		cout << " (same)" << endl;
	else
		cout << " (different)" << endl;
	return 0;
}

/********************************************************************

$ pitems
I am a class Book: Where Is Joe Merchant?
I am a class Book: Jurassic Park (different)
I am a class Vhs: Jurassic Park
I am a class Book: Jurassic Park (different)
I am a class Vhs: Jurassic Park
I am a class Laserdisc: Jurassic Park (same)
I am a class Vhs: Jurassic Park
I am a class SuperVhs: Jurassic Park (same)

NOTES:
	1. SuperVhs should be a subclass of Video, not Vhs. That's because a SuperVhs is not
		compatable with a Vhs. (SuperVhs tapes won't play in Vhs units).

	2. Note that no extra code needs to be written to include SuperVhs objects into our
		Published_Item hierarchy. Because SuperVhs is a Video object, the compiler calls
		Video::equals() and compares objects with dynamic cast. This means a SuperVhs will
		match against a Vhs or a Laserdisc that has the same title, but will not match
		against a Book.

	3. The changes are in Publish.h

*/

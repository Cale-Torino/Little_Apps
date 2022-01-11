// ship3.c - object-oriented approach with boxes and letters
#include <iostream.h>
#include "Package.h"

float ship(const Package & p) {
	return p.cost();										// calculate cost
}

int main()
{
	Box b("Yuma", "Denver", 25.5);					// 25.5 pound box
	cout << ship(b) << endl;

	Letter m("Atlanta", "Boise", 100);				// 100 page letter
	cout << ship(m) << endl;
	return 0;
}

/**********************************************************************

$ ship3 
12.75
5

*/

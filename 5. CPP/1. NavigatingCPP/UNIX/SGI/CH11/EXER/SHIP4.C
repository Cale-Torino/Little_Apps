// ship4.c - object-oriented approach with boxes, letters, and crates
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

	Wood_Crate wc("Boston", "Nashville", 250);	// 250 pound wood crate
	cout << ship(wc) << endl;

	Metal_Crate mc("Fresno", "Tucson", 800);		// 800 pound metal crate
	cout << ship(mc) << endl;
	return 0;
}

/**********************************************************************

$ ship4 
12.75
5
375
2000

*/

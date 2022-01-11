// rom1.c - Roman objects
#include <iostream.h>
#include "Roman.h"

int main()
{
	Roman r1 = 5, r2 = 50;
	Roman r3 = r1 + r2;								// add Roman objects
	cout << r3.getroman() << endl;				// displays LV

	r1 += r2;											// update r1 by r2
	cout << r1.getroman() << endl;				// displays LV
	return 0;
}

/**********************************************************************

$ rom1 
LV
LV

NOTES:
1. See Roman.h for discussion.

*/

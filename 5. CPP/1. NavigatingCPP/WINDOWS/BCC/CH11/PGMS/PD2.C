// pd2.c - private derivation BArray
#include <iostream.h>
#include "Barray.h"

int main()
{
	try {
		BArray<int> eighties(1980, 1989);		// Bounded Array of 10 years
		BArray<bool> alphabet('a', 'z');			// Bounded Array of 26 booleans

		cout << "length of eighties = " << eighties.length() << endl;
		cout << "length of alphabet = " << alphabet.length() << endl;

		int val = 1;
		eighties[1985] = val++;
		alphabet['m'] = true;
		cout << eighties[1985] << ' ' << alphabet['m'] << endl;
	}
	catch (const ArrayError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ pd2 
length of eighties = 10
length of alphabet = 26
1 1

*/

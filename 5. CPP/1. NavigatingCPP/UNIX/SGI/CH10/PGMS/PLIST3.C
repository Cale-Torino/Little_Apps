// plist3.C - List of String objects
#include <iostream.h>
#include "List.h"
#include "String.h"

const int max = 3;

int main()
{
	try {
		static const String brothers[] = { "groucho", "chico", "harpo" };

		List<String> L1;								// empty List
		for (int i = 0; i < max; i++)
			L1.append(brothers[i]);					// append to List

		Iterator<String> iterf(L1);				// Iterator at front of List
		for (; !iterf; iterf++)						// iterate forward
			cout << iterf() << ' ';					// display data item
		cout << endl;

		Iterator<String> iterb(L1,					// Iterator at end of List
				Iterator<String>::end);		
		for (; !iterb; iterb--)						// iterate reverse
			cout << iterb() << ' ';					// display data item
		cout << endl;

		List<String> L2;								// empty list				
		L2 = L1;											// List assignment
		cout << L2 << endl;							// display List
	}
	catch (const ListError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**************************************************************

$ plist3
groucho chico harpo 
harpo chico groucho 
groucho chico harpo 

*/

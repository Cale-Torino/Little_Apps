// plist2.C - remove and print List of char * strings
#include <iostream.h>
#include "List2.h"

const int max = 3;

int main()
{
	static const char *brothers[] = { "groucho", "chico", "harpo" };
	List L1;

	for (int i = 0; i < max; i++)
		L1.append(brothers[i]);
	cout << "L1 has " << L1.length() << " strings" << endl;
	L1.print();

	L1.remove(L1.getEnd());						// remove last entry
	L1.remove("chico");							// find and remove "chico"
	L1.print();
	return 0;
}

/**********************************************************************

$ plist2 
L1 has 3 strings
groucho chico harpo 
groucho 

*/

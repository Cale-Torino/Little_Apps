// plistn2.C - print List of char * strings, nested classes (extended)
#include <iostream.h>
#include "Listn2.h"

const int max = 3;

int main()
{
	static const char *brothers[] = { "groucho", "chico", "harpo" };
	List L1;

	for (int i = 0; i < max; i++)
		L1.append(brothers[i]);
	cout << "L1 has " << L1.length() << " strings" << endl;
	L1.print();
	return 0;
}

/**********************************************************************

$ plistn2 
L1 has 3 strings
groucho chico harpo 

*/

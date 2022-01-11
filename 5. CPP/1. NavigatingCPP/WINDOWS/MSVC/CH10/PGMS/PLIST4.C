// plist4.C - List of String objects
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
		cout << L1 << endl;

		Iterator<String> iterf(L1);				// Iterator at front of List
		for (; !iterf; iterf++)
			if (iterf() == "chico") {
				L1.remove(iterf);
				L1.insert("zeppo", iterf);
				break;
			}
		cout << L1 << endl;
		L1.prepend("gummo");
		cout << L1 << endl;
	}
	catch (const ListError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**************************************************************

$ plist4
groucho chico harpo 
groucho zeppo harpo 
gummo groucho zeppo harpo 

*/

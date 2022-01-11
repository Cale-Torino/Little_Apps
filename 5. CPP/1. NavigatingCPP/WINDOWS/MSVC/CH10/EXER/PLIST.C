// plist.c - List remove(), replace() template functions 
#include <iostream.h>
#include "String.h"
#include "List.h"

template <class TYPE>
void remove(List<TYPE> & list, const TYPE & target) {
	for (Iterator<TYPE> iter(list); !iter; iter++)
		if (iter() == target) {							// find target
			list.remove(iter);							// remove it
			return;
		}
	throw ListError("List data not found");
}

template <class TYPE>
void replace(List<TYPE> & list, const TYPE & oldt, const TYPE & newt) {
	for (Iterator<TYPE> iter(list); !iter; iter++)
		if (iter() == oldt) {							// find old target
			list.remove(iter);							// remove it
		  	list.insert(newt, iter);					// replace
			return;
		}
	throw ListError("List data not found");
}

void remove(List<String> & list, const char *target) {		// specialize
	remove(list, static_cast<String>(target));
}

void replace(List<String> & list, const char *oldt, const char *newt) {
	replace(list, static_cast<String>(oldt), static_cast<String>(newt));
}

int main()
{
	try {
		 List<String> L1;
		 L1.append("groucho");	L1.append("chico");		L1.append("harpo");

		 remove(L1, "chico");						// remove "chico" from L1
		 replace(L1, "harpo", "zeppo");			// replace "harpo" with "zeppo"
		 cout << L1 << endl;
	}
	catch (const ListError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ plist
groucho zeppo 

NOTES:
	1. The remove() and replace() functions are not members of List because 
		they are too specialized.  That is, both functions seem more like part
		of an application rather than a class interface. 
		Note that each function calls List member functions to do their job.

	2. Another reason is that neither function takes an Iterator for an
		argument, so an attached Iterator would not "know" when a data item 
		was replaced or removed.

	3. Note that we also specialize remove() and replace() with char *
		versions.

*/

// lcopy1.C - List of pointer to String objects
#include <iostream.h>
#include "String.h"
#include "ListCopy.h"

const int max = 3;

int main()
{
	static const String brothers[] = { "Eric", "Bruce", "Scott" };
	
	ListCopyC<String> L1;
	
	for (int i = 0; i < max; i++) {
		L1.append(new String(brothers[i]));
	}
	ListCopyC<String> L2(L1);									// copy constructor
	
	cout << "L1 = " << L1 << endl;							// display entire List
	cout << "L2 = " << L2 << endl;							// display entire List
	PtrIterator<String> iterL1(L1);
	delete L1.remove(iterL1);									// remove first element
	L2 = L1;															// assignment
	cout << "L1 = " << L1 << endl;							// display entire List
	cout << "L2 = " << L2 << endl;							// display entire List
	return 0;
}

/************************************************************************

$ lcopy1
L1 = Eric Bruce Scott 
L2 = Eric Bruce Scott 
L1 = Bruce Scott 
L2 = Bruce Scott 

*/

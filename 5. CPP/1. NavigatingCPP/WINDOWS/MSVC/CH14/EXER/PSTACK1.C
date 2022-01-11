// pstack1.C - Bounded, Unbounded Stack class (pointer semantics)
#include <iostream.h>
#include "BPStack.h"
#include "UBPStack.h"

int main()
{
	int i, *intptr;
	const int stacksize = 10;
	BPtrStack<int> s(stacksize);				// Bounded Stack
	UBPtrStack<int> t;							// Unbounded Stack

	for (i = 1; !s.full(); i++) {
		intptr = new int(i);
		s.push(intptr);
	}
	while (!s.empty()) {
		intptr = s.pop();
		cout << *intptr << ' ';
		delete intptr;
	}
	cout << endl;
	for (i = 1; i <= stacksize; i++) {
		intptr = new int(i*10);
		t.push(intptr);
	}
	while (!t.empty()) {
		intptr = t.pop();
		cout << *intptr << ' ';
		delete intptr;
	}
	cout << endl;
	return 0;
}

/**********************************************************************

$ pstack1 
10 9 8 7 6 5 4 3 2 1 
100 90 80 70 60 50 40 30 20 10 

*/

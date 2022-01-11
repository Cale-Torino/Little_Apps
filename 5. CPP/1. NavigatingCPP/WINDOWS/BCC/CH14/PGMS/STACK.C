// stack.C - Bounded, Unbounded Stack class (value semantics)
#include <iostream.h>
#include "BStack.h"
#include "UBStack.h"
#include "String.h"

int main()
{
	int i;
	const int nums = 10;
	const int strings = 3;
	static const String brothers[] = { "groucho", "chico", "harpo" };
	BStack<int> s(nums), t(nums);				// bounded int Stack

	for (i = 1; i <= nums; i++)
		if (!s.full())
			s.push(i);
	t = s;											// Stack object assignment

	while (!t.empty())
		cout << t.pop() << ' ';
	cout << endl;

	UBStack<String> u, v;						// unbounded Stack of Strings

	for (i = 0; i < strings; i++)
		u.push(brothers[i]);

	v = u;											// Stack object assignment
	while (!v.empty())
		cout << v.pop() << ' ';
	cout << endl;
	return 0;
}

/***********************************************************************

$ stack
10 9 8 7 6 5 4 3 2 1 
harpo chico groucho 

*/

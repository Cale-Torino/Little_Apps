// tstack2.C - Template Stack class, full boilerplate
#include <iostream.h>
#include "Stack2.h"

int main()
{
	try {
		 Stack<int> s(10);                      // Stack of int objects

		 for (int i = 1; i <= s.length(); i++)
			  if (!s.full())
				  s.push(i);

		 cout << "There are " << s.nitems() << " items on the Stack" << endl;

		 Stack<int> t = s;								// Stack copy initialization
		 Stack<int> w(10);
		 w = t;												// Stack assignment

		 while (!s.empty())
			 cout << s.pop() << ' ';
		 cout << endl;

		 while (!t.empty())
			 cout << t.pop() << ' ';
		 cout << endl;

		 while (!w.empty())
			 cout << w.pop() << ' ';
		 cout << endl;
	}
	catch (const StackError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ tstack2 
There are 10 items on the Stack
10 9 8 7 6 5 4 3 2 1 
10 9 8 7 6 5 4 3 2 1 
10 9 8 7 6 5 4 3 2 1 

NOTES:
1. You do NOT need the full boilerplate with this design approach because
	of Array containment.

*/

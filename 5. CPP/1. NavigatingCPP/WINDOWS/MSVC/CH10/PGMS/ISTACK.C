// istack.C - Stack class with integers
#include <iostream.h>
#include "StackInt.h"

int main()
{
	try {
		 Stack s(10);                             // Stack of int objects

		 for (int i = 1; i <= s.length(); i++)
			  if (!s.full())
				  s.push(i);

		 cout << "There are " << s.nitems() << " items on the Stack" << endl;
		 while (!s.empty())
			 cout << s.pop() << ' ';
		 cout << endl;
	}
	catch (const StackError & e) {
		e.response();
		return 1;
	}
   return 0;
}

/**********************************************************************

$ istack 
There are 10 items on the Stack
10 9 8 7 6 5 4 3 2 1 

*/

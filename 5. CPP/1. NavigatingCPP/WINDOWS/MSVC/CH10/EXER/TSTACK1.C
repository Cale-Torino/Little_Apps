// tstack1.C - Template Stack class, constructor initializer
#include <iostream.h>
#include "Stack1.h"
#include "String.h"

template <class TYPE>
TYPE Stack<TYPE>::ival = 0;						// template initialization

String Stack<String>::ival = "";					// specialized initialization

int main()
{
	try {
		 Stack<int> s(10);                      // Stack of int objects
		 for (int i = 1; i <= s.length(); i++)
			  if (!s.full())
				  s.push(i);
		 cout << "There are " << s.nitems() << " items on the Stack" << endl;

		 Stack<int> t = s;								// Stack copy initialization
		 while (!t.empty())
			 cout << t.pop() << ' ';
		 cout << endl;

		 Stack<String> w(10, "abc");					// push initial value
		 w.push("def");
		 w.push("ghi");
		 cout << "There are " << w.nitems() << " items on the Stack" << endl;

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

$ tstack1 
There are 10 items on the Stack
10 9 8 7 6 5 4 3 2 1 
There are 3 items on the Stack
ghi def abc 

*/

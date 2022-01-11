// stack1.C - STL stack adapter
#include <iostream.h>
#include <vector.h>
#include <deque.h>
#include <stack.h>
#include <mstring.h>

//using namespace std;

int main()
{
	int i;
	const int nums = 10;
	const int strings = 3;
	static const string brothers[] = { "groucho", "chico", "harpo" };
	stack< int, vector<int> > s, t;			// stack of integers

	for (i = 1; i <= nums; i++)
 		s.push(i);
	t = s;											// stack assignment

	for (; !t.empty(); t.pop())
		cout << t.top() << ' ';
	cout << endl;

	stack< string, vector<string> > u, v;	// stack of strings

	for (i = 0; i < strings; i++)
		u.push(brothers[i]);

	v = u;											// stack assignment
	for (; !v.empty(); v.pop())
		cout << v.top() << ' ';
	cout << endl;
	return 0;
}

/***********************************************************************

$ stack1
10 9 8 7 6 5 4 3 2 1 
harpo chico groucho 


*/

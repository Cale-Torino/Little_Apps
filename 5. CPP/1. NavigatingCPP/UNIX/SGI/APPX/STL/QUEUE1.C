// queue1.C - STL queue adapter
#include <iostream.h>
#include <list.h>
#include <deque.h>
#include <vector.h>
#include <stack.h>
#include <mstring.h>

//using namespace std;

int main()
{
	const int max = 3;
	static const string brothers[] = { "groucho", "chico", "harpo" };

	queue< string, list<string> > f;
	for (int i = 0; i < max; i++)
		f.push(brothers[i]);

	queue< string, list<string> > g;
	g = f ;											// queue assignment
	queue< string, list<string> > h = g;	// copy initialization

	cout << "queue has " << h.size() << " objects" << endl;
	for (; !h.empty(); h.pop())
 		cout << h.front() << ' ';				// read strings from queue h
	cout << endl;
	return 0;
}

/*********************************************************************

$ queue1
queue has 3 objects
groucho chico harpo 

*/

// queue1.C - STL queue adapter
#include <iostream>
//#include <list>
#include <queue>
#include <string>

using namespace std;

int main()
{
	const int Max = 3;
	static const string brothers[] = { "groucho", "chico", "harpo" };

	//queue< list<string> > f;
	queue<string> f;
	for (int i = 0; i < Max; i++)
		f.push(brothers[i]);

	//queue< list<string> > g;
	queue<string> g;
	g = f ;											// queue assignment
	//queue< list<string> > h = g;
	queue<string> h = g;							// copy initialization

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

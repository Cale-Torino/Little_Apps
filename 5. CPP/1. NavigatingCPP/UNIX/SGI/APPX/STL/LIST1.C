// list1.C - STL list container
#include <iostream.h>
#include <list.h>
#include <mstring.h>

//using namespace std;

template <class TYPE>
ostream & operator<<(ostream & os, const list<TYPE> & v) {
	copy(v.begin(), v.end(), ostream_iterator<TYPE>(os," "));
	return os;
}

int main()
{
	const int Max = 3;
	static const string brothers[] = { "groucho", "chico", "harpo" };
	list<string> L1(brothers, brothers+Max);		// initialize list

	list<string>::iterator iterf = L1.begin();
	for (; iterf != L1.end(); iterf++)				// iterate forward
 		cout << *iterf << ' ';						// display data item
	cout << endl;

	// position at last item and reverse
	list<string>::reverse_iterator iterb = L1.rbegin();
	for (; iterb != L1.rend(); iterb++)				// iterate reverse
 		cout << *iterb << ' ';
	cout << endl;

	list<string> L2;								// empty list				
	L2 = L1;										// list assignment
	cout << L2 << endl;								// display list
	return 0;
}

/*********************************************************************

$ list1
groucho chico harpo 
harpo chico groucho 
groucho chico harpo 

*/

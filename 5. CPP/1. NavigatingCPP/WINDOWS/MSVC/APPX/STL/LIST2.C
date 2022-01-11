// list2.C - STL list container with iterator searches
#include <iostream>
#include <list>
#include <string>

using namespace std;

template <class TYPE>
ostream & operator<<(ostream & os, const list<TYPE> & ls) {
	copy(ls.begin(), ls.end(), ostream_iterator<TYPE>(os," "));
	return os;
}

int main()
{
	const int Max = 3;
	static const string brothers[] = { "groucho", "chico", "harpo" };

	//list<string> L1(brothers, brothers+Max);		// initialize list
	list<string> L1;											// initialize list
	for (int j = 0; j < 3; j++)
		L1.push_back(brothers[j]);
	cout << L1 << endl;

	list<string>::iterator iterf = L1.begin();
	for (; iterf != L1.end(); iterf++)		// iterate forward
		if (*iterf == "chico") {
			*iterf = "zeppo";						// replace "chico" with "zeppo"
			L1.insert(iterf, "harpo");			// insert before "zeppo"
			break;
		}
	cout << L1 << endl;
	L1.pop_front();								// get rid of "groucho"
	L1.push_front("gummo");						// put "gummo" at front
	L1.push_back("zeppo");						// put "zeppo" at end
	cout << L1 << endl;
	return 0;
}

/*********************************************************************

$ list2
groucho chico harpo 
groucho harpo zeppo harpo 
gummo harpo zeppo harpo zeppo 

*/

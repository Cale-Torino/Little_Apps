// find1.C - STL find() generic algorithm
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	static const int numbers[] = { 1, 6, 9, 10 };
	static const string brothers[] = { "groucho", "chico", "harpo" };

	vector<int> a(numbers, numbers+4);			// initialize a
	//list<string> b(brothers, brothers+3);	// initialize b
	list<string> b;									// initialize b
	for (int j = 0; j < 3; j++)
		b.push_back(brothers[j]);

	vector<int>::iterator i = find(a.begin(), a.end(), 9);
	list<string>::iterator s = find(b.begin(), b.end(), "harpo");

	if (i != a.end())
		cout << "Found: " << *i << endl;
	if (s != b.end())
		cout << "Found: " << *s << endl;
	return 0;
}

/*********************************************************************

$ find1
Found: 9
Found: harpo

*/

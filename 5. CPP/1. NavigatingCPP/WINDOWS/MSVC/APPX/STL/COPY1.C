// copy1.C - STL copy() algorithm
#include <iostream.h>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

template <class TYPE>
ostream & operator<<(ostream & os, const list<TYPE> & ls)
{
	copy(ls.begin(), ls.end(), ostream_iterator<TYPE>(os," "));
	return os;
}

template <class TYPE>
ostream & operator<<(ostream & os, const vector<TYPE> & ls)
{
	copy(ls.begin(), ls.end(), ostream_iterator<TYPE>(os," "));
	return os;
}

//template <class T2, class T1>
//ostream& operator<<(ostream& os, const T1<T2>& con)
//{
	//copy(con.begin(), con.end(), ostream_iterator<T2>(os," "));
	//return os;
//}

int main()
{
// Note: the container class must have storage allocated BEFORE
// using copy().
	static int array[] = { 8, 3, 7, 7, 2, 3 };
	const int len = 6;
	vector<int> v(len);				// allocate len slots
	list<int> ls(len);				// allocate len slots

// show copy()
	copy(array, array+len, v.begin());
	cout << "vector output: " ;
	cout << v << endl;

	copy(v.begin(), v.end(), ls.begin());
	cout << "list output: " ;
	cout << ls << endl;

// show sort()
	sort(v.begin(), v.end());
	cout << "vector output: " ;
	cout << v << endl;

// show list member functions reverse() and remove()
// Note: list::sort() bombs!
	ls.reverse();
	cout << "list output: " ;
	cout << ls << endl;

	ls.remove(3);
	cout << "list output: " ;
	cout << ls << endl;

// show unique()
// Note: unique does not erase any elements!
	vector<int>::iterator i = unique(v.begin(), v.end());
	v.erase(i, v.end());
	cout << "vector output: " ;
	cout << v << endl;
	return 0;
}

/**************************************************************

$ copy1
vector output: 8 3 7 7 2 3 
list output: 8 3 7 7 2 3 
vector output: 2 3 3 7 7 8 
list output: 3 2 7 7 3 8 
list output: 2 7 7 8 
vector output: 2 3 7 8 
*/

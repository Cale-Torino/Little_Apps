// algo1.C - STL generic algorithms
#include <iostream.h>
#include <vector.h>
#include <algo.h>

//using namespace std;

bool neg(int n) { return n < 0; }			// predicate function

int main()
{
	int i;
	vector<int> a(15);
	for (i = 0; i < 15; i++)
		a[i] = i-4;

	int result = 0;
	//int result;
	//result = count_if(a.begin(), a.end(), neg);
	count_if(a.begin(), a.end(), neg, result);
	cout << result << " elements in vector are negative" << endl;

	reverse(a.begin(), a.end());
	replace_if(a.begin(), a.end(), neg, 0);

	for (i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}

/*********************************************************************

$ algo1
4 elements in vector are negative
10 9 8 7 6 5 4 3 2 1 0 0 0 0 0 

*/

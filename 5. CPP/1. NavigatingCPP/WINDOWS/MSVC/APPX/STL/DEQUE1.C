// deque1.C - STL deque container
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

bool negative(int i) { return i < 0; }			// predicate function

void display_times_ten(int i) { cout << i*10 << ' '; }

int main()
{
	static const int numbers[] = { -5, 6, 0, -5, -1, -12, 20, -1 };
	const int len = 8;
	deque<int> a;								// double-ended queue of ints
	int i;
	for (i = 0; i < len; i++)
		if (numbers[i] < 0)
			a.push_front(numbers[i]);		// negative values to front
		else 
			a.push_back(numbers[i]);		// non-negative values to end
	for (i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << endl;

	sort(a.begin(), a.end());				// sort deque

	int neg;
	neg = count_if(a.begin(), a.end(), negative);			// count negative
	cout << "There are " << neg
			<< " negative values in container a" << endl;
	for_each(a.begin(), a.end(), display_times_ten);	// apply to each
	cout << endl;
	return 0;
}

/*********************************************************************

$ deque1
-1 -12 -1 -5 -5 6 0 20 
There are 5 negative values in container a
-120 -50 -50 -10 -10 0 60 200 

*/

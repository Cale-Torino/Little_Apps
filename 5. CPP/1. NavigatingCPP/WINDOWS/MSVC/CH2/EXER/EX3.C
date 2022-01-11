// ex3.C - populate a two-dim integer array, use pointers to display
#include <iostream.h>
#include <iomanip.h>

int main()
{
	int nums[5][10];						// 5 X 10 integer array
	int *p = nums[0];						// ptr to first int, first row
	int value = 1;

	while (p < nums[5])					// check against last int in row
		*p++ = value++;

	for (p = nums[0]; p < nums[5]; p++) {
		cout << setw(3) << *p;
		if ((&nums[4][9] - p) % 10 == 0)			// end of row?
			cout << endl;
	}
	return 0;
}

/************************************************************************

$ ex3
  1  2  3  4  5  6  7  8  9 10
 11 12 13 14 15 16 17 18 19 20
 21 22 23 24 25 26 27 28 29 30
 31 32 33 34 35 36 37 38 39 40
 41 42 43 44 45 46 47 48 49 50

*/

// move1.c - generic object copy
#include <iostream.h>
#include "String.h"

template <class TYPE>
void move(TYPE *dest, const TYPE *src, int count) {
	if (count <= 0)
		throw "move(): count is zero or negative";
	for (int i = 0; i < count; i++)
		dest[i] = src[i];
}

template <class TYPE>
void display(const TYPE *a, int count) {
	if (count <= 0)
		throw "display(): count is zero or negative";
	for (int i = 0; i < count; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int main()
{
	try {
		const int len = 10;
		static int ivals[len] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int a[len], b[len];
		move(a, ivals, len);							// fill with integers
		display(a, len);
		move(b, a, 5);									// move 5 integers
		display(b, 5);

		static String svals[len] = { "zero", "one", "two", "three", "four",
											  "five", "six", "seven", "eight", "nine" };
		String c[len], d[len], e[len];
		move(c, svals, len);							// fill with Strings
		display(c, len);
		move(d, c, 5);									// move 5 Strings
		display(d, 5);

		move(e, d, -10);								// illegal count, throws exception
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/**********************************************************************

$ move1
0 1 2 3 4 5 6 7 8 9 
0 1 2 3 4 
zero one two three four five six seven eight nine 
zero one two three four 
move(): count is zero or negative

*/

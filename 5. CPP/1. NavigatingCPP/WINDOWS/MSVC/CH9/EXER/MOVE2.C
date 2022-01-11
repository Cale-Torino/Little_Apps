// move2.c - generic object copy, specialized
#include <iostream.h>
#include "String.h"

void *bmove(void *destptr, const void *srcptr, size_t count) {
	const int bsize = 256;								// tunable block size parameter
	typedef unsigned char byte;
	struct mblock {
		byte buf[bsize];									// block buffer
	};
	byte *dest = static_cast<byte *>(destptr);
	const byte *src = static_cast<const byte *>(srcptr);

	while (count >= bsize) {							// transfer blocks
		*reinterpret_cast<mblock *>(dest) =			// block move
			*reinterpret_cast<const mblock *>(src);
		dest += bsize;										// increment dest pointer
		src += bsize;										// increment src pointer
		count -= bsize;									// decrement count
	}
	while (count--)										// transfer remaining bytes
		*dest++ = *src++;
	return destptr;										// return pointer to data
}

template <class TYPE>
void move(TYPE *dest, const TYPE *src, int count) {	// template function
	if (count <= 0)
		throw "move(): count is zero or negative";
	for (int i = 0; i < count; i++)
		dest[i] = src[i];
}

void move(int *dest, const int *src, int count) {		// specialize integers
	if (count <= 0)
		throw "move(): count is zero or negative";
	bmove(dest, src, count * sizeof(int));					// optimzed block move
}

void move(double *dest, const double *src, int count) {	// specialize doubles
	if (count <= 0)
		throw "move(): count is zero or negative";
	bmove(dest, src, count * sizeof(double));					// optimzed block move
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

		static double dvals[len] = { 0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 
												6.1, 7.1, 8.1, 9.1 };
		double s[len], t[len];
		move(s, dvals, len);							// fill with doubles
		display(s, len);
		move(t, s, 5);									// move 5 doubles
		display(t, 5);

		//move(e, d, -10);							// illegal count, throws exception
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/**********************************************************************

$ move2
0 1 2 3 4 5 6 7 8 9 
0 1 2 3 4 
zero one two three four five six seven eight nine 
zero one two three four 
0.1 1.1 2.1 3.1 4.1 5.1 6.1 7.1 8.1 9.1 
0.1 1.1 2.1 3.1 4.1 

*/

// bmove2.c - optimized block move function, no default tunable parameter
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <memory.h>

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

int main()
{
	int a[10]; 
	static int b[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	bmove(a, b, 10*sizeof(int));						// block move integer data
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}

/******************************************************************

$ bmove2
0 1 2 3 4 5 6 7 8 9 

NOTE:
bsize cannot be a default argument in bmove() because it's used as a
length with array buf in struct mblock.

*/

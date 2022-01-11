// bmove.c - optimized block move function
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

int main(int argc, const char *argv[])
{
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " length" << endl;
		return 1;
	}
	int i, length = atoi(argv[1]);
	int *a = new int[length];		int *b = new int[length];

	for (i = 0; i < length; i++)						// fill with integers
		b[i] = i;
	bmove(a, b, length * sizeof(int));				// block move integer data
	for (i = 0; i < length; i++)						// display moved data
 		cout << setw(4) << a[i] << (((i+1) % 10) ? ' ' : '\n');
	cout << endl;
	delete [] a;
	delete [] b;

	char *c = new char[length];		char *d = new char[length];
	memset(d, 'x', length);								// fill with char data
	bmove(c, d, length);									// block move char data
	for (i = 0; i < length; i++)						// display moved data
 		cout << setw(4) << c[i] << (((i+1) % 10) ? ' ' : '\n');
	delete [] c;
	delete [] d;
	return 0;
}

/******************************************************************

* Here are the stats:

		Integers:	(9 block moves x 256) + (96 byte moves) = 2400/2 = 1200
								96 %                  4 %

			Chars:	(4 block moves x 256) + (176 byte moves) = 1200	  
								85 %                 15 %

$ bmove 1200
	 0    1    2    3    4    5    6    7    8    9
	10   11   12   13   14   15   16   17   18   19
  . .  . .  . .  . .  . .  . .  . .  . .  . .  . .
 1180 1181 1182 1183 1184 1185 1186 1187 1188 1189
 1190 1191 1192 1193 1194 1195 1196 1197 1198 1199

	 x    x    x    x    x    x    x    x    x    x
  . .  . .  . .  . .  . .  . .  . .  . .  . .  . .
	 x    x    x    x    x    x    x    x    x    x

*/

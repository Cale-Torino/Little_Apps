// ndim.C - Multi-dimensional array routines
#include <iostream.h>
#include "ndim.h"
void *dimcalc(int, int, int *);

void ndim(void *pn, ...)								// build array
{
	va_list args;
	va_start(args, pn);									// get array pointer
	int num = va_arg(args, int);						// pop stack for no. of dims
	int size = va_arg(args, int);						// pop stack for size

	int *nargs = new int[num];							// holds remaining arguments
	for (int i = 0; i < num; i++)						// pop remaining args from stack
		nargs[i] = va_arg(args, int);

	*static_cast<char **>(pn) = static_cast<char*>(dimcalc(num-1, size, nargs));
	delete [] nargs;
	va_end(args);
}

void nfree(void *pf, int num)							// release array
{
	if (--num)
		nfree(*static_cast<char **>(pf), num);		// recursive call
	delete [] pf;
}

void *dimcalc(int dim, int size, int *nargs)		// support routine
{
	if (dim > 0) {
		void **prow = new void * [size];
		int cdim = *nargs;								// get current dimension
		int nbytes = nargs[dim];						// size of object
		*nargs *= size;									// update by size
		int newsize = *nargs++;							// get size of this dimension
		char *p = static_cast<char *>(dimcalc(dim-1, newsize, nargs));
		for (int i = 0; i < size; i++) { 
			prow[i] = p;
			p += cdim * nbytes;							// scale by object's size
		}
		return prow;
	} 
	else {  
		int nbytes = *nargs;								// size of object
		void *pdata = new char [size * nbytes];	// allocate data
		return pdata;
	}
}

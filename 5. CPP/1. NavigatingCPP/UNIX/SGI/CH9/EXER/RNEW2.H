#ifndef RNEWH
#define RNEWH
// Rnew2.h - Template realloc() definition, specialization
#include <memory.h>

int *rnew(int *p, int old_len, int new_len) {			// integer specialization
	if (p == 0)														// check zero pointer
		throw "rnew(): called with zero pointer";
	int *newp = new int [new_len];							// allocate new memory
	int min_len = old_len < new_len ? old_len : new_len;
	memcpy(newp, p, min_len * sizeof(int));				// copy integers
	delete [] p;													// delete old memory
	return newp;
}

double *rnew(double *p, int old_len, int new_len) {	// double specialization
	if (p == 0)														// check zero pointer
		throw "rnew(): called with zero pointer";
	double *newp = new double [new_len];					// allocate new memory
	int min_len = old_len < new_len ? old_len : new_len;
	memcpy(newp, p, min_len * sizeof(double));			// copy doubles
	delete [] p;													// delete old memory
	return newp;
}

template <class TYPE>
TYPE *rnew(TYPE *p, int old_len, int new_len) {
	if (p == 0)													// check zero pointer
		throw "rnew(): called with zero pointer";
	TYPE *newp = new TYPE [new_len];						// allocate new memory
	int min_len = old_len < new_len ? old_len : new_len;
	for (register int i = 0; i < min_len; i++)		// copy data
		newp[i] = p[i];
	delete [] p;												// delete old memory
	return newp;
}
#endif

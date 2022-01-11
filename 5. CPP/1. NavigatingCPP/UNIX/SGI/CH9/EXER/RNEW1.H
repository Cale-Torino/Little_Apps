#ifndef RNEWH
#define RNEWH
// Rnew1.h - Template renew()

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

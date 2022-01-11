// Range.C - Template Range number implementation
#include <iostream.h>
#include "Range.h"

template <class TYPE>
Range<TYPE>::Range(const TYPE & v, const TYPE & min, const TYPE & max) : minv(min), maxv(max) {
	if (v >= minv && v <= maxv)
		value = v;
	else
		throw RangeError<TYPE>(v, *this);			// throw exception
}

template <class TYPE>
Range<TYPE> & Range<TYPE>::operator=(const Range<TYPE> & r1) {
	if (r1 >= minv && r1 <= maxv)					// within range?
		value = r1;									// assign new value
	else
		throw RangeError<TYPE>(r1, *this);			// throw exception
	return *this;
}

template <class TYPE>
istream & operator>>(istream & is, Range<TYPE> & r1) {
	int temp;
	is >> temp;										// input integer
	r1 = temp;										// range check
	return is;
}

template <class TYPE>
ostream & operator<<(ostream & os, const Range<TYPE> & r1) {
	return os << '(' << static_cast<TYPE>(r1) << ", " << r1.min() 
				<< ", " << r1.max() << ')';
}

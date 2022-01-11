#ifndef BARRAYH
#define BARRAYH
// BArray.h - generic bounded Array class
#include <stdio.h>
#include "Array.h"

class BArrayError : public ArrayError {				// BArray exception object
private:
	char buf[80];
public:
	BArrayError(int index, int lower, int upper) {	// BArray subscript error
		sprintf(buf, "BArray: subscript %d out of bounds for "
			"lower = %d, upper = %d", index, lower, upper);
	}
	void response() const { cerr << buf << endl; }
};

template <class TYPE>
class BArray : private Array<TYPE> {
private:
	int lower, upper;
	void range(int) const;
	static TYPE ival;								// initial value
	void init(const TYPE &);					// initialize with values
public:
// Constructor
   BArray(int lb, int ub, const TYPE & value = ival) : 
		Array<TYPE> (ub - lb + 1) { lower = lb; upper = ub; init(value); } 
// Modifiers
	inline TYPE & operator[](int);
// Selectors
	inline const TYPE & operator[](int) const;
	int lb() const { return lower; }
	int ub() const { return upper; }
// Using declaration
	using Array<TYPE>::length;
};

template <class TYPE>
void BArray<TYPE>::init(const TYPE & v) {			// initialize with values
	for (int i = lb(); i <= ub(); i++)
		Array<TYPE>::operator[](i - lower) = v;
}

template <class TYPE>
void BArray<TYPE>::range(int i) const {
	if (i < lower || i > upper)
		throw BArrayError(i, lower, upper);			// out of range
}

template <class TYPE> 
inline TYPE & BArray<TYPE>::operator[](int i) {
#ifndef NORANGE
	range(i);
#endif
	return Array<TYPE>::operator[](i - lower);
}

template <class TYPE> 
inline const TYPE & BArray<TYPE>::operator[](int i) const {
#ifndef NORANGE
	range(i);
#endif
	return Array<TYPE>::operator[](i - lower);
}

template <class TYPE>							 	// iostream output
ostream & operator<<(ostream & os, const BArray<TYPE> & v1) {
	for (int i = v1.lb(); i <= v1.ub(); i++)
		os << v1[i] << ' ';							// output TYPE element
	return os;
}

int BArray<int>::ival = 0;
#endif

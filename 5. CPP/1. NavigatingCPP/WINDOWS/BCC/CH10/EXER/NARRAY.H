#ifndef NARRAYH
#define NARRAYH
// nArray.h - n-dimensional array class interface
#include <iostream.h>
#include <stdio.h>
#include <stdarg.h>

template <class TYPE>
class nArray {
private:
	enum { max = 20 };							// max of 20 dimensions
	int dimensions[max];							// holds dimensions
	mutable int subscript;						// holds subscript to data
	int dim;											// for the recursion
	int len;											// for the recursion
	int ndimensions;								// number of dimensions
	union {
		nArray<TYPE> **subv;						// pointer to subvectors
		TYPE *pdata;								// pointer to data
	};
	void dimcalc(int *);							// recursive support function
	void range(int) const;						// range-checking for subscripts
	void copy(const nArray<TYPE> &);			// copy memory
	void free();									// free memory
public:
// Constructors
	nArray() { subv = 0; len = dim = 0; subscript = -1; }
	nArray(int, ...);
	nArray(int, int *);
	nArray(const nArray<TYPE> & a) { copy(a); }		// copy constructor
// Destructor
	~nArray() { free(); }
// Modifiers
	nArray<TYPE> & operator=(const nArray<TYPE> &);
	inline nArray<TYPE> & operator[](int);
	nArray<TYPE> & operator=(const TYPE &);
// Selectors
	inline const nArray<TYPE> & operator[](int) const;
	int ndim() const { return ndimensions; }
	int getdim(int nd) const;
	operator TYPE () const;
	friend ostream & operator<<(ostream &, const nArray<TYPE> &);
};

template <class TYPE>
class nArrayError {
private:
	char buf[80];
public:
	nArrayError(int dimno, const nArray<TYPE> & a) {
		sprintf(buf, 
			"nArray: dimension %d is illegal for %d dimensional array", 
				dimno, a.ndim());
	}
	nArrayError(int index, int maxindex) {		// nArray subscript error
		sprintf(buf, "nArray: subscript %d out of bounds, max subscript = %d",
				index, maxindex-1);
	}
	nArrayError(const char *msg) {
		sprintf(buf, "nArray: %s", msg);
	}
	void response() const { cerr << buf << endl; }
};

template <class TYPE>
inline int nArray<TYPE>::getdim(int nd) const { 
	if (nd <= 0 || nd > ndim())
		throw nArrayError<TYPE>(nd, *this);
	return dimensions[nd-1];
}

template <class TYPE>
inline nArray<TYPE>::operator TYPE () const { 
	if (subscript < 0)
		throw nArrayError<TYPE>("illegal cast");
	return pdata[subscript]; 
}

template <class TYPE>										// subscript operator
inline nArray<TYPE> & nArray<TYPE>::operator[](int i) {
#ifndef NORANGE
	range(i);
#endif
	subscript = i;												// save current subscript
	return (dim > 0) ? *subv[i] : *this;				// return subvector or this one
}

template <class TYPE>										// subscript operator
inline const nArray<TYPE> & nArray<TYPE>::operator[](int i) const {
#ifndef NORANGE
	range(i);
#endif
	subscript = i;												// save current subscript
	return (dim > 0) ? *subv[i] : *this;				// return subvector or this one
}
#include "nArray.C"
#endif

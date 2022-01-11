#ifndef ARRAYPH
#define ARRAYPH
// Arrayp.h - One dimensional Array object interface, protected access
#include <iostream.h>
#include <stdio.h>

class ArrayError {											// Array exception object
private:
	char buf[80];
public:
	ArrayError() { }											// default constructor
	virtual ~ArrayError() { }								// virtual destructor
	ArrayError(int sizerr) {								// Array length error
		sprintf(buf, "Array: %d is an illegal length", sizerr);
	}
	ArrayError(int index, int maxindex) {				// Array subscript error
		sprintf(buf, "Array: subscript %d out of bounds, max subscript = %d",
				index, maxindex-1);
	}
	virtual void response() const { cerr << buf << endl; }
};

template <class TYPE>
class Array {
protected:
	TYPE *v;												// pointer to generic elements
private:
	int len;												// length of array 
	void range(int) const;
	void copy(const Array<TYPE> &);
	void free();
public:
// Constructors
	explicit Array(int length = 1);
	Array(const Array<TYPE> & a) { copy(a); }	// copy constructor
// Destructor
	virtual ~Array() { free(); }					// virtual destructor
// Modifiers
	Array<TYPE> & operator=(const Array<TYPE> &);
	inline TYPE & operator[](int);
// Selectors
	inline const TYPE & operator[](int) const;
	int length() const { return len; }
	virtual void print(ostream & os) const;
};

template <class TYPE>
inline TYPE & Array<TYPE>::operator[](int i) {
#ifndef NORANGE
	range(i);
#endif
	return v[i];
}

template <class TYPE>
inline const TYPE & Array<TYPE>::operator[](int i) const {
#ifndef NORANGE
	range(i);
#endif
	return v[i];
}
#include "Arrayp.C"
#endif

#ifndef ASSOCH
#define ASSOCH
// Assoc2.h - Associative Array, lvalue and rvalue separation, ++, --, +=, -=
#include "Array.h"
#include <strstrea.h>

template <class KEY, class DATA>
class AssocError {										// Assoc exception object
private:
	char buf[80];
public:
	AssocError(int sizerr) {							// Assoc size error
	   ostrstream osbuf(buf, 80);
		osbuf << "Assoc: array of length " << sizerr << " exceeded" << ends;
	}
	AssocError(const KEY & k) {						// Assoc lookup error
	   ostrstream osbuf(buf, 80);
		osbuf << "Assoc: could not find \"" <<  k << '"' << ends;
	}
	void response() const { cerr << buf << endl; }
};

template <class KEY, class DATA> 			
class Assoc;										// forward reference

template <class KEY, class DATA>
class Subscript {									// handles KEY indices
private:
	class Assoc<KEY, DATA> & obj;				// reference to Assoc object
	const KEY & key;								// reference to const KEY index
public:
	Subscript(Assoc<KEY, DATA> & a, const KEY & k) : 		// constructor
		obj(a), key(k) { }
	Subscript & operator=(const DATA &);	// lvalue assignment
	Subscript & operator+=(const DATA &);	// lvalue - update
	Subscript & operator-=(const DATA &);	// lvalue - update
	Subscript & operator++();					// lvalue - prefix (++a)
	Subscript operator++(int);					// lvalue - postfix (a++)
	Subscript & operator--();					// lvalue - prefix (--a)
	Subscript operator--(int);					// lvalue - postfix (a--)
	operator DATA () const;						// rvalue
};

template <class KEY, class DATA>
class Assoc {
	friend class Subscript<KEY, DATA>;		// friend class
private:
	class Element {								// nested class
	public:
		KEY k;										// KEY subscript
		DATA data;									// mapping DATA value
	};
	Array<Element> e;								// Array of Elements
	int count;										// current number of Elements
public:
// Constructor
	explicit Assoc(int size = 1) : e(size) { count = 0; }
// Modifiers
	Subscript<KEY, DATA> operator[](const KEY & k) {
		return Subscript<KEY, DATA>(*this, k);
	}
// Selectors
	const DATA & operator[](const KEY &) const;
	int length() const { return e.length(); }
	int getcount() const { return count; }
// Friend functions
	friend ostream & operator<<(ostream &, const Assoc<KEY, DATA> &);
};
#include "Assoc2.C"
#endif

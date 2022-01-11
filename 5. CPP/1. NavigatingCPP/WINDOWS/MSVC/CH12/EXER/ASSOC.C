// Assoc.C - Associative Array implementation
#include <iostream.h>
#include "Assoc.h"

template <class KEY, class DATA>				// lvalue assignment
Subscript<KEY, DATA> & Subscript<KEY, DATA>::operator=(const DATA & d) {
	int i;
	for (i = 0; i < obj.count; i++)
		if (key == obj.e[i].k) {				// look for KEY index
			obj.e[i].data = d;					// if found, update DATA
			return *this;							// return Subscript
		}
	if (obj.count == obj.length())  			// no more room?
		throw AssocError<KEY, DATA>(obj.count);			// maximum length exceeded
	else {
		  obj.e[i].k = key;						// store new KEY index
		  obj.e[i].data = d;						// store new DATA value
		  obj.count++;								// increment count
	}
	return *this;									// return Subscript
}

template <class KEY, class DATA>				// rvalue
Subscript<KEY, DATA>::operator DATA () const {
	int i;
	for (i = 0; i < obj.count; i++)
		if (key == obj.e[i].k)  				// look for KEY index
			break;
	if (i == obj.count)
		throw AssocError<KEY, DATA>(key);	// unable to find KEY index
	return obj.e[i].data;						// return DATA value
}

template <class KEY, class DATA>				// const KEY subscripts
const DATA & Assoc<KEY, DATA>::operator[](const KEY & k) const {		
	int i;
	for (i = 0; i < count; i++)
		if (k == e[i].k)  
			break;
	if (i == count)
		throw AssocError<KEY, DATA>(k);			// can't find KEY index
	return e[i].data;
}

template <class KEY, class DATA>
ostream & operator<<(ostream & os, const Assoc<KEY, DATA> & a) {
	for (int i = 0; i < a.getcount(); i++)
		os << i << " : " << a.e[i].k << " : " << a.e[i].data << endl;
	return os;
}

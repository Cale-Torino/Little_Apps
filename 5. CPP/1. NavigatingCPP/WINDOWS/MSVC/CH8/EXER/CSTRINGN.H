#ifndef CSTRINGNH
#define CSTRINGNH
// cStringN.h - StringN class interface with reference counts
#include <iostream.h>
#include "StringN.h"

class StringN_ref {
	friend class cStringN;
private:
	StringN *pstring;									// handle
	int refcount;										// reference count
	StringN_ref() {									// StringN_ref default constructor
		pstring = new StringN();					// create StringN object
		refcount = 1;
	}
	StringN_ref(int length, const char *p) {	// StringN_ref constructor
		pstring = new StringN(length, p);		// create StringN object
		refcount = 1;
	}
	StringN_ref(const StringN_ref & tf) {		// StringN_ref copy constructor
		pstring = new StringN(*tf.pstring);		// call StringN copy constructor
		refcount = 1;
	}
	StringN_ref & operator=(const StringN_ref &);	// disallow assignment
	~StringN_ref() { delete pstring; }			// release StringN object
};

class cStringN {
private:
	StringN_ref *pref;								// handle
	void copy(const cStringN & c) {
		pref = c.pref;									// assign same node
		pref->refcount++;								// increase reference count
	}
	void free() {
		if (--pref->refcount == 0)					// decrement ref count, is it 0?
 		delete pref;									// free reference pointer
	}
	void newcopy() {									// StringN copy on write
		pref->refcount--;								// decrement old reference count
		pref = new StringN_ref(*pref);			// create new StringN_ref node
	}
public:
// Constructors
	cStringN() { 										// cStringN constructor
		pref = new StringN_ref();
	}
	cStringN(int length, const char *p) { 		// cStringN constructor
		pref = new StringN_ref(length, p);
	}
	cStringN(const cStringN & b) { copy(b); }		// copy constructor
// Destructor
	~cStringN() { free(); }
// Modifiers
	cStringN & operator=(const cStringN & a) {	// assignment
		if (this != &a) {
			free();  
			copy(a); 
		}
		return *this;
	}
// Selectors
	void print() const { pref->pstring->print(); }
	int length() const { return pref->pstring->length(); }
};
#endif

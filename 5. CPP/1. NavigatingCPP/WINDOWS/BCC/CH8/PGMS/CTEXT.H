#ifndef CTEXTH
#define CTEXTH
// cText.h - Text class interface with reference counts
#include <iostream.h>
#include "String.h"
#include "Text.h"

class Text_ref {
	friend class cText;
private:
	Text *ptext;										// handle
	int refcount;										// reference count
	Text_ref(int length) {							// Text_ref constructor
		ptext = new Text(length);					// create Text object
		refcount = 1;
	}
	Text_ref(const Text_ref & tf) {				// Text_ref copy constructor
		ptext = new Text(*tf.ptext);				// call Text copy constructor
		refcount = 1;
	}
	Text_ref & operator=(const Text_ref &);	// disallow assignment
	~Text_ref() { delete ptext; }					// release Text object
};

class cText {
private:
	Text_ref *pref;									// handle
	void copy(const cText & c) {
		pref = c.pref;									// assign same node
		pref->refcount++;								// increase reference count
	}
	void free() {
		if (--pref->refcount == 0)					// decrement ref count, is it 0?
 			delete pref;								// free reference pointer
	}
	void newcopy()	{									// copy on write
		pref->refcount--;								// decrement old reference count
		pref = new Text_ref(*pref);				// create new Text_ref node
	}
	void write(const String &) const;			// no writes to const objects
public:
// Constructors
	explicit cText(int size = 1) {				// cText constructor
		pref = new Text_ref(size);
	}
	cText(const cText & b) { copy(b); }			// copy constructor
// Destructor
	~cText() { free(); }
// Modifiers
	cText & operator=(const cText & a) {		// assignment
		if (this != &a) {
			free();  
			copy(a); 
		}
		return *this;
	}
	void write(const String & s) {			// write to Text object
		if (pref->refcount > 1)					// two or more Text objects?
			newcopy();								// make new Text copy
 		pref->ptext->write(s);					// write to new Text object
	}
// Selectors
	int nitems() const { return pref->ptext->nitems(); }
	int length() const { return pref->ptext->length(); }
	String read(int n) const { return pref->ptext->read(n); }
};
#endif

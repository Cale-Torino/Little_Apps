#ifndef LISTCOPYH
#define LISTCOPYH
// ListCopy.h - List Copy (pointer semantics)
#include "PtrList.h"

template <class TYPE>
class PtrListCopy : public PtrList<TYPE> {		// abstract base
private:
	virtual void ptrcopy(const PtrListCopy &) = 0;
public:
// Constructors
	PtrListCopy(deletetype p = ShouldDelete) : PtrList<TYPE>(p) { }
// Modifiers
	PtrListCopy<TYPE> & operator=(const PtrListCopy<TYPE> &);
};

template <class TYPE>
PtrListCopy<TYPE> & PtrListCopy<TYPE>::operator=(const PtrListCopy<TYPE> & lc) {
	if (this != &lc) {
		if (DeletePointers()) 
			freedata();								// from PtrList
		else
			free();									// from List
		ptrcopy(lc);								// virtual call
	}
	return *this;
}

template <class TYPE>
class ListCopyC : public PtrListCopy<TYPE> {		// for non-polymorphic classes
private:
	void ptrcopy(const PtrListCopy<TYPE> &);
public:
// Constructors
	ListCopyC(deletetype p = ShouldDelete) : PtrListCopy<TYPE>(p) { }
// Copy constructor
	ListCopyC(const ListCopyC<TYPE> & list): 
		PtrListCopy<TYPE>(list.DeletePointers() ? ShouldDelete : ShouldNotDelete) 
				{ ptrcopy(list); }
};

template <class TYPE>
void ListCopyC<TYPE>::ptrcopy(const PtrListCopy<TYPE> & lc) {
	for (PtrIterator<TYPE> iter(lc); !iter; iter++)
		append(new TYPE(*iter()));					// make copy of TYPE
}

template <class TYPE>
class ListCopyA : public PtrListCopy<TYPE> {			// for polymorphic classes
private:
	void ptrcopy(const PtrListCopy<TYPE> &);
public:
// Constructors
	ListCopyA(deletetype p = ShouldDelete) : PtrListCopy<TYPE>(p) { }
// Copy constructor
	ListCopyA(const ListCopyA<TYPE> & list): 
		PtrListCopy<TYPE>(list.DeletePointers() ? ShouldDelete : ShouldNotDelete) 
				{ ptrcopy(list); }
};

template <class TYPE>
void ListCopyA<TYPE>::ptrcopy(const PtrListCopy<TYPE> & lc) {
	for (PtrIterator<TYPE> iter(lc); !iter; iter++)
		append(iter()->clone());					// virtual call
}
#endif

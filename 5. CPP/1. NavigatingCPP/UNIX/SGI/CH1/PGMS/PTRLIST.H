#ifndef PTRLISTH
#define PTRLISTH
// PtrList.h - List object with Iterator (pointer semantics)
#include "List.h"

template <class TYPE> class PtrIterator;		// forward reference

template <class TYPE>
class PtrList : protected List<TYPE *> {		// PtrList object
	friend class PtrIterator<TYPE>;
public: 
	enum deletetype { ShouldDelete, ShouldNotDelete };
private:
	PtrList(const PtrList<TYPE> &);			// disallow copy constructor
	void operator=(const PtrList<TYPE> &);	// disallow assignment
	const deletetype pointers;					// delete pointer objects?
protected:
	bool DeletePointers() const 
		{ return (pointers == ShouldDelete ? true : false ); }
public:
// Constructors
	PtrList(deletetype p = ShouldDelete) : pointers(p) { }
// Destructor
	~PtrList() { if (DeletePointers()) freedata(); }
// Modifiers
	void freedata();
	using List<TYPE *>::remove;								// using declaration
	using List<TYPE *>::append;								// using declaration
	using List<TYPE *>::prepend;								// using declaration
	using List<TYPE *>::insert;								// using declaration
// Selectors
	using List<TYPE *>::length;								// using declaration
};

template <class TYPE>
class PtrIterator : public Iterator<TYPE *> {			// PtrList Iterator
public:
	PtrIterator(const PtrList<TYPE> & lp, place p = front) : 
		Iterator<TYPE *>(static_cast<const List<TYPE *> &>(lp), p) {  }
};

template <class TYPE>
void PtrList<TYPE>::freedata() {
	while (length() > 0)
		delete removeNode(getStart()); 
}

template <class TYPE>
ostream & operator<<(ostream & os, const PtrList<TYPE> & list) {
	for (PtrIterator<TYPE> iter(list); !iter; iter++)
		os << *iter() << ' ';
	return os;
}
#endif

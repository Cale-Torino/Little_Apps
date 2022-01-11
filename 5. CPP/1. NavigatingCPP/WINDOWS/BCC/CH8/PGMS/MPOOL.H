#ifndef MPOOLH
#define MPOOLH
// Mpool.h - Memory Pool
#include <iostream.h>
#include <stdio.h>

class Mpool {											// Memory Pool
private:
	enum { maxc = 50 };								// maximum no. of chunks
	unsigned int sitem;								// item size
	unsigned int nitem;								// number of items
	int nc;												// number of chunks
	class Alloc {										// nested Alloc link class
	public:
		Alloc *next;									// pointer to next Alloc link
	};
	Alloc *freestore;									// first available slot
	Alloc *chunks[maxc];								// array of pointers to chunks
	Mpool(const Mpool &);							// disable copy initialization
	Mpool & operator=(const Mpool &);			// disable assignment
	void grow(int);									// grow Memory pool
public:
	Mpool(size_t, unsigned int);					// constructor
	~Mpool();											// destructor
	void *alloc(size_t);								// allocator
	void dealloc(void *);							// deallocator
	int nitems() const { return nitem; }		// number of items 
	int item_size() const { return sitem; }	// size of item 
};

class MpoolError {									// Mpool exception object
private:
	char buf[80];
public:
	MpoolError(const char *msg) { sprintf(buf, "Mpool: %s", msg); }
	void response() const { cerr << buf << endl; }
};

Mpool::Mpool(size_t size, unsigned int nitems) {
	cout << "Mpool constr(size, nitems): " << size << ',' << nitems << endl; 
	sitem = size;										// store size of item
	nitem = nitems;									// store number of items
	nc = 0;												// initialize chunk count
	freestore = 0;										// initialize free list pointer
}

Mpool::~Mpool() { 
	cout << "Mpool destructor" << endl; 
	for (int i = nc-1; i >= 0; i--)
		delete [] chunks[i];							// delete each chunk
}

void *Mpool::alloc(size_t size) { 
	if (freestore == 0)								// grow pool?
		grow(size < sizeof(Alloc *) ? sizeof(Alloc *) : size);
	Alloc *ps = freestore;							// avaliable slot
	freestore = ps->next;							// next available slot
	cout << "Mpool::alloc - " << ps << endl;
	return ps;											// return available slot 
}

void Mpool::dealloc(void *ps) { 
	cout << "Mpool::dealloc - " << ps << endl;
	if (ps) {
		Alloc *pa = static_cast<Alloc *>(ps);	// convert void *
		pa->next = freestore;						// next available slot
		freestore = pa;								// mark avaiable slot
	}
}

void Mpool::grow(int size) {								// extend memory pool
	const int chunk = size * nitem;
	Alloc *start = 											// start of chunk
		reinterpret_cast<Alloc *>(::new char[chunk]);
	Alloc *end = &start[nitem - 1];						// end of chunk
	if (nc >= maxc)
		throw MpoolError("max buffer length exceeded");
	chunks[nc++] = start;									// save chunk address
	Alloc *pc;
	for (pc = start; pc < end; pc++)						// loop over links
		pc->next = pc + 1;									// connect Alloc links
	pc->next = 0;												// end of freelist
	freestore = start;										// first slot available
}
#endif

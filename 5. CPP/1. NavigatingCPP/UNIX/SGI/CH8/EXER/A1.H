#ifndef A1H
#define A1H
// A1.h - Class specific overloading with Memory Pool
#include <iostream.h>
#include "Mpool.h"

class A {
private:
	int *p;
	static Mpool *mp;								// pointer to memory pool
public:
	A();												// default constructor
	~A();												// destructor
	void *operator new(size_t);				// allocate A object from pool
	void operator delete(void *);				// deallocate A object from pool
	static void free_pool();					// free memory pool
};

A::A() { p = new int[10]; }
A::~A() { delete [] p; }

void *A::operator new(size_t size) {		// allocate A object
	static const int max = 256;				// max objects in pool
	if (mp == 0)
		mp = ::new Mpool(size, max);			// create memory pool
	return mp->alloc(size);						// allocate A in memory pool
}

void A::operator delete(void *p) {			// deallocate A object
	if (mp)
		mp->dealloc(p);							// delete A from memory pool
}

void A::free_pool() { 							// release memory pool
	delete mp; 
} 

Mpool *A::mp = 0;									// initialze static pointer
#endif

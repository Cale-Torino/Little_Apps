// New.C - Memory Leak Detector Implementation
#include <iostream.h>
#include <malloc.h>
#include <stdlib.h>
#include "New.h"

static void grow(int);								// grow Dse array

class Dse {												// Dynamic Storage Element
private:
	enum { delta = 256 };							// default pointer list length
	void *pfs;											// pointer to free store
	const char *fname;								// file name for call to new
	int lineno;											// line number for call to new
	friend void grow(int);							// grow Dse array
	friend void *operator new(size_t, const char *, int);		// allocate
	friend void operator delete(void *);		// deallocate
	friend void mleak_check();						// show allocated pointers
};

static Dse *plist = 0;								// pointer list
static int plist_length = 0;						// length of pointer list
static int used = 0;									// number of calls to allocator
static const char *fname_delete;					// file name for call to delete
static int lineno_delete;							// line number for call to delete

void *operator new(size_t size, const char *file, int lineno) {
	void *pfs = malloc(size);						// allocate memory
	if (pfs == 0)
		throw NewError(size, file, lineno);

	if (used == plist_length) 						// time to grow?
		grow(plist_length + Dse::delta);

	for (int i = 0; i < plist_length; i++) {
		if (plist[i].pfs == 0) {					// available slot?
			plist[i].pfs = pfs;						// save pointer
			plist[i].fname = file;					// save file name
			plist[i].lineno = lineno;				// save line number
			used++;										// increment use count
			return pfs;									// return memory address
		}
	}
	//throw NewError ("internal error");			// should never happen
	return 0;
}

static void grow(int new_len) {					// grow Dse array
	if (plist == 0)
		plist = static_cast<Dse *>(malloc(new_len * sizeof(Dse)));
	else
		plist = static_cast<Dse *>
									(realloc(plist, new_len * sizeof(Dse)));
	if (plist == 0)
		throw NewError("no heap memory");

	for (int i = plist_length; i < new_len; i++)
		plist[i].pfs = 0;								// initialize to 0
	plist_length = new_len;							// update new length
}

void deletep(const char *file, int lineno) {		// save file, line for delete
	fname_delete = file;
	lineno_delete = lineno;
}

void operator delete(void *pfs) {
	if (pfs == 0) 										// make delete 0 harmless
		return;
	for (int i = 0; i < plist_length; i++)
		if (plist[i].pfs == pfs) {					// pointer there?
			plist[i].pfs = 0;							// make available
			free(pfs);									// free pointer
			used--;										// decrement use count
			return;
	}
	cerr << "Attempt to delete bad free store pointer: " << endl;
	cerr << "\tFilename: " << fname_delete << endl;
	cerr << "\tLine Number: " << lineno_delete << endl;
	cerr << "\tPointer address: " << pfs << endl;
}

//void *operator new[](size_t size, const char *file, int lineno) {
	//return operator new(size, file, lineno);
//}

//void operator delete[](void *pfs) {
	//operator delete(pfs);
//}

void mleak_check() {									// show allocated pointers
	if (used)											// memory leaks?
		for (int i = 0; i < plist_length; i++)
			if (plist[i].pfs) {						// pointer remaining?
				cerr << "Memory Leak:" << endl;
				cerr << "\tFilename: " << plist[i].fname << endl;
				cerr << "\tLine Number: " << plist[i].lineno << endl;
				cerr << "\tPointer address: " << plist[i].pfs << endl;
			}
}

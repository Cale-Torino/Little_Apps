#ifndef NEWH
#define NEWH
// New.h - header file for memory leak detection
#include <iostream.h>
#include <stdio.h>

class NewError {
private:
	char buf[80];
public:
	NewError(size_t size, const char *file, int lineno) {
		sprintf(buf, "New: file %s - line %d: new error for %u bytes", 
				file, lineno, size);
	}
	NewError(const char *msg) { sprintf(buf, "New: %s", msg); }
	NewError(void *pfs) { sprintf(buf, 
		"New: attempt to delete bad free store pointer: %x", pfs); }
	void response() const { cerr << buf << endl; }
};

#ifdef MLEAK
#define New new(__FILE__, __LINE__)
#define Delete deletep(__FILE__, __LINE__), delete

void *operator new(size_t, const char *, int);
//void *operator new[](size_t, const char *, int);
void operator delete(void *);
//void operator delete[](void *);
void deletep(const char *, int);
void mleak_check(); 

#else
#define New new
#define Delete delete
inline void mleak_check() { }
#endif

#endif

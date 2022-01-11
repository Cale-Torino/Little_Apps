#ifndef NEWDH
#define NEWDH
// Newd.h - header file for customized memory allocators
#include <iostream.h>
#include <stdio.h>

class NewError {						// New exception object
private:
	char buf[80];
public:
	NewError(size_t size, const char *file, int lineno) {
		sprintf(buf, "file %s - line %d: new error for %u bytes", 
				file, lineno, size);
	}
	void response() const { cerr << buf << endl; }
};

#ifdef NEW
#include <malloc.h>
#define New new(__FILE__, __LINE__)

inline void *operator new(size_t size, const char *file, int lineno) 
{
   //void *pfs = ::new char [size];
   void *pfs = malloc(size);					// to make it fail
   if (pfs == 0)
		throw NewError(size, file, lineno);
   return pfs;
}

inline void *operator new[](size_t size, const char *file, int lineno) 
{
   return operator new(size, file, lineno);
}

#else
#define New new
#endif
#endif

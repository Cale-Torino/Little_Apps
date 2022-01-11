#ifndef PERSISTH
#define PERSISTH
// Persist.h - a base class for persistence
#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <typeinfo.h>
#include "String.h"
#include "Assoc.h"

class PersistError {										// Persist exception object
private:
	char buf[80];
public:
	PersistError(const char *msg) { sprintf(buf, "Persist: %s", msg); }
	void response() const { cerr << buf << endl; }
};

class Persist {												// abstract base
public:
	typedef Persist * (*PTRF)(ifstream &);				// pointer to function
private:
	static Assoc<String, PTRF> typemap;					// associative array
	static void do_mapping();								// initialize array
public:
	virtual ~Persist() { }
	static Persist *restore(ifstream &);				// persistent read
	virtual void save(ofstream &) const = 0;			// persistent write
};

inline ofstream & operator<<(ofstream & ofs, const Persist & p) {
	p.save(ofs);									// virtual call
	return ofs;
}
#endif

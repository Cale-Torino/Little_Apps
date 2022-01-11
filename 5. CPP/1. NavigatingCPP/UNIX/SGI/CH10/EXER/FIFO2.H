#ifndef FIFOH
#define FIFOH
// Fifo2.h - Template Fifo class, List containment
#include <stdio.h>
#include "List.h"

template <class TYPE>
class Fifo {
private:
	List<TYPE> lv;									// contains List object
public:
// Constructors
	Fifo() : lv() { }
// Modifiers
	void write(const TYPE &);					// write data to Fifo
	TYPE read();									// read data from Fifo
// Selectors
	int nitems() const { return length(); }
	int length() const { return lv.length(); }
	bool empty() const { return length() == 0; }
};

class FifoError {							// Fifo exception object
private:
	char buf[80];
public:
	FifoError(const char *msg) { sprintf(buf, "Fifo: %s", msg); }
	void response() const { cerr << buf << endl; }
};

template <class TYPE>
void Fifo<TYPE>::write(const TYPE & c) {	// write data to Fifo
	lv.append(c);									// put data at end of List
}

template <class TYPE>
TYPE Fifo<TYPE>::read() {						// read data from Fifo
	if (empty())
		throw FifoError("Fifo is empty");
	Iterator<TYPE> iter(lv);					// attach Iterator to front of List
	return lv.remove(iter);						// remove data from List
}
#endif

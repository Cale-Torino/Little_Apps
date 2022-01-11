#ifndef FIFOH
#define FIFOH
// Fifo.h - Template Fifo class, Array containment
#include <stdio.h>
#include "Array.h"

template <class TYPE>
class Fifo {
private:
	Array<TYPE> fv;								// contains Array object
	int front;										// read position	
	int rear;										// write position
	int count;										// current number of items
	enum { maxlen = 80 };						// default length
public:
// Constructors
	explicit Fifo(int size = maxlen) : fv(size) {
		front = rear = count = 0;
	}
// Modifiers
	void write(const TYPE &);					// write data to Fifo
	TYPE read();									// read data from Fifo
// Selectors
	int nitems() const { return count; }
	int length() const { return fv.length(); }
	bool full() const { return count == length(); }
	bool empty() const { return count == 0; }
};

class FifoError {							// Fifo exception object
private:
	char buf[80];
public:
	FifoError(const char *msg) { sprintf(buf, "Fifo: %s", msg); }
	void response() const { cerr << buf << endl; }
};

template <class TYPE>
void Fifo<TYPE>::write(const TYPE & c) {			// write data to Fifo
	if (full()) 
		throw FifoError("Fifo is full");
	else {
		count++;
		if (rear == length())						// reached the end?
  			rear = 0;									// wrap around
		fv[rear++] = c;								// put data into Array
	}
}

template <class TYPE>
TYPE Fifo<TYPE>::read() {							// read data from Fifo
	if (empty())
		throw FifoError("Fifo is empty");
	else {
		count--; 
		if (front == length())						// reached the end?
			front = 0;									// wrap around
	}
	return fv[front++];								// get data from Array
}
#endif

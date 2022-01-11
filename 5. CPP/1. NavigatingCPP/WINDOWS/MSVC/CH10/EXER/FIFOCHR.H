#ifndef FIFOCHRH
#define FIFOCHRH
// FifoChr.h - Fifo char class
#include <stdio.h>
#include "Fifo.h"

class Fifo<char> {								// specialized for char
private:
	Array<char> fv;								// contains Array<char> object
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
	void write(char);								// write char to Fifo
	char read();									// read char from Fifo
// Selectors
	int nitems() const { return count; }
	int length() const { return fv.length(); }
	bool full() const { return count == length(); }
	bool empty() const { return count == 0; }
};

void Fifo<char>::write(char c) {				// write char to Fifo
	if (full()) 
		throw FifoError("Fifo is full");
	else {
		count++;
		if (rear == length())					// reached the end?
  			rear = 0;								// wrap around
		fv[rear++] = c;							// put data into Array
	}
}

char Fifo<char>::read() {							// read char from Fifo
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

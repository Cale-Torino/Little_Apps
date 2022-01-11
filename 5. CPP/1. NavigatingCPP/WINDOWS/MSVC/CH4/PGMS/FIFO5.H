#ifndef FIFOH
#define FIFOH
// Fifo5.h - Fifo class interface
#include <iostream.h>
#include <stdio.h>

const int Fifo_max = 80;

class FifoError {									// Fifo exception object
private:
	char buf[80];
public:
	FifoError(const char *p, int size) {
		sprintf(buf, 
			"Fifo: length of %d is too small for \"%s\"", size, p);
	}
	FifoError(const char *msg) { sprintf(buf, "Fifo: %s", msg); }
	void response() const { cerr << buf << endl; }
};

class Fifo {
private:
	char *s;											// pointer to char data
	mutable int front;							// read placeholder	
	int rear;										// write placeholder
	mutable int count;							// current number of chars
	int len;											// length
	void write(char) const;						// disallow writes to const Fifos
public:
// Constructors
	Fifo(int size = Fifo_max) { 				// inline Constructor
		s = new char[len = size];
		front = rear = count = 0; 
	}
	Fifo(const char *, int size = Fifo_max);
	Fifo(const Fifo &);							// copy constructor

// Destructor
	~Fifo() { delete [] s; }

// Member Functions
	int nitems() const { return count; }
	int length() const { return len; }
	bool full() const { return count == len; }
	bool empty() const { return count == 0; }
	void print() const;								// display a Fifo's data
	void write(char);									// write char to Fifo
	char read() const;								// allow reads from const Fifos
};
#endif

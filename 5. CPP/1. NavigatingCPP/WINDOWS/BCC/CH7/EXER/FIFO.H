#ifndef FIFOH
#define FIFOH
// Fifo.h - Fifo class interface, full boilerplate
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
	char *s;												// pointer to char data
	mutable int front;								// read placeholder	
	int rear;											// write placeholder
	mutable int count;								// current number of chars
	int len;												// length
	void write(char) const;							// disallow writes to const Fifos
	void copy(const Fifo &);						// copy Fifo
	void free() { delete [] s; }					// free Fifo data
public:
// Constructors
	explicit Fifo(int size = Fifo_max) {		// inline constructor
		s = new char[len = size];
		front = rear = count = 0; 
	}
	explicit Fifo(const char *, int size = Fifo_max);
	Fifo(const Fifo & obj) { copy(obj); }		// copy constructor
// Destructor
	~Fifo() {  free(); }								// destructor - free Fifo data
// Modifiers
	Fifo & operator=(const Fifo & obj) {		// Fifo assignment
		if (this != &obj) {							// check self-assignment
			free();										// free Fifo
			copy(obj);									// copy Fifo
		}
		return *this;									// return Fifo
	}
// Member Functions
	int nitems() const { return count; }
	int length() const { return len; }
	bool full() const { return count == len; }
	bool empty() const { return count == 0; }
	void print(ostream &) const;					// display Fifo's data
	void write(char);									// write char to Fifo
	char read() const;								// allow reads from const Fifos
};

inline ostream & operator<<(ostream & os, const Fifo & f) {
	f.print(os);										// display Fifo on ostream
	return os;
}
#endif

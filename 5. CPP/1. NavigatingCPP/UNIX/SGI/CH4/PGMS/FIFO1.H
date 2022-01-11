#ifndef FIFOH
#define FIFOH
// Fifo1.h - Fifo interface/implementation

const int Fifo_max = 80;							// default Fifo length

struct Fifo {                                
// Implementation
	char s[Fifo_max];									// holds char data
	int front;											// read placeholder
	int rear;											// write placeholder
	int count;											// current number of chars

// Interface - operations are inline member functions
	void init() { front = rear = count = 0; }
	int nitems() { return count; }
	bool full() { return count == Fifo_max; }
	bool empty() { return count == 0; }
	void write(char c) { count++; s[rear++] = c; }
	char read() { count--; return s[front++]; }
};
#endif

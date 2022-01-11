#ifndef FIFOH
#define FIFOH
// Fifo4.h - Fifo class

const int Fifo_max = 80;

class Fifo {
private:
	char s[Fifo_max];									// holds char data
	int front;											// read placeholder
	int rear;											// write placeholder
	int count;											// current number of chars
public:
	void init() { front = rear = count = 0; }
	int nitems() { return count; }
	bool full() { return count == Fifo_max; }
	bool empty() { return count == 0; }
	void write(char);									// write char to Fifo
	char read();										// read char from Fifo
};
#endif

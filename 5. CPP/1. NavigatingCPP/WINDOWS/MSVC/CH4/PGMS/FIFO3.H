#ifndef FIFOH
#define FIFOH
// Fifo3.h - Fifo class

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
	void write(char);									// prototype 
	char read();										// prototype
};

inline void Fifo::write(char c) { count++; s[rear++] = c; }
inline char Fifo::read() { count--; return s[front++]; }
#endif

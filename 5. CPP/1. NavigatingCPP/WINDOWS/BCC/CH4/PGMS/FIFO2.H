#ifndef FIFOH
#define FIFOH
// Fifo2.h - Fifo interface/implementation with private and public

const int Fifo_max = 80;

struct Fifo {
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
	void write(char c) { count++; s[rear++] = c; }
	char read() { count--; return s[front++]; }
};
#endif

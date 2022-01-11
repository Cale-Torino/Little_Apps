// Fifo4.C - Fifo implementation
#include <iostream.h>
#include "Fifo4.h"

void Fifo::write(char c) {					// write char to Fifo
	if (full()) 
		throw "Fifo is full";
	else {
		count++;
		if (rear == Fifo_max)				// reached the end?
  			rear = 0;
		s[rear++] = c;
	}
}

char Fifo::read() {							// read char from Fifo
	if (empty())
		throw "Fifo is empty";
	else {
		count--; 
		if (front == Fifo_max)				// reached the end?
			front = 0;
	}
	return s[front++];
}

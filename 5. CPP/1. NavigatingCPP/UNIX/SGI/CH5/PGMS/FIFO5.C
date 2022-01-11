// Fifo5.C - Fifo implementation with constructors and destructors
#include <iostream.h>
#include <string.h>
#include "Fifo5.h"

Fifo::Fifo(const char *p, int size) {
	s = new char[len = size];
	front = rear = count = 0; 
	if (strlen(p) <= len)
		while (*p)										// write char data to Fifo
			write(*p++);
	else
		throw FifoError(p, size);					// throw exception
}

Fifo::Fifo(const Fifo & f1) {						// copy constructor
	s = new char[len = f1.len];
   count = f1.count;  front = f1.front;  rear = f1.rear;
	for (int i = 0; i < len; i++)
		s[i] = f1.s[i];
}

void Fifo::write(char c) {							// write char to Fifo
	if (full()) 
		throw FifoError("Fifo is full");
	else {
		count++;
		if (rear == len)								// reached the end?
  			rear = 0;
	}
	s[rear++] = c;
}

char Fifo::read() const {							// read char from Fifo
	if (empty())
		throw FifoError("Fifo is empty");
	else {
		count--; 
		if (front == len)								// reached the end?
			front = 0;
	}
	return s[front++];
}

void Fifo::print() const {							// display a Fifo's data
	if (empty())
		return;
	int index = front;
	while (index != rear) {
		if (index == len)								// reached the end?
			index = 0;
		cout << s[index++];							// return char at front
	}
	cout << endl;
}

#ifndef BLOCKH
#define BLOCKH
// Block1.h - template Block class, specialized, no default initialization
#include <stdio.h>
#include <memory.h>

template <class TYPE>
class Block {
private:
	TYPE **pd;										// pointer to pointer to data
	int len;														// block length
	Block(const Block<TYPE> &);							// disable copy constructor
	Block<TYPE> & operator=(const Block<TYPE> &);	// disable assignment
public:
	Block(int, const TYPE &);					// constructor
	~Block();										// destructor
	TYPE & operator[](int i) { return *pd[i]; }
	const TYPE & operator[](int i) const { return *pd[i]; }
	int length() const { return len; }
};

class BlockError {								// Block exception object
private:
	char buf[80];
public:
	BlockError(int sizerr) {					// Block length error
		sprintf(buf, "Block: %d is an illegal length", sizerr);
	}
	void response() const { cerr << buf << endl; }
};

template <class TYPE>										// constructor
Block<TYPE>::Block(int size, const TYPE & value) {
	if (size <= 0)
		throw BlockError(size);								// illegal length
	pd = new TYPE * [len = size];							// create pointer array
	for (int i = 0; i < len; i++)
		pd[i] = new TYPE(value);							// copy initializtion
}

template <class TYPE>										// destructor
Block<TYPE>::~Block() {
	for (int i = len-1; i >= 0; i--)
		delete pd[i];											// delete data
	delete [] pd;												// delete pointer array
}

class Block<char> {								// specialize for char
private:
	char *pc;										// pointer to char data
	int len;														// block length
	Block(const Block<char> &);							// disable copy constructor
	Block<char> & operator=(const Block<char> &);	// disable assignment
public:
	Block(int, char);								// constructor
	~Block() { delete [] pc; }					// destructor
	char & operator[](int i) { return pc[i]; }
	const char & operator[](int i) const { return pc[i]; }
	int length() const { return len; }
};

Block<char>::Block(int size, char value) {
	if (size <= 0)
		throw BlockError(size);					// illegal length
	pc = new char [len = size];
	memset(pc, value, len);
}

class Block<int> {								// specialize for integer
private:
	int *pi;											// pointer to intger data
	int len;														// block length
	Block(const Block<int> &);								// disable copy constructor
	Block<int> & operator=(const Block<int> &);		// disable assignment
public:
	Block(int, int);								// constructor
	~Block() { delete [] pi; }					// destructor
	int & operator[](int i) { return pi[i]; }
	const int & operator[](int i) const { return pi[i]; }
	int length() const { return len; }
};

Block<int>::Block(int size, int value) {
	if (size <= 0)
		throw BlockError(size);					// illegal length
	pi = new int [len = size];
	for (int i = 0; i < len; i++)
		pi[i] = value;								// initial values
}
#endif

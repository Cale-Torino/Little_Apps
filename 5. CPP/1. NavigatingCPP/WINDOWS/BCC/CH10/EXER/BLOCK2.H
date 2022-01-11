#ifndef BLOCKH
#define BLOCKH
// Block2.h - Block class, specialized, default values, full boilerplate
#include <stdio.h>
#include <memory.h>

template <class TYPE>
class Block {
private:
	TYPE **pd;													// pointer to pointer to data
	int len;														// length of block data
	static TYPE ival;											// initial value
	static int count;											// static count
	void copy(const Block<TYPE> &);						// copy objects
	void free();												// free resources
public:
	explicit Block(int size = 1, const TYPE & value = ival);
	Block(const Block<TYPE> & a) { copy(a); }			// copy constructor
	~Block()	{ free(); }										// destructor
	Block<TYPE> & operator=(const Block<TYPE> &);	// assignment
	TYPE & operator[](int i) { return *pd[i]; }
	const TYPE & operator[](int i) const { return *pd[i]; }
	int length() const { return len; }
	static TYPE initial_value(const TYPE &);
	static int getcount() { return count; }
};

class BlockError {											// Block exception object
private:
	char buf[80];
public:
	BlockError(int sizerr) {								// Block length error
		sprintf(buf, "Block: %d is an illegal length", sizerr);
	}
	void response() const { cerr << buf << endl; }
};

template <class TYPE>
TYPE Block<TYPE>::initial_value(const TYPE & iv) { 
	TYPE oldval = ival;							// save old initial value
	ival = iv;										// set new initial value
	return oldval;									// return old initial value
}

template <class TYPE>										// constructor
Block<TYPE>::Block(int size, const TYPE & value) {
	if (size <= 0)
		throw BlockError(size);								// illegal length
	count++;
	pd = new TYPE * [len = size];							// create pointer array
	for (int i = 0; i < len; i++)
		pd[i] = new TYPE(value);							// create values
}

template <class TYPE>
void Block<TYPE>::copy(const Block<TYPE> & b) {		// copy objects
	count++;														// increment count
	pd = new TYPE * [len = b.len];						// create pointer array
	for (int i = 0; i < len; i++)
		pd[i] = new TYPE(*b.pd[i]);						// create values
}

template <class TYPE>										// free()
void Block<TYPE>::free() {
	count--;														// decrement count
	for (int i = len-1; i >= 0; i--)
		delete pd[i];											// delete values
	delete [] pd;												// delete pointer array
}

template <class TYPE>
Block<TYPE> & Block<TYPE>::operator=(const Block<TYPE> & s) {
	if (this != &s) {
		free();
		copy(s);
	}
	return *this;
}

class Block<char> {											// specialize for char
private:
	char *pc;
	int len;
	static char ival;											// initial value
	static int count;											// static count
	void copy(const Block<char> &);						// copy objects
	void free()	 { count--; delete [] pc; }			// free memory
public:
	explicit Block(int size = 1, char value = ' ');	// constructor
	Block(const Block<char> & a) { copy(a); }			// copy constructor
	~Block() { free(); }										// destructor
	Block<char> & operator=(const Block<char> &);	// assignment
	char & operator[](int i) { return pc[i]; }
	const char & operator[](int i) const { return pc[i]; }
	int length() const { return len; }
	static int getcount() { return count; }
};

Block<char>::Block(int size, char value) {			// Block<char> constructor
	if (size <= 0)
		throw BlockError(size);								// illegal length
	count++;														// increment count
	pc = new char [len = size];
	memset(pc, value, len);
}

void Block<char>::copy(const Block<char> & b) {		// copy objects
	count++;														// increment count
	pc = new char [len = b.len];							// allocate memory
	memcpy(pc, b.pc, len);									// copy char data
}

Block<char> & Block<char>::operator=(const Block<char> & s) {
	if (this != &s) {
		free();
		copy(s);
	}
	return *this;
}

class Block<int> {											// specialize for integer
private:
	int *pi;
	int len;
	static int ival;											// initial value
	static int count;											// static count
	void copy(const Block<int> &);						// copy objects
	void free()	 { count--; delete [] pi; }			// free memory
public:
	explicit Block(int size = 1, int value = 0);		// constructor
	Block(const Block<int> & a) { copy(a); }			// copy constructor
	~Block() { free(); }										// destructor
	Block<int> & operator=(const Block<int> &);	// assignment
	int & operator[](int i) { return pi[i]; }
	const int & operator[](int i) const { return pi[i]; }
	int length() const { return len; }
	static int getcount() { return count; }
};

Block<int>::Block(int size, int value) {				// Block<int> constructor
	if (size <= 0)
		throw BlockError(size);								// illegal length
	count++;														// increment count
	pi = new int [len = size];
	for (int i = 0; i < len; i++)
		pi[i] = value;											// initial values
}

void Block<int>::copy(const Block<int> & b) {		// copy objects
	count++;														// increment count
	pi = new int [len = b.len];							// allocate memory
	memcpy(pi, b.pi, len*sizeof(int));					// copy integer data
}

Block<int> & Block<int>::operator=(const Block<int> & s) {
	if (this != &s) {
		free();
		copy(s);
	}
	return *this;
}
#endif

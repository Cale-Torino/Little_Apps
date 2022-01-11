#ifndef BUFFERH
#define BUFFERH
// Buffer.h - constant expression parameters
#include <iostream.h>
#include <stdio.h>

class BufferError {								// Buffer exception object
private:
	char buf[80];
public:
	BufferError(int index, int maxindex) {				// subscript error
		sprintf(buf, 
			"Buffer: subscript %d out of bounds, max subscript = %d",
				index, maxindex-1);
	}
	void response() const { cerr << buf << endl; }
};

template <class TYPE, int size>
class Buffer {
private:
	TYPE buf[size];									// fixed length buffer
	void range(int) const;							// range checks
public:
	TYPE & operator[](int i) { range(i); return buf[i]; }
	const TYPE & operator[](int i) const { range(i); return buf[i]; }
	int length() const { return size; }
};

template <class TYPE, int size>
void Buffer<TYPE, size>::range(int i) const {
	if (i < 0 || i >= size)
		throw BufferError(i, size);				// out of range subscript
}
#endif

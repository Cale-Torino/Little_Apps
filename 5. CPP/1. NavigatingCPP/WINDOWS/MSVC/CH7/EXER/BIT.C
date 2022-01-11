// Bit.C - Bit class implementation, lvalue/rvalue for Bitslices
#include <iostream.h>
#include <stdlib.h>
#include "Bit.h"

Bit::Bit(int size, unsigned int val) {
	len = size;  b = new bool [len];  
	for (int i = 0; i < len; i++, val >>= 1)
		b[i] = val & 1;
}

void Bit::copy(const Bit & b1) { 
	b = new bool [(len = b1.len)];
	for (int i = 0; i < len; i++)
		b[i] = b1.b[i];
}

void Bit::free() {
	delete [] b;										// free Bit data
}

void Bit::range(int index) const {
	if (index < 0 || index >= length())			// out of bounds?
		throw BitError(index);						// range error
}

bool & Bit::operator[](int index) { 
	range(index);									// range check 
	return b[index];								// return bool reference
}

const bool & Bit::operator[](int index) const {
	range(index);									// range check 
	return b[index];								// return const bool reference
}

ostream & operator<<(ostream & os, const Bit & b1) {
	for (int i = b1.length()-1; i >= 0; i--)
		os << b1[i];
	return os;
}

Bit & BitSlice::operator=(const Bit & b1) {					// lvalue
	int len = (b1.length() < count) ? b1.length() : count;
	for (int i = pos; i < len; i++)
		bs[i] = b1[i];
	return bs;
}

Bit & BitSlice::operator=(const BitSlice & b1) {			// lvalue
	int len = (b1.count < count) ? b1.count : count;
	for (int i = pos; i < len; i++)
		bs[i] = b1.bs[i+b1.pos];
	return bs;
}

BitSlice::operator Bit () const {					// rvalue
	Bit result(count);									// Bit constructor	
	for (int i = 0; i < count; i++)
		result[i] = bs[i+pos];
	return result;
}

void Bit::poscount(int pos, int count) const {
	if (pos < 0 || pos > length() - 1 || 
			count <= 0 || count + pos > length())
		throw BitError(pos, count);
}

BitSlice Bit::operator()(int pos, int count) {			// BitSlices
	poscount(pos, count);									// check position, count
	return BitSlice(*this, pos, count);				// create BitSlice
}

const Bit Bit::operator()(int pos, int count) const {			// BitSlices
	poscount(pos, count);						// check position, count
	Bit bnew(count);								// Bit constructor
	for (int i = 0; i < count; i++)
		bnew[i] = b[i+pos];
	return bnew;									// return const Bit value
}

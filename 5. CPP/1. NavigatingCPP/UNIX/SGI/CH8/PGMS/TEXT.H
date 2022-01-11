#ifndef TEXTH
#define TEXTH
// Text.h - Text class interface
#include <iostream.h>
#include <stdio.h>
#include "String.h"

class TextError {									// Text exception object
private:
	char buf[80];
public:
	TextError(int length) {
		sprintf(buf, "Text: max length of %d reached", length);
	}
	TextError(int index, int count) {
		sprintf(buf, 
			"Text: index %d incorrect with %d sentences", index, count);
	}
	void response() const { cerr << buf << endl; }
};

class Text {
private:
	String **s;										// pointer to array
	int len;											// length of array
	int count;										// number of Strings
	void copy(const Text &);
	void free();
public:
// Constructors
	explicit Text(int n = 1) : len(n) {		// initialize length
		s = new String * [len];					// String pointer array
		count = 0;									// initialize count
	}
	Text(const Text & a) { copy(a); }		// copy constructor
// Destructor
	~Text() { free(); }
// Modifiers
	Text & operator=(const Text & a) {		// assignment
		if (this != &a) {
			free();  
			copy(a); 
		}
		return *this;
	}
	void write(const String &);					// write to Text object
// Selectors
	int nitems() const { return count; }		// number of sentences
	int length() const { return len; }			// length of Text object
	String read(int) const;							// read from Text object
};

void Text::copy(const Text & t) {
	len = t.len;	count = t.count;
	s = new String * [len];							// create String pointer array
	for (int i = 0; i < count; i++)
		s[i] = new String(*t.s[i]);				// copy sentence 
}

void Text::free() {
	for (int i = 0; i < count; i++)
		delete s[i];									// delete each sentence
	delete [] s;										// delete String pointer array
}

void Text::write(const String & t) {
	if (count == len)									// no more room?
		throw TextError(len);
	String *sp = new String(t);					// copy sentence
	s[count++] = sp;									// store sentence
}

String Text::read(int n) const { 
	int index = n-1;
	if (index < 0 || index >= count)
		throw TextError(n, count);					// illegal subscript
	return *s[index];									// return String sentence
}
#endif

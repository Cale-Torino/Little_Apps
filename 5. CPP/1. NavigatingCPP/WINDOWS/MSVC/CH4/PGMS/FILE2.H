#ifndef FILEH
#define FILEH
// File2.h - File object with exception objects
#include <iostream.h>
#include <stdio.h>

class FileError {							// Fifo exception object
private:
	char buf[80];
public:
	FileError(const char *fname, const char *mode) {
		sprintf(buf, "File: can't open %s for mode (%s)", fname, mode);
	}
	void response() const { cerr << buf << endl; }
};

class File {
private:
	FILE *fp;												// File pointer
public:
// Constructors
	File(const char *fn, const char *mode) {
		fp = fopen(fn, mode);
		if (fp == NULL)
			throw FileError(fn, mode);
	}
	File() {												// default constructor
		fp = tmpfile();								// open temp file for read/write
		if (fp == NULL)
			throw FileError("tmp", "w+");
	}
// Destructor
	~File() {
		fclose(fp);
	}
	FILE *getfp() const { return fp; }
};
#endif

#ifndef FILEH
#define FILEH
// File1.h - File object
#include <stdio.h>
#include <string.h>

class File {
private:
	FILE *fp;												// File pointer
public:
// Constructors
	File(const char *fn, const char *mode = "w+") {
		fp = fopen(fn, mode);
		if (fp == NULL)
			throw "can't open file";
	}
	File() {												// default constructor
		fp = tmpfile();								// open temp file for read/write
		if (fp == NULL)
			throw "can't open file";
	}
// Destructor
	~File() {
		fclose(fp);
	 }
	 FILE *getfp() const { return fp; }
};
#endif

#ifndef FILEH
#define FILEH
//  File1.h - File objects with Exceptions
#include <iostream.h>
#include <stdio.h>
#include "String.h"
#include "FilePtr.h"

class FileError {
public:
	virtual void response() const = 0;
	virtual ~FileError() { }
};

class FBadOpen : public FileError {
private:
	String name;
	String access;
public:
	FBadOpen(const String & nn, const String & aa) : 
			name(nn), access(aa) { }
	void response() const {
		cerr << "Unable to open file " << name 
			<< " for access " << "\"" << access 
				<< "\"" << endl;
	}
};

class File {
private:
	FilePtr fp;									// manages FILE pointer
	String name;								// file name
	String mode;								// access mode
public:
	File(const String & n, const String & a) : 
		fp(fopen(n, a)), name(n), mode(a) {
		if (fp.get() == 0) 
			throw FBadOpen(n, a);
	}
	operator FILE * () const { return fp.get(); }
	String getname() const { return name; }
	String getmode() const { return mode; }
};
#endif

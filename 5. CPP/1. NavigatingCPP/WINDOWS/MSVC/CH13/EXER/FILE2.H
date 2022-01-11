#ifndef FILEH
#define FILEH
//  File2.h - File objects with Exceptions
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

class FBadRead : public FBadOpen {
public:
	FBadRead(const String & nn, const String & aa): FBadOpen(nn, aa) { }
	void response() const {
		FBadOpen::response();
		cerr << "(File not readable or does not exist)" << endl;
	}
};

class FBadWrite : public FBadOpen {
public:
	FBadWrite(const String & nn, const String & aa): FBadOpen(nn, aa) { }
	void response() const {
		FBadOpen::response();
		cerr << "(File not writable)" << endl;
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
		if (fp.get() == 0 && a == "r")
			throw FBadRead(n, a);
		else if (fp.get() == 0 && a == "w")
			throw FBadWrite(n, a);
	}
	operator FILE * () const { return fp.get(); }
	String getname() const { return name; }
	String getmode() const { return mode; }
};
#endif

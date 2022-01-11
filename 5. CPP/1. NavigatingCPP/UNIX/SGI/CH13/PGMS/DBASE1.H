#ifndef DBASEH
#define DBASEH
// Dbase1.h - DataBase object, no exceptions from constructor
#include <iostream.h>
#include "String.h"

class DbaseError {									// abstract base
public:
	DbaseError() { }
	virtual ~DbaseError() { }						// virtual destructor
	virtual void response() const  = 0;			// pure virtual
};

class DbaseReadError : public DbaseError {
public:
	void response() const { cout << "DbaseReadError" << endl; }
};

class DbaseWriteError : public DbaseError {
public:
	void response() const { cout << "DbaseWriteError" << endl; }
};

class DbaseOpenError : public DbaseError {
public:
	void response() const { cout << "DbaseOpenError" << endl; }
};

class Dbase {
private:
	int filed;
public:
	Dbase(int fd = 0) : filed(fd) { cout << "Dbase constr" << endl; }
	~Dbase() { cout << "Dbase destr" << endl; }
	String read() { 
		if (filed == 0)
			throw DbaseReadError();
		return "record";
	}
	void write(const String & s) { cout << s << endl; }
};
#endif

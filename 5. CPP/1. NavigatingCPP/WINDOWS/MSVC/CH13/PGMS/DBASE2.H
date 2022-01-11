#ifndef DBASEH
#define DBASEH
// Dbase2.h - throws exceptions from constructor, resource leaks
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

class Network { };

class Base {
private:
	Network *id;
public:
	Base() { id = new Network; cout << "Base constr" << endl; }
	virtual ~Base() { delete id; cout << "Base destr" << endl; }
};

class FileTbl {
public:
	FileTbl() { cout << "FileTbl constr" << endl; }
	~FileTbl() { cout << "FileTbl destr" << endl; }
};

class ProcessTbl {
public:
	ProcessTbl() { cout << "ProcessTbl constr" << endl; }
	~ProcessTbl() { cout << "ProcessTbl destr" << endl; }
};

class Dbase : public Base {
private:
	int filed;
	FileTbl *ft;
	ProcessTbl *pt;
	String name;
public:
	Dbase(int fd = 0, const String & n = "central") : name(n) {
		cout << "Dbase constr" << endl;
		filed = fd;
		ft = new FileTbl;							// allocate file table
		pt = new ProcessTbl;						// allocate process table
		if (filed == 0)
			throw DbaseOpenError();				// throw exception
	}
	~Dbase() { 										// never gets called
		cout << "Dbase destr" << endl;
		delete ft;									// release file table
		delete pt;									// release process table
	}
	String read() { 
		if (filed == 0)
			throw DbaseReadError();
		return "record";
	}
	void write(const String & s) { cout << s << endl; }
};
#endif

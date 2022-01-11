#ifndef DBASEH
#define DBASEH
// Dbase4.h - throws exceptions from constructor, no abstract base
#include <iostream.h>
#include "String.h"
#include "autoptr.h"

class DbaseError {									// not abstract base
public:
	DbaseError() { }
	virtual ~DbaseError() { }						// virtual destructor
	virtual void response() const { cout << "DbaseError" << endl; }
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
	auto_ptr<Network> id;
public:
	Base() : id(new Network) { cout << "Base constr" << endl; }
	virtual ~Base() { cout << "Base destr" << endl; }
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
	auto_ptr<FileTbl> ft;						// file table
	auto_ptr<ProcessTbl> pt;					// process table
	String name;
public:
	Dbase(int fd = 0, const String & n = "central") : 
		filed(fd), ft(new FileTbl), pt(new ProcessTbl), name(n) { 
		cout << "Dbase constr" << endl;
		if (filed == 0)
			throw DbaseOpenError();				// throw exception
	}
	~Dbase() { 
		cout << "Dbase destr" << endl;
	}
	String read() { 
		if (filed == 0)
			throw DbaseReadError();
		return "record";
	}
	void write(const String & s) { cout << s << endl; }
};
#endif

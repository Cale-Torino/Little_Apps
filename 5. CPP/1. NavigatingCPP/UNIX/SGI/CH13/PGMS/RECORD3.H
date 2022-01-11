#ifndef RECORDH
#define RECORDH
// Record3.h - exceptions in destructors, with catch handler, discards
#include <iostream.h>

class Record {
private:
	int recnum;
	static void lock(Record *);
	static void unlock(Record *);					// throws exception
public:
	Record(int n = 0);								// constructor
	~Record();											// destructor
	void status() const {							// throws exception
		if (recnum == 0)
			throw "status_error";
	}
};

Record::Record(int n) : recnum(n) { lock(this); }

Record::~Record() { 									// destructor
	try {
		unlock(this);									// throws exception
	}
	catch (...) { }									// discard any exception
}

void Record::lock(Record *p) {
	cout << "locking record " << p->recnum << endl;
}

void Record::unlock(Record *p) {
	cout << "unlocking record " << p->recnum << endl;
	if (p->recnum == 0)
		throw "unlock_error";						// throw exception
}
#endif

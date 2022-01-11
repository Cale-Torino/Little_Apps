#ifndef RECORDH
#define RECORDH
// Record4.h - exceptions in destructors, catch handler, discards, audits
#include <iostream.h>

void start_audit() { cout << "start_audit" << endl; }
void stop_audit() {  cout << "stop_audit" << endl;}

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

Record::Record(int n) : recnum(n) { 			// constructor
	start_audit();										// start auditing
	lock(this);
}

Record::~Record() { 									// destructor
	try {
		unlock(this);									// throws exception
	}
	catch (...) { }									// discard any exception
	stop_audit();										// stop auditing
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

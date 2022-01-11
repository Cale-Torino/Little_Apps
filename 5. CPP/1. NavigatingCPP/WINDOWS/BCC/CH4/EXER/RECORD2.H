#ifndef RECORDH
#define RECORDH
// Record2.h - Record class description with containment, references
#include <iostream.h>
#include <string.h>
#include "StringN.h"

class Record {										// Record class with fields
private:
	const StringN id;
	const StringN & field1;						// references
	const StringN & field2;						// references
public:
// Constructor
	Record(const char *p, const StringN & s1, const StringN & s2) : 
		id(strlen(p), p), field1(s1), field2(s2) { }
// Member functions
	void print() const { id.print(); cout << " : ";
		field1.print(); cout << " : "; field2.print(); cout << endl; 
	}
};
#endif

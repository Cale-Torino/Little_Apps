#ifndef PSTRINGH
#define PSTRINGH
// PString.h - Strings with persistence
#include "Persist.h"
#include "String.h"

class Persist_String : public String, public Persist {
public:
	Persist_String(const char *ch = "") : String(ch) { }
	Persist_String(const String & str) : String(str) { }
	Persist_String(ifstream & ifs) { ifs >> *this; }
	static Persist *new_string(ifstream & ifs) 
		{ return new Persist_String(ifs); }
	void save(ofstream & ofs) const {
		ofs << typeid(*this).name() <<  '\n' << *this;
	}
};
#endif

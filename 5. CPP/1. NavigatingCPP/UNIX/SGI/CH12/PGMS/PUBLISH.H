#ifndef PUBLISH
#define PUBLISH
// Publish.h - publish header file
#include <iostream.h>
#include <typeinfo.h>
#include "String.h"

class Published_Item {
private:
	String title;
public:
	Published_Item(const String & s = "Untitled") : title(s) { }
	virtual ~Published_Item() {}
	virtual void output(ostream &) const;
	virtual bool equals(const Published_Item &) const;
	String getTitle() const { return title; }
};

inline bool Published_Item::equals(const Published_Item & op) const {
	if (typeid(*this) == typeid(op))
		return getTitle() == op.getTitle();
	return false;
}

inline bool operator==(const Published_Item & op1, const Published_Item & op2) {
	return op1.equals(op2);
}

inline void Published_Item::output(ostream & os) const {  
	os << "I am a " << typeid(*this).name() << ": " << getTitle();
}

inline ostream & operator<<(ostream & os, const Published_Item & pi) {
	pi.output(os);
	return os;
}

class Book : public Published_Item {
public:
	Book(const String & s) : Published_Item(s) { }
};

class Video : public Published_Item {
public:
	Video(const String & s) : Published_Item(s) { }
	bool equals(const Published_Item &) const;
};

inline bool Video::equals(const Published_Item & op) const {
	const Video *vp = dynamic_cast<const Video *>(&op);
	if (vp)
		return getTitle() == vp->getTitle();
	return false;
}

class Vhs : public Video { 
public:
	Vhs(const String & s) : Video(s) { }
};

class Laserdisc : public Video { 
public:
	Laserdisc(const String & s) : Video(s) { }
};
#endif

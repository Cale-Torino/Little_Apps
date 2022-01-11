#ifndef PACKAGEH
#define PACKAGEH
// Package.h - Package interface
#include "String.h"

class Package {
private:
	String src;										// origin
	String dest;									// destination
public:
	Package(const String & s, const String & d) : src(s), dest(d) { }
	virtual float cost() const = 0;			// placeholder
	String getsrc() const { return src; }
	String getdest() const { return dest; }
};

class Box : public Package {
private:
	float weight;								// weight for a Box
public:
	Box(const String & s, const String & d, float w) :
			Package(s, d), weight(w) { }
	float cost() const;						// Box cost
	float getweight() const { return weight; }
};

class Letter : public Package {
private:
	int npages;									// number of pages for a Letter
public:
	Letter(const String & s, const String & d, int np) :
			Package(s, d), npages(np) { }
	float cost() const;						// Letter cost
	int getnpages() const { return npages; }
};

class Crate : public Package {
private:
	float weight;								// weight for a Crate
public:
	Crate(const String & s, const String & d, float w) :
			Package(s, d), weight(w) { }
	float getweight() const { return weight; }
};

class Wood_Crate : public Crate {
public:
	Wood_Crate(const String & s, const String & d, float w) :
			Crate(s, d, w) { }
	float cost() const;						// Wood_Crate cost
};

class Metal_Crate : public Crate {
public:
	Metal_Crate(const String & s, const String & d, float w) :
			Crate(s, d, w) { }
	float cost() const;						// Metal_Crate cost
};

inline float Box::cost() const {
		return (weight > 100) ? .75 * weight : .5 * weight;
}

inline float Letter::cost() const {
		return (npages > 100) ? .10 * npages : .05 * npages;
}

inline float Wood_Crate::cost() const {
		float weight = getweight();
		return (weight > 100) ? 1.5 * weight : 1.25 * weight;
}

inline float Metal_Crate::cost() const {
		float weight = getweight();
		return (weight > 500) ? 2.5 * weight : 1.75 * weight;
}
#endif

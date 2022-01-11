#ifndef RESIDENTH
#define RESIDENTH
// Resident.h - Residence base
#include <iostream.h>

class Residence {
private:
	int square_feet;
public:
	Residence(int sf) : square_feet(sf) { }
	virtual ~Residence() { }
	virtual void move_in() = 0;
	virtual void move_out() = 0;
	int get_footage() const { return square_feet; }
	virtual void output(ostream & os) const {
		os << "square footage = " << get_footage() << endl;
	}
};

class House : public Residence {
public:
	House(int sf) : Residence(sf) { }
	void move_in() { cout << "House::move_in()" << endl; }
	void move_out() { cout << "House::move_out()" << endl; }
};

inline ostream & operator<<(ostream & os, const Residence & r) {
   r.output(os);									// virtual call
	return os;
}
#endif

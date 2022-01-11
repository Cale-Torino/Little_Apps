#ifndef RESIDENT
#define RESIDENT
// Resident.h - multiple inheritance with distinct bases
#include <iostream.h>

class Residence {
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

inline ostream & operator<<(ostream & os, const Residence & r) {
   r.output(os);									// virtual call
	return os;
}
#endif

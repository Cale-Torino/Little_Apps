#ifndef MOTORH
#define MOTORH
// Motorhme.h - multiple inheritance with distinct bases
#include <iostream.h>
#include "Vehicle.h"
#include "Resident.h"
#include "String.h"

class MotorHome : public LandVehicle, public Residence {
public:
	MotorHome(int len, int sf) : LandVehicle(len), Residence(sf) { }
	void move_in() { cout << "Motorhome::move_in()" << endl; }
	void move_out() { cout << "Motorhome::move_out()" << endl; }
	void output(ostream & os) const {
		Vehicle::output(os);
		Residence::output(os);
	}
};

class HouseBoat : public Boat, public Residence {
public:
	HouseBoat(const String & n, int len, int sf) 
		: Boat(n, len), Residence(sf) { }
	void move_in() { cout << "HouseBoat::move_in()" << endl; }
	void move_out() { cout << "HouseBoat::move_out()" << endl; }
	void output(ostream & os) const {
		Boat::output(os);
		Residence::output(os);
	}
};
#endif

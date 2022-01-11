#ifndef VEHICLEH
#define VEHICLEH
// Vehicle.h - multiple inheritance with distinct bases
#include <iostream.h>
#include "String.h"

class Vehicle {
private:
	int length;
public:
	Vehicle(int len) : length(len) { }
	virtual ~Vehicle() { }
	virtual void go() = 0;
	virtual void stop() = 0;
	int get_length() const { return length; }
	virtual void output(ostream & os) const {
		os << "length = " << length << endl;
	}
};

inline ostream & operator<<(ostream & os, const Vehicle & v) {
   v.output(os);									// virtual call
	return os;
}

class WaterVehicle : public Vehicle {
public:
	WaterVehicle(int len) : Vehicle(len) { }
	void go() { cout << "WaterVehicle::go()" << endl; }
	void stop() { cout << "WaterVehicle::stop()" << endl; }
};

class Boat : public WaterVehicle {
private:
	String name;
public:
	Boat(const String & n, int len) : name(n), WaterVehicle(len) { }
	String get_name() const { return name; }
	void output(ostream & os) const {
		Vehicle::output(os);
		os << "name = " << get_name() << endl;
	}
};

class LandVehicle : public Vehicle {
public:
	LandVehicle(int len) : Vehicle(len) { }
	void go() { cout << "LandVehicle::go()" << endl; }
	void stop() { cout << "LandVehicle::stop()" << endl; }
};
#endif

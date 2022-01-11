// flight.c - class descriptions
#include "PtrList.h"

class Flight {					// class name
private:
	int flightnum;				// class data member (private attribute)
public:
	void take_off() { }			// class member function (public behavior)
};

class Airplane { };

class RunWay {
private:
	PtrList<Airplane> theplanes;			// List of Airplane pointers
public:
	void taxi() { }
};

int main()
{
	Flight f;
	RunWay r;
	f.take_off();
	r.taxi();
	return 0;
}

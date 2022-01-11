// motorh.c - class descriptions, generalization, multiple inheritance

class Vehicle {								// base class
public:
	virtual void go() = 0;					// placeholder, all vehicles go
};

class Residence {								// base class
public:
	virtual void sleep() = 0;				// placeholder, all residences sleep
};

class MotorHome : public Vehicle, public Residence {
public:
	void go() { }								// travel
	void sleep() { }							// rest
};

int main()
{
	MotorHome m;
	return 0;
}

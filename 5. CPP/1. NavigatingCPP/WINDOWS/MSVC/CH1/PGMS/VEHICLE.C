// vehicle.c - class descriptions, generalization

class Vehicle {								// base class
public:
	virtual void go() = 0;					// placeholder, all vehicles go
};

class Airplane : public Vehicle {		// derived class
public:
	void go() { }								// fly through the air
};

class Automobile : public Vehicle {		// derived class
public:
	void go() { }								// travel on the ground
};

class Boat : public Vehicle {				// derived class
public:
	void go() { }								// travel over the water
};

int main()
{
	Airplane a;
	Automobile b;
	Boat c;
	return 0;
}

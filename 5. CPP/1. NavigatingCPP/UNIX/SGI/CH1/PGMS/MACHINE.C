// machine.c - class descriptions, multiple inheritance, virtual bases

class Machine {								// base class
public:
	virtual void execute() = 0;			// placeholder
};

class Fax : virtual public Machine {
public:
	void execute() { }						// Fax execute
};

class Copier : virtual public Machine {
public:
	void execute() { }						// Copier execute
};

class Copier_Fax : public Copier, public Fax {
public:
	void execute() { }						// Copier_Fax execute
};

int main()
{
	Copier_Fax cf;
	return 0;
}

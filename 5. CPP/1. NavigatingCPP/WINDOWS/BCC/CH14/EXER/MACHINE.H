#ifndef MACHINEH
#define MACHINEH
// Machine.h - Multiple Inheritance with Virtual Base
#include <iostream.h>
#include <typeinfo.h>
#include "String.h"

class PowerSupply { };

class Modem { 
public:
	void answer() { }
	void dial() { }
	bool ringing() const { bool status = true; return status; }
};

class Machine {
protected:
	PowerSupply ps;
public:
	Machine() { }
	virtual ~Machine() { }
	virtual void power_on() { cout << whatmachine() << " power_on()" << endl; }
	virtual void power_off() { cout << whatmachine() << " power_off()" << endl; }
	virtual void execute() = 0;
	String whatmachine() const { return typeid(*this).name(); }
};

class Fax : virtual public Machine {
private:
	Modem md;
public:
	void print() { cout << "Fax::print()" << endl; }
	void send() { cout << "Fax::send()" << endl; }
	void receive() { cout << "Fax::receive()" << endl; }
	void dial_out() { md.dial(); }
	void execute();
};

void Fax::execute() {
	cout << "Fax::execute()" << endl;
	if (md.ringing()) {
		md.answer();
		receive();
		print();
	}
	else {
		dial_out();
		send();
	}
}

class LaserPrinter : virtual public Machine {
private:
	PowerSupply ps;
public:
	void print() { cout << "LaserPrinter::print()" << endl; }
	void execute() { cout << "LaserPrinter::execute()" << endl; }
};

class Copier : virtual public Machine {
private:
	volatile int ncopies_button;
public:
	Copier() { ncopies_button = 1; }
	void copy() { cout << "Copier::copy()" << endl; }
	void print() { cout << "Copier::print()" << endl; }
	void collate() { cout << "Copier::collate()" << endl; }
	void execute();
};

void Copier::execute() {
	cout << "Copier::execute()" << endl;
	copy();
	for (int n = ncopies_button; n > 0; n--) {
		print();
		collate();
	}
}

class Copier_Fax : public Copier, public Fax {
public:
	void print() { Copier::print(); }
	void execute() {
		Fax::execute();
		Copier::execute();
	}
};

class Printer_Fax : public LaserPrinter, public Fax {
public:
	void print() { LaserPrinter::print(); }
	void execute() {
		Fax::execute();
		LaserPrinter::execute();
	}
};

inline ostream & operator<<(ostream & os, const Machine &) { return os; }
#endif

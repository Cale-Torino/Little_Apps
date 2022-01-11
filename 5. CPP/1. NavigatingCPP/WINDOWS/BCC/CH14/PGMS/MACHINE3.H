#ifndef MACHINEH
#define MACHINEH
// Machine3.h - Multiple Inheritance with Virtual Base, serial number
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
private:
	long serial_num;
protected:
	PowerSupply ps;
public:
	Machine(long sn) : serial_num(sn) { }
	virtual ~Machine() { }
	virtual void power_on() { 
		cout << whatmachine() << ' ' << get_serial_num() << ": " 
			<< "power_on()" << endl;
	}
	virtual void power_off() { 
		cout << whatmachine() << ' ' << get_serial_num() << ": " 
			<< "power_off()" << endl;
	}
	virtual void execute() = 0;
	String whatmachine() const { return typeid(*this).name(); }
	long get_serial_num() const { return serial_num; }
};

class Fax : virtual public Machine {
private:
	Modem md;
public:
	Fax(long sn) : Machine(sn) { }
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

class Copier : virtual public Machine {
private:
	volatile int ncopies_button;
public:
	Copier(long sn) : Machine(sn) { ncopies_button = 1; }
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
	Copier_Fax(long sn) : Fax(sn), Copier(sn), Machine(sn) { }
	void print() { Copier::print(); }
	void execute() {
		Fax::execute();
		Copier::execute();
	}
};

inline ostream & operator<<(ostream & os, const Machine &) { return os; }
#endif

#ifndef INVESTH
#define INVESTH
// Invest.h - Investment type, no RTTI
#include <iostream.h>

class Investment {									// Library class
private:
	static int descr;
public:
	virtual float purchase();	
	static int *type() { return &descr; }
	bool isA(const int *pd) const { return type() == pd; } 
};

class Stock : public Investment {				// our class
private:
	static int descr;
public:
	float purchase();	
	virtual float dividend() const;	
	static int *type() { return &descr; }
};

class Land : public Investment {					// Library class
private:
	static int descr;
public:
	float purchase();	
	static int *type() { return &descr; }
};

void tax(Investment *pi) {							// Library specific
	pi->purchase();									// OK
	if (pi->isA(Stock::type())) {					// check type
		Stock *ps = static_cast<Stock *>(pi);	// downcast
		ps->dividend();								// OK
	}
}

float Investment::purchase() { 
	cout << "Investment::purchase()" << endl;
	return 0;
}

float Stock::purchase() {
	cout << "Stock::purchase()" << endl;
	return 0;
}

float Stock::dividend() const {
	cout << "Stock::dividend()" << endl;
	return 0;
}

float Land::purchase() {
	cout << "Land::purchase()" << endl;
	return 0;
}

int Investment::descr = 0;
int Stock::descr = 0;
int Land::descr = 0;
#endif

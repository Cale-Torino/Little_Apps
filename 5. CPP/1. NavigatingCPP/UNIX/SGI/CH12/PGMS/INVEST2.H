#ifndef INVESTH
#define INVESTH
// Invest2.h - Investment type, dynamic cast
#include <iostream.h>
#include <typeinfo.h>

class Investment {									// Library class
public:
	virtual float purchase();	
};

class Stock : public Investment {				// our class
public:
	float purchase();									// override virtual purchase()	
	virtual float dividend() const;				// new virtual function	
};

class Land : public Investment {					// our class
public:
	float purchase();									// override virtual purchase()	
};

void tax(Investment *pi) {							// pointer argument 
	pi->purchase();									// OK
	Stock *ps = dynamic_cast<Stock *>(pi);		// downcast								
	if (ps) 												// successful?
		ps->dividend();								// for any Stock type
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
#endif

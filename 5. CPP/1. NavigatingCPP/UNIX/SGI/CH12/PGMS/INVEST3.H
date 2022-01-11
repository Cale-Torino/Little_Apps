#ifndef INVESTH
#define INVESTH
// Invest3.h - Investment type
#include <iostream.h>
#include <typeinfo.h>

class Investment {									// Library class
public:
	virtual float purchase();	
};

class Stock : public Investment {				// our class
public:
	float purchase();									// override	
	virtual float dividend() const;				// new virtual function	
};

class QStock : public Stock {						// derived Stock class
public:
	float purchase();	
	float dividend() const;	
};

class Land : public Investment {					// our class
public:
	float purchase();	
};

void tax(Investment *pi) {							// pointer argument 
	pi->purchase();									// OK
	Stock *ps = dynamic_cast<Stock *>(pi);		// downcast								
	if (ps) 												// succeessful?
		ps->dividend();								// for any Stock type
}

void audit(const Investment *pi) {				// pointer argument
	//Stock *ps1 = dynamic_cast<Stock *>(pi);						// error
	//Stock *ps1 = const_cast<Stock *>(dynamic_cast<const Stock *>(pi));
	const Stock *ps = dynamic_cast<const Stock *>(pi);			// OK
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

float QStock::purchase() {
	cout << "QStock::purchase()" << endl;
	return 0;
}

float QStock::dividend() const {
	cout << "QStock::dividend()" << endl;
	return 0;
}

float Land::purchase() {
	cout << "Land::purchase()" << endl;
	return 0;
}
#endif

#ifndef INVESTH
#define INVESTH
// Invest4.h - Investment type
#include <iostream.h>
#include <stdio.h>
#include <typeinfo.h>
#define bad_cast Bad_cast 

class InvestmentError {								// Investment exception object
private:
	char buf[80];
public:
	InvestmentError(const char *msg) { sprintf(buf, "Investment: %s", msg); }
	void response() const { cerr << buf << endl; }
};

class Investment {									// Library class
protected:
	float price;
public:
	Investment(float p) { price = p; }
	virtual float purchase() = 0;	
	virtual bool compare(const Investment &) const = 0;
};

class Stock : public Investment {				// our class
protected:
	float div;
public:
	Stock(float p = 0, float d = 0) : Investment(p) { div = d; }
	bool compare(const Investment &) const;
	float purchase();	
	virtual float dividend() const;	
};

class QStock : public Stock {						// derived Stock class
public:
	QStock(float p = 0, float d = 0) : Stock(p, d) { }
	float purchase();	
	float dividend() const;	
};

class Land : public Investment {					// our class
public:
	Land(float p = 0) : Investment(p) { }
	float purchase();	
	bool compare(const Investment &) const { return true; }
};

void tax(Investment *pi) {							// Pointer argument 
	pi->purchase();									// OK
	Stock *ps = dynamic_cast<Stock *>(pi);		// downcast								
	if (ps) 												// succeessful?
		ps->dividend();								// for any Stock type
}

bool Stock::compare(const Investment & ri) const {		// reference argument
	try {
		const Stock & rs = dynamic_cast<const Stock &>(ri);
		return rs.dividend() > dividend();
	}
	catch (bad_cast) {
		throw InvestmentError("argument must be a Stock");
	}
}

float Investment::purchase() { 
	cout << "Investment::purchase()" << endl;
	return price;
}

float Stock::purchase() {
	cout << "Stock::purchase()" << endl;
	return price;
}

float Stock::dividend() const {
	cout << "Stock::dividend()" << endl;
	return div;
}

float QStock::purchase() {
	cout << "QStock::purchase()" << endl;
	return price;
}

float QStock::dividend() const {
	cout << "QStock::dividend()" << endl;
	return div;
}

float Land::purchase() {
	cout << "Land::purchase()" << endl;
	return price;
}

bool buy(const Investment & i1, const Investment & i2) {
	return i1.compare(i2);
}
#endif

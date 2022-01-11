// pro3.C - Protected access level, access restrictions
#include <iostream.h>
#include "String.h"

class Investment {
protected:
	int account;
public:
	void tax();
};

class Land : public Investment {
public:
	Land(int) { }
};

class Oil : public Investment {
public:
	Oil(const String &) { }
	void drill(int, const String &);
};

void Oil::drill(int price, const String & title) {
	Investment *p = new Land(price);
	//p->account -= price;							// illegal
	Land *lp = new Land(price);
	//lp->account -= price;							// illegal
	p->tax();											// legal
	lp->tax();											// legal

	Oil *q = new Oil(title);
	q->account -= price;								// legal
}

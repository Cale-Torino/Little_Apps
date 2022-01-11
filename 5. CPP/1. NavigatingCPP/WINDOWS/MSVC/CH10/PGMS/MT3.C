// mt3.C - member templates, virtual functions
#include <iostream.h>
#include <typeinfo.h>
#include "String.h"

class Action {
public:
	virtual void f(double) {							// virtual non-template
		cout << "Action::f(double)" << endl;
	}
	virtual void w(const String &) {					// virtual non-template
		cout << "Action::w(String)" << endl;
	}
};


class Suit : public Action {
private:
	template <class TYPE>
	void g(const TYPE & a) {							// private member template
		cout << "Suit::g(" << typeid(a).name() << ')' << endl;
	}
public:
	void f(double d) { g(d); }							// virtual non-template
	void w(const String & d) { g(d); }				// virtual non-template
};

int main()
{
	Action *p = new Action;
	p->f(3.4);											// Action::f(double)
	p->w("abc");										// Action::w(String)

	Action *q = new Suit;
	q->f(5.6);											// Suit::g(double)
	q->w("xyz");										// Suit::g(String)
	return 0;
}

/*********************************************************************

$ mt3
Action::f(double)
Action::w(String)
Suit::g(double)
Suit::g(class String)

*/

// invest1.c - template friend functions
#include <iostream.h>

class Oil { };
class Land { };

template <class TYPE>										// friend functions
class Invest {													// Investment class
	friend void audit();										// non-template template
	friend void stock(const Invest<TYPE> &);			// one-to-one template
	//template <class T>
	//friend void portfolio(const Invest<T> &);		// one-to-many template
private:
	int amount;
public:
	Invest(int a) { amount = a; }
};

template <class TYPE>
void stock(const Invest<TYPE> & i)	{
	cout << i.amount << endl;								// private access
}

template <class T>
void portfolio(const Invest<T> & i)	{
	cout << i.amount << endl;								// private access
}

Invest<Oil> g1(30000);										// Oil investment
Invest<Land> c1(25000);										// Land investment

void audit() {
	cout << "audit(): " << g1.amount << endl;				// private access
	cout << "audit(): " << c1.amount << endl;				// private access
}

int main()
{
	stock(g1);										// stock in Oil
	stock(c1);										// stock in Land
	//portfolio(g1);								// Oil portfolio
	//portfolio(c1);								// Land portfolio
	audit();											// all investments
	return 0;
}

/*******************************************************************

$ invest1
30000
25000
audit(): 30000
audit(): 25000

*/

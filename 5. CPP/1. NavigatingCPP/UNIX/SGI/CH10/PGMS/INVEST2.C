// invest2.c - template friend member functions
#include <iostream.h>

class Oil { };
class Land { };

class Tax {												// non-template class
private:
	int year;
public:
	Tax(int y) { year = y; }
	void pay();
};

template <class TYPE>
class Invest;

template <class TYPE>								// template class
class Account {
private:
	int total;
public:
	Account(int t) { total = t; }
	void buy(int);
	void report();
};

template <class TYPE>										// friend member functions
class Invest {													// Investment class
	friend void Tax::pay();									// non-template
	friend void Account<TYPE>::buy(int);				// one-to-one template
	//template <class T>
	//friend void Account<T>::report();					// one-to-many template
private:
	int amount;
public:
	Invest(int a) { amount = a; }
};

template <class TYPE>
void Account<TYPE>::buy(int num) {
	Invest<TYPE> i(num);
	cout << (total -= i.amount) << endl;				// private access
}

Account <Oil> a1(32000);									// Oil Account
Account <Land> a2(32000);									// Land Account

Invest<Oil> g1(30000);										// Oil investment
Invest<Land> c1(25000);										// Land investment

void Tax::pay() {
	cout << "Tax::pay(): " << g1.amount * .2 << endl;		// tax Oil
	cout << "Tax::pay(): " << c1.amount * .5 << endl;		// tax Land
}

//template <class T>
//void Account<T>::report()	{
	//cout << (total -= g1.amount) << endl;					// private access
	//cout << (total -= c1.amount) << endl;					// private access
//}

int main()
{
	Tax t(1995);

	a1.buy(20000);							// buy Oil in Oil Account
	a2.buy(10000);							// buy Land in Land Account

	t.pay();									// pay from all Accounts and Investments
	//a1.report();
	return 0;
}

/*******************************************************************

$ invest2
12000
22000
Tax::pay(): 6000
Tax::pay(): 12500

*/

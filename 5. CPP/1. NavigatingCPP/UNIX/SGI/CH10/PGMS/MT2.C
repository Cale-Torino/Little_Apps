// mt2.C - member templates, specialization
#include <iostream.h>
#include <typeinfo.h>
#include "String.h"

template <class TYPE>
class Act {
public:
	void f(double);								// non-template prototype
	template <class NEWTYPE>					// member template prototype
	void f(const NEWTYPE &);
};

template <class TYPE> 
void Act<TYPE>::f(double) {						// template definition
	cout << typeid(*this).name() << " non-template member" << endl;
}

template<class TYPE>
template<class NEWTYPE>
void Act<TYPE>::f(const NEWTYPE &) {			// member template definition
	cout << typeid(*this).name() << " template member" << endl;
}

template <> 
void Act<String>::f(double) {					// specialized non-template definition
	cout << "Act<String> specialized non-template member" << endl;
}

template<>
template<>
void Act<String>::f(const String &) {			// specialized member template definition
	cout << "Act<String> specialized template member" << endl;
}

int main()
{
	Act<String> play;
	play.f(3.4);								// Act<String> specialized non-template member

	String middle = "Act III";
	play.f(middle);								// Act<String> specialized template member

	Act<int> m1;
	m1.f(3.4);									// Act<int> non-template member
	m1.f(middle);								// Act<int> template member
	m1.f(100);									// Act<int> template member
	return 0;
}

/****************************************************************************************

$ mt2
Act<String> specialized non-template member
Act<String> specialized template member
Act<int> non-template member
Act<int> template member
Act<int> template member

*/

// finance.C - friend functions and namespaces
#include <iostream.h>

namespace Finance {
	class Audit_Report { };
	class Account {
	friend void audit(const Account &, Audit_Report &);
	};										// end of Account
}											// end of namespace Finance

void Finance::audit(const Account &, Audit_Report &) {
  cout << "audit() called" << endl;
}

int main()
{
	using namespace Finance;
	Account acc;
	Audit_Report ar;
	audit(acc, ar);
	return 0;
}

/************************************************************************

$ finance
audit() called

*/

// forties.C - display years as Roman numbers
#include <iostream.h>
#include "Roman.h"

namespace ASG = Anderson_Software_Group;
using namespace ASG;

int main()
{
	for (int year = 1940; year <= 1949; year++) {
		Roman r = year;
		cout << r.getnum() << '\t' << r.getroman() << endl;
	}
	return 0;
}

/**********************************************************************

$ forties 
1940	MCMXL
1941	MCMXLI
1942	MCMXLII
1943	MCMXLIII
1944	MCMXLIV
1945	MCMXLV
1946	MCMXLVI
1947	MCMXLVII
1948	MCMXLVIII
1949	MCMXLIX

*/

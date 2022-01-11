// movies.C - display years as Roman numbers
#include <iostream.h>
#include "Roman.h"

int main()
{
	for (int year = 1925; year <= 1948; year++) {
		Roman r = year;
		cout << r.getnum() << '\t' << r.getroman() << endl;
	}
	return 0;
}

/**********************************************************************

$ movies 
1925	MCMXXV
1926	MCMXXVI
1927	MCMXXVII
1928	MCMXXVIII
1929	MCMXXIX
1930	MCMXXX
1931	MCMXXXI
1932	MCMXXXII
1933	MCMXXXIII
1934	MCMXXXIV
1935	MCMXXXV
1936	MCMXXXVI
1937	MCMXXXVII
1938	MCMXXXVIII
1939	MCMXXXIX
1940	MCMXL
1941	MCMXLI
1942	MCMXLII
1943	MCMXLIII
1944	MCMXLIV
1945	MCMXLV
1946	MCMXLVI
1947	MCMXLVII
1948	MCMXLVIII

*/

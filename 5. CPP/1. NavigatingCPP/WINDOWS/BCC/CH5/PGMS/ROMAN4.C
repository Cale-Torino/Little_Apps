// Roman4.C - Roman implementation
#include <string.h>
#include "Roman4.h"

int Roman::count = 0;

void Roman::convert_Roman() {
	static const char *rom[] = {
		"Z", "MZ", "W", "MW", "M", "CM", "D", "CD", "C", "XC",
		"L", "XL", "X", "IX", "V", "IV", "I" };
	static const int dec[] = { 10000, 9000, 5000, 4000, 1000, 900, 500, 
					400, 100,   90,   50,   40,   10,   9,   5,   4,   1 };

	s[0] = '\0';
	int num = value;
	for (int i = 0; num; ) {
		while (dec[i] - num > 0)
			i++;
		strcat(s, rom[i]);
		num -= dec[i];
	}
}

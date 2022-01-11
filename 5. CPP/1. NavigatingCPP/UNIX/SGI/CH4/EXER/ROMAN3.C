// Roman3.C - Roman implementation, integer to Roman conversions
#include <iostream.h>
#include <string.h>
#include "Roman3.h"

#define NELEMS(A) (sizeof(A) / sizeof(A[0]))

static const char *rom[] = {
	"Z", "MZ", "W", "MW", "M", "CM", "D", "CD", "C", "XC",
	"L", "XL", "X", "IX", "V", "IV", "I" };

static const int decn[] = { 10000, 9000, 5000, 4000, 1000, 900, 500, 
				400, 100,   90,   50,   40,   10,   9,   5,   4,   1 };

void Roman::convert_Roman() {
	s[0] = '\0';
	int num = value;
	for (int i = 0; num; ) {
		while (decn[i] - num > 0)
			i++;
		strcat(s, rom[i]);
		num -= decn[i];
	}
}

int Roman::convert_decimal(const char *ps) {
	int num = 0;
	int index = 0;
	for (int i = 0; i < strlen(ps); i++, index++) {
			for (;index < NELEMS(rom); index++)
				if (ps[i] == rom[index][0])
					break;
			if (index == NELEMS(rom))
				throw RomanError(ps);
			if (ps[i] == 'M') {
				if (strncmp(ps+i, rom[index], 2) == 0) i++;
				if (strncmp(ps+i, rom[index+2], 2) == 0) i++,index=3;
				if (strncmp(ps+i, "MMM", 3) == 0) 
					i+=2, index = 4, num += 2*decn[index];
				else if (strncmp(ps+i, "MM", 2) == 0) 
					i++, index = 4, num += decn[index];
			}
			else if (ps[i] == 'C') {
				index = 8;
				if (strncmp(ps+i, "CM", 2) == 0) i++, index = 5;
				if (strncmp(ps+i, "CD", 2) == 0) i++, index = 7;
				if (strncmp(ps+i, "CCC", 3) == 0) 
					i+=2, num += 2*decn[index];
				else if (strncmp(ps+i, "CC", 2) == 0) 
					i++, num += decn[index];
			}
			else if (ps[i] == 'X') {
				index = 12;
				if (strncmp(ps+i, "XC", 2) == 0) i++, index = 9;
				if (strncmp(ps+i, "XL", 2) == 0) i++, index = 11;
				if (strncmp(ps+i, "XXX", 3) == 0) 
					i+=2, num += 2*decn[index];
				else if (strncmp(ps+i, "XX", 2) == 0) 
					i++, num += decn[index];
			}
			else if (ps[i] == 'I') {
				index = 16;
				if (strncmp(ps+i, "IX", 2) == 0) i++, index = 13;
				if (strncmp(ps+i, "IV", 2) == 0) i++, index = 15;
				if (strncmp(ps+i, "III", 3) == 0) 
					i+=2, num += 2*decn[index];
				else if (strncmp(ps+i, "II", 2) == 0) 
					i++, num += decn[index];
			}
			num += decn[index];
	}
	return num;
}

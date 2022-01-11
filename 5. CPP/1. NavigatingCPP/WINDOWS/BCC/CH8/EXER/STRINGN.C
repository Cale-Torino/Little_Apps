// StringN.C - StringN implementation
#include <iostream.h>
#include <iomanip.h>
#include <ctype.h>
#include "StringN.h"

StringN::StringN(const StringN & s1) {		// copy constructor
	len = s1.len;
	s = new char[len];
	memcpy(s, s1.s, len);						// copy data (including NULL bytes)
}

void StringN::print() const {
	cout << oct << setiosflags(ios::showbase);
	for (int i = 0; i < len; i++)
		if (isprint(s[i]) || s[i] == '\n')
			cout << s[i];
		else
			cout << '\\' << static_cast<int>(s[i]);
	cout << dec << resetiosflags(ios::showbase);
}

// StringN.C - StringN implementation
#include <iostream.h>
#include <ctype.h>
#include "StringN.h"

StringN::StringN(const StringN & s1) {		// copy constructor
	len = s1.len;
	s = new char[len];
	memcpy(s, s1.s, len);						// copy data (including NULL bytes)
}

void StringN::print() const {
	long save1 = cout.setf(ios::showbase);						// save state
	long save2 = cout.setf(ios::oct, ios::basefield);		// save state

	for (int i = 0; i < len; i++)
		if (isprint(s[i]) || s[i] == '\n')
			cout << s[i];
		else
			cout << '\\' << static_cast<int>(s[i]);
	cout.setf(save2, ios::basefield);							// restore state
	cout.setf(save1);													// restore state
}

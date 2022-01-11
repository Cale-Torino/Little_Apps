// ex1.c - frequency counts
#include <iostream.h>

int main()
{
	int ch, total, upper, lower, digits, other;
	total = upper = lower = digits = other = 0;

	cout << "Input a line of characters: ";
	while ((ch = cin.get()) != '\n') {
		total++;
		if (ch >= 'A' && ch <= 'Z')					// uppercase leter?
			upper++;
		else if (ch >= 'a' && ch <= 'z')				// lowercase letter?
			lower++;
		else if (ch >= '0' && ch <= '9')				// digit?
			digits++;
		else													// other
			other++;
	}
	cout << upper << " uppercase, " << lower << " lowercase, " 
		<< digits << " digits, "
		<< other << " others" << endl;
	cout << total << " characters total" << endl;
	return 0;
}

/************************************************************************

$ ex1
Input a line of characters: Hello There, 123 (@)
2 uppercase, 8 lowercase, 3 digits, 7 others
20 characters total

*/

// switch1.c - switch construct
#include <iostream.h>

int main()
{
	unsigned int num;
	cout << "Input an integer: ";
	cin >> num;

	switch (num) {
		case 0:														// 00
			cout << "both bits are off" << endl;
			break;
		case 1:														// 01
			cout << "bit 0 is on" << endl;
			break;
		case 2:														// 10
			cout << "bit 1 is on" << endl;
			break;
		case 3:														// 11
			cout << "bits 1,0 are on" << endl;
			break;
		default:
			cerr << num << " is an illegal two bit value" << endl;
			break;
	}
	return 0;
}

/*************************************************************************

$ switch1
Input an integer: 3
bits 1,0 are on

$ switch1
Input an integer: 100 
100 is an illegal two bit value

*/

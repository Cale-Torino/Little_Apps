// avg1.c - average() function with exceptions
#include <iostream.h>
#include <stdlib.h>

template <class TYPE>								// library function
TYPE avg(const TYPE *buf, unsigned int len) {
	if (len == 0)
		throw "avg: array length is zero";
	TYPE sum = 0;
	for (int i = 0; i < len; i++)
		sum += buf[i];
	return sum / len;
}

double calc_avg(unsigned int len) {
	const unsigned int max = 6;
	double b[max] = { 1.2, 2.2, 3.3, 4.4, 5.5, 6.6 };
	if (len > max) {
		cerr << "calc_avg: Using length default of " << max << endl;
		len = max;
	}
	try {
		return avg(b, len);						// calculate average
	}
	catch (char *msg) {							// catch handler
		cerr << msg << endl;
		cerr << "calc_avg: Using length default of " << max << endl;
		return avg(b, max);						// use max for average
	}
}

int main(int argc, const char *argv[])
{
	if (argc == 1) {
		cerr << argv[0] << " length" << endl;
		return 1;
	}
	unsigned int n =atoi(argv[1]);
	cout << calc_avg(n) << endl;
	return 0;
}

/********************************************************

$ avg1 6
3.86667

$ avg1 10
calc_avg: Using length default of 6
3.86667

$ avg1 0
avg: array length is zero
calc_avg: Using length default of 6
3.86667

*/

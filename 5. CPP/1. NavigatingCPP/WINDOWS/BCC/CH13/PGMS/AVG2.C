// avg2.c - average() function with rethrows
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
	if (len > max)
		throw "calc_avg: array length is greater than 6";
	try {
		return avg(b, len);						// calculate average
	}
	catch (char *msg) {							// catch handler
		cerr << "calc_avg: length must be between 1 and 6" << endl;
		throw;										// rethrow
	}
}

double do_avg(unsigned int n) {
	try {
		return calc_avg(n);
	}
	catch (char *msg) {							// catch handler
		cerr << msg << endl;
		cout << "Input another length: ";
		cin >> n;									// input another length
		return do_avg(n);							// try again
	}
}

int main(int argc, const char *argv[])
{
	if (argc == 1) {
		cerr << argv[0] << " length" << endl;
		return 1;
	}
	unsigned int n =atoi(argv[1]);
	cout << do_avg(n) << endl;
	return 0;
}

/********************************************************

$ avg2 6
3.86667

$ avg2 10
calc_avg: array length is greater than 6
Input another length: 6
3.86667

$ avg2 0
calc_avg: length must be between 1 and 6
avg: array length is zero
Input another length: 0
calc_avg: length must be between 1 and 6
avg: array length is zero
Input another length: 10
calc_avg: array length is greater than 6
Input another length: 6
3.86667

*/

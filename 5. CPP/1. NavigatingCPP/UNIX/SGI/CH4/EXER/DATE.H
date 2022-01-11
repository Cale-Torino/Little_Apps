#ifndef DATEH
#define DATEH
// Date.h - Date interface
#include <string.h>

class DateErr {
private:
	char buf[80];
public:
	DateErr(const char *msg) { strcpy(buf, msg); }
	void response() const {
		cerr << buf << endl;
	}
};

class Date {
private:
	int cmonth, cday, cyear;
	int mdays(int) const;
	bool leapyear() const;
	void setmon(int);
	void setday(int, int);
	void setyear(int);
public:
// Constructors
	Date();
	Date(int, int, int);
// Member functions
	void print() const;
	void set(int, int, int);
	int month() const;
	void month(int);
	int day() const;
	void day(int);
	int year() const;
	void year(int);
	void tomorrow() const;
	void yesterday() const;
};
#endif

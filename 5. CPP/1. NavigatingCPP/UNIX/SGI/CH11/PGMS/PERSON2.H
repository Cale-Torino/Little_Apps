#ifndef PERSONH
#define PERSONH
// Person2.h - Person class interface - overrides output() in Student
#include "String.h"

class Person {
private:
	String firstname;
	String lastname;
	String soc_sec_num;
public:
	Person(const String & f, const String & ln, const String & ss) :
		firstname(f), lastname(ln), soc_sec_num(ss) { }
	void output(ostream & os) const { 
		os << lastname << ", " << firstname << " (" << soc_sec_num << ")"
			<< endl;
	}
	String get_name() const { return firstname - lastname; }
	String get_ssn() const { return soc_sec_num; }
};

class Student : public Person {
private:
	String major;
	double gpa;
public:
	Student(const Person & p, const String & ma, double g) :
		Person(p), major(ma), gpa(g) { }
	Student(const String & f, const String & ln, const String & ss,
		const String & ma, double g) : Person(f, ln, ss), major(ma), gpa(g) { }
	void output(ostream & os) const { 
		Person::output(os);
		os << major << ": " << gpa << endl; 
	}
	String get_major() const { return major; }
	double get_gpa() const { return gpa; }
};
#endif

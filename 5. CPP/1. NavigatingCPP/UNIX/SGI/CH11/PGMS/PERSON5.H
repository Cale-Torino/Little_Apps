#ifndef PERSONH
#define PERSONH
// Person5.h - Mixing access levels with virtual functions (bad)
#include "String.h"

class Person {
protected:
   String first;
	String lastname;
	String soc_sec_num;
public:
	Person(const String & f, const String & l, const String & ss) :
	   first(f), lastname(l), soc_sec_num(ss) { }
   virtual ~Person() { cout << "Person destructor" << endl; }
	virtual void output(ostream & os) const {
		 os << lastname << ", " << first << " (" << soc_sec_num << ")" << endl;
	}
};

class Student : public Person {
private:
	String major;
	double gpa;
	void output(ostream & os) const {
		os << soc_sec_num << " (" << lastname << ", " << first << ") "
		 			<< endl;
		os << major << ": " << gpa << endl; 
	}
public:
	 Student(const Person& p, const String& ma, const double& g) :
		  Person(p), major(ma), gpa(g) { }
	 Student(const String & f, const String & ln, const String & ss,
		  const String & ma, double g): Person(f, ln, ss), major(ma), gpa(g) 
		  { }
	 ~Student() { cout << "Student destructor" << endl; }
	 double get_gpa() const { return gpa; }
};

inline ostream & operator<<(ostream & os, const Person & p)
{
   p.output(os);               // virtual call
	return os;
}
#endif

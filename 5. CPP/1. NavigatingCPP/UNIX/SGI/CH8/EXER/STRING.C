// String.C - String class implementation, reference counts
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

String_ref::String_ref(int size) {						// length constructor
	s = new char[(len = size) + 1];
	s[len] = '\0'; 
	refcount = 1;
}

String_ref::String_ref(const char *p) {				// char string constructor
	s = new char[(len = strlen(p)) + 1];  
	strcpy(s, p);
	refcount = 1;
}

String_ref::String_ref(const String_ref & sr1, const String_ref & sr2) {
	s = new char[(len = sr1.len + sr2.len) + 1];
	strcpy(s, sr1.s);		strcpy(s + sr1.len, sr2.s); 
	refcount = 1; 
}

String_ref::String_ref(const String_ref & sr1, 
					const String_ref & sr2, char c) {
	s = new char[(len = sr1.len + sr2.len + 1) + 1];
	strcpy(s, sr1.s);		s[sr1.len] = c; 
	strcpy(s + sr1.len + 1, sr2.s); 
	refcount = 1; 
}

String::String(int size) {							// private constructor
	pref = new String_ref(size);
}

String::String(const char *p) { 					// char string constructor
	pref = new String_ref(p);
}

void String::copy(const String & s1) { 
	pref = s1.pref;									// assign same node
	pref->refcount++;									// increase reference count
}

void String::newcopy() {							// copy on write
	pref->refcount--;
	pref = new String_ref(pref->s);
}

void String::free() {
	if (--pref->refcount == 0)					// decrement ref count, is it 0?
		delete pref;								// free reference pointer
}

String operator+(const String & s1, const String & s2) {
	String result(s1);							// copy constructor
	result += s2;									// call operator+=()
	return result;									// return result by value
}

String operator-(const String & s1, const String & s2) {
	String result(s1);							// copy constructor
	result -= s2;									// call operator-()=
	return result;									// return result by value
}

String operator-(const char * s1, const String & s2) {
	return static_cast<String>(s1) - s2;
}

String operator-(const String & s1, const char * s2) {
	return s1 - static_cast<String>(s2);
}

String operator+(const char * s1, const String & s2) {
	return static_cast<String>(s1) + s2;
}

String operator+(const String & s1, const char * s2) {
	return s1 + static_cast<String>(s2);
}

String & String::operator+=(const String & s1) { 
	String_ref *newrp = new String_ref(*pref, *s1.pref);
	free();
	pref = newrp;
	return *this;
}

String & String::operator-=(const String & s1) {
	String_ref *newrp = new String_ref(*pref, *s1.pref, ' ');
	free();
	pref = newrp;
	return *this;
}

char & SubScript::operator=(char c) {						// lvalue
	if (str.pref->refcount > 1)
		str.newcopy();												// copy on write
	str.pref->s[index] = c; 
	return str.pref->s[index];
}

char & SubScript::operator=(const SubScript & s1) {	// lvalue
	if (str.pref->refcount > 1)
		str.newcopy();												// copy on write
	str.pref->s[index] = s1.str.pref->s[s1.index]; 
	return str.pref->s[index];
}

SubScript::operator char () const {							// rvalue
	return str.pref->s[index];
}

void String::range(int index) const {
	if (index < 0 || index >= length())						// out of bounds?
		throw StringError(index);								// range error
}

SubScript String::operator[](int index) { 
	range(index);										// range check 
	return SubScript(*this, index);				// create SubScript
}

const char & String::operator[](int index) const {
	range(index);									// range check 
	return pref->s[index];						// return const character reference
}

ostream & operator<<(ostream & os, const String & s1) {
	return os << static_cast<const char *>(s1);
}

istream & operator>>(istream & is, String & s1) {
	const int bufmax = 256;						// maximum length
	static char buffer[bufmax];				// array buffer
	is.getline(buffer, bufmax);				// input into buffer
	s1 = buffer;									// String assignment
	return is;										// return istream
}

String & SubString::operator=(const String & s1) {					// lvalue
	if (str.pref->refcount > 1)
		str.newcopy();											// make new String object
	int len = (s1.length() < count) ? s1.length() : count;
	strncpy(str.pref->s + pos, s1.pref->s, len);
	return str;
}

String & SubString::operator=(const SubString & s1) {				// lvalue
	if (str.pref->refcount > 1)
		str.newcopy();											// make new String object
	int len = (s1.count < count) ? s1.count : count;
	strncpy(str.pref->s + pos, s1.str.pref->s + s1.pos, len);
	return str;
}

SubString::operator String () const {					// rvalue
	String result(count);									// private String constructor
	strncpy(result.pref->s, str.pref->s + pos, count);
	return result;
}

void String::poscount(int pos, int count) const {
	if (pos < 0 || pos > length() - 1 || 
				count <= 0 || count + pos > length())
		throw StringError(pos, count, *this);
}

SubString String::operator()(int pos, int count) {			// Substrings
	poscount(pos, count);									// check position, count
	return SubString(*this, pos, count);				// create SubString
}

const String String::operator()(int pos, int count) const {			// Substrings
	poscount(pos, count);						// check position, count
	String snew(count);							// private String constructor
	strncpy(snew.pref->s, pref->s + pos, count);			// copy substrinig
	return snew;									// return const substring value
}

bool operator==(const String & s1, const String & s2) { 
	return strcmp(s1, s2) == 0; 
}
bool operator==(const char *s1, const String & s2) { 
	return strcmp(s1, s2) == 0; 
}
bool operator==(const String & s1, const char *s2) { 
	return strcmp(s1, s2) == 0; 
}
bool operator!=(const String & s1, const String & s2) { 
	return strcmp(s1, s2) != 0; 
}
bool operator!=(const char *s1, const String & s2) { 
	return strcmp(s1, s2) != 0; 
}
bool operator!=(const String & s1, const char *s2) { 
	return strcmp(s1, s2) != 0; 
}
bool operator>(const String & s1, const String & s2) { 
	return strcmp(s1, s2) > 0; 
}
bool operator>(const char *s1, const String & s2) { 
	return strcmp(s1, s2) > 0; 
}
bool operator>(const String & s1, const char *s2) { 
	return strcmp(s1, s2) > 0; 
}
bool operator>=(const String & s1, const String & s2) { 
	return strcmp(s1, s2) >= 0; 
}
bool operator>=(const char *s1, const String & s2) { 
	return strcmp(s1, s2) >= 0; 
}
bool operator>=(const String & s1, const char *s2) { 
	return strcmp(s1, s2) >= 0; 
}
bool operator<(const String & s1, const String & s2) { 
	return strcmp(s1, s2) < 0; 
}
bool operator<(const char *s1, const String & s2) { 
	return strcmp(s1, s2) < 0; 
}
bool operator<(const String & s1, const char *s2) { 
	return strcmp(s1, s2) < 0; 
}
bool operator<=(const String & s1, const String & s2) { 
	return strcmp(s1, s2) <= 0; 
}
bool operator<=(const char *s1, const String & s2) { 
	return strcmp(s1, s2) <= 0; 
}
bool operator<=(const String & s1, const char *s2) { 
	return strcmp(s1, s2) <= 0; 
}

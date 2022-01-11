// FString1.h - Fixed String class, constant expression parameters
#include <iostream.h>
#include <stdio.h>
#include <string.h>

class FStringError {
private:
	char buf[80];
public:
	FStringError(const char *p, int size) {
		sprintf(buf, 
			"FString: length of %d is too small for \"%s\"", size, p);
	}
	FStringError(int index) {
		sprintf(buf, "FString: index %d out of bounds", index);
	}
	void response() const { cerr << buf << endl; }
};

template <int size>
class FString {
private:
	char s[size+1];						// fixed length String plus NULL
	int len;									// length
	void range(int) const;				// subscript range check
public:
	FString(const char *p = "") { 
		if (strlen(p) > size)
			throw FStringError(p, size);
		strcpy(s, p);
		len = strlen(p);
	}
	operator const char * () const { return s; }
	char & operator[](int);							// non-const subscripts
	const char & operator[](int) const;			// const subscripts
	int length() const { return len; }
};

template <int size>
inline void FString<size>::range(int index) const {
	if (index < 0 || index >= length())			// out of bounds?
		throw FStringError(index);					// range error
}

template <int size>
inline char & FString<size>::operator[](int index) { 
	range(index);							// range check 
	return s[index];						// return character reference
}

template <int size>
inline const char & FString<size>::operator[](int index) const {
	range(index);							// range check 
	return s[index];						// return const character reference
}

template <int size>
inline ostream & operator<<(ostream & os, const FString<size> & s1) {
	return os << static_cast<const char *>(s1);
}

template <int size>
inline istream & operator>>(istream & is, FString<size> & s1) {
	static char buffer[size];					// array buffer
	is.getline(buffer, size);					// input into buffer
	s1 = buffer;									// FString assignment
	return is;										// return istream
}

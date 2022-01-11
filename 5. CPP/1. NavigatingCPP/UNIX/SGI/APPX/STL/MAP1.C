// map1.C - STL map container
#include <iostream.h>
#include <map.h>
#include <mstring.h>

//using namespace std;

struct less_string {					// function object
	bool operator()(const string & s1, const string & s2) const {
		return s1 < s2;
	}
};

typedef map<string, long, less_string> zipmap;

ostream & operator<<(ostream & os, const zipmap & z) {
	zipmap::const_iterator index_pair = z.begin();
	for (int i = 0; index_pair != z.end(); index_pair++, i++)
		os << i << ": [" << (*index_pair).first << "] : " 
				<< (*index_pair).second << endl;
	return os;
}

void display_zip(zipmap & z, const string & name) {
	if (z.count(name))
		cout << name << "'s zipcode is " << z[name] << endl;
	else
		cout << "Could not find entry " << name << endl;
}

int main()
{
	zipmap zip;									// create zipcode map
	zip["tom"] = 92019;							// assign zipcode
	zip["paul"] = 92024;						// assign zipcode
	zip["steve"] = 92119;						// assign zipcode
	cout << "size of zip array is " << zip.size() << endl;
	cout << zip;								// display zipcode map
	cout << "zip.count(\"paul\") = " << zip.count("paul") << endl;
	display_zip(zip, "steve");					// OK
	display_zip(zip, "fritz");					// error, "fritz" not in  map
	
	zipmap num1;								// create zipcode map
	num1 = zip;									// map assignment
		 
	const zipmap num2 = num1;					// copy initialization
	return 0;
}

/*********************************************************************

$ map1
size of zip array is 3
0: [paul] : 92024
1: [steve] : 92119
2: [tom] : 92019
zip.count("paul") = 1
steve's zipcode is 92119
Could not find entry fritz

*/

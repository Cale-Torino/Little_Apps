// binit.C - static const array initialization
#include <iostream.h>
#include <stdlib.h>
#include <string.h>

struct hue {
	char s[20];
	int scale;
	float val;
};

template <int len = 3>
class Colors {
private:
	static hue buf[len];							// static array
public:
	Colors() { }									// default constructor
	void colorinfo() const;						// display colors
	void setcolor(char *, int, float);		// set colors
};

template <int len>
void Colors<len>::colorinfo() const {
	for (int i = 0; i < len; i++)
		cout << buf[i].scale << ' ' << buf[i].val << ' ' << buf[i].s << endl;
}

template <int len>
void Colors<len>::setcolor(char *c, int s, float v) {
	static int index = 3;
	strcpy(buf[index].s, c);
	buf[index].scale = s;
	buf[index++].val = v;
}

template <int len>
hue Colors<len>::buf[len] = {				// initialize static array
	{ "red", 1, 1.2 },
	{ "blue", 2, 3.4 },
	{ "green", 3, 5.6 }
};

int main()
{
	Colors<5> m1;							// static array length is 5
	m1.setcolor("yellow", 4, 7.8);
	m1.setcolor("brown", 5, 8.9);
	m1.colorinfo();
	cout << endl;

	Colors<> m2;							// default static array length of 3
	m2.colorinfo();

	//Colors<2> m3;						// error, too short for initializers
	return 0;
}

/****************************************************************************

$ binit
1 1.2 red
2 3.4 blue
3 5.6 green
4 7.8 yellow
5 8.9 brown

1 1.2 red
2 3.4 blue
3 5.6 green

*/

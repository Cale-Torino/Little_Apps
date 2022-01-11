// maxlen.c - String max word length function
#include <iostream.h>
#include <string.h>

const char *English[3] = { "one", "two", "three" };
char *Spanish[3] = { "uno", "dos", "tres" };

int maxwordlen(const char * const * ps, int len) {
	int wlen, maxlen = 0;
	for (int i = 0; i < len; i++)
		if ((wlen = strlen(ps[i])) > maxlen)
			maxlen = wlen;
	return maxlen;
}

int main()
{
	cout << "English: " << maxwordlen(English, 3) << endl;
	cout << "Spanish: " << maxwordlen(Spanish, 3) << endl;
	return 0;
}

/**********************************************************************

$ maxlen 
English: 5
Spanish: 4

*/

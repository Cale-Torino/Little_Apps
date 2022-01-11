// cast1.c - constant casts
#include <iostream.h>

int plot(char *) { return 0; }			// older C function
const char *m;									// pointer to constant char

int main()
{
	plot(const_cast<char *>(m));			// cast away const to call function
	return 0;
}

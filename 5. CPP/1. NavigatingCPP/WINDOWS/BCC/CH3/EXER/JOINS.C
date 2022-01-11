// joins.C - joins strings with new/delete operators
#include <iostream.h>
#include <string.h>

int main()
{
	char *join(const char*, const char*); 
	char *joinb(const char*, const char*);
	char *p1, *p2;

	cout << (p1 = join("alpha", "bet")) << ' ' 
			<< (p2 = joinb("duck", "soup")) << endl;

	delete [] p1;     delete [] p2;
   return 0;
}

char *join(const char *s1, const char *s2)        // join s1, s2 
{
	char *pnew = new char[strlen(s1) + strlen(s2) + 1];
	return strcat(strcpy(pnew, s1), s2);


}

char *joinb(const char *s1, const char *s2)     // join s1, s2 with blank
{
	char *pnew = new char[strlen(s1) + strlen(s2) + 2];
	return strcat(strcat(strcpy(pnew, s1), " "), s2);
}

/*************************************************************************

$ joins
alphabet duck soup

This program has a design flaw because join() and joinb() allocate
memory with operator new but do not release memory. 
That task falls to main(), which must call operator delete to
prevent memory leaks.


*/

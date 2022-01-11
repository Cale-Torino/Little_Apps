// fruits.C - arrays of pointers
#include <iostream.h>
#include <ctype.h>

#define NELEMS(A) (sizeof(A) / sizeof A[0])

const char *domestic[] = {								// array of pointers
	"avocado", "figs", "lemons",
	"oranges", "strawberries", "watermelon"
};

const char *tropical[] = {								// array of pointers
	"bananas", "coconuts", "guava",
	"kiwi", "mangos", "papayas"
};

const char **fruits[] = {								// array of pointers to pointers
	domestic, tropical 
};
enum FruitType { Domestic, Tropical, NoFruit };

const int NumFruits = NELEMS(domestic) + NELEMS(tropical);

int main()
{
	int nf;
	cout << "NumFruits = " << NumFruits << endl;
	for (int ft = Domestic; ft < NoFruit; ft++) {
		switch (ft) {
			case Domestic: 	cout << "domestic:" << endl;
							nf = NELEMS(domestic);
							break;
			case Tropical: 	cout << "tropical:" << endl;
							nf = NELEMS(tropical);
							break;
		}
		for (int i = 0; i < nf; i++)
			cout << '\t' << static_cast<char>(toupper(*fruits[ft][i])) 
					<< " for " << *(fruits[ft] + i) << endl;
	}
	return 0;
}

/**********************************************************************

$ fruits 
NumFruits = 12
domestic:
	A for avocado
	F for figs
	L for lemons
	O for oranges
	S for strawberries
	W for watermelon
tropical:
	B for bananas
	C for coconuts
	G for guava
	K for kiwi
	M for mangos
	P for papayas

*/

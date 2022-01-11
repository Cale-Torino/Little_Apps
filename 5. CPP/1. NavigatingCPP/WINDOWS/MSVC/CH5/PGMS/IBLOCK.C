// iblock.c - static const data members
#include <iostream.h>

class IBlock {
private:
	int *p;
	int len;
	static const int max;
public:
	explicit IBlock(int size = max) { p = new int[len = size]; }
	~IBlock() { delete [] p; }
	int getlength() const { return len; }
};

const int IBlock::max = 80;

int main()
{
	IBlock m;
	cout << m.getlength() << endl;
	IBlock n(100);
	cout << n.getlength() << endl;
	return 0;
}

/*****************************************************************

$ iblock
80
100

*/

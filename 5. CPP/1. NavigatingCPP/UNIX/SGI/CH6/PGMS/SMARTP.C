// smartp.c - smart pointer, overloading ->
#include <iostream.h>
#include <string.h>

class Graph {
public:
	Graph() { }
	void plot(double x, double y) { cerr << "plot: " << x << ' ' << y << endl; }
};

class GraphPtr {
private:
	const char *id;
	int count;
	Graph *pg;
public:
	GraphPtr(const char *s) : id(s) {
		count = 0;
		pg = new Graph;
	}
	~GraphPtr() { delete pg; }
	Graph *operator->() {
		cerr << id << ": " << ++count << endl;
		return pg;
	}
};

int main()
{
	GraphPtr g("servo");
	g->plot(3.4, -55.8);
	g->plot(5.6, 8.9);

	GraphPtr h("curve");
	h->plot(1.2, 6.8);
	h->plot(5.5, 7.7);
	return 0;
}

/**********************************************************************

$ smartp 
servo: 1
plot: 3.4 -55.8
servo: 2
plot: 5.6 8.9
curve: 1
plot: 1.2 6.8
curve: 2
plot: 5.5 7.7

*/

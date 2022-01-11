// nest.c - template nested classes
#include <iostream.h>
#include "Fifo.h"
#include "String.h"

template <class TYPE>
class Scheduler {									// enclosing class
private:
	class Task {									// nested class
	public:											// public access
		TYPE *pt;									// pointer to type of Task
		int priority;								// Task priority
		Task(TYPE *p = 0, int pr = 0) : 		// build Task
				pt(p), priority(pr) { }
		void suspend(int);						// suspend Task
	};
	Fifo<Task> q;									// queue of Tasks
public:
	Scheduler(int ntasks) : q(ntasks) { }
	void insert(TYPE *p) { 
		Task m(p);									// create Task 
		q.write(m);									// write Task into queue
  	}
	void freedata();								// free user pointers
};

template <class TYPE>
void Scheduler<TYPE>::freedata() {
	while (!q.empty())
		delete q.read().pt;						// delete data pointer
}

class Printer { 
private:
	String name;
public:
	Printer(const String & n) : name(n) { }
};

int main()
{
	Scheduler<Printer> s(10);
	Printer *pt1 = new Printer("remote");
	Printer *pt2 = new Printer("local");
	s.insert(pt1);
	s.insert(pt2);
	s.freedata();									// free Printers
	return 0;
}

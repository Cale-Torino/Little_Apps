// fclass.c - template friend classes
#include <iostream.h>

class User { } ;
class Bank { }; 

template <class TYPE>						// template forward reference
class Tree;

template <class TYPE>
class Node {
	friend class Debugger;					// non-template
	friend class Tree<TYPE>;				// one-to-one template
	//template <class T>						// one-to-many template
	//friend class Network;					
private:
	TYPE d;										// holds data
	Node<TYPE> *left;							// pointer to left Node
	Node<TYPE> *right;						// pointer to right Node
	Node(const TYPE & data) : d(data) { left = right = 0; active = false; }
	bool active;
};

class Debugger {
private:
	Node<Bank> *table;
	Node<User> *symbol;
public:
	void run() { table->active = true; symbol->active = true; } 
	Debugger(const Bank & b, const User & u) { 
		table = new Node<Bank>(b);
		symbol = new Node<User>(u);
	}
	~Debugger() { delete table; delete symbol; }
};

template <class TYPE>
class Tree {
private:
	Node<TYPE> *root;
public:
	Tree() { root = 0; }
	void set(const TYPE & v) { root = new Node<TYPE>(v); root->active = true; }
	~Tree() { delete root; }
};

template <class TYPE>
class Network {
private:
	Node<TYPE> *root;
	Node<int> *names;
public:
	Network() { names = 0; root = 0; }
	//void reset(const TYPE & v) { 
		//root = new Node<TYPE>(v); root->active = false;
		//names = new Node<int>(10); names->active = false;
	//}
	~Network() { delete root; delete names; }
};

int main()
{
	Bank b;
	User u;
	Debugger d(b, u);
	d.run();

	Tree<User> t;
	t.set(u);

	Network<User> n;
	Network<Bank> m;
	//n.reset(u);
	//m.reset(b);
	return 0;
}

// Btree.h - Binary Tree interface
#include <iostream.h>

template <class TYPE> class BinaryTree;		// forward reference

template <class TYPE>
class Node {
	friend class BinaryTree<TYPE>;
private:
	Node *left;
	Node *right;
	TYPE data;											// data item
	Node(const TYPE & d) : data(d) { left = right = 0; }
};

template <class TYPE>
class BinaryTree {
private:
	Node<TYPE> *root;
	void (*ptrf)(TYPE &);
	void init() { root = 0; }									// initialize Tree
	void copyNode(const Node<TYPE> *node);
	void copy(const BinaryTree<TYPE> & tree)				// copy Tree
		{ if (tree.root) copyNode(tree.root); }
	void free() { if (root) removeNode(root); }
	void removeNode(Node<TYPE> *node);
	void applyNode(Node<TYPE> *node);
	void printNode(const Node<TYPE> *node) const;
public:
// Constructors
	BinaryTree() { init(); }
	BinaryTree(const BinaryTree<TYPE> & tree) {	init(); copy(tree); }
// Destructor
	~BinaryTree() { free(); }
// Modifiers
	BinaryTree<TYPE> & operator=(const BinaryTree<TYPE> & tree) {
		if (this != &tree) {
			free();
			copy(tree);
		}
		return *this;
	}
	int insert(const TYPE & value);
	void apply(void (*pf)(TYPE &));
// Selectors
	int lookup(const TYPE & value) const;
	void trace() const;
};

template<class TYPE>
void BinaryTree<TYPE>::removeNode(Node<TYPE> *node)
{
	if (node->left)
		removeNode(node->left);
	if (node->right)
		removeNode(node->right);
	delete node;
}

template<class TYPE>
int BinaryTree<TYPE>::insert(const TYPE & value)
{
	Node<TYPE> *current = root;
	if (current == 0) {									// first entry
		root = new Node<TYPE>(value);
		return 1;
	}
	while (1) {
		if (current->data == value)					// no duplicate entries
			return 0;
		else if (value < current->data) {			// check left side
			if (current->left) {							// is there a left side?
				current = current->left;
				continue;
			}
			// no left side, so insert node here at left
			current->left = new Node<TYPE>(value);
			return 1;
		}
		else  { // check right side
			if (current->right) {						// is there a right side?
				current = current->right;
				continue;
			}
			// no right side, so insert node here at right
			current->right = new Node<TYPE>(value);
			return 1;
		}
	}
}

template<class TYPE>
int BinaryTree<TYPE>::lookup(const TYPE & value) const
{
	Node<TYPE> *current = root;
	while (current) {
		if (value == current->data)
			return 1;
		else if (value < current->data)				// less, so check left
			current = current->left;
		else
			current = current->right;
	}
	return 0;												// can't find it!
}

template<class TYPE>
void BinaryTree<TYPE>::apply(void (*pf)(TYPE &))
{
	ptrf = pf;
	if (root) applyNode(root);
}

template<class TYPE>
void BinaryTree<TYPE>::applyNode(Node<TYPE> *node)
{
	// left side first:
	if (node->left)
		applyNode(node->left);
	(*ptrf)(node->data);
	// right side last:
	if (node->right)
		applyNode(node->right);
}

template<class TYPE>
void BinaryTree<TYPE>::trace() const
{
	if (root) printNode(root);
}

template<class TYPE>
void BinaryTree<TYPE>::printNode(const Node<TYPE> *node) const
{
	if (node->left)								// left side first
		printNode(node->left);
	cout << node->data << endl;				// root
	if (node->right)								// right side last:
		printNode(node->right);
}

template<class TYPE>
void BinaryTree<TYPE>::copyNode(const Node<TYPE> *node)
{
	if (node->left)								// left side first
		copyNode(node->left);
	insert(node->data);							// root
	if (node->right)								// right side last:
		copyNode(node->right);
}

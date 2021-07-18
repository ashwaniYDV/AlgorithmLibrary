#include <iostream>

using namespace std;

enum QueryType {Greater, Smaller, GreaterOrEqual, SmallerOrEqual}; 

template <class Data>
class Node {
	Data data;
	int subTreeSize;		// Number of nodes in the subtree
	int count;			// If there are multiple nodes with same 'data' value, we don't create
					// duplicate nodes. Instead, we increase 'count' by 1.
	Node<Data>* leftNode;
	Node<Data>* rightNode;
	
public:
	Node(Data value);
	~Node();
	void insert(Data value);
	int query(Data value, QueryType queryType);		// Count how many nodes in its
								// subtree are greater / smaller then "value"
};

template <class Data>
Node<Data>::Node(Data value) {
	data = value;
	subTreeSize = 1;		// The only node in the subtree is the Node itself
	count = 1;
	leftNode = rightNode = NULL;
}

template <class Data>
Node<Data>::~Node() {
	if (leftNode != NULL)
		delete leftNode;
	if (rightNode != NULL)
		delete rightNode;
}

template <class Data>
void Node<Data>::insert(Data value) {
	if (value < data) {
		if (leftNode == NULL)
			leftNode = new Node(value);
		else
			leftNode->insert(value);
	}
	else if (value > data) {
		if (rightNode == NULL)
			rightNode = new Node(value);
		else
			rightNode->insert(value);
	}
	else
		count++;
	
	subTreeSize++;		// A new node is added in the subtree
	
	// Duplicate node data are not allowed in a tree. if (value == data), we don't
	// allow any more recursion on the child nodes. But it will increase the subTreeSize and count of this node.
}

template <class Data>
int Node<Data>::query(Data value, QueryType queryType) {
	int result = 0;
	
	if (value < data) {
		if (leftNode != NULL)
			result += leftNode->query(value, queryType);
		if (queryType == Greater || queryType == GreaterOrEqual) {
			if (rightNode != NULL)
				result += rightNode->subTreeSize;	// All the nodes in the right subtree are greater than 'value'
			result += count;				// This node is also greater than 'value'
		}
	}
	else if (value > data) {
		if (rightNode != NULL)
			result += rightNode->query(value, queryType);
		if (queryType == Smaller || queryType == SmallerOrEqual) {
			if (leftNode != NULL)
				result += leftNode->subTreeSize;	// All the nodes in the left subtree are greater than 'value'
			result += count;				// This node is also smaller than 'value'
		}
	}
	else {
		if (queryType == GreaterOrEqual || queryType == SmallerOrEqual)
			result += count;
		
		if (queryType == Greater || queryType == GreaterOrEqual)
			if (rightNode != NULL)
				result += rightNode->subTreeSize;
		else
			if (leftNode != NULL)
				result += leftNode->subTreeSize;
	}
	
	return result; 
}

template <class Data>
class GSCTree {
	Node<Data> *root;
	
public:
	GSCTree() {root = NULL;}
	~GSCTree() { if (root != NULL) delete root; }
	void insert(Data value) {
		if (root == NULL) root = new Node<Data>(value); 
		else root->insert(value); 
	}
	
	int greaterCount(Data value) { return root->query(value, Greater); }
	int smallerCount(Data value) { return root->query(value, Smaller); }
	int greaterOrEqualCount(Data value) { return root->query(value, GreaterOrEqual); }
	int smallerOrEqualCount(Data value) { return root->query(value, SmallerOrEqual); }
};


int main() {
	const int SIZE = 10;
	int val[] = {4, 5, 2, 1, 5, 9, 1, 4, 7, 6};
	
	GSCTree<int> tree;
	for (int i = 0; i < SIZE; i++)
		tree.insert(val[i]);
		
	cout << tree.greaterCount(3) << endl;
	cout << tree.smallerCount(3) << endl;
	cout << tree.greaterOrEqualCount(3) << endl;
	cout << tree.smallerOrEqualCount(3) << endl;
	
	return 0;
}

/*
Binary Search Tree
------------------
A particular type of data structure that stores items in memory.
They allow fast lookup, addition and removal of items, and can be
used to implement either dynamic sets of items, or lookup tables
that allow finding an item by its key. 
------------------
Time Complexity : O(logn)
Space Complexity : O(n)
*/

#include <iostream>

using namespace std;

class node
{
public:
	char key;
	int data;

	node();
	node(char key, int data);

	BinarySearchTree *left;
	BinarySearchTree *right;
	node *parent;

	BinarySearchTree *mytree;
};

class BinarySearchTree
{
public:
	node *root;

	BinarySearchTree();
	BinarySearchTree(node *root);

	bool is_empty();

	node *search(char key);

	node *minimum();
	node *maximum();

	node *predecessor(node *x);
	node *successor(node *x);

	void insert(node *x);
	void remove(node *x);

	void set(char key, int value);
};

node::node(char key, int data){
	this->key = key;
	this->data = data;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
	this->mytree = NULL;
}

BinarySearchTree::BinarySearchTree(){
	this->root = NULL;
}

BinarySearchTree::BinarySearchTree(node *root){
	this->root = root;
}

bool BinarySearchTree::is_empty(){
	return root == NULL;
}

node *BinarySearchTree::search(char key){
	if (is_empty()){
		return NULL;
	}
	if (root->key > key){
		return root->left->search(key);
	} else if (root->key < key){
		return root->right->search(key);
	} else {
		return root;
	}
}

node *BinarySearchTree::minimum(){
	if (is_empty){
		return NULL;
	}
	if (root->left == NULL){
		return root;
	}
	return root->left->minimum();
}

node *BinarySearchTree::maximum(){
	if (is_empty){
		return NULL;
	}
	if (root->right == NULL){
		return root;
	}
	return root->right->minimum();
}

node *BinarySearchTree::predecessor(node *x){
	if (x->left != NULL){
		return x->left->maximum();
	}
	node *top = x->parent;
	while (top != NULL and top->key	> x->key){
		x = top;
		top = top->parent;
	}
	return top;
}

node *BinarySearchTree::successor(node *x){
	if (x->right != NULL){
		return x->right->minimum();
	}
	node *top = x->parent;
	while (top != NULL and top->key	< x->key){
		x = top;
		top = top->parent;
	}
	return top;
}

void BinarySearchTree::insert(node *x){
	if (is_empty()){
		node *n = new node(x->key, x->data);
		n->parent = NULL;
		n->mytree = this;
		root = n;
		return ;
	}

	node *current = root;

	while (true){
		if (x->key < current->key){
			if (current->left == NULL){
				BinarySearchTree *left = new BST();
				node *next = new node(x->key, x->data);
				next->parent = current;
				node->mytree = left;
				left->root = next;
				current->left = left;
				return ;
			} else {
				current = current->left->root;
			}
		} else if (x->key > current->key){
			if (current->right == NULL){
				BinarySearchTree *right = new BinarySearchTree();
				node *next = new node(x->key, x->data);
				next->parent = current;
				next->mytree = right;
				right->root = next;	
				current->right = right;
				return ;

			} else {
				current = current->right->root;
			}
		} else {
			return ;
		}
	}
}

void BinarySearchTree::remove(node *x)
{
	node *tmp;

	if (x->left == NULL and x->right == NULL){
		if (x->parent != NULL){
			if (x->parent->left != NULL and x->parent->left->root->key == x->key){
				x->parent->left = NULL;
			}
			else if (x->parent->right != NULL and x->parent->right->root->key == x->key){
				x->parent->right = NULL;
			}
		}

		delete x;
		return ;
	}

	if (x->left == NULL){
		tmp = x->right->root;
		if (x->parent != NULL){
			if (x->parent->left != NULL and x->parent->left->root->key == x->key){
				x->parent->left = tmp->mytree;
			}
			else if (x->parent->right != NULL and x->parent->right->root->key == x->key){
				x->parent->right = tmp->mytree;
			}
		}

		tmp->parent = x->parent;
		delete x;
		return ;
	}

	if (x->right == NULL){
		tmp = x->left->root;
		if (x->parent != NULL){
			if (x->parent->left != NULL and x->parent->left->root->key == x->key){
				x->parent->left = tmp->mytree;
			}
			else if (x->parent->right != NULL and x->parent->right->root->key == x->key){
				x->parent->right = tmp->mytree;
			}
		}

		tmp->parent = x->parent;
		delete x;
		return ;
	} else {
		tmp = successor(x);
		x->key = tmp->key;
		x->data = tmp->data;
		remove(tmp);
	}
}

void BinarySearchTree::set(char key, int value){
	if (search(key) != NULL){
		insert(new node(key, value));
	}
}
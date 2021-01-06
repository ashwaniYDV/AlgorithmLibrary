#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void printPostOrder(vector<int>::iterator, vector<int>::iterator, int);

int main()
{
	int in[] = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
	int pre[] = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};

	vector <int> inOrder(in, in+15); 
	vector <int> preOrder(pre, pre+15);
	int root;

	printPostOrder(inOrder.begin(), preOrder.begin(), inOrder.size());

	getchar();
	return 0;
}

void printPostOrder(vector<int>::iterator in, vector<int>::iterator pre, int n)
{
	/* The first element of vector preOrder is always root.
	* Searching the index that contains that root in vetcor inOrder to find the left and right subtrees. */
	int root = find(in, in+n, *pre) - in;

	// If left subtree is not empty, call recurrsively to print left subtree
	if (root != 0)
		printPostOrder(in, pre+1, root);

	// If right subtree is not empty, call recurrsively to print right subtree
	if (root != n-1)
		printPostOrder(in+root+1, pre+root+1, n-root-1);

	// Print root
	cout << *pre << " ";
}

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void inOrder(int, int, int);
void preOrder(int, int, int);
void postOrder(int, int, int);

vector <int> v;

int main()
{
	int n, root;
	
	n = 10;
	v.push_back(0); // Using the 1st index (index: 0) as Dummy. we wiil not use it.

	for(int i=1; i<=n; i++){
		v.push_back(i);
	}

	root = 1;
	int len = v.size()-1;

	inOrder( root, len, (len/2)+1 );
	printf("\n");
	preOrder( root, len, (len/2)+1 );
	printf("\n");
	postOrder( root, len, (len/2)+1 );
	printf("\n");

	getchar();
	return 0;
}

void inOrder(int root, int len, int d){

	if( root<=d && 2*root<=len ) inOrder( 2*root, len, d);
	printf("%d ", v[root]);
	if( root<=d && (2*root)+1<=len ) inOrder(2*root+1, len, d);

	return;
}

void preOrder(int root, int len, int d){
		
	printf("%d ", v[root]);
	if( root<=d && 2*root<=len ) preOrder( 2*root, len, d);
	if( root<=d && (2*root)+1<=len ) preOrder(2*root+1, len, d);

	return;
}

void postOrder(int root, int len, int d){
		
	if( root<=d && 2*root<=len ) postOrder( 2*root, len, d);
	if( root<=d && (2*root)+1<=len ) postOrder(2*root+1, len, d);
	printf("%d ", v[root]);

	return;
}
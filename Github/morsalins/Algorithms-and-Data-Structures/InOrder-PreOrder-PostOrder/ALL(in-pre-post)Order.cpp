#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void inOrder(int, int, int);
void preOrder(int, int, int);
void postOrder(int, int, int);

int arr[21];

int main()
{
    int n, root;
    n = 15;

    for(int i=1; i<=n; i++){
        arr[i] = i;
    }

    root = 1;
    inOrder( root, n, ((n/2)+1) );
    printf("\n");

    root = 1;
    preOrder( root, n, ((n/2)+1) );
    printf("\n");

    root = 1;
    postOrder( root, n, ((n/2)+1) );
    printf("\n");

	getchar();
	return 0;
}

void inOrder( int root, int n, int d ){

	if( root<=d && 2*root<=n ) inOrder( 2*root, n, d);
	printf("%d ", arr[root]);
	if( root<=d && (2*root)+1<=n ) inOrder(2*root+1, n, d);

	return;
}

void preOrder( int root, int n, int d ){

	printf("%d ", arr[root]);
	if( root<=d && 2*root<=n ) preOrder( 2*root, n, d);
	if( root<=d && (2*root)+1<=n ) preOrder(2*root+1, n, d);

	return;
}

void postOrder( int root, int n, int d ){

	if( root<=d && 2*root<=n ) postOrder( 2*root, n, d);
	if( root<=d && (2*root)+1<=n ) postOrder(2*root+1, n, d);
	printf("%d ", arr[root]);

	return;
}





#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void inOrder(int, int, int);

int arr[21];

int main()
{
	//int loop = 1;
	//while(loop<=20){
		int n, root;
		n = 15;

		for(int i=1; i<=n; i++){

			arr[i] = i;
		}

		root = arr[1];
		inOrder( root, n, ((n/2)+1) );
		
		//printf("\n");
		//getchar();
		//loop++;
	//}
	
	getchar();
	return 0;
}

void inOrder( int root, int n, int d ){
	
	//if( root > n ) return;

	if( root<=d && 2*root<=n ) inOrder( 2*root, n, d);
	printf("%d ", arr[root]);
	if( root<=d && (2*root)+1<=n ) inOrder(2*root+1, n, d);

	return;
}
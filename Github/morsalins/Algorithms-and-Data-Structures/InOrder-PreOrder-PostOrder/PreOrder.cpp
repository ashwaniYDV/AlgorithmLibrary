#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void preOrder(int, int, int);

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
		preOrder( root, n, ((n/2)+1) );
		
		//printf("\n");
		//getchar();
		//loop++;
	//}
	
	getchar();
	return 0;
}

void preOrder( int root, int n, int d ){
	
	//if( root > n ) return;

	printf("%d ", arr[root]);
	if( root<=d && 2*root<=n ) preOrder( 2*root, n, d);
	if( root<=d && (2*root)+1<=n ) preOrder(2*root+1, n, d);

	return;
}
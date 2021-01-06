#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void postOrder(int, int, int);

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
		postOrder( root, n, ((n/2)+1) );
		
		//printf("\n");
		//getchar();
		//loop++;
	//}
	
	getchar();
	return 0;
}

void postOrder( int root, int n, int d ){
	
	//if( root > n ) return;

	if( root<=d && 2*root<=n ) postOrder( 2*root, n, d);
	if( root<=d && (2*root)+1<=n ) postOrder(2*root+1, n, d);
	printf("%d ", arr[root]);

	return;
}
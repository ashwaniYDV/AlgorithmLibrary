#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[100+7][100+7];          // dp will store the result. Its size must be W*n ( dp[W][n] ). The ans will be stored at dp[W][n] index. 
int w[] = {0, 5, 4, 3, 2, 1};  // Weights of the elements. For Simplicity using index 0 as Dummy.
int c[] = {0, 1, 2, 3, 4, 5};  // Profit or Cost of The elements. For Simplicity using index 0 as Dummy.

void Calculate_KnapSack (int, int);
void init (int, int);

int main(){

	int W = 10; // Maximum weight.
	int n = sizeof(w) / sizeof(w[0]) - 1; // Number of total enements.

	Calculate_KnapSack(n, W );

	cout << "Maximum Profit: " << dp[n][W] << endl;

	return 0;
}

void Calculate_KnapSack (int n, int W) {

	init( W, n );  // Initialize 0 to the index of dp[row][col] if row=0 or col=0.

	for(int i=1; i<=n; i++){
		
		for(int j=1; j<=W; j++){
			
			if( w[i] <= j )
				dp[i][j] = max( dp[i-1][ j-w[i] ] + c[i], dp[i-1][j] );
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	
	return;
}

void init (int W, int n){

	int len = max(W, n);

	for(int i=0; i<=len+1; i++){
		if( i<=n+1 ) dp[i][0] = 0;
		if( i<=W+1 ) dp[0][i] = 0;
	}

	return;
}
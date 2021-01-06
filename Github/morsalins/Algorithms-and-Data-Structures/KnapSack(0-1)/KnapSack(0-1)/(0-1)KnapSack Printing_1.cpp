/* This 0-1 Knapsack implementation will find the result of both Maximum Profit and the objects that need to be choosen
 * dp[][] is the 2D array which calculate the profit. It's size must be W*n. The answer will be stored in dp[n][W] index.
 * 2D boolean Array take[][] just marks the object wheather it can be taken or not. But it doesn't mean that every object markes as true can be taken.

 * Object printing: We start the process of choosing/printing object from nth item and go down to 1 until n>0 or W>0. 
 * When the 1st time we find a object is true suppose take[i][W] == true (ith object within W weight) then we will take it. 
 * As we took it the knapsack will be filled by w[i] weight ( ith object's weight ).
 * So we will start finding from the next i-1 objects whose can be fit in W-w[i] weight. Then we continue this process until n>0 or W>0. 
 * See the recursive function printItems(int n, int W) carefully to understand the process. 
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[100+7][100+7];          // dp will store the result. Its size must be W*n ( dp[W][n] ). The ans will be stored at dp[W][n] index. 
bool take[100+7][100+7];	   // take will mark the objects true that can be taken. Its size must be W*n ( dp[W][n] ).  
int w[] = {0, 5, 4, 3, 2, 1};  // Weights of the elements. For Simplicity using index 0 as Dummy.
int c[] = {0, 5, 4, 3, 2, 1};  // Profit or Cost of The elements. For Simplicity using index 0 as Dummy.

void Calculate_KnapSack (int, int);
void init (int, int);
void printItems(int, int); 

int main(){

	int W = 10; // Maximum weight.
	int n = sizeof(w) / sizeof(w[0]) - 1; // Number of total enements.

	Calculate_KnapSack(n, W );

	cout << "Maximum Profit: " << dp[n][W] << "\n" << "Choosen Items: ";
	printItems(n, W);


	return 0;
}

void Calculate_KnapSack (int n, int W) {

	init( W, n );  // Initialize 0 to the index of dp[row][col] if row=0 or col=0.

	for(int i=1; i<=n; i++){
		
		for(int j=1; j<=W; j++){
			
			if( w[i] <= j && dp[i-1][ j-w[i] ] + c[i] > dp[i-1][j] ){  // Condition: dp[i-1][ j-w[i] ] + c[i] >= dp[i-1][j] is also acceptable. but it will 
				dp[i][j] = dp[i-1][ j-w[i] ] + c[i];				   // print	other possible correct solution if there are more than one solution.
				take[i][j] = true;  // We are taking it.
			}
			else{ 
				dp[i][j] = dp[i-1][j];
				take[i][j] = false; // We are not taking it.
			}
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

void printItems (int n, int W){

	if( n==0 || W == 0 ) return;
	
	if( take[n][W] ){
		printItems(n-1, W-w[n]);
		cout << n << " ";
	}
	else
		printItems(n-1, W);

	return;
}
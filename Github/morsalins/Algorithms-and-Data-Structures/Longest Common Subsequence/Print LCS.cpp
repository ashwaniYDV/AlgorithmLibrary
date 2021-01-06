#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100

int dp[MAX+5][MAX+5];
char path[MAX+5][MAX+5];

void LCS (string, string, int, int);
void printLCS(string, string, int, int);

int main()
{

	string X = "thisisatest"; 
	string Y = "testing123testing";

	int lenX = X.size();
	int lenY = Y.size();

	LCS(X, Y, lenX, lenY);

	cout << "The length of LCS is : " << dp[lenX][lenY] << endl;

	cout << "The LCS is: ";
	printLCS(X, Y, lenX, lenY);
	cout << endl;

	return 0;
}

void LCS(string X, string Y, int lenX, int lenY){
		
	memset( dp, 0, sizeof dp );

	for(int i=1; i<=lenX; i++){
		for(int j=1; j<=lenY; j++){
			
			if( X[i-1] == Y[j-1] ){
				dp[i][j] = dp[i-1][j-1] + 1;
				path[i][j] = 'D'; // D indicates - from the diagonal upper-left index. 
			}

			else if( dp[i-1][j] >= dp[i][j-1] ){
				dp[i][j] = dp[i-1][j];
				path[i][j] = 'U'; // U indicates - from the upper index.
			}

			else{
				dp[i][j] = dp[i][j-1];
				path[i][j] = 'L'; // L indeicates - from the left index.
			}
		}
	}

	return;
}

void printLCS(string X, string Y, int lenX, int lenY){

	if( lenX==0 || lenY==0 ) return;

	if( path[lenX][lenY] == 'D' ){
		printLCS( X, Y, lenX-1, lenY-1 );
		cout << X[lenX-1]; // or you can write - cout << Y[lenY-1];
	}

	else if( path[lenX][lenY] == 'U' )
		printLCS( X, Y, lenX-1, lenY );
	
	else if( path[lenX][lenY] == 'L' )
		printLCS( X, Y, lenX, lenY-1 );
	
	return;
}
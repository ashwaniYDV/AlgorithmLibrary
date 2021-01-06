#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100

int dp[MAX+5][MAX+5];

void LCS (string, string, int, int);

int main()
{

	string X = "thisisatest"; 
	string Y = "testing123testing";

	int lenX = X.size();
	int lenY = Y.size();

	LCS(X, Y, lenX, lenY);

	cout << dp[lenX][lenY] << endl;

	return 0;
}

void LCS(string X, string Y, int lenX, int lenY){
		
	memset( dp, 0, sizeof dp );

	for(int i=1; i<=lenX; i++){
		for(int j=1; j<=lenY; j++){
			
			if( X[i-1] == Y[j-1] )
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max( dp[i-1][j], dp[i][j-1] );

		}
	}

	return;
}
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 200

void editDistance (string, string, int, int);

int dp[MAX+5][MAX+5];

int main()
{
	string X = "axb";
	string Y = "yab";

	int lenX = X.size();
	int lenY = Y.size();

	editDistance(X, Y, lenX, lenY);

	for(int i=0; i<=lenX; i++){
		for(int j=0; j<=lenY; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

void editDistance (string X, string Y, int lenX, int lenY){

	for(int i=0; i <= max(lenX, lenY); i++){
		if( i<=lenX ) dp[i][0] = i;
		if( i<=lenY ) dp[0][i] = i;
	}
	
	for(int i=1; i<=lenX; i++){
		for(int j=1; j<=lenY; j++){

			if( X[i-1] != Y[j-1] )
				dp[i][j] = min( dp[i-1][j-1], min( dp[i-1][j], dp[i][j-1] ) ) + 1;

			else dp[i][j] = dp[i-1][j-1];
		}
	}

	return;
}
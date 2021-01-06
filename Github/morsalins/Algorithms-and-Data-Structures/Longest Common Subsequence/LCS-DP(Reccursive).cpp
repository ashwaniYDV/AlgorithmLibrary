#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100

int dp[MAX+5][MAX+5];

int LCS (int, int);

string X = "thisisatest"; 
string Y = "testing123testing";

int main()
{
	memset( dp, 0, sizeof dp );

	int lenX = X.size();
	int lenY = Y.size();

	cout << LCS(lenX, lenY) << endl;

	return 0;
}

int LCS( int lenX, int lenY ){
		
	if( lenX == 0 || lenY == 0 ) return 0;

	if( X[lenX-1] == Y[lenY-1] )
		return dp[lenX][lenY] = LCS( lenX-1, lenY-1) + 1; 
		
	return dp[lenX][lenY] = max( LCS(lenX-1, lenY), LCS(lenX, lenY-1) );

}
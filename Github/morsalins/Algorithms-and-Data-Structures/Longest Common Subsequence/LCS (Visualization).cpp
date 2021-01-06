#include <cstdio>
#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

#define MAX 100
#define pic pair <int, char>
#define ff first
#define ss second

pic dp[MAX+5][MAX+5];

void LCS (string, string, int, int);
void displayString (string, int);
void displayTable (int, int);

int main()
{

	string X = "thisisatest";
	string Y = "testing123testing";

	int lenX = X.size();
	int lenY = Y.size();

	LCS(X, Y, lenX, lenY);

	cout << "\nPress any key to Quit!....."; getchar();
	return 0;
}

void LCS(string X, string Y, int lenX, int lenY){
		
	memset( dp, 0, sizeof dp );

	for(int i=1; i<=lenX; i++){
		for(int j=1; j<=lenY; j++){
			
			cout << "String 1: ";
			displayString( X, i-1 );
			cout << endl;
			cout << "String 2: ";
			displayString( Y, j-1 );
			cout << endl << endl;

			if( X[i-1] == Y[j-1] ){
				dp[i][j].ff = dp[i-1][j-1].ff + 1;
				dp[i][j].ss = '\\';
			}
			else if( dp[i-1][j].ff >= dp[i][j-1].ff ){
				dp[i][j].ff = dp[i-1][j].ff;
				dp[i][j].ss ='^';
			}

			else{
				dp[i][j].ff = dp[i][j-1].ff;
				dp[i][j].ss = '<';
			}

			displayTable(lenX, lenY);
			Sleep(500);
			if( j<lenY )system("CLS");
		}
		if( i<lenX ) system("CLS");
	}

	return;
}

void displayString (string X, int len){

	for(int i=0; i<=len; i++) cout << X[i];

	return;
}

void displayTable (int n, int m){

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cout << dp[i][j].ss << dp[i][j].ff << "  ";
		}
		cout <<endl << endl;
	}

	return;
}
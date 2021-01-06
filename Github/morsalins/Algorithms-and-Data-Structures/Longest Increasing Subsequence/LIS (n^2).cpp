#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100 

int LIS (int); // parameter : size of the input array.

int A[] = {3, 2, 5, 4, 7, 8, 6, 10};
int dp[MAX+5];

int main()
{
	cout << LIS(8) << endl; // Sending the size of array A as parameter.

	return 0;
}

int LIS (int n) {

	int ans = 0;

	for(int i=0; i<n; i++){
		
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if( A[j] < A[i] )
				dp[i] = max( dp[i], dp[j] + 1 ); 
		}

		ans = max( ans, dp[i] );
	}

	return ans;
}
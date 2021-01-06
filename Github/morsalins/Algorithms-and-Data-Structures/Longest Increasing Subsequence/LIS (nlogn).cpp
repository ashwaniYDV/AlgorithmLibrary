#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100 
#define INF 0x7f7f7f7f

void LIS (int); // parameter : size of the input array.

int A[] = {3, 2, 5, 4, 7, 8, 10, 6};
int dp[MAX+5];

int main()
{
	 LIS(8); // Sending the size of array A as parameter.

	return 0;
}

void LIS (int n) {

	memset( dp, INF, sizeof dp );
	dp[0] = -INF;

	for(int i=0; i<n; i++){
		int j = upper_bound( dp, dp+n, A[i]) - dp;
		if( dp[j-1] < A[i] && A[i] < dp[j] )
			dp[j] = A[i];
	}

	return;
}
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100
#define pii pair <int, int>

pii LIS (int); // parameter : size of the input array.
void printPath (int);

int A[] = {3, 2, 5, 4, 7, 8, 6, 10};
int dp[MAX+5];
int path[MAX+5];

int main()
{
	pii ans = LIS(8);

	/* ans receives 2 values.
	 * ans.first is the LIS value.
	 * ans.second is the last element of LIS.
	 */

	cout << "LIS value: " << ans.first << endl;   // ans.first is the LIS value;
	cout << "The Sequence is: ";
	printPath( ans.second );   // ans.second is the last element of LIS.

	/*** The path or Sub-Sequence of LIS of a full sequence may not be unique. It may have many path. ***/

	return 0;
}

pii LIS (int n) {

	int ans = 0, last;

	for(int i=0; i<n; i++){

		dp[i] = 1;
		path[ A[i] ] = -1;

		for(int j=0; j<i; j++){
			if( A[j] < A[i] )
				if( dp[j]+1 > dp[i] ){
					dp[i] = dp[j] + 1;
					path[ A[i] ] = A[j];
				}
		}

		if( dp[i] > ans ){
			ans = dp[i];
			last = A[i];
		}
	}

	return pii(ans, last);
}

void printPath (int last){

	if( last == -1 ) return;

	printPath( path[last] );

	printf("%d ", last);

	return;
}

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <functional>
#include <map>
#include <cstring>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
#include <cctype>
#include <math.h>
#include <cstdlib>

using namespace std;

#define I64 long long int
#define INF 0x7f7f7f7f
#define pii pair<int, int>
#define SIZE 1000
#define MAX 100000
#define VI vector <int>
#define VS vector <string>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string, string>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define IT iterator
#define ff first
#define ss second
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

int A[MAX+7] = {3, 2, 4, 5, 7, 8, 6, 10}; // Input Array
int dp[MAX+7];							  // Storing every value of A to find LIS
int id[MAX+7];							  // Storing the index of every value of A.
/*** if dp[i] stores a value of array A then id[i] will store the index number of that value of array A. ***/

int path[MAX+7];
/* Store the sequence of LIS by storing the index number of each value in A.
 *It will not store the value rather it will store the index number of that value in A as its ancestor.
 */

pii LIS (int);
void Print_LIS (int);

int main()
{
	pii ans = LIS(8);

	int LIS_Value = ans.ff; // Get the Longest increasing Subsequence value.
	int last = ans.ss; // Get the index of last element of Longest increasing Subsequence.

    printf("LIS value is : %d\n", LIS_Value);
    Print_LIS( last );

    return 0;
}

pii LIS (int n){

	SET( dp, INF);
    dp[0] = -INF;
    id[0] = -1;
	int ans = 0, last;

    for(int i=0; i<n; i++){

        int j = upper_bound( dp, dp+ans+2, A[i] ) - dp;

        if( dp[j-1] < A[i] && A[i] < dp[j] ){
            dp[j] = A[i];
            id[j] = i;
            path[i] = id[j-1];

            if( ans < j ){
                ans = j;
                last = i;
            }
        }
    }

	return pii( ans, last );
}

void Print_LIS(int last){

    if( last == -1 ) return;

    Print_LIS( path[last] ); // recurrsive call to get its ancestors.

	printf("%d\n", A[last]);

    return;
}

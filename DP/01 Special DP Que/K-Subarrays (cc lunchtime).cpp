// https://www.codechef.com/LTIME96B/problems/CHESUB
// https://discuss.codechef.com/t/chesub-editorial/90440

/*
Problem:

You are given two integers N and K, and an array A of N integers. 
You have to choose K disjoint non-empty subarrays such that the score is maximized.

The score is calculated as follows:
Score = ∑(Sum[i]⋅i), where i from 1 to k.
where Sum[i] denotes sum of elements of i-th subarray. 
By the i-th subarray, we mean the i-th one in the order from left to right.

Find the maximum score that can be achieved.

Note: The subarrays are not required to cover the whole array. It is allowed for some elements of A to belong to none of the subarrays.
*/

/*
Let’s create our DP[i][j] which is defined as follows:

DP[i][j] is defined as the maximum score that is possible by taking the first i index 
of the array A and having exactly j subarrays such that the jth subarray ends at index i.



Transition will be as follows:
Suppose we are at index i of an array and we had selected j subarrays till now. 
Now for this index, i we had choices as:

Case 1:
Take this element in the j-th subarray, then our transition will be as:
DP[i][j] = DP[i-1[[j] + j*A[i]

Case 2:
Start a new subarray from this index of an array.
DP[i][j] = max(DP[i-1][j-1], DP[i-2][j-1], ..., DP[1][j-1]) + j*A[i]
or
dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i]*j, dp[i-2][j-1] + a[i]*j, dp[i-3][j-1] + a[i]*j, ..., dp[1][j-1] + a[i]*j)

But above case 2 will give TLE since it's O(N^2*K)

So we introduces a preifx[i][j] where
preifx[i][j] = max(dp[i][j], dp[i-1][j], dp[i-2][j], ..., dp[1][j])

Case 2:
dp[i][j] = max(dp[i][j], prefix[i-1][j-1] + a[i]*j)
*/

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int inf = 1e18;
 
int dp[100010][110];
int prefix[100010][110];
 
void solve() {
    int n, k;
    cin >> n >> k;
    int a[n], b[k];
 
    for(int i=0; i<n; i++)
        cin >> a[i];
 
    for(int i=0; i<n; i++){
        dp[i][0] = 0;
        prefix[i][0] = 0;
        for(int j=1; j<=k; j++){
            dp[i][j] = -inf;
            prefix[i][j] = -inf;
        }
    }
 
    dp[0][1] = a[0]*1;
    prefix[0][1] = dp[0][1];
 
    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++) {
            // case 1:
            dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i]*j);
            // case 2: 
            dp[i][j] = max(dp[i][j], prefix[i-1][j-1] + a[i]*j);
            
            prefix[i][j] = max(prefix[i-1][j], dp[i][j]);
        }
    }
 
 
    int ans = -inf;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i][k]);
    }
 
    cout << ans << "\n";
}
 
int32_t main(){
  // freopen("sub5.in","r",stdin);
  // freopen("sub5.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
 
  while(t--)
  {
    solve();
  }
 
return 0;
}

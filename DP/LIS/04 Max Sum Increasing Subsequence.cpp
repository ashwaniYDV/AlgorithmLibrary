/*
Maximum Sum Increasing subsequence is a subsequence of a given list of integers, whose sum is maximum and in the subsequence, 
all elements are sorted in increasing order.
*/

/*
dp[i] stores the max sum of increasing subsequence when nums[i] is included
*/ 


#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fa(i,a,n) for(int i=a;i<n;i++)
#define loop(i,a, n) for(int i = a; i <= n; i++)
#define loopb(i,a, n) for(int i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5 + 5;
const int N = 1e5+5;
int n, m;


void solve() {
    cin >> n;
    vector<int> nums(n);
    f(i, n) cin >> nums[i];
    
    vector<int> dp(n+1, 0);

    f(i, n) dp[i] = nums[i];
 
    int mx = dp[0];
    for(int i=1; i < n; ++i) {
        for(int j=0; j < i; ++j) {
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
        mx = max(mx, dp[i]);
    }
    
    cout << mx;
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}

/*
Input:
5
1 4 3 8 8
Output:
13

Input:
10
1 2 4 3 2 5 4 6 8 
Output:
26
*/

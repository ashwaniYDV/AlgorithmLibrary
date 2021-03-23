/*
// https://www.geeksforgeeks.org/dynamic-programming-building-bridges
// https://www.youtube.com/watch?v=o1h3aoeSTOU&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=4

Approach: It is a variation of LIS problem. The following are the steps to solve the problem.

1) Sort the north-south pairs on the basis of increasing order of north x-coordinates.
2) If two north x-coordinates are same, then sort on the basis of increasing order of south x-coordinates.
3) Now find the Longest Increasing Subsequence of the south x-coordinates.
4) One thing to note that in the increasing subsequence a value can be greater as well as can be equal to its previous value.
   [i.e two bridges can have same north or south point; only condion is that they should not cross each other;
   NOTE: But this is not the case for Russian doll problem; there, width and height must both be different]

We can also sort on the basis of south x-coordinates and find the LIS on the north x-coordinates.
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
    int x, y, z, u, v;
    cin >> n;
    vector<int> north(n), south(n);
    f(i, n) cin >> north[i];
    f(i, n) cin >> south[i];
    
    // first: north;  second: south
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; ++i){
        arr[i].first = north[i];
        arr[i].second = south[i];
    }
    // sort by north (south if same north)
    sort(arr.begin(), arr.end());
    
    vector<int> dp(n, 1);
    int mx = 0;

    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; j++){
            if(arr[i].second >= arr[j].second){
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
        mx = max(mx, dp[i]); 
    }
    
    cout << mx << endl;
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}

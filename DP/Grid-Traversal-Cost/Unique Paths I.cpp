// https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
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
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 5e5+5;
const int N = 5e5+5;
int n, m;

int fun1(int n, int m) {
    if(n==1 || m==1) return 1;
    return fun1(n-1,m) + fun1(n, m-1);
}

int fun2(int n, int m){
    int dp[n][m];
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for (int j = 0; j < m; j++) {
        dp[0][j] = 1; 
    }

    for (int i = 1; i < n; i++) { 
        for (int j = 1; j < m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    } 
    return dp[n - 1][m - 1]; 
}

int fun3(int n, int m){
    int dp[m];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 0; i < n; i++) { 
        for (int j = 1; j < m; j++) { 
            dp[j] += dp[j - 1]; 
        } 
    } 
    return dp[m - 1]; 
}

int fun4(int n, int m){
    int path = 1; 
    for (int i = m; i < (n + m - 1); i++) {
        path *= i;
        path /= (i - m + 1);
    } 
    return path;
}

void solve() {
    int x, y, k, l, r;
    
    cout<<fun1(3, 7)<<endl;
    cout<<fun2(3, 7)<<endl;
    cout<<fun3(3, 7)<<endl;
    cout<<fun4(3, 7)<<endl;
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define debug(x) cout << #x << " is: " << (x) << endl;
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;i<n;i++)
#define loop(i,a, n) for(ll i = a; i <= n; i++)
#define loopb(i,a, n) for(ll i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define setmem(x, k) memset(x, k, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e5+1;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

int calculateRecursive(string s, int start, int len){
    if(len == 1){
        return 1;
    }
    if(len == 0){
        return 0;
    }
    if(s[start] == s[start+len-1]){
        return 2 + calculateRecursive(s,start+1,len-2);
    }else{
        return max(calculateRecursive(s, start+1, len-1), calculateRecursive(s, start, len-1));
    }
}

void solve() {
    ll t, k, d, x, y, z;
    string s;
    cin >> s;
    n = s.size();
    cout << calculateRecursive(s, 0, n) << endl;
    ll dp[n][n];
    for(ll i=0; i < n; i++){
        dp[i][i] = 1;
    }
    for(ll l = 2; l <= n; l++){
        for(ll i = 0; i < n-l + 1; i++){
            ll j = i + l - 1;
            if(l == 2 && s[i] == s[j]){
                dp[i][j] = 2;
            }else if(s[i] == s[j]){
                dp[i][j] = dp[i + 1][j-1] + 2;
            }else{
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
}


int32_t main() {
    IOS
    clock_t begin = clock();
    ll T = 1;
    // cin >> T;
    while(T--)
    solve();
    cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}

// https://youtu.be/dzMdbWulRII
// interview important

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

unordered_map<string, bool> mp;
bool go(string str, string pat, ll s = 0, ll p = 0) {
    string temp = to_string(s) + "|" + to_string(p);

    if(mp.count(temp)) return mp[temp];

    if(p == pat.length()){
        return mp[temp] = (s == str.length());
    }
    if(s == str.length()){
        for(ll i = p; i < pat.length(); i++)
            if(pat[i] != '*')
                return (mp[temp]=false);
        return (mp[temp] = true);
    }

    // ? -> match one
    if(pat[p] == '?' or pat[p] == str[s])
        return mp[temp] = go(str, pat, s+1, p+1);

    // * -> match all or match none
    if(pat[p] == '*')
        return mp[temp] = go(str, pat, s+1, p) or go(str, pat, s, p+1);

    return mp[temp] = false;
}

ll dp_sol(string str, string pat, ll n, ll m){
    ll dp[n + 1][m + 1];

    // empty pattern can only match with empty string 
    if (m == 0) return (n == 0); 

    memset(dp, 0, sizeof dp);

    // empty pattern can match with empty string 
    dp[0][0] = 1;

    // Only '*' can match with empty string 
    for (ll j = 1; j <= m; j++) {
        if (pat[j - 1] == '*') 
            dp[0][j] = dp[0][j - 1];
    }

    // fill the table in bottom-up fashion 
    for (ll i = 1; i <= n; i++) { 
        for (ll j = 1; j <= m; j++) { 
            // Two cases if we see a '*' 
            // a) We ignore ‘*’ character and move to next character in pattern, 
            // i.e., ‘*’ indicates an empty sequence. 
            // b) '*' character matches with ith character in input 
            if (pat[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; 
            }
  
            // Current characters are considered as matching in two cases 
            // (a) current character of pattern is '?' 
            // (b) characters actually match 
            else if (pat[j - 1] == '?' || str[i - 1] == pat[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; 
            }
  
            // If characters don't match 
            else dp[i][j] = false; 
        } 
    } 
  
    return dp[n][m];
}

void solve() {
    ll t, k, d, x, y, z;
    string s, pattern;
    cin >> s >> pattern;
    n = s.size(), m = pattern.size();
    cout << dp_sol(s, pattern, n, m);
    // cout << go(s, pattern) << endl;
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

/*
INPUT:
asdfgh
*s*f?*

OUTPUT:
1 (True)
*/

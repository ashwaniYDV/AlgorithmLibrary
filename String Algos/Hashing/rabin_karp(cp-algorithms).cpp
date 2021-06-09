#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define MOD2 998244353
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e5;
int n, m, k;


vector<int> rabin_karp(string const& str, string const& pat) {
    const int p = 31; 
    const int mod = 1e9 + 9;
    int n = str.size(), m = pat.size();

    vector<long long> p_pow(max(n, m)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) {
        p_pow[i] = (p_pow[i-1] * p) % mod;
    }

    vector<long long> h_str(n + 1, 0); 
    for (int i = 0; i < n; i++) {
        h_str[i+1] = (h_str[i] + (str[i] - 'a' + 1) * p_pow[i]) % mod; 
    }

    long long h_pat = 0; 
    for (int i = 0; i < m; i++) {
        h_pat = (h_pat + (pat[i] - 'a' + 1) * p_pow[i]) % mod; 
    }

    vector<int> occurences;
    for (int i = 0; i <= n - m; i++) { 
        long long cur_h = (h_str[i+m] - h_str[i] + mod) % mod; 
        // (cur_h / p_pow[i]) = h_pat
        if (cur_h == h_pat * p_pow[i] % mod) {
            occurences.push_back(i);
        }
    }
    return occurences;
}

void solve() {
    string str, pat;
    cin >> str >> pat;
    for(auto i: rabin_karp(str, pat)) cout << i << " ";
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}

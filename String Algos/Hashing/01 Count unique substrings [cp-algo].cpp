// https://cp-algorithms.com/string/string-hashing.html#toc-tgt-5

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
int n, m;

int count_unique_substrings(string const& s) {
    int n = s.size();
    const int p = 31;
    const int mod = 1e9 + 9;

    vector<int> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % mod;

    vector<int> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }

    // for substring s(i, i+l-1): left=i, right=i+l-1
    // from prefix (1 index based), cur_h = ((h[right+1] - h[left]) / p^i) % m = ((h[i + l] - h[i]) / p^i) % m
    // But we do not use inverse_mod here for p^i.
    // Hash calculation of substring concept:-
    // https://cp-algorithms.com/string/string-hashing.html#toc-tgt-3
    
    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<int> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] - h[i] + mod) % mod;
            cur_h = (cur_h * p_pow[n-1-i]) % mod;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}

void solve() {
    string s;
    cin >> s;
    cout << count_unique_substrings(s) << endl;
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}

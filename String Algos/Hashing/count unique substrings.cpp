// https://youtu.be/wh1APrnUfF8

/* 
Similar questions which can be solved:-
----------------------------------------
Count number of distinct substrings of a given length
Count distinct substrings of a string using string hashing/Rabin Karp algorithm
*/

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

int add(int a, int b, int mod) {
    int res = (a + b) % mod;
    if (res < 0) res += mod;
    return res;
}
int mult(int a, int b, int mod) {
    int res = (a * 1LL * b) % mod;
    if (res < 0) res += mod;
    return res;
}
int power(int a, int b, int mod) {
    a %= mod;
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

struct hsh_str {
    int mod = 1e9 + 9, base = 31, n;
    vector<int> pw, inv, hash_str;
    
    void init(string s) {
        n = s.size();
        pw.resize(n+2), inv.resize(n+1), hash_str.resize(n+2);

        pw[0] = 1;
        for(int i = 1; i < n; i++) {
            pw[i] = mult(pw[i - 1], base, mod);
        }

        int pw_inv = power(base, mod - 2, mod);
        inv[0] = 1;
        for(int i = 1; i < n; i++) {
            inv[i] = mult(inv[i - 1], pw_inv, mod);
        }

        // build hash
        for(int i = 0; i < n; i++) {
            hash_str[i] = add((i == 0) ? 0 : hash_str[i - 1], mult(pw[i], s[i] - 'a' + 1, mod), mod);
        }
    }

    int getHash(int x, int y) {
        int res = add(hash_str[y], (x == 0) ? 0 : -hash_str[x - 1], mod);
        res = mult(res, inv[x], mod);

        return res;
    }
};


void solve() {
    string s;
    cin >> s;
    n = s.size();

    hsh_str obj;
    obj.init(s);
    int res = 0;

    // iterating over all length l = 1 to l = n
    loop(l, 1, n) {
        set<int> st;
        for (int i = 0; i <= n - l; i++) {
            st.insert(obj.getHash(i, i+l-1));
        }
        res += st.size();
    }
    cout << res << endl;
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}

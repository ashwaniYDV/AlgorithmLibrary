// https://www.geeksforgeeks.org/palindrome-substring-queries/ 
// Using Cumulative Hash

/*
Given a string and several queries on the substrings of the given input string to check whether the substring is a palindrome or not.

Suppose our input string is “abaaabaaaba” and the queries- [0, 10], [5, 8], [2, 5], [5, 9]

We have to tell that the substring having the starting and ending indices as above is a palindrome or not.

[0, 10] → Substring is “abaaabaaaba” which is a palindrome.
[5, 8] → Substring is “baaa” which is not a palindrome.
[2, 5] → Substring is “aaab” which is not a palindrome.
[5, 9] → Substring is “baaab” which is a palindrome.
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

const int p = 31;
const int mod = 1e9 + 9;
vector<int> p_pow, h, h_rev;


void hash_init(string s, string s_rev) {
    p_pow.resize(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i-1] * p) % mod;
    }

    h.resize(n+1);
    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }

    h_rev.resize(n+1);
    for (int i = 0; i < n; i++) {
        h_rev[i+1] = (h_rev[i] + (s_rev[i] - 'a' + 1) * p_pow[i]) % mod;
    }
}

int getHash(int i, int j) {
    int cur_h = (h[j+1] - h[i] + mod) % mod;
    cur_h = (cur_h * p_pow[n-1-i]) % mod;
    return cur_h;
}

int getHashRev(int x, int y) {
    int i = n - y - 1, j = n - x - 1;
    int cur_h = (h_rev[j+1] - h_rev[i] + mod) % mod;
    cur_h = (cur_h * p_pow[n-1-i]) % mod;
    return cur_h;
}

void solve() {
    int x, y, q;
    string s, s_rev;
    cin >> s;
    s_rev = s;
    reverse(s_rev.begin(), s_rev.end());
    n = s.size();
    hash_init(s, s_rev);

    cin >> q;
    while(q--) {
        // 0 based indexing of x, y
        cin >> x >> y;
        if(getHash(x, y) == getHashRev(x, y)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

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
------
abaaabaaaba
4
0 10
5 8
2 5
5 9

Output:
--------
YES
NO
NO
YES

*/

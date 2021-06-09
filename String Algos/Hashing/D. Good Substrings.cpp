// https://codeforces.com/problemset/problem/271/D

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

int prefBad[N];

int count_unique_substrings(string const& s) {
    int n = s.size();
    const int p = 31;
    const int m = 1e9 + 9;

    vector<int> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<int> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<int> hs;
        for (int i = 0; i <= n - l; i++) {
            int left = i, right = i + l - 1;
            int temp = prefBad[right+1] - prefBad[left];
            if(temp > k) continue;
            long long cur_h = (h[right+1] - h[left] + m) % m;
            cur_h = (cur_h * p_pow[n-1-i]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}

void solve() {
    string s, num;
    cin >> s;
    cin >> num;
    cin >> k;
    n = s.size();
    f(i, n) {
        if(num[s[i] - 'a'] == '0')
            prefBad[i+1] = prefBad[i] + 1;
        else
            prefBad[i+1] = prefBad[i];
    }
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

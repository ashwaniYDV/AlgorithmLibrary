// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/

#include<bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long long int ll;
#define int long long int
#define ld long double
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debug2(x,y) cerr << (#x) <<", "<<(#y)<< " are: " << (x) <<", "<<(y)<< endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define kickstart(testcase, res) cout << "Case #" << testcase << ": " << res << endl;
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
#define MOD2 998244353
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 5e5+5;
const int N = 1e6+5;
int n, m, k;

int phi[MAXN + 1], pillai[MAXN + 1];
int a[N], BIT[N];

int inline mod(int x) {
    return (x % MOD + MOD) % MOD;
}

// Euler Phi Function in O(Nlog(logN)) [preprocessing time]
void init_phi() {
    for(int i = 1; i <= MAXN; i++) {
        phi[i] = i;
    }

    for(int i = 2; i <= MAXN; i++) {
        if(phi[i] == i) {
            for(int j = i; j <= MAXN; j += i) {
            phi[j] *= (i - 1);
            phi[j] /= i;
           } 
        }
    }
}

void init_pillai() {
    for(int i = 1; i <= MAXN; i++)
        for(int j = i; j <= MAXN; j += i) {
            pillai[j] += i * phi[j / i];
            pillai[j] = mod(pillai[j]);
        }
}

void update(int i, int val) {
    while(i <= n) {
        BIT[i] += val;
        i += (i&-i);
    }
}

int query(int i) {
    int sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i -= (i&-i);
    }
    return sum;
}


void solve() {
    int t, x, y;
    init_phi();
    init_pillai();
    cin >> n;
    loop(i, 1, n) {
        cin >> a[i];
        update(i, pillai[a[i]]);
    }
    cin >> t;
    while(t--){
        char c;
        cin >> c >> x >> y;
        if (c == 'U') {
            // increment is added as update
            update(x, pillai[y] - pillai[a[x]]);
            a[x] = y;
        } else if (c == 'C') {
            cout << mod(query(y) - query(x - 1)) << '\n';
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

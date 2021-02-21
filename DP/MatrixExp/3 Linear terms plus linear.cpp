// https://unacademy.com/class/matrix-exponentiation-and-matrix-operations/VOM2NSM6

/*
Special Sequence
---------------------------------------
F[n] = 4*F[n-1] + 3*F[n-2] + 5*n + 7 

Given:
F[0] = 1, F[1] = 2

| F[n] |  =  | 4 3 5 7 | | F[n-1] |
|F[n-1]|  =  | 1 0 0 0 | | F[n-2] |
| n+1  |  =  | 0 0 1 1 | |    n   |
|  1   |  =  | 0 0 0 1 | |    1   |

| F[n] |  =  | 4 3 5 7 |^(n-1) | F[1] |
|F[n-1]|  =  | 1 0 0 0 |       | F[0] |
|  n+1 |  =  | 0 0 1 1 |       |   n  |
|   1  |  =  | 0 0 0 1 |      .|   1  |

| F[n] |  =  | 4 3 5 7 |^(n-1) | 2 |
|F[n-1]|  =  | 1 0 0 0 |       | 1 |
|  n+1 |  =  | 0 0 1 1 |       | n |
|   1  |  =  | 0 0 0 1 |      .| 1 |
*/

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_map;
// methods: find_by_order(k); & order_of_key(k); To make it an ordered_multiset, use pairs of (value, time_of_insertion) to distinguish values which are similar
 
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
const int MAXN = 1e5+5;
const int N = 1e5+5;
int n, m;

const int K = 4;

matrix mul(matrix A, matrix B) {
    matrix C(K, vector<int>(K));
    f(i, K)
    	f(j, K)
    		f(k, K)
        		C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(matrix A, int p) {
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int fun(int N) {
	if (N == 0) return 0;

    // create vector F1
    vector<int> F1 = {2,
    				  1,
    				  N, 
    				  1};

    // create matrix T
    matrix T = {{4, 3, 5, 7}, 
    			{1, 0, 0, 0}, 
    			{0, 0, 1, 1},
    			{0, 0, 0, 1}};

    // raise T to the (N-1)th power
    T = pow(T, N-1);

    // the answer is the first row of T.F1
    int res = 0;
    f(i, K) {
        res = (res + T[0][i] * F1[i]) % MOD;
    }
    return res;
}

void solve() {
    cin >> n;
    cout << fun(n) << endl;
}

int32_t main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}

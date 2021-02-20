// https://codeforces.com/problemset/problem/166/E
// https://unacademy.com/class/matrix-exponentiation-and-matrix-operations/VOM2NSM6

/*
DP[n][X] means we are on state X and we have n steps to go to D

DP[n][A] = DP[n-1][B] + DP[n-1][C] + DP[n-1][D]
DP[n][B] = DP[n-1][A] + DP[n-1][C] + DP[n-1][D]
DP[n][C] = DP[n-1][A] + DP[n-1][B] + DP[n-1][D]
DP[n][D] = DP[n-1][A] + DP[n-1][B] + DP[n-1][C]

DP[0][A] = 0 (We are on A and we have 0 steps to go to D)
DP[0][B] = 0
DP[0][C] = 0
DP[0][D] = 1  (We are already on D and we have 0 steps to go to D)


| DP[n][A] |  =  | 0 1 1 1 | | DP[n-1][A] |
| DP[n][B] |  =  | 1 0 1 1 | | DP[n-1][B] |
| DP[n][C] |  =  | 1 1 0 1 | | DP[n-1][C] |
| DP[n][D] |  =  | 1 1 1 0 |.| DP[n-1][D] |

| DP[n][A] |  =  | 0 1 1 1 |^n | DP[0][A] |
| DP[n][B] |  =  | 1 0 1 1 |   | DP[0][B] |
| DP[n][C] |  =  | 1 1 0 1 |   | DP[0][C] |
| DP[n][D] |  =  | 1 1 1 0 |  .| DP[0][D] |

| DP[n][A] |  =  | 0 1 1 1 |^n | 0 |
| DP[n][B] |  =  | 1 0 1 1 |   | 0 |
| DP[n][C] |  =  | 1 1 0 1 |   | 0 |
| DP[n][D] |  =  | 1 1 1 0 |  .| 1 |
*/

#include<bits/stdc++.h>
using namespace std;
 
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
const int N = 1e7+5;
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
    // create vector F1
    vector<int> F1 = {0, 
    				  0,
    				  0,
    				  1};

    // create matrix T
    matrix T = {{0, 1, 1, 1}, 
    			{1, 0, 1, 1}, 
    			{1, 1, 0, 1}, 
    			{1, 1, 1, 0}};

    // raise T to the (N-1)th power
    T = pow(T, N);

    // the answer is the fourth row of T.F1
    int res = 0;
    f(i, K) {
        res = (res + T[3][i] * F1[i]) % MOD;
    }
    return res;
}

void solve() {
	cin >> n;
	cout << fun(n) << endl;
}






















// MLE on test 13
const int N = 1e7+5;
int n, m;
int dp[N][2];
 
int fun(int n, int state) {
	if(n == 0) {
		if(state == 1) return 1;
		else return 0;
	}
 
	if(dp[n][state] != -1) return dp[n][state];
 
	int res = 0;
	if(state == 1) {
		res += 3 * fun(n - 1, 0);
		res %= MOD;
	} else {
		res += 2 * fun(n - 1, 0);
		res += fun(n - 1, 1);
		res %= MOD;
	}
	return dp[n][state] = res % MOD;
}
 
void solve() {
	memset(dp, -1, sizeof dp);
	cin >> n;
	cout << fun(n, 1) << endl;
}























// AC method 2
const int N = 1e7+5;
int n, m;
const int K = 2;

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
    // create vector F1
    vector<int> F1 = {1, 
    				  0};

    // create matrix T
    matrix T = {{0, 3}, 
    			{1, 2}};

    // raise T to the (N-1)th power
    T = pow(T, N);

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

// https://youtu.be/nuUspQ7ORXE

/*
Array must be of non-negative integers
*/

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
 
int BIT[N+5], a[N+5];

void update(int i, int val) {
    while(i < N) {
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

// returns index of lower_bound of prefixSum
int prefixSumLB(int prefixSum) {
	int curr = 0, prevSum = 0;
	for (int i = log2(N); i >= 0; i--) {
		if((curr + (1 << i)) < N && BIT[curr + (1 << i)] + prevSum < prefixSum) {
			curr += (1 << i);
			prevSum += BIT[curr];
		}
	}
	return curr + 1;
}

// returns index of upper_bound of prefixSum
int prefixSumUB(int prefixSum) {
	int curr = 0, prevSum = 0;
	for (int i = log2(N); i >= 0; i--) {
		if((curr + (1 << i)) < N && BIT[curr + (1 << i)] + prevSum <= prefixSum) {
			curr += (1 << i);
			prevSum += BIT[curr];
		}
	}
	return curr + 1;
}

void solve() {
    cin >> n;
    loop(i, 1, n) {
    	cin >> a[i];
    	update(i, a[i]);
    }
    cout << prefixSumLB(3) << endl;
    cout << prefixSumUB(3) << endl;
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
5
1 2 3 4 5

Output:
2
3
*/

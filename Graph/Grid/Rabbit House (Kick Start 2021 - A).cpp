// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cb14

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
#define debug2(x,y) cout << (#x) <<", "<<(#y)<< " are: " << (x) <<", "<<(y)<< endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define kickstart(testcase, res) cout << "Case #" << testcase << ": " << res << endl;
#define f(i,n) for(int i=0;i<n;i++)
#define fa(i,a,n) for(int i=a;i<n;i++)
#define loop(i,a, n) for(int i = a; i <= n; i++)
#define loopb(i,a, n) for(int i = a; i >= n; i--)
#define pb emplace_back
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
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 305;
int n, m;

int a[N][N];
int vis[N][N];

bool isSafe(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j>= m) return false;
    return true;
}

void solve(int tc) {
	int x, y;
	cin >> n >> m;

	set<pair<int, pair<int, int>>> st;
	f(i, n) {
		f(j, m) {
			cin >> a[i][j];
			st.insert({-a[i][j], {i, j}});
		}
	}

	int res = 0;
    while(!st.empty()) {
        auto top = *st.begin();
        st.erase(st.begin());
        int h = -top.first;
        x = top.second.first, y = top.second.second;
        
        f(z, 4) {
            int nx = x + dx[z];
            int ny = y + dy[z];
            
            if(!isSafe(nx, ny)) continue;

            if(a[nx][ny] >= h-1) {
            	continue;
            }

            int diff = h - 1 - a[nx][ny];
        	res += diff;
        	st.erase({-a[nx][ny], {nx, ny}});
        	a[nx][ny] = h-1;
        	st.insert({-a[nx][ny], {nx, ny}});
        }
    }

	kickstart(tc, res);
}
 
signed main() {
	IOS
	int T = 1;
	cin >> T;
	int ct = 1;
	while(T--)
	solve(ct++);
	return 0;
}

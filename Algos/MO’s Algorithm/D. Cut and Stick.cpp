// https://youtu.be/goXYV_aTxL0
// https://codeforces.com/contest/1514/problem/D

/*
Prerequisite: FREQ2 - Most Frequent Value.cpp
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
#define UNIQUE(a) sort(a.begin(), a.end() ); a.erase( unique( a.begin(), a.end() ), a.end() );
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debug2(x,y) cout << (#x) <<", "<<(#y)<< " are: " << (x) <<", "<<(y)<< endl;
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
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e4+5;
const int N = 2e5+5;
int n, m;


// sqrt(n)
int BLOCK = 555;

struct query {
    int l, r, i;
    bool operator<(const query &o) const {
        if((l / BLOCK) != (o.l / BLOCK))
            return l < o.l;
        return l / BLOCK & 1 ? r < o.r : r > o.r;
    }
};

query Q[300005];
int ar[300005] , ans[300005];
int freq[300005];
int freqOfFreq[300005];
int maxFreq = 0;

void add(int pos) {
	int ele = ar[pos];

	int prevFreq = freq[ele];
	freq[ele]++;
	int curFreq = freq[ele];

	freqOfFreq[prevFreq]--;
	freqOfFreq[curFreq]++;

	maxFreq = max(maxFreq, freq[ele]);
}
 
void remove(int pos) {
	int ele = ar[pos];
	
	int prevFreq = freq[ele];
	freq[ele]--;
	int curFreq = freq[ele];

	freqOfFreq[prevFreq]--;
	freqOfFreq[curFreq]++;

	while(freqOfFreq[maxFreq] == 0) {
		maxFreq--;
	}
}

void solve() {
	int q;
	cin >> n >> q;
	f(i, n) cin >> ar[i];
	f(i, q) {
		cin >> Q[i].l >> Q[i].r;
		Q[i].l--, Q[i].r--;
		Q[i].i = i;
	}
	sort(Q, Q + q);

	int ML = 0 , MR = -1;
	f(i, q) {
		int L = Q[i].l;
		int R = Q[i].r;
 
 		// expansion
		while(ML > L)
		ML-- , add(ML);
 	
 		// expansion
		while(MR < R)
		MR++ , add(MR);
 
 		// contraction
		while(ML < L)
		remove(ML) , ML++;
 
 		// contraction
		while(MR > R)
		remove(MR) , MR--;
 

 		// observation (there can be at most 1 element with frequency > ceil(total / 2))
 		int total = (R - L + 1);
 		int half = (total+1) / 2;
 		int rem = total - maxFreq;

 		// 1 element with frequency > ceil(total / 2))
 		if(maxFreq > half) {
 			ans[Q[i].i] = total - 2 * rem;
 		}
 		// no element with frequency > ceil(total / 2))  
 		else {
 			ans[Q[i].i] = 1;
 		}
	}
 
	f(i, q) cout << ans[i] << endl;
}
 
signed main() {
	IOS
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
} 

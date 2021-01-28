#include<bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
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
const int MAXN = 1e3+5;
const int N = 1e5+5;
int n, m;
 
struct node {
	int v = 0;
	node() {}
	node(int val) {
		v = val;
	}
	void merge(const node &l, const node &r) {
		v = l.v + r.v;
	}
};

struct update {
	int v = 0;
	update() {}
	update(int val) {
		v = val;
	}

	// you can be sure that "other" is the newer update than the current
	void combine(update &other, const int32_t &tl, const int32_t &tr) {
		v += other.v;
		// ([Type 2 update] Set all value on a range to other value ignoring current) 
		// v = other.v;  
	}
	void apply(node &x, const int32_t &tl, const int32_t &tr) {
		x.v += (tr - tl + 1) * v;
		// (For type 2 update)
		// x.v = (tr - tl + 1) * v; 
	}
};

template<typename node, typename update>
struct segtree {
	int len;
	vector<node> t;
	vector<update> u;
	vector<bool> lazy;
	node identity_element;
	update identity_transformation;

	segtree(int l) {
		len = l;
		t.resize(4 * len);
		u.resize(4 * len);
		lazy.resize(4 * len);
		identity_element = node();
		identity_transformation = update();
	}

	void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr) {
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		apply(v << 1, tl, tm, u[v]);
		apply(v << 1 | 1, tm + 1, tr, u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}

	void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd) {
		if(tl != tr) {
			lazy[v] = 1;
			u[v].combine(upd, tl, tr);
		}
		upd.apply(t[v], tl, tr);
	}

	template<typename T>
	void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr) {
		if(tl == tr) {
			t[v] = arr[tl];
			return;
		}

		int32_t tm = (tl + tr) >> 1;
		build(arr, v << 1, tl, tm);
		build(arr, v << 1 | 1, tm + 1, tr);
		t[v].merge(t[v << 1], t[v << 1 | 1]);
	}

	node query(const int32_t &v, const int32_t &tl, const int32_t & tr, const int32_t &l, const int32_t &r) {
		if(l > tr || r < tl) {
			return identity_element;
		}

		if(tl >= l && tr <= r) {
			return t[v];
		}

		pushdown(v, tl, tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r);
		node ans;
		ans.merge(a, b);
		return ans;
	}

	void rupd(const int32_t &v, const int32_t &tl, const int32_t & tr, const int32_t &l, const int32_t &r, const update &upd) {
		if(l > tr || r < tl) {
			return;
		}

		if(tl >= l && tr <= r) {
			apply(v, tl, tr, upd);
			return;
		}

		pushdown(v, tl, tr);

		int32_t tm = (tl + tr) >> 1;
		rupd(v << 1, tl, tm, l, r, upd);
		rupd(v << 1 | 1, tm + 1, tr, l, r, upd);
		t[v].merge(t[v << 1], t[v << 1 | 1]);
	}

public:
	template<typename T>
	void build(const T &arr) {
		build(arr, 1, 0, len-1);
	}
	node query(const int32_t &l, const int32_t &r) {
		return query(1, 0, len - 1, l, r);
	}
	void rupd(const int32_t &l, const int32_t &r, const update &upd) {
		rupd(1, 0, len - 1, l, r, upd);
	}
};

void solve() {
	int x, y, k, q;
	segtree<node, update> s(N);

	s.rupd(2, 6, 3);
	s.rupd(5, 9, 10);

	for (int i = 0; i < 15; ++i) {
		cout << s.query(i, i).v << " ";
	}

	cout << endl << s.query(2, 5).v;

}

int32_t main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}

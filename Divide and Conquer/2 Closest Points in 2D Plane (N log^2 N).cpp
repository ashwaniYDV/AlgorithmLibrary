// https://github.com/Ashishgup1/Competitive-Coding

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


struct Point {
    int x, y;
    Point operator - (Point p) {
        return {x - p.x, y - p.y};
    }

    int dist() {
        return x*x + y*y;
    }
};

bool by_x(Point &a, Point &b) {
    return a.x < b.x;
}

bool by_y(Point &a, Point &b) {
    return a.y < b.y;
}

Point pt[N];

int fun(int L, int R) {
    if(L == R) return 1e18;

    int M = (L + R) / 2;

    sort(pt + L, pt + R + 1, by_x);

    int d = min(fun(L, M), fun(M + 1, R));
    int midx = pt[L + (R - L + 1) / 2].x;
    
    vector<Point> v;
    for(int i = L; i <= R; i++) {
        if(Point{pt[i].x - midx, 0}.dist() < d) {
            v.push_back(pt[i]);
        }
    }
    sort(v.begin(), v.end(), by_y);

    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(Point{0, v[i].y - v[j].y}.dist() > d) {
                break;
            }
            d = min(d, (v[i] - v[j]).dist());
        }
    }

    return d;
}

void solve() {
    int x, y;
    cin >> n;
    f(i, n) {
        cin >> pt[i].x >> pt[i].y;
    }
    int distanceSquare = fun(0, n - 1);
    cout << sqrt(distanceSquare) << endl;
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}

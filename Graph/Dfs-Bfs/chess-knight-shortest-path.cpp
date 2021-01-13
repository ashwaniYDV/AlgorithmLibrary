// https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/

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
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e5+5;
int n, m;

int row[] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[] = {-1, 1, 1, -1, 2, -2, 2, -2};

struct Node {
    int x, y, dist;
    Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}
};

bool valid(int x, int y) {
    if(x < 0 || y < 0 || x >= 8 || y >= 8) return false;
    return true;
}

int bfs(pair<int, int> src, pair<int, int> dest) {
    map<pair<int, int>, int> visited;
    queue<Node> q;
    q.push({src.F, src.S, 0});
    visited[src] = 1;
    while(!q.empty()){
        Node node = q.front();
        q.pop();
        int x = node.x;
        int y = node.y;
        int dist = node.dist;

        if(x == dest.F && y == dest.S){
            return dist;
        }

        f(i, 8) {
            int x1 = x + row[i];
            int y1 = y + col[i];
            if(!visited[{x1, y1}] && valid(x1, y1)) {
                q.push({x1, y1, dist+1});
                visited[{x1, y1}] = 1;
            }
        }
    }
    return -1;
}

void solve() {
    int u, v;
    pair<int, int> src = {4, 5};
    pair<int, int> dest = {1, 1};
    // pair<int, int> src = {0, 7};
    // pair<int, int> dest = {7, 0};
    cout << bfs(src, dest);
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}

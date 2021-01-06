/* 
Kosaraju's Algorithm to calculate and print 
Strongly Connected Components (SCC) in directed graph

https://youtu.be/TEbr3edMzo0
*/

#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5 + 5;
const int N = 1e5+5;
int n, m;


vector<int> g[N];
vector<int> transpose_g[N];
int vis[N];
stack<int> st;

void dfs(int u) {
    vis[u] = 1;

    for(int v: g[u]) {
        if(!vis[v]) dfs(v);
    }

    st.push(u);
}

void revDfs(int u) {
    vis[u] = 1;
    cout << u << " ";

    for(int v: transpose_g[u]) {
        if(!vis[v]) revDfs(v);
    }
}

void solve() {
    int x, y, z, k, u, v;
    cin >> n >> m;

    f(i, m) cin >> u >> v, g[u].pb(v);

    // Method 1 for creating transpose_g
    // f(i, m) cin >> u >> v, g[u].pb(v), transpose_g[v].pb(u);

    // Method 2 for creating transpose_g
    loop(i, 1, n) {
        for(int v: g[i]) {
            transpose_g[v].pb(i);
        }
    }
    
    // to store nodes in decreasing order of out time in stack
    loop(i, 1, n) {
        if(!vis[i]) dfs(i);
    }


    loop(i, 0, n) vis[i] = 0;

    ll totalSCC = 0;
    // driver
    while(!st.empty()) {
        int ind = st.top();
        st.pop();

        if(!vis[ind]) {
            totalSCC++;
            cout << "SCC\n";
            revDfs(ind);
            cout << endl;
        }
    }

    cout << "Total SCC = " << totalSCC << endl;

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
INP:

5 5
3 1
1 2
2 3
1 4
4 5


OUT:

SCC
1 3 2 
SCC
4 
SCC
5 
Total SCC = 3
*/

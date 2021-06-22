// Print all shortest paths between given source and destination in an undirected unweighted graph
// https://www.geeksforgeeks.org/print-all-shortest-paths-between-given-source-and-destination-in-an-undirected-graph/

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
// #define endl "\n"
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e5+5;
int n, m;
 
int dist[N];
vector<int> g[N];
vector<int> parent[N];
 
void bfs(int source) {
	for(int i = 1; i <= n; i++) {
		dist[i] = 1e18;
	}
 
	queue<int> q;
	q.push(source);
	dist[source] = 0;
	parent[source] = { -1 };
 
	while(!q.empty()) {
		int u = q.front();
        q.pop();
 
		for(int v: g[u]) {
			if (dist[v] > dist[u] + 1) {
				// A shorter distance is found
                // So erase all the previous parents and insert new parent u in parent[v]
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v].clear();
                parent[v].push_back(u);
            } else if (dist[v] == dist[u] + 1) {
 				// Another candidate parent for shortes path found
                parent[v].push_back(u);
            }
		}
	}
}
 
void find_paths(vector<vector<int> >& paths, vector<int>& path, int u) {
    // Base Case
    if (u == -1) {
        paths.push_back(path);
        return;
    }
 
    // Loop for all the parents of the given vertex
    for (int par : parent[u]) {
 		// Insert the current vertex in path
        path.push_back(u);
 
        // Recursive call for its parent
        find_paths(paths, path, par);
 
        // Remove the current vertex
        path.pop_back();
    }
}

void printPaths(int source, int destination) {
	vector<vector<int>> paths;
    vector<int> path;
 
	// Function call to find_paths
    find_paths(paths, path, destination);
 
    for (auto v : paths) {
        // Since paths contain each path in reverse order
        reverse(v.begin(), v.end());
 
        // Print node for the current path
        for (int u : v) cout << u << " ";
        cout << endl;
    }
}

void solve() {
	int u, v;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> u>> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int source = 1;
	bfs(source);

	loop(i, 1, n) {
		int destination = i;
		printPaths(source, destination);
		cout << endl;
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

/*
Input:
6 7
1 2
1 3
2 4
2 5
3 4
4 6
5 6

Output:
1 

1 2 

1 3 

1 2 4 
1 3 4 

1 2 5 

1 2 4 6 
1 3 4 6 
1 2 5 6 
*/

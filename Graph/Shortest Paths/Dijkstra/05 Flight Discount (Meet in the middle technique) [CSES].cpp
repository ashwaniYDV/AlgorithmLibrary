// https://cses.fi/problemset/task/1195/

/*
Question: (NOTE: edges are directed)
Your task is to find a minimum-price flight route from city 1 to city n. 
You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.

Input:
The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,...,n.
After this there are m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. 
Each flight is unidirectional. You can assume that it is always possible to get from city 1 to city n.
*/

/*
CF Blog: 
https://codeforces.com/blog/entry/79518

Find minimum distance from 1 till starting of edge and minimum distance
from end of node till n and add weight/2. may be the concept involved here
is called meet in the middle. 
create two graphs original and reverse.
from original graph start dijkstra from 1 and store result in FRM1 and from
reverse graph start dijkstra from n and store result in TON .then iterate
through all edges and ans is minimum of (FRM1[edge[i].start + edge.weight/2 + TON[edge.end])
*/




const int N = 2e5+5;
int n, m;

vector<pair<int,int>> g[N];
int dp[N];


void dijkstra(int source, vector<int>& dist) {
    for (int i = 1; i <= n; i++) dp[i] = INF;

    dp[source] = 0;
    set<pair<int, int>> s;
    s.insert({dp[source], source});

	while (!s.empty()) {
	    int u = s.begin()->second;
	    s.erase(s.begin());
	    for (auto v : g[u]) {
	        int a = v.first, b = v.second;
	        if (dp[a] > dp[u] + b) {
	        	s.erase({dp[a], a});
	        	dp[a] = dp[u] + b;
	        	s.insert({dp[a], a});
	       	}
	    }
	}

	for (int i = 1; i <= n; i++) dist[i] = dp[i];
}
 
void solve() {
    int u, v, w;
    cin >> n >> m;

    vector < pair < int, pair < int, int >>> edges;
    f(i, m) {
        cin >> u >> v >> w, g[u].pb({v, w});
        edges.pb({w, {u, v}});
    }

    vector < int > dist1(n + 1);
    dijkstra(1, dist1);

    // createing a new graph by reversing the directed edges
    /*
    	this will not effect anything because if in the original graph we can go from node1 -> node2
    	then in this new grpah we can go from node2 -> node1 and the weight will be same
    	we are interested in weight only 
    */
    loop(i, 1, n) g[i].clear();
    for (auto i: edges) {
        int w = i.F;
        int u = i.S.F, v = i.S.S;
        g[v].pb({u, w});
    }

    vector < int > distN(n + 1);
    dijkstra(n, distN);

    // applying "Meet in the middle search technique"

    // calculating answer for original graph girected adges u->v
    int ans = dist1[n];
    for (auto i: edges) {
        int w = i.F;
        int u = i.S.F, v = i.S.S;

        if (dist1[u] != INF && distN[v] != INF) {
            ans = min(ans, dist1[u] + distN[v] + w / 2);
        }
    }

    cout << ans << endl;
}

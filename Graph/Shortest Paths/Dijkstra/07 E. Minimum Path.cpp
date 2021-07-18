// https://codeforces.com/contest/1473/problem/E
// https://unacademy.com/class/tricky-variations-of-dijkstra-algorithm/TA76JSGL

/*
Let's consider a problem where you can subtract the weight of any edge (not only the maximum one) 
that belong to the current path and similarly add the weight of any edge (not only the minimum one) 
that belong to the current path.

To solve that problem we can build a new graph where the node can be represented as the following triple 
(node from the initial graph, flag that some edge has been subtracted, flag that some edge has been added). 
Now we can run Dijkstra's algorithm to find the length of the shortest paths in such a graph.

We can notice that on the shortest path, the maximum weight edge was subtracted and the minimum weight edge was added. 
Let's assume that this is not the case, and an edge of non-maximum weight was subtracted from the path, 
then we can reduce the length of the path by choosing an edge of maximum weight. 
But this is not possible, because we considered the shortest path. 
Similarly, it is proved that the added edge was of minimal weight.

Using this fact, it is not difficult to notice that by solving the modified problem, 
we have solved the original one.
*/

/*
DP Tranitions:

i = mxCount and j = mnCount
             w
[u, i, j] ----------->  [v, i, j]             (neither add nor subtract)

            w + w
[u, i, j] ---------->  [v, i, j + 1]          (only add)

            w - w
[u, i, j] ---------->  [v, i + 1, j]          (only subtract)

           w + w - w
[u, i, j] ---------->  [v, i + 1, j + 1]      (both add and subtract)

NOTE: Most optimal answer is minimum value of path length
Thus PathLength = Summation(Paths) - Max(Path) + Min(Path)
Thus dijkstra hame optimal answer tabhi dega jab Max(Path) khud max value hogi and Min(Path) khud sabse min value hogi
tabhi PathLength optimal aaega

Thus we will add and subtract every possible combination and dijkstra hame final optimal answer tabhi dega jab 
sabse max subtract hui ho and sabse min add hui ho kyuki tabhi sabse min pathlength milegi.
*/

/*
For visualiztion of Dijkstra:
These nodes can be visualized for old and new graph as shown below.
Thus if we have N nodes in old graph then in new graph we will have = N * 2 * 2 = 4N nodes 

In old graph                                                     In new graph

   [u]                                         [u, 0, 0] , [u, 0, 1], [u, 1, 0], [u, 1, 1]
*/


const int N = 2e5+5;
int n, m;

vector<pair<int, int>> g[N];
// [node][isSubtracted][isAdded]
int dp[N][2][2];

void dijkstra() {
	int source = 1;
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j < 2; j++) {
    		for (int k = 0; k < 2; k++) 
    			dp[i][j][k] = INF;
    	}
    }

    dp[source][0][0] = 0;

    // {distance, {node, isSubtracted, isAdded}}, where isSubtracted = (0 or 1) and isAdded = (0 or 1)
    set<pair<int, array<int, 3>>> st;
    st.insert({dp[source][0][0], {source, 0, 0}});

	while (!st.empty()) {
		auto it = *st.begin();
		st.erase(it);
	    int u = it.second[0];
	    int isSubtracted = it.second[1];
	    int isAdded = it.second[2];

	    for (auto x : g[u]) {
	    	int v = x.first, w = x.second;

	    	// neither add nor subtract
	        if (dp[v][isSubtracted][isAdded] > (dp[u][isSubtracted][isAdded] + w)) {
          		st.erase({dp[v][isSubtracted][isAdded], {v, isSubtracted, isAdded}});
        		dp[v][isSubtracted][isAdded] = (dp[u][isSubtracted][isAdded] + w);
        		st.insert({dp[v][isSubtracted][isAdded], {v, isSubtracted, isAdded}});
      		}

      		// subtract only
      		if(isSubtracted == 0) {
      			if (dp[v][isSubtracted + 1][isAdded] > (dp[u][isSubtracted][isAdded] + w) - w) {
	          		st.erase({dp[v][isSubtracted + 1][isAdded], {v, isSubtracted + 1, isAdded}});
	        		dp[v][isSubtracted + 1][isAdded] = (dp[u][isSubtracted][isAdded] + w) - w;
	        		st.insert({dp[v][isSubtracted + 1][isAdded], {v, isSubtracted + 1, isAdded}});
	      		}
      		}

      		// add only
      		if(isAdded == 0) {
      			if (dp[v][isSubtracted][isAdded + 1] > (dp[u][isSubtracted][isAdded] + w) + w) {
	          		st.erase({dp[v][isSubtracted][isAdded + 1], {v, isSubtracted, isAdded + 1}});
	        		dp[v][isSubtracted][isAdded + 1] = (dp[u][isSubtracted][isAdded] + w) + w;
	        		st.insert({dp[v][isSubtracted][isAdded + 1], {v, isSubtracted, isAdded + 1}});
	      		}
      		}

      		// both add and subtract
      		if(isAdded == 0 && isSubtracted == 0) {
      			if (dp[v][isSubtracted + 1][isAdded + 1] > (dp[u][isSubtracted][isAdded] + w) + w - w) {
	          		st.erase({dp[v][isSubtracted + 1][isAdded + 1], {v, isSubtracted + 1, isAdded + 1}});
	        		dp[v][isSubtracted + 1][isAdded + 1] = (dp[u][isSubtracted][isAdded] + w) + w - w;
	        		st.insert({dp[v][isSubtracted + 1][isAdded + 1], {v, isSubtracted + 1, isAdded + 1}});
	      		}
      		}
	    }
	}

	for (int i = 2; i <= n; i++) {
        int res = dp[i][1][1];
        cout << res << " ";
    }
}
 
void solve() {
	int u, v, w;
	cin >> n >> m;

    f(i, m) {
    	cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    }

    dijkstra();
}

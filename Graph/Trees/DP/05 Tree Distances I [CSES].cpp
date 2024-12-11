// https://cses.fi/problemset/task/1132/
// https://usaco.guide/gold/all-roots
// https://usaco.guide/problems/cses-1132-tree-distances-i/solution

/*
Q1) Height of tree when root is 1...n
Q2) Determine for each node the maximum distance to another node.
*/

/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the maximum distance to another node.

Input:
The first input line contains an integer n: the number of nodes. 
The nodes are numbered 1,2,…,n.
Then there are n-1 lines describing the edges. 
Each line contains two integers a and b: there is an edge between nodes a and b.

Output:
Print n integers: 
for each node 1,2,…,n, the maximum distance to another node.
*/





// Method 1: Time = O(n ^ 2)
/*
Do a DFS from each node.
*/





// Method 2: Using 3 DFS (Diameter concept)
// https://youtu.be/Rnv4qvoxsTo
/*
node1 and node2 are the end points of diameter of tree.
When any node is rooted, it's max height will eventually end at end points of diameter, i.e. either node1 or node2

depth1 = calculated when node1 is root
depth2 = calculated when node2 is root
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;
 
vector<int> g[N];
vector<int> depth1, depth2;

void dfs(int u, int par, int d, vector<int>& depth) {
    depth[u] = d;
    for(int v: g[u]) {
        if(v == par) continue;
        dfs(v, u, d + 1, depth);
    }
}

void diameterOfTree() {
    depth1 = vector<int>(n+1, 0);
    // DFS 1
    dfs(1, -1, 0, depth1);
    int node1 = 0, mx = 0;
    for(int i = 1; i <= n; i++) {
        if(depth1[i] > mx) {
            mx = depth1[i];
            node1 = i;
        }
    }

    depth1 = vector<int>(n+1, 0);
    // DFS 2
    dfs(node1, -1, 0, depth1);

    int node2 = 0;
    mx = 0;
    for(int i = 1; i <= n; i++) {
        if(depth1[i] > mx) {
            mx = depth1[i];
            node2 = i;
        }
    }

    depth2 = vector<int>(n+1, 0);
    // DFS 3
    dfs(node2, -1, 0, depth2);
}

int main() {
    int u, v;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    }

    diameterOfTree();

    for (int i = 1; i <= n; i++) {
        cout << max(depth1[i], depth2[i]) << " ";
    }    
}











// Method 3: DP (most easy to understand solution)
// https://youtu.be/V1OrZvvKC0k?si=TioMjDaP-ictHyMf
/*
in_dis[u] = longest path in subtree of u
out_dis[u] = longest path outside subtree of u (longest path of u in tree excluding subtree of u)
res[u] = max(in_dis[u], out_dis[u])

in_dis[u] = height[u]

out_dis[v] = max(1 + out_dis[parent], 2 + in_dis[childs of u excluding v])
out_dis[v] = max(1 + out_dis[u], 2 + in_dis[childs_of_u_excl_v])

for calculating in_dis[childs_of_u_excl_v] we can calculate mx1 and mx2 
mx1, mx2 are the first and second largest in_dis (heights) of children of u

in_dis[childs_of_u_excl_v] = mx1 (if mx1 is not equal to height[v])
otherwise in_dis[childs_of_u_excl_v] = mx2
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;

vector<int> g[N];
int in_dis[N], out_dis[N];
 
void dfs_height(int u, int par) {
    in_dis[u] = 0;
    for(int v: g[u]) {
        if(v == par) continue;
        
        dfs_height(v, u);
        in_dis[u] = max(in_dis[u], 1 + in_dis[v]);
    }
}
 
void dfs_res(int u, int par) {
    // mx1, mx2 are first and second largest in_dis (heights) of children of u
	int mx1 = -1, mx2 = -1;
    for(int v: g[u]) {
        if(v == par) continue;

        if(in_dis[v] > mx1) {
        	mx2 = mx1;
        	mx1 = in_dis[v];
        } else if (in_dis[v] > mx2) {
        	mx2 = in_dis[v];
        }
    }
 
    for(int v: g[u]) {
        if(v == par) continue;

        int mx = mx1;
        // if mx1 is same as in_dis[v], then we have to take mx2
        // we cannot take mx1, since partial_dis should not include its own path
        if (mx == in_dis[v]) mx = mx2;
        
        out_dis[v] = max(1 + out_dis[u], 2 + mx);

        dfs_res(v, u);
    }
 
    // res[u] = max(in_dis[u], out_dis[u]);
}

int32_t main() {
    int u, v;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    }

    dfs_height(1, 0);
    dfs_res(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << max(in_dis[i], out_dis[i]) << " ";
    }
}













// Method 4.1: DP
// https://youtu.be/N7e4CTfimkU?si=yae-q37iVV8Xhbta
/*
Kartik Arora explanation
------------------------

res[u] = max(max distance in its subtree, max distance in any other part of tree other than its subtree)
res[u] = max(height of u's subtree, max distance of any path going outside of u's subtree through its parent)
res[u] = max(height[u], 1 + par_partial_dis)

par_partial_dis for a node = longest path of parent of this node which does not passes through cur_node
                           = thus this path can pass through parent of par or it can pss through any of the child of par (where child != cur_node)

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;

vector<int> g[N];
int res[N];
int height[N];
 
void dfs_height(int u, int par) {
    height[u] = 0;
    for(int v: g[u]) {
        if(v == par) continue;
        
        dfs_height(v, u);
        height[u] = max(height[u], 1 + height[v]);
    }
}
 
void dfs_res(int u, int par, int par_partial_dis) {
    vector<int> prefixMax, suffixMax;
    
    for(int v: g[u]) {
        if(v == par) continue;

        prefixMax.push_back(height[v]);
        suffixMax.push_back(height[v]);
    }

    // build prefix and suffix
    for(int i = 1; i < (int)prefixMax.size(); i++)
        prefixMax[i] = max(prefixMax[i], prefixMax[i - 1]);

    for(int i = (int)suffixMax.size() - 2; i >= 0; i--)
        suffixMax[i] = max(suffixMax[i], suffixMax[i + 1]);
 
    // calculate ans for every child
    int childNodeIdx = 0;
    for(int v: g[u]) {
        if(v == par) continue;

        int left = (childNodeIdx == 0) ? INT_MIN : (int)prefixMax[childNodeIdx - 1];
        int right = (childNodeIdx == (int)suffixMax.size() - 1) ? INT_MIN : suffixMax[childNodeIdx + 1];
        
        int partial_dis = 1 + max({par_partial_dis, left, right});

        dfs_res(v, u, partial_dis);
        childNodeIdx++;
    }
 
 	// calculate ans for this node
    res[u] = max(height[u], 1 + par_partial_dis);
}

int32_t main() {
    int u, v;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    }

    dfs_height(1, 0);
    // for root node, par_partial_dis = -1 (or INT_MIN)
    dfs_res(1, 0, -1);

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
}




// Method 4.2: DP (space optimized)
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;

vector<int> g[N];
int res[N];
int height[N];
 
void dfs_height(int u, int par) {
    height[u] = 0;
    for(int v: g[u]) {
        if(v == par) continue;
        
        dfs_height(v, u);
        height[u] = max(height[u], 1 + height[v]);
    }
}
 
void dfs_res(int u, int par, int par_partial_dis) {
    // mx1, mx2 are the two largest heights of children of u
	int mx1 = -1, mx2 = -1;
    for(int v: g[u]) {
        if(v == par) continue;

        if(height[v] > mx1) {
        	mx2 = mx1;
        	mx1 = height[v];
        } else if (height[v] > mx2) {
        	mx2 = height[v];
        }
    }
 
    // calculate ans for every child
    for(int v: g[u]) {
        if(v == par) continue;

        int mx = mx1;
        // if mx1 is same as height[v], then we have to take mx2
        // we cannot take mx1, since partial_dis should not include its own path
        if (mx == height[v]) mx = mx2;
        
        int partial_dis = 1 + max({par_partial_dis, mx});

        dfs_res(v, u, partial_dis);
    }
 
 	// calculate ans for this node
    res[u] = max(height[u], 1 + par_partial_dis);
}

int32_t main() {
    int u, v;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    }

    dfs_height(1, 0);
    // for root node, par_partial_dis = -1 (or INT_MIN)
    dfs_res(1, 0, -1);

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
}

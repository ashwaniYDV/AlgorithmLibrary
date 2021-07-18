// https://leetcode.com/problems/is-graph-bipartite/

/*
Note:
----
No cycle or Even cycle graph -> Bipartite
Odd cycle graph -> Not-Bipartite
*/


// Method 1
/*
Using both vis and color array
colors => { 0 = RED, 1 = BLUE }
*/
class Solution {
public:
    bool dfs(int u, int c, vector<int>& vis, vector<int>& color, vector<vector<int>>& g) {
        vis[u] = 1;
        color[u] = c;
        for(int v: g[u]) {
            if(!vis[v]) {
                if(!dfs(v, c^1, vis, color, g)) return false;
            } else {
                if(color[v] == color[u]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> vis(n), color(n);

        for(int i = 0; i < n; i++) {
            if(!vis[i] && !dfs(i, 1, vis, color, g)) return false;
        }

        return true;
    }
};



// Method 2: (space optimized)
/*
Using only color array
colors => { 1 = RED, 2 = BLUE }
*/

class Solution {
public:
    bool dfs(int u, int c, vector<int>& color, vector<vector<int>>& g) {
        color[u] = c;
        for(int v: g[u]) {
            if(color[v] == 0) {
				if(!dfs(v, c == 1 ? 2 : 1, color, g)) return false;
				// if(!dfs(v, 3 - c, color, g)) return false;
            } else {
                if(color[v] == color[u]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> color(n);

        for(int i = 0; i < n; i++) {
            if(color[i] == 0 && !dfs(i, 1, color, g)) return false;
        }

        return true;
    }
};
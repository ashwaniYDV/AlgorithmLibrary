// https://www.lintcode.com/problem/860

/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical). 
You may assume all four edges of the grid are surrounded by water.
Count the number of distinct islands. An island is considered to be the same as another if and only if 
one island has the same shape as another island (and not rotated or reflected).

Notice that:

11
1
and

 1
11

are considered different island, because we do not consider reflection / rotation.
*/




class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    vector<vector<int>> vis;
    set<vector<pair<int, int>>> st;
    vector<pair<int, int>> a;

    bool isSafe(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == 0)
            return false;
        return true;
    }

    void normalize() {
        // shifting the origin to (0, 0)
        sort(a.begin(), a.end());
        int x = a[0].first, y = a[0].second;
        for(auto& it: a) {
            it.first -= x;
            it.second -= y;
        }

        st.insert(a);
    }

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(!isSafe(i, j, grid)) return;

        vis[i][j] = 1;
        a.push_back({i, j});

        for(int z = 0; z < 4; z++) {
            dfs(i + dx[z], j + dy[z], grid);
        }
    }

    int numberofDistinctIslands(vector<vector<int>> &grid) {
        n = grid.size(), m = grid[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, 0)); 
        st.clear();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    a.clear();
                    dfs(i, j, grid);
                    normalize();
                }
            }
        }

        return st.size();
    }
};

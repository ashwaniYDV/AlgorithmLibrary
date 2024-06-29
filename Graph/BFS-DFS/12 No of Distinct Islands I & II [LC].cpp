// https://leetcode.com/problems/number-of-distinct-islands/

/*
You are given an m x n binary matrix grid. 
An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
Return the number of distinct islands.
*/

class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    bool isSafe(int i, int j, vector<vector<int>>& grid) {
        return !(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0);
    }

    void dfs(int x, int y, int srcX, int srcY, vector<pair<int,int>>& pattern, vector<vector<int>>& grid) {
        // mark as visited
        grid[x][y] = 0;
        
        // normalize the data
        pattern.push_back({x - srcX, y - srcY});

        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z];
            int ny = y + dy[z];

            if(!isSafe(nx, ny, grid)) continue;

            dfs(nx, ny, srcX, srcY, pattern, grid);
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        set<vector<pair<int,int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    vector<pair<int,int>> pattern;
                    dfs(i, j, i , j, pattern, grid);
                    st.insert(pattern);
                }
            }
        }

        return st.size();
    }
};







// https://leetcode.com/problems/number-of-distinct-islands-ii/

/*
You are given an m x n binary matrix grid. 
An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
An island is considered to be the same as another if they have the same shape, 
or have the same shape after rotation (90, 180, or 270 degrees only) 
or reflection (left/right direction or up/down direction).
Return the number of distinct islands.
*/

/*
Intuition
---------
* After we get coordinates for an island, compute all possible rotations/reflections 
  (https://en.wikipedia.org/wiki/Dihedral_group) of it and then sort them using the default comparison. 
* The first representation in this order is then the canonical one.

* Each island has 8 equivalent arrangements, which can be formed by combinations of reflections / rotations. 
  So compute all those arrangements (s[0], s[1], .., s[7]) and sort them using default ordering, and return the first arrangement. 
  Equivalent island has the same set of equivalent arrangements so the norm function return the same value.
*/
class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    bool isSafe(int i, int j, vector<vector<int>>& grid) {
        return !(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0);
    }

    void dfs(int x, int y, int srcX, int srcY, vector<pair<int,int>>& pattern, vector<vector<int>>& grid) {
        // mark as visited
        grid[x][y] = 0;
        
        // normalize the data
        pattern.push_back({x - srcX, y - srcY});

        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z];
            int ny = y + dy[z];

            if(!isSafe(nx, ny, grid)) continue;

            dfs(nx, ny, srcX, srcY, pattern, grid);
        }
    }

    vector<pair<int, int>> norm(vector<pair<int, int>>& pattern) {
        // find 4 rotations + 4 reflections = total 8 ways of representation
        vector<vector<pair<int, int>>> s(8);
        for (auto &it: pattern) {
            int x = it.first;
            int y = it.second;
            s[0].push_back({ x, y });
            s[1].push_back({ x, -y });
            s[2].push_back({ -x, y });
            s[3].push_back({ -x, -y });
            s[4].push_back({ y, x });
            s[5].push_back({ y, -x });
            s[6].push_back({ -y, x });
            s[7].push_back({ -y, -x });
        }

        for (int i = 0; i < s.size(); i++) {
            sort(s[i].begin(), s[i].end());
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 1; j < pattern.size(); j++) {
                s[i][j].first = s[i][j].first - s[i][0].first;
                s[i][j].second = s[i][j].second - s[i][0].second;
            }
            s[i][0].first = 0;
            s[i][0].second = 0;
        }
        sort(s.begin(), s.end());
        return s[0];
    }

    int numDistinctIslands2(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        set<vector<pair<int,int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    vector<pair<int, int>> pattern;
                    dfs(i, j, i , j, pattern, grid);
                    st.insert(norm(pattern));
                }
            }
        }

        return st.size();
    }
};

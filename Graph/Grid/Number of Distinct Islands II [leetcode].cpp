// https://www.lintcode.com/problem/804/


/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
Count the number of distinct islands. An island is considered to be the same as another if they have the same shape, 
or have the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).
*/



// https://www.tutorialspoint.com/number-of-distinct-islands-ii-in-cplusplus
// Method 1:
class Solution {
public:
    using pii = pair<int, int>;
    int n, m, cnt;
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

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(!isSafe(i, j, grid)) return;

        vis[i][j] = 1;
        a.push_back({i, j});

        for(int z = 0; z < 4; z++) {
            dfs(i + dx[z], j + dy[z], grid);
        }
    }

    void norm(){
        vector<vector<pair<int, int> > > s(8);
        for (int i = 0; i < a.size(); i++) {
            int x = a[i].first;
            int y = a[i].second;
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
            for (int j = 1; j < a.size(); j++) {
                s[i][j].first = s[i][j].first - s[i][0].first;
                s[i][j].second = s[i][j].second - s[i][0].second;
            }
            s[i][0].first = 0;
            s[i][0].second = 0;
        }
        sort(s.begin(), s.end());
        st.insert(s[0]);
    }

    int numDistinctIslands2(vector<vector<int>>& grid) {
        n = grid.size(), m = n ? grid[0].size() : 0;
        if (!n || !m) return 0;

        cnt = 0;
        vis = vector<vector<int>>(n, vector<int>(m, 0)); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    a.clear();
                    dfs(i, j, grid);
                    norm();
                }
            }
        }

        return st.size();
    }
};























class Solution {
public:
    using pii = pair<int, int>;
    int n, m, cnt;
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

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(!isSafe(i, j, grid)) return;

        vis[i][j] = 1;
        a.push_back({i, j});

        for(int z = 0; z < 4; z++) {
            dfs(i + dx[z], j + dy[z], grid);
        }
    }

    vector<vector<pii>> islands;
    string get(int x, int y) {
        return to_string(x) + "," + to_string(y) + ",";
    }
    
    pii rotate(int x, int y, int type) {
        if (type == 0) return {x, y};
        if (type == 1) return {y, n - 1 - x};
        if (type == 2) return {n - 1 - x, m - 1 - y};
        if (type == 3) return {m - 1 - y, x};
        if (type == 4) return {n - 1 - x, y};
        if (type == 5) return {x, m - 1 - y};
    }

    int numDistinctIslands2(vector<vector<int>>& grid) {
        n = grid.size(), m = n ? grid[0].size() : 0;
        if (!n || !m) return 0;

        cnt = 0;
        vis = vector<vector<int>>(n, vector<int>(m, 0)); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    a.clear();
                    dfs(i, j, grid);
                    islands.push_back(a);
                }
            }
        }

        int res = 0;
        unordered_set<string> S;
        for (int i = 0; i < islands.size(); i++) {
            vector<pii> cur = islands[i];
            vector<string> tmp;

            for (int j = 0; j < 6; j ++) {
                vector<pii> t;
                for (auto p: cur) {
                    t.push_back(rotate(p.first, p.second, j));
                }
                sort(t.begin(), t.end());
                auto start = t[0];
                string s = "";
                for (int i = 0; i < t.size(); i++) {
                    int x = t[i].first - start.first;
                    int y = t[i].second - start.second;
                    s += get(x, y);
                }
                tmp.push_back(s);
            }
            int find = 0;
            for (auto s : tmp) {
                if (S.find(s) != S.end()) find++;
            }
            if (find == 0) res++;

            for (auto s : tmp) {
                S.insert(s);
            }
        }
        return res;
    }
};

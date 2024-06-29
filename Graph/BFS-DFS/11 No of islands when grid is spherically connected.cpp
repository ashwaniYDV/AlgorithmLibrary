/*
Given a world map such that all the places covered via land are represented by ‘L’ and rest by ‘W’. 
Since world is spherical hence rows and columns are cyclic (before row 1 row n comes and after row n row 1 same for column). 
Count the number of islands.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    int dirx[4] = {1, -1, 0, 0};
    int diry[4] = {0, 0, 1, -1};

    bool isSafe(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        if (vis[i][j] || grid[i][j] != 'L') return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        if (!isSafe(i, j, grid, vis)) return;

        vis[i][j] = 1;
        for (int z = 0; z < 4; z++) {
            int ni = (i + dirx[z] + n) % n;
            int nj = (j + diry[z] + m) % m;
            dfs(ni, nj, grid, vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 'L') {
                    dfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    Solution obj;
    cout << obj.numIslands(a) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}


/*
Input:
4
4 4
L W W L
L L W L
L W W W
L W L L
4 4
L W W L
L L W W
L W W W
L W L W
2 2
L L
L L
3 3
W W W
W L W
W W W


Output:
1
2
1
1
*/

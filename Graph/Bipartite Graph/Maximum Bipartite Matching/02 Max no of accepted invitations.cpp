// https://leetcode.com/problems/maximum-number-of-accepted-invitations/
// https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html

/*
There are m boys and n girls in a class attending an upcoming party.
You are given an m x n integer matrix grid, where grid[i][j] equals 0 or 1. 
If grid[i][j] == 1, then that means the ith boy can invite the jth girl to the party. 
A boy can invite at most one girl, and a girl can accept at most one invitation from a boy.
Return max possible number of accepted invitations. 


Input: grid = [[1,1,1],
               [1,0,1],
               [0,0,1]]
Output: 3
Explanation: The invitations are sent as follows:
- The 1st boy invites the 2nd girl.
- The 2nd boy invites the 1st girl.
- The 3rd boy invites the 3rd girl.

Input: grid = [[1,0,1,0],
               [1,0,0,0],
               [0,0,1,0],
               [1,1,1,0]]
Output: 3
Explanation: The invitations are sent as follows:
-The 1st boy invites the 3rd girl.
-The 2nd boy invites the 1st girl.
-The 3rd boy invites no one.
-The 4th boy invites the 2nd girl.
 
Constraints:
1 <= m, n <= 200
*/



// https://youtu.be/70cuAeXs6rk?si=ZIelUBCMGZ2pSx0u
// Method 1.1: Kuhn's algorithm
class Solution {
    int m, n;
public:
    // returns true if a new match is made
    bool bipartiteMatch(int u, vector<bool>& vis, vector<int>& matching, vector<vector<int>>& grid) {
        vis[u] = true;

        for (int v = 0; v < m; v++) {
            if (grid[u][v] == 0) {
                continue;
            }
            
            // if girl is not taken (matching[v] = -1), then match this girl; or
            // if girl is already taken, then take this girl and try to match previous boy of this girl (ie matching[v]) to some other girl
            if (matching[v] == -1 || (!vis[matching[v]] && bipartiteMatch(matching[v], vis, matching, grid))) {
                matching[v] = u;
                return true;
            }
       }
        
       return false;
    }
    
    int maximumInvitations(vector<vector<int>>& grid) {
        n = grid.size(); // no of boys
        m = grid[0].size(); // no of girls
        vector<int> matching(m, -1);
        
        int matches = 0;
        for (int boy = 0; boy < n; boy++) {
            vector<bool> vis(n, false);
            // try to find a girl for boy
            // but also make sure previous matched boys still have girls (though boy->girl connection may change)
            if (bipartiteMatch(boy, vis, matching, grid)) {
                matches++;
            }
        }
        return matches;
    }
};



// Method 1.2: Kuhn's algorithm
class Solution {
    int m, n;
public:
    // returns true if a new match is made
    bool bipartiteMatch(int u, vector<bool>& vis, vector<int>& matching, vector<vector<int>>& grid) {
        vis[u] = true;

        for (int v = 0; v < m; v++) {
            if (grid[u][v] == 0) {
                continue;
            }
            
            // if girl is not taken (matching[v] = -1), then match this girl; or
            // if girl is already taken, then take this girl and try to match previous boy of this girl (ie matching[v]) to some other girl
            if (matching[v] == -1 || (!vis[matching[v]] && bipartiteMatch(matching[v], vis, matching, grid))) {
                matching[v] = u;
                return true;
            }
       }
        
       return false;
    }
    
    int maximumInvitations(vector<vector<int>>& grid) {
        n = grid.size(); // no of boys
        m = grid[0].size(); // no of girls
        vector<int> matching(m, -1);
        
        for (int boy = 0; boy < n; boy++) {
            vector<bool> vis(n, false);
            // try to find a girl for boy
            // but also make sure previous matched boys still have girls (though boy->girl connection may change)
            bipartiteMatch(boy, vis, matching, grid);
        }
        
        int matches = 0;
        for(int i = 0; i < m; i++) {
            if(matching[i] != -1) matches++;
        }
        return matches;
    }
};









// TLE solution
class Solution {
public:
    int n, m;

    int f(int i, vector<int> check, vector<vector<int>>& grid) {
        if(i == n) return 0;

        int res = f(i+1, check, grid);
        for(int j = 0; j < m; j++) {
            if(grid[i][j] && !check[j]) {
                check[j] = 1;
                res = max(res, 1 + f(i+1, check, grid));
                check[j] = 0;
            }
        }

        return res;
    }

    int maximumInvitations(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<int> check(m, 0);
        return f(0, check, grid);
    }
};
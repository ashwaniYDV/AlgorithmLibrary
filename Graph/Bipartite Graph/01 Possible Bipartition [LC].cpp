// https://leetcode.com/problems/possible-bipartition/

/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. 
Each person may dislike some other people, and they should not go into the same group.
Given the integer n and the array dislikes where dislikes[i] = [ai, bi] 
indicates that the person labeled ai does not like the person labeled bi, 
return true if it is possible to split everyone into two groups in this way.

Input: 
n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].
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

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n+1);
        vector<int> color(n+1);

        for(auto it: dislikes) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }

        for(int i = 1; i <= n; i++) {
            if(color[i] == 0 && !dfs(i, 1, color, g)) return false;
        }

        return true;
    }
};
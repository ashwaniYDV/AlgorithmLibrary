// https://leetcode.com/problems/evaluate-division/

/*
You are given an array of variable pairs equations and an array of real numbers values, 
where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. 
Each Ai or Bi is a string that represents a single variable.
You are also given some queries, 
where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. 
If a single answer cannot be determined, return -1.0.
Note: The input is always valid. 
      You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
      The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.


Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
*/

class Solution {
public:
    double bfs(string src, string dest, unordered_map<string, vector<pair<string, double>>>& g) {
        if(g[src].size() == 0) return -1;

        unordered_map<string, bool> vis;
        vis[src] = 1;
        queue<pair<string, double>> q;
        q.push({src, 1.0});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            string u = it.first;
            double dis = it.second;

            if(u == dest) return dis;

            for(auto it: g[u]) {
                if(!vis[it.first]) {
                    q.push({it.first, dis * it.second});
                    vis[it.first] = 1;
                }
            }
        }
        return -1;
    } 
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> g;
        for(int i = 0; i < equations.size(); i++) {
            g[equations[i][0]].push_back({equations[i][1], values[i]});
            g[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> res;
        for(auto &it: queries) {
            res.push_back(bfs(it[0], it[1], g));
        }

        return res;
    }
};
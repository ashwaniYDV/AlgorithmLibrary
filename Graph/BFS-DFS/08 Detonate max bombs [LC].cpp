// https://leetcode.com/problems/detonate-the-maximum-bombs/

/*
You are given a list of bombs. 
The range of a bomb is defined as the area where its effect can be felt. 
This area is in the shape of a circle with the center as the location of the bomb.
The bombs are represented as bombs[i] = [xi, yi, ri]. 
ri denotes the radius of its range.
You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. 
These bombs will further detonate the bombs that lie in their ranges.
Given the list of bombs, return max no of bombs that can be detonated 
if you are allowed to detonate only one bomb.

Input: 
    bombs = [[2,1,3],[6,1,4]]
Output: 
    2
Explanation:
    If we detonate the left bomb, the right bomb will not be affected.
    But if we detonate the right bomb, both bombs will be detonated.
    So the maximum bombs that can be detonated is max(1, 2) = 2.
*/

/*
Intuition
---------
We can represent bombs using a directed graph - 
when a bomb i can detonate bomb j, there is an edge from i to j. 
Note that the opposite may not be true.
We have to return max size of any connected component.
*/

class Solution {
public:
    bool checkDetonate(vector<int>& c1, vector<int>& c2) {
        long long x1 = c1[0], y1 = c1[1], r1 = c1[2];
        long long x2 = c2[0], y2 = c2[1];
        long long cDisSquare = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
        return cDisSquare <= (r1*r1);
    }

    int dfs(int u, vector<bool>& vis, vector<vector<int>>& g) {
        vis[u] = 1;
        int cnt = 1;

        for(int v: g[u]) {
            if(!vis[v]) cnt += dfs(v, vis, g);
        }
        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> g(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                // check if bomb_i can detonate bomb_j
                if(checkDetonate(bombs[i], bombs[j])) {
                    g[i].push_back(j);
                }
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            // we cannot use global vis, since its a directed graph
            vector<bool> vis(n, 0);
            res = max(res, dfs(i, vis, g));
        }        

        return res;
    }
};
// https://leetcode.com/problems/course-schedule-iv/

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
Return a boolean array answer, where answer[j] is the answer to the jth query.



Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
Course 0 is not a prerequisite of course 1, but the opposite is true.

Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites, and each course is independent.


Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]
 

Constraints:
2 <= numCourses <= 100
0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
prerequisites[i].length == 2
0 <= ai, bi <= numCourses - 1
ai != bi
All the pairs [ai, bi] are unique.
The prerequisites graph has no cycles.
1 <= queries.length <= 10^4
0 <= ui, vi <= numCourses - 1
ui != vi
*/


// Method 1.1: Floyd Warshall
class Solution {
public:
    const int INF = 1e9;

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<long long>> dp(n, vector<long long>(n, INF));

        for(int i = 0; i < n; i++) dp[i][i] = 0;

        for(auto& it: prerequisites) {
            int u = it[0], v = it[1];
            dp[u][v] = 1;
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        vector<bool> res;
        for(auto& it: queries) {
            int u = it[0], v = it[1];
            res.push_back(dp[u][v] != INF);
        }
        return res;
    }
};


// Method 1.2: Floyd Warshall
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (auto& it: prerequisites) {
            int u = it[0], v = it[1];
            dp[u][v] = true;
        }

        for (int intermediate = 0; intermediate < n; intermediate++) {
            for (int src = 0; src < n; src++) {
                for (int target = 0; target < n; target++) {
                    // If src -> intermediate & intermediate -> target exists
                    // then src -> target will also exist.
                    dp[src][target] = dp[src][target] || (dp[src][intermediate] && dp[intermediate][target]);
                }
            }
        }

        vector<bool> res;
        for (auto& it: queries) {
            int u = it[0], v = it[1];
            res.push_back(dp[u][v]);
        }

        return res;
    }
};







// Method 2: Topological sort
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);
        for (auto& it: prerequisites) {
            int u = it[0], v = it[1];
            g[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Map from the node as key to the set of prerequisite nodes
        unordered_map<int, unordered_set<int>> nodePrerequisites;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v: g[u]) {
                nodePrerequisites[v].insert(u);
                for (auto ancestorOfU: nodePrerequisites[u]) {
                    nodePrerequisites[v].insert(ancestorOfU);
                }

                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        vector<bool> res;
        for (auto& it: queries) {
            int u = it[0], v = it[1];
            res.push_back(nodePrerequisites[v].contains(u));
        }

        return res;
    }
};









// Method 3
class Solution {
public:
    // Iterate over each node and perform BFS starting from it.
    // Mark the starting node as a prerequisite to all the nodes in the BFS traversal.
    void preprocess(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& g, vector<vector<bool>>& isPrerequisite) {
        for (int i = 0; i < n; i++) {
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto v : g[u]) {
                    // If we have marked i as a prerequisite of adj it implies we have visited it. 
                    // This is equivalent to using a visited array.
                    if (!isPrerequisite[i][v]) {
                        isPrerequisite[i][v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int n,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        for (auto& it: prerequisites) {
            int u = it[0], v = it[1];
            g[u].push_back(v);
        }

        vector<vector<bool>> isPrerequisite(n, vector<bool>(n, false));
        // Store the prerequisite for each node in the array.
        preprocess(n, prerequisites, g, isPrerequisite);

        vector<bool> res;
        for (auto& it: queries) {
            int u = it[0], v = it[1];
            res.push_back(isPrerequisite[u][v]);
        }

        return res;
    }
};

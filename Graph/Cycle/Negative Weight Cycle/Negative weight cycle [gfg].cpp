// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

/*
Given a weighted directed graph with n nodes and m edges. 
Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
*/

class Solution {
public:
    int isNegativeWeightCycle(int n, vector < vector < int >> edges) {
        vector < int > dis(n, INT_MAX);
        int src = 0;
        dis[src] = 0;
        for (int i = 1; i <= n - 1; i++) {
            for (auto x: edges) {
                int u = x[0];
                int v = x[1];
                int d = x[2];
                if (dis[u] < INT_MAX) {
                    dis[v] = min(dis[v], dis[u] + d);
                }
            }
        }

        for (auto x: edges) {
            int u = x[0];
            int v = x[1];
            int d = x[2];
            if (dis[u] != INT_MAX && dis[v] > dis[u] + d) {
                return true;
            }
        }

        return false;
    }
};














class Solution {
public:
    int isNegativeWeightCycle(int n, vector < vector < int >> edges) {
        vector < long long > dis(n, 1e9);
        int src = 0;
        dis[src] = 0;
        for (int i = 1; i <= n - 1; i++) {
            for (auto x: edges) {
                int u = x[0];
                int v = x[1];
                int d = x[2];
                dis[v] = min(dis[v], dis[u] + d);
            }
        }

        for (auto x: edges) {
            int u = x[0];
            int v = x[1];
            int d = x[2];
            if (dis[v] > dis[u] + d) {
                return true;
            }
        }

        return false;
    }
};












class Solution {
public:
    int isNegativeWeightCycle(int n, vector < vector < int >> edges) {
        vector < long long > dis(n, 1e9);
        int src = 0;
        dis[src] = 0;
        for (int i = 1; i <= n - 1; i++) {
            vector < long long > tempDis(dis);
            for (auto x: edges) {
                int u = x[0];
                int v = x[1];
                int d = x[2];
                tempDis[v] = min(tempDis[v], dis[u] + d);
            }
            dis = tempDis;
        }

        for (auto x: edges) {
            int u = x[0];
            int v = x[1];
            int d = x[2];
            if (dis[v] > dis[u] + d) {
                return true;
            }
        }

        return false;
    }
};

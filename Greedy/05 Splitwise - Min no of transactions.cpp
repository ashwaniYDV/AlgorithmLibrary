// https://leetcode.com/problems/optimal-account-balancing/description/
// https://medium.com/@mithunmk93/algorithm-behind-splitwises-debt-simplification-feature-8ac485e97688

/*
You are given an array of transactions transactions where transactions[i] = [fromi, toi, amounti] indicates that the person with ID = fromi gave amounti $ to the person with ID = toi.
Return the minimum number of transactions required to settle the debt.

Note
----
* Actual Solution by splitwise uses "Max Flow Algorithm" (Dinic or ford fulkerson)
* https://medium.com/@mithunmk93/algorithm-behind-splitwises-debt-simplification-feature-8ac485e97688
*/


class Solution {
public:
    int n = 15;
    int f(int i, vector<int>& balance) {
        if(i == n) return 0;

        if(balance[i] == 0) return f(i+1, balance);

        int res = INT_MAX;
        for(int j = i+1; j < n; j++) {
            int u = balance[i], v = balance[j];
            if(u * v < 0) {
                balance[j] = u + v;
                res = min(res, 1 + f(i+1, balance));

                // backtrack
                balance[j] = v;
            }
        }
        return res;
    }

    int minTransfers(vector<vector<int>>& txns) {
        vector<int> balance(n, 0);
        for(auto &it: txns) {
            int u = it[0], v = it[1], w = it[2];
            balance[u] -= w;
            balance[v] += w;
        }

        return f(0, balance);
    }
};



class Solution {
public:
    int f(int i, vector<int>& balance) {
        if(i == balance.size()) return 0;

        if(balance[i] == 0) return f(i+1, balance);

        int res = INT_MAX;
        for(int j = i+1; j < balance.size(); j++) {
            int u = balance[i], v = balance[j];
            if(u * v < 0) {
                balance[i] = 0;
                balance[j] = u + v;
                res = min(res, 1 + f(i+1, balance));

                // backtrack
                balance[i] = u;
                balance[j] = v;
            }
        }
        return res;
    }

    int minTransfers(vector<vector<int>>& txns) {
        int n = 0;
        for(auto &it: txns) {
            n = max({n, it[0], it[1]});
        }

        vector<int> balance(n+1, 0);
        for(auto &it: txns) {
            int u = it[0], v = it[1], w = it[2];
            balance[u] -= w;
            balance[v] += w;
        }

        return f(0, balance);
    }
};
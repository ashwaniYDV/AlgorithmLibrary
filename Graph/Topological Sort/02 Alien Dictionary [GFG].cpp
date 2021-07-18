// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
Find the order of characters in the alien language.
Note: Many orders may be possible, return any valid order.
*/

// Method 1: Kahn
class Solution {
public:
    static const int MXN = 26 + 5;
    int n, m;
    vector < int > g[MXN];
    int in [MXN];
    vector < int > res;

    string kahn(int n) {
        queue < int > q;
        for (int i = 0; i < n; i++) {
            if (in [i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v: g[u]) {
                in [v]--;
                if (in [v] == 0) q.push(v);
            }
        }

        if ((int) res.size() < n) {
            return "";
        }

        string str = "";
        for (int x: res) str += (char)(x + 'a');
        return str;
    }

    string findOrder(string dict[], int N, int K) {
        for (int i = 0; i < MXN; i++) {
            g[i].clear(); 
            in[i] = 0;
        }
        int impossible = 0;
        res.clear();

        for (int i = 0; i < N - 1; i++) {
            int j = i + 1;
            string s1 = dict[i], s2 = dict[j];
            int m = min(s1.size(), s2.size());
            int flag = 1;
            for (int i = 0; i < m; i++) {
                if (s1[i] != s2[i]) {
                    flag = 0;
                    g[s1[i] - 'a'].push_back(s2[i] - 'a'); 
                    in[s2[i] - 'a']++;
                    break;
                }
            }

            if (flag && (s1 > s2)) {
                impossible = 1;
            }
        }

        if (impossible) {
            return "";
        }

        return kahn(K);
    }
};










// Method 2: DFS
class Solution {
public:
    static const int MXN = 26 + 5;
    vector < int > g[MXN];
    int color[MXN];
    vector < int > res;
    int impossible;

    void dfs(int u) {
        color[u] = 1;

        for (int v: g[u]) {
            if (color[v] == 1) {
                impossible = 1;
                return;
            }
            if (color[v] == 0) {
                dfs(v);
            }
        }

        color[u] = 2;
        res.push_back(u);
    }

    string findOrder(string dict[], int N, int K) {
        for (int i = 0; i < MXN; i++) {
            g[i].clear();
            color[i] = 0;
        }
        impossible = 0;
        res.clear();

        for (int i = 0; i < N - 1; i++) {
            int j = i + 1;
            string s1 = dict[i], s2 = dict[j];
            int m = min(s1.size(), s2.size());
            int flag = 1;
            for (int i = 0; i < m; i++) {
                if (s1[i] != s2[i]) {
                    flag = 0;
                    g[s1[i] - 'a'].push_back(s2[i] - 'a');
                    break;
                }
            }

            if (flag && (s1 > s2)) {
                impossible = 1;
            }
        }

        if (impossible) {
            return "";
        }

        for (int i = 0; i < K; i++) {
            if (color[i] == 0) {
                dfs(i);
            }
            if (impossible) {
                return "";
            }
        }

        reverse(res.begin(), res.end());
        string str = "";
        for (int x: res) str += (char)(x + 'a');
        return str;
    }
};

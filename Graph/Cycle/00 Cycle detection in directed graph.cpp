// since it's for directed graph, therefore works for undirected as well


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int color[N]; // 0 = white, 1 = grey, 2 = black
bool cycleDetected = false;

void dfs(int u) {
    color[u] = 1; // mark grey (in current DFS path)

    for (int v : g[u]) {
        if (color[v] == 0) {
            // not visited
            dfs(v);
        } 
        else if (color[v] == 1) {
            // back edge → cycle found
            cycleDetected = true;
        }
    }

    color[u] = 2; // mark black (fully processed)
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); // directed edge
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    if (cycleDetected) {
        cout << "Yes, there is/are cycle(s)";
    } else {
        cout << "There is no cycle";
    }

    return 0;
}

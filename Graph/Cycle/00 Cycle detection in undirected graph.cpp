#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
bool visited[N];
bool cycleDetected = false;

void dfs(int u, int parent) {
    visited[u] = true;

    for (int v : g[u]) {
        if (visited[v] && v != parent) {
            cycleDetected = true;
            return;
        }

        if (!visited[v]) {
            dfs(v, u);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // undirected graph
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
            if (cycleDetected) break; // optional early exit
        }
    }

    if (cycleDetected) {
        cout << "Yes, there is/are cycle(s)";
    } else {
        cout << "There is no cycle";
    }

    return 0;
}

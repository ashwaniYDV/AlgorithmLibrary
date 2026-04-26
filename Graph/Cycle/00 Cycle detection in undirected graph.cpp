#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;

vector<int> g[N];
bool visited[N];
bool cycleDetected = false;

void dfs(int u, int parent) {
    visited[u] = true;

    for (int v : g[u]) {
        if (!visited[v]) {
            dfs(v, u);
        } 
        else if (v != parent) {
            // visited and not parent → cycle exists
            cycleDetected = true;
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
        }
    }

    if (cycleDetected) {
        cout << "Yes, there is/are cycle(s)";
    } else {
        cout << "There is no cycle";
    }

    return 0;
}

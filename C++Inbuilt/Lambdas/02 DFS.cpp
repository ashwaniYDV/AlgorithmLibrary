#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, u, v; 
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> vis(n);

    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Lambda function for DFS
    auto dfs = [&](int u, auto&& self) -> void {
        cout << u << " ";
        vis[u] = 1;
        for (auto& v : g[u]) {
            if (!vis[v]) self(v, self);
        }
    };

    dfs(0, dfs);
}







#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, u, v; 
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> vis(n);

    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Lambda function for DFS
    auto dfs = [&](int u, auto&& dfs) -> void {
        cout << u << " ";
        vis[u] = 1;
        for (auto& v : g[u]) {
            if (!vis[v]) dfs(v, dfs);
        }
    };

    dfs(0, dfs);
}
// https://cses.fi/problemset/task/1672/

/*
There are n cities and m roads between them. Your task is to process q queries 
where you have to determine the length of the shortest route between two given cities.

Input:
The first input line has three integers n, m and q: the number of cities, roads, and queries.
Then, there are m lines describing the roads. 
Each line has three integers a, b and c: there is a road between cities a and b whose length is c. 
All roads are two-way roads.
Finally, there are q lines describing the queries. 
Each line has two integers a and b: determine the length of the shortest route between cities a and b.

Output:
Print the length of the shortest route for each query. If there is no route, print −1 instead.
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 500+5;
const int INF = 1e18;
int n, m;
int g[N][N];

void solve() {
    int u, v, x, q;
    cin >> n >> m >> q;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
        }
    }

    while(m--) {
        cin >> u >> v >> x;
        g[u][v] = min(g[u][v], x);
        g[v][u] = min(g[v][u], x);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]); 
            }
        }
    }
    
    while(q--) {
        cin >> u >> v;
        cout << (g[u][v] == INF ? -1 : g[u][v]) << endl;
    }
}

int32_t main() {
    solve();
}











#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 500+5;
const int INF = 1e18;
int n, m;
int dis[N][N];
int g[N][N];

void solve() {
    int u, v, x, q;
    cin >> n >> m >> q;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
        }
    }

    while(m--) {
        cin >> u >> v >> x;
        g[u][v] = min(g[u][v], x);
        g[v][u] = min(g[v][u], x);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dis[i][j] = g[i][j];
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
            }
        }
    }
    
    while(q--) {
        cin >> u >> v;
        cout << (dis[u][v] == INF ? -1 : dis[u][v]) << endl;
    }
}

int32_t main() {
    solve();
}

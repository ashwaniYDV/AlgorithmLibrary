// https://cses.fi/problemset/task/1131/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;

vector<int> g[N];
int height[N];
int d = 0;
 
void dfs(int u, int par) {
	height[u] = 0;
	int mx1 = 0, mx2 = 0, child = 0;
 
	for (int v: g[u]) {
		if(v == par) continue;
 
		dfs(v, u);
 
		height[u] = max(height[u], 1 + height[v]);
 
		if(height[v] > mx1) {
			mx2 = mx1;
			mx1 = height[v];
		} else if(height[v] > mx2) {
			mx2 = height[v];
		}
 
		child++;
	}
 
	d = max(d, height[u]);
 
	if(child >= 2) {
		d = max(d, 2 + mx1 + mx2);
	}
}

int main() {
    int u, v;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    }

    dfs(1, 0);
    cout << d << endl;  
}










#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;

vector<int> g[N];
int d = 0;
 
int dfs(int u, int par) {
    int heightU = 0;
    int mx1 = 0, mx2 = 0, child = 0;
 
    for (int v: g[u]) {
        if(v == par) continue;
 
        int heightV = dfs(v, u);
 
        heightU = max(heightU, 1 + heightV);
 
        if(heightV > mx1) {
            mx2 = mx1;
            mx1 = heightV;
        } else if(heightV > mx2) {
            mx2 = heightV;
        }
 
        child++;
    }
 
    d = max(d, heightU);
 
    if(child >= 2) {
        d = max(d, 2 + mx1 + mx2);
    }

    return heightU;
}

int main() {
    int u, v;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    }

    dfs(1, 0);
    cout << d << endl;  
}
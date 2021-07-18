// https://youtu.be/VBxiavZYfoA

/*
You are given a tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes of the tree.
*/


/*
Note:
par is not needed in dp state since its just used to check if v == par
*/


const int N = 2e5+5;
int n, m;

vi g[N];
int dp[N][2][2];

int dfs(int u, int isCam, int isParCam, int par) {
    if(dp[u][isCam][isParCam] != -1) return dp[u][isCam][isParCam];
    
    int x = INF, y = INF, z = INF;

    if(isCam) {
        x = 1;
        for(int v: g[u]) {
            if(v == par) continue;
            x += min(dfs(v, 0, 1, u), dfs(v, 1, 1, u));
        }
    } else {
        if(isParCam) {
            y = 0;
            for(int v: g[u]) {
                if(v == par) continue;
                y += min(dfs(v, 0, 0, u), dfs(v, 1, 0, u));
            }
        } else {
            // atleast one child sould have camera i.e. atleast one child sould have isCam = true
            
            int total = 0;
            for(int v: g[u]) {
                if(v == par) continue;
                total += min(dfs(v, 0, 0, u), dfs(v, 1, 0, u));
            }

            // applying atleast one child should have camera condition            
            for(int v: g[u]) {
                if(v == par) continue;
                int temp = total - min(dfs(v, 0, 0, u), dfs(v, 1, 0, u));
                z = min(z, dfs(v, 1, 0, u) + temp);
            }
        }
    }
    
    return dp[u][isCam][isParCam] = min({x, y, z});
}

void solve() {
    int u, v;
    cin >> n;

    f(i, n - 1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    memset(dp, -1, sizeof dp);
    cout << min(dfs(1, 0, 0, -1), dfs(1, 1, 0, -1));
}

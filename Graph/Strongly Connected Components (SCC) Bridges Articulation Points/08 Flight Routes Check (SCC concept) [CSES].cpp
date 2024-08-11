// https://cses.fi/problemset/task/1682/

/*
There are n cities and m flight connections. Your task is to check if you can travel from any city to any other city using the available flights.

Input:
The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,…,n.
After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. 
All flights are one-way flights.

Output:
Print "YES" if all routes are possible, and "NO" otherwise. 
In the latter case also print two cities a and b such that you cannot travel from city a to city b.
*/

const int N = 2e5+5;
int n, m;

vector<int> g[N], transpose_g[N];
int vis[N];
stack<int> st;

void dfs(int u) {
    vis[u] = 1;
    for(int v: g[u]) {
        if(!vis[v]) dfs(v);
    }
    st.push(u);
}

void revDfs(int u) {
    vis[u] = 1;
    for(int v: transpose_g[u]) {
        if(!vis[v]) revDfs(v);
    }
}

void solve() {
    int u, v;
    cin >> n >> m;

    f(i, m) cin >> u >> v, g[u].pb(v), transpose_g[v].pb(u);
    
    // to store nodes in decreasing order of out time in stack
    loop(i, 1, n) {
        if(!vis[i]) dfs(i);
    }

    loop(i, 1, n) vis[i] = 0;
    ll totalSCC = 0;
    
    vector<int> vec;
    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            totalSCC++;
            revDfs(node);
            vec.pb(node);
        }
    }

    if(totalSCC == 1) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    cout << vec[1] << " " << vec[0] << endl;
}

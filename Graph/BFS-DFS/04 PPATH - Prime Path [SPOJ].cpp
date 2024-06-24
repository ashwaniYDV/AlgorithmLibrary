// https://www.spoj.com/problems/PPATH/

/*
Given two 4 digit prime numbers A and B, 
find the min no of operations to convert A to B.
In one step you can change one digit of the number and the resulting number must be prime.
*/

const int N = 1e5+5;
int n, m;

vector<int> g[N];
vector<int> primes;
int dist[N];

bool check(int i, int j) {
    int cnt = 0;
    while(i) {
        if((i % 10) != (j % 10)) cnt++;
        i /= 10;
        j /= 10;
    }
    return cnt == 1;
}

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void buildGraph() {
    for(int i = 1000; i <= 9999; i++) {
        if (isPrime(i)) primes.pb(i);
    }

    for(int i = 0; i < primes.size(); i++) {
        for(int j = i + 1; j < primes.size(); j++) {
            int u = primes[i], v = primes[j];
            if (check(u, v)) {
                g[u].pb(v);
                g[v].pb(u);
            }
        }           
    }
}

void bfs(int src, int dest) {
    for(int i = 1000; i <= 9999; i++) {
        dist[i] = INF;
    }
    
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v: g[u]) {
            if(dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    if(dist[dest] == INF)
        cout << "IMPOSSIBLE\n";
    else
        cout << dist[dest] << endl;

}

void solve() {
    buildGraph();

    int t, u, v;
    cin >> t;
    while(t--) {
        cin >> u >> v;
        bfs(u, v);
    }
}

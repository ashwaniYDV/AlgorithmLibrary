// hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/pasha-jumps-on-a-permutation-june-easy-19-9e608b68/

/*
Problem:
You are standing at position 1. From position i, you can walk to i+1 or i-1 with cost 1. 
From position i, you can travel to without any cost to p[i] (p is a permutation of numbers 1...n). 
You have to reach position n. Determine the minimum possible cost.

Input format

First line: T denotes the number of test cases (1 <= T <= 10)
For each test case:
  First line: n (1 <= n <= 50,000)
  Second line: n integers where the i'th integer is p[i]

Output format
Print the minimum possible cost.
*/

const int N = 1e5+5;
int n, m;

int p[N];

void bfs01(int src, int dest) {
    vector<int> dis(n+1, INF);

    deque<int> q;
    q.push_back(src);
    dis[src] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop_front();

        int v = p[u];
        int w = 0;
        if(dis[v] > dis[u] + w) {
            dis[v] = dis[u] + w;
            q.push_front(v);
        }

        v = u + 1;
        if(v <= n) {
            int w = 1;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push_back(v);
            }
        }
        v = u - 1;
        if(v >= 1) {
            int w = 1;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push_back(v);
            }
        }
    }

    if(dis[dest] != INF) cout << dis[dest] << endl;
}

void solve() {
    int x, y, z;
    cin >> n;
    loop(i, 1, n) cin >> p[i];

    bfs01(1, n);
}

signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    PRECISION(10);
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}

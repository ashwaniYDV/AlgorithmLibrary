// https://cses.fi/problemset/task/1750/
// https://usaco.guide/problems/cses-1750-planets-queries-i/solution

/*
You are playing a game consisting of n planets. Each planet has a teleporter to another planet (or the planet itself).
Your task is to process q queries of the form: when you begin on planet x and travel through k teleporters, which planet will you reach?

Input:
The first input line has two integers n and q: the number of planets and queries. The planets are numbered 1,2,…,n.
The second line has n integers t1,t2,…,tn: for each planet, the destination of the teleporter. It is possible that ti = i.
Finally, there are q lines describing the queries. Each line has two integers x and k: you start on planet x and travel through k teleporters.

Output:
Print the answer to each query.
*/


/*
Solution:
Construct a parent matrix (where parent[i][d] is the 2^dth parent of i). 
Then, we can answer each query by using binary lifting from the starting node based on the binary representation of the distance.
Since the query distance k can be up to 10^9, we set the maximum depth to log_2(10^9) = 30.
*/

const int N = 2e5+5;
int n, m;

const int height = 30;
int LCA[N][height + 1]; // LCA[node][i] == [node] 's [2^i]th parent
int par[N];

void initLCA() {
    // 2^0
    for(int i = 1; i <= n; i++) {
        LCA[i][0] = par[i];
    }

    // 2^i
    for(int i = 1; i < height; i++) {
        for(int node = 1; node <= n; node++) {
            int parNode = LCA[node][i-1];
            if(parNode != -1) {
              LCA[node][i] = LCA[parNode][i-1];
            } else {
              LCA[node][i] = -1;
            }
        }
    }
}

int getKthParent(int node, int k) {
    for(int i = 0; i < height; i++) {
        if(k & (1 << i)) {
            node = LCA[node][i];
            if(node == -1) return -1;
        }
    }
    return node;
}

void solve() {
    int q, x, k;
    cin >> n >> q;

    loop(i, 1, n) cin >> par[i];

    initLCA();

    while(q--) {
        cin >> x >> k;
        cout << getKthParent(x, k) << endl;
    }
}

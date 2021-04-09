// https://codingblocks.com/resources/travelling-salesman/
// NP Hard Problem

const ll N = 4;
ll dp[int(pow(2, N))][N];

ll dis[N][N] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

// all cities have been visited (1111)
ll VISITED_ALL = (1 << N) - 1;

ll tsp(ll mask, ll curCity) {
    // base case
    if (mask == VISITED_ALL) {
        return dis[curCity][0];
    }

    if(dp[mask][curCity] != -1) return dp[mask][curCity];

    ll minDistance = INT_MAX;

    // try to go to unvisited cities
    for(ll city = 0; city < N; city++) {
        if((mask & (1 << city)) == 0) {
            ll tempDis = dis[curCity][city] + tsp(mask | (1 << city), city);
            minDistance = min(minDistance, tempDis);
        }
    }

    return dp[mask][curCity] = minDistance;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cout << "Min weight hamiltonian path weight: ";
    cout << tsp(1, 0) << endl;
}

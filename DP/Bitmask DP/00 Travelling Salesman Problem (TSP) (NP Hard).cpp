// https://www.geeksforgeeks.org/travelling-salesman-problem-using-dynamic-programming/
// NP Hard Problem

/*
Travelling Salesman Problem (TSP): 

Given a set of cities and the distance between every pair of cities, 
the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point. 
Find a minimum weight Hamiltonian Cycle. 

Note: Diff bw Hamiltonian Cycle and TSP. 
Hamiltonian cycle problem is to find if there exists a tour that visits every city exactly once. 
Here we know that Hamiltonian Tour exists (because the graph is complete) and infact, many such tours exist.
The problem is to find a minimum weight Hamiltonian Cycle. 
*/


#include <bits/stdc++.h>
using namespace std;

const int N = 4;
long long dp[N][1 << N];

long long dis[N][N] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

// All cities have been visited (1111)
const long long VISITED_ALL = (1 << N) - 1;

long long tsp(long long curCity, long long mask) {
    if (mask == VISITED_ALL) {
        return dis[curCity][0];
    }

    if (dp[curCity][mask] != -1) return dp[curCity][mask];

    long long minDistance = LLONG_MAX;

    // Try to go to unvisited cities
    for (long long city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            long long tempDis = dis[curCity][city] + tsp(city, mask | (1 << city));
            minDistance = min(minDistance, tempDis);
        }
    }

    return dp[curCity][mask] = minDistance;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cout << "Min weight Hamiltonian path weight: " << tsp(0, 1) << endl;
}

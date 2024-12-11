// https://leetcode.com/discuss/interview-question/1647092/coinbase-virtual-on-site-interview-questions

/*
You are given a list of currency relationships with exchange values. 
Find the best exchange rate from currency1 to currency2.
Note: There is no possiblility of arbitrage.

Test 1: 
USD,CAD,1.3;USD,GBP,0.71;USD,JPY,109;GBP,JPY,155
USD
JPY
Output: 110.05

Test 2: 
USD,GBP,0.7;USD,JPY,109;GBP,JPY,155;CAD,CNY,5.27;CAD,KRW,921
USD
CNY
Output: -1.0
*/



/*
Intuition
---------
First you need to create a graph with the exchange rate as the edge weight. 
Whatever path that gives you the higher value when multiplying the edges is your solution. 
*/


// Method 1: Backtracking
// check if as need to add reverse edge also with 1/w weight
#include <bits/stdc++.h>
using namespace std;

double bestExchangeRate(string src, string dest, unordered_map<string, unordered_map<string, double>>& g, unordered_map<string, int>& vis) {
    if(src == dest) return 1;
    
    vis[src] = 1;

    double maxRate = 0;
    for(auto& [v, w] : g[src]) {
        if(vis[v] == 1) continue;
        maxRate = max(maxRate, w * bestExchangeRate(v, dest, g, vis));
    }

    // backtrack
    vis[src] = 0;
    
    return maxRate;
}

int main() {
    int n;
    cin >> n;

    unordered_map<string, unordered_map<string, double>> g;

    while(n--) {
        string u, v;
        double w;
        cin >> u >> v >> w;
        g[u][v] = w;
        // g[v][u] = 1 / w;
    }
    
    string src, dest;
    cin >> src >> dest;
    
    unordered_map<string, int> vis;
    double rate = bestExchangeRate(src, dest, g, vis);

    cout << (rate == 0 ? -1 : rate) << endl;
}

/*
Input
-----
4
USD CAD 1.3
USD GBP 0.71
gUSD JPY 109
GBP JPY 155
USD
JPY

Output = 110.05


Input
-----
5
USD GBP 0.7
USD JPY 109
GBP JPY 155
CAD CNY 5.27
CAD KRW 921
USD
CNY

Output = -1.0
*/






// Method 2: Bellman-Ford
/*
First you need to convert the problem to a shortest path problem. 

To do so:
Instead of finding the value of E1 x E2 x E3 ... and find the path with max value, find the max value for
log(E1 x E2 x E3 ...) = log(E1) + log(E2) + log(E3) + ...

For the shortest path, we look for the minimum value, so we multiply each edge by -1. 
Now we are looking for a min value for:
-log(E1 x E2 x E3 ...) = -log(E1) - log(E2) - log(E3) - ....

Thus after taking a logarithm of edges weight and negating them, we have a shortest path problem with negative edges. 
Dijkstra doesn't work (due to negative edges) so we need to apply Bellman-Ford (works for negative edges but not for negative weight cycles).
Since its not a currency arbitrage question, so we can't have negative weight cycles.
*/

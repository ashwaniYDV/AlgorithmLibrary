// https://anilpai.medium.com/currency-arbitrage-using-bellman-ford-algorithm-8938dcea56ea

// https://www.linkedin.com/feed/update/urn:li:activity:7418275911759958016/
/*
Imagine a closed system where you trade 1 dollar for 0.9 Euros, trade those Euros for 150 Yen, and then trade those Yen back for 1.10 dollars. 
In the span of three transactions, you have manifested a 10% return out of thin air! 
In an efficient market, the product of exchange rates along any closed loop should equal exactly 1.0. 
When it does not, we have a financial "free lunch" known as currency arbitrage. So how can we find them?

To understand the solution, we must first frame the market as a weighted directed graph G = (V, E). 
In this model, each vertex represents a currency, and each edge (u, v) represents the exchange rate R(u, v). 
If we follow a cycle of trades, our goal is to find a path where the product of the rates is greater than 1.0. 
Formally, we seek a cycle where R1 * R2 * ... * Rn > 1.

Now we face a hurdle, most standard graph algorithms are designed for additive weights, not multiplicative ones. 
This is where the Logarithmic Transformation becomes essential. 
By taking the negative natural logarithm of the exchange rates, we transform the multiplication of rates into the addition of weights.
Formally, if we seek a path where R1 * R2 * R3 > 1, this is equivalent to log(R1) + log(R2) + log(R3) > 0. 
By negating the values, the inequality flips: -log(R1) - log(R2) - log(R3) < 0.

The problem is now reduced to finding a negative weight cycle in a directed graph. 
This is where the Bellman-Ford algorithm excels. Unlike other shortest-path algorithms, 
Bellman-Ford can detect negative cycles, making it the perfect tool for identifying these rare, profitable discrepancies in global markets.

Don't get too excited tho, it's not free money because HFTs have bigger machines and better algorithms to identify and neutralize such fleeting opportunities!
*/

/*
Problem Statement
-----------------
Suppose we are given a table of currency exchange rates, represented as a 2D array. 
Determine whether there is a possible arbitrage, 
i.e, whether there are certain sequence of trades you can make, 
starting with some amount A of any currency, 
such that you can end up with some amount greater than A of same currency.

Let’s say, 1 USD bought 0.82 Euro, 
1 Euro bought 129.7 Japanese Yen, 
1 Japanese Yen bought 12 Turkish Lira, 
and 1 Turkish Lira bought 0.0008 USD. 

Then, by converting currencies, 
a trader can start with 1 USD and buy USD, 
thus turning a 0.82*129.7*12*0.008 = 1.02 USD, thus making a 2% profit.


Intuition (Finding arbitrage)
------------------------------
Arbitrage opportunities arise when a cycle is determined such that 
the edge weights satisfy the following expression:
w1 * w2 * w3 * … * wn > 1                                   --------------- (i)

The above constraint of finding the cycles is harder in graphs. 
Instead we must transform the edge weights of the graph such that 
the standard graph algorithms can be applied.

Let’s take the logarithm on both sides, such that:
log(w1) + log(w2) + log(w3) + … + log(wn) > 0               --------------- (ii)

Taking the negative log, this becomes:
(-log(w1)) + (-log(w2)) + (-log(w3)) + … + (-log(wn)) < 0   --------------- (iii)

Therefore we can conclude that if we can find a cycle of vertices 
such that the sum of their weights is negative, 
then we can conclude there exists an opportunity for currency arbitrage. 

Luckily, Bellman-Ford algorithm is a standard graph algorithm 
that can be used to easily detect negative weight cycles in O(|V * E|) time.
*/

/*
# Time Complexity: O(N^3)
# Space Complexity: O(N^2)
*/



// Authors python solution (which i think is not 100% correct, check my comment in his blog to know which case is failing)
from typing import Tuple, List
from math import log

rates = [
    [1, 0.23, 0.25, 16.43, 18.21, 4.94],
    [4.34, 1, 1.11, 71.40, 79.09, 21.44],
    [3.93, 0.90, 1, 64.52, 71.48, 19.37],
    [0.061, 0.014, 0.015, 1, 1.11, 0.30],
    [0.055, 0.013, 0.014, 0.90, 1, 0.27],
    [0.20, 0.047, 0.052, 3.33, 3.69, 1],
]

currencies = ('PLN', 'EUR', 'USD', 'RUB', 'INR', 'MXN')


def negate_logarithm_convertor(graph: Tuple[Tuple[float]]) -> List[List[float]]:
    ''' log of each rate in graph and negate it'''
    result = [[-log(edge) for edge in row] for row in graph]
    return result


def arbitrage(currency_tuple: tuple, rates_matrix: Tuple[Tuple[float, ...]]):
    ''' Calculates arbitrage situations and prints out the details of this calculations'''

    trans_graph = negate_logarithm_convertor(rates_matrix)

    # Pick any source vertex -- we can run Bellman-Ford from any vertex and get the right result

    source = 0
    n = len(trans_graph)
    min_dist = [float('inf')] * n

    pre = [-1] * n
    
    min_dist[source] = source

    # 'Relax edges |V-1| times'
    for _ in range(n-1):
        for source_curr in range(n):
            for dest_curr in range(n):
                if min_dist[dest_curr] > min_dist[source_curr] + trans_graph[source_curr][dest_curr]:
                    min_dist[dest_curr] = min_dist[source_curr] + trans_graph[source_curr][dest_curr]
                    pre[dest_curr] = source_curr

    # if we can still relax edges, then we have a negative cycle
    for source_curr in range(n):
        for dest_curr in range(n):
            if min_dist[dest_curr] > min_dist[source_curr] + trans_graph[source_curr][dest_curr]:
                # negative cycle exists, and use the predecessor chain to print the cycle
                print_cycle = [dest_curr]
                # Start from the source and go backwards until you see the source vertex again
                while True:
                    source_curr = pre[source_curr]
                    if source_curr in print_cycle:
                        break
                    print_cycle.append(source_curr)
                print_cycle.append(dest_curr)
                print("Arbitrage Opportunity: \n")
                print(" --> ".join([currencies[p] for p in print_cycle[::-1]]))


if __name__ == "__main__":
    arbitrage(currencies, rates)

/*
Arbitrage Opportunity: 
RUB --> INR --> RUB

Arbitrage Opportunity: 
PLN --> MXN --> USD --> RUB --> INR --> PLN

Arbitrage Opportunity: 
RUB --> USD --> MXN --> RUB

Arbitrage Opportunity: 
PLN --> USD --> MXN --> PLN
*/







// My solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const double INF = 1e9;

    vector<vector<double>> negative_logarithm_convertor(vector<vector<double>>& rates) {
        vector<vector<double>> g(rates.size(), vector<double>(rates[0].size()));

        for (size_t i = 0; i < rates.size(); ++i) {
            for (size_t j = 0; j < rates[i].size(); ++j) {
                g[i][j] = -log(rates[i][j]);
            }
        }
        return g;
    }

    void solve(vector<vector<double>>& rates, vector<string>& currencies) {
        vector<vector<double>> transformedRates = negative_logarithm_convertor(rates);
        
        int source = 0;
        size_t n = transformedRates.size();

        vector<double> dis(n, INF);
        vector<int> parent(n, -1);
        
        dis[source] = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    if (transformedRates[u][v] != INF && dis[v] > dis[u] + transformedRates[u][v]) {
                        dis[v] = dis[u] + transformedRates[u][v];
                        parent[v] = u;
                    }
                }
            }
        }
        
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (dis[v] > dis[u] + transformedRates[u][v]) {
                    int cycle_start = v, cycle_end = u;
                    vector<int> cycle;

                    cycle.push_back(cycle_start);
                    for (int node = cycle_end; node != cycle_start; node = parent[node]) {
                        cycle.push_back(node);
                    }
                    cycle.push_back(cycle_start);

                    reverse(cycle.begin(), cycle.end());

                    cout << "Arbitrage Opportunity: \n";
                    for (int i = 0; i < cycle.size(); i++) {
                        cout << currencies[cycle[i]];
                        if(i != cycle.size() - 1) cout << " --> ";
                    }
                    cout << endl;

                    cout << "Arbitrage cost: ";
                    double cost = 1.0;
                    for (int i = 1; i < cycle.size(); i++) {
                        cost *= rates[cycle[i-1]][cycle[i]];
                    }
                    cout << cost << endl << endl;

                    return;
                }
            }
        }
    }
    
};

int main() {
    vector<vector<double>> rates = {
        {1, 0.23, 0.25, 16.43, 18.21, 4.94},
        {4.34, 1, 1.11, 71.40, 79.09, 21.44},
        {3.93, 0.90, 1, 64.52, 71.48, 19.37},
        {0.061, 0.014, 0.015, 1, 1.11, 0.30},
        {0.055, 0.013, 0.014, 0.90, 1, 0.27},
        {0.20, 0.047, 0.052, 3.33, 3.69, 1},
    };

    vector<string> currencies = {"PLN", "EUR", "USD", "RUB", "INR", "MXN"};

    Solution obj;
    obj.solve(rates, currencies);    
    return 0;
}

/*
Arbitrage Opportunity: 
RUB --> INR --> PLN --> RUB
Arbitrage cost: 1.00305
*/

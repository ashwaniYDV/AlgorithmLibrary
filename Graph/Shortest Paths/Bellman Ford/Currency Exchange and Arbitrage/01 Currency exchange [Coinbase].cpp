// https://leetcode.com/discuss/interview-question/1647092/coinbase-virtual-on-site-interview-questions

/*
You are given a data set in the form of list of <currency1 - currency2 - ask - bid>.
ask mean how much currency2 do you have to spend to buy one unit of currency1.
bid mean how much currency2 you will get if you sell one unit of currency2. 
Now given any two currencied X and Y, find the best conversion rate.
Note: There is no possiblility of arbitrage.

// give me proper test case for this question


[
    {"cur1": "USD", "cur2": "BTC", "bid": 99, "ask": 100},
    {"cur1": "EUR", "cur2": "BTC", "bid": 115, "ask": 120},
    {"cur1": "USD", "cur2": "ETH", "bid": 98, "ask": 100},
    {"cur1": "EUR", "cur2": "ETH", "bid": 400, "ask": 420}
]
*/


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
        double ask, bid;
        cin >> u >> v >> ask >> bid;
        g[u][v] = ask;
        g[v][u] = bid;
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

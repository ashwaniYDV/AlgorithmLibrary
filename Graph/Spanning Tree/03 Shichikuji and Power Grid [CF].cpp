// https://codeforces.com/contest/1245/problem/D

/*
Shichikuji is the new resident deity of the South Black Snail Temple. 
Her first job is as follows:
There are 𝑛 new cities located in Prefecture X. 
Cities are numbered from 1 to 𝑛. 
City 𝑖 is located 𝑥𝑖 km North of the shrine and 𝑦𝑖 km East of the shrine. 
It is possible that (𝑥𝑖,𝑦𝑖)=(𝑥𝑗,𝑦𝑗) even when 𝑖≠𝑗.

Shichikuji must provide electricity to each city either by building a power station in that city, 
or by making a connection between that city and another one that already has electricity. 

So the City has electricity if it has a power station in it 
or it is connected to a City which has electricity by a direct connection 
or via a chain of connections.
Building a power station in City 𝑖 will cost 𝑐𝑖 yen;
Making a connection between City 𝑖 and City 𝑗 will cost 𝑘𝑖+𝑘𝑗 yen per km of wire used for the connection. 
However, wires can only go the cardinal directions (North, South, East, West). 
Thus, the length of the wire if City 𝑖 and City 𝑗 are connected is |𝑥𝑖−𝑥𝑗|+|𝑦𝑖−𝑦𝑗| km.

Shichikuji wants to do this job spending as little money as possible.
And so, you have to provide Shichikuji with the following information: 
min amount of yen needed to provide electricity to all cities, 
the cities in which power stations will be built, 
and the connections to be made.

If there are multiple ways to choose the cities and the connections to obtain the construction of minimum price, 
then print any of them.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e3+5;
int n, m;

vector<vector<int>> input, result;

struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n+1, -1);
    }
    int findParent(int a) {
        if(par[a] < 0) return a;
        return par[a] = findParent(par[a]);
    }
    bool unionSet(int a, int b){
        a = findParent(a);
        b = findParent(b);
        if(a == b) return 0;
        if(par[a] > par[b]) swap(a,b);
        par[a] += par[b];
        par[b] = a;
        return 1;
    }
    bool sameSet(int x, int y) { 
        return findParent(x) == findParent(y); 
    }
    int size (int x) { 
        return -par[findParent(x)]; 
    }
};

int x[N], y[N], c[N], k[N];

int distance(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int kruskals() {
    sort(input.begin(), input.end());
    DSU dsu(n+1);

    int cost = 0;
    for(auto it: input) {
        int w = it[0], u = it[1], v = it[2];
        if(!dsu.sameSet(u, v)) {
            result.push_back(it);
            cost += w;
            dsu.unionSet(u, v);
        }
    }

    return cost;
}

int32_t main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> k[i];

    for(int i = 1; i <= n; i++) {
        input.push_back({c[i], 0, i});
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n ; j++) {
            input.push_back({(k[i] + k[j]) * distance(i, j), i, j});
        }
    }

    int res = kruskals();
    cout << res << endl;

    vector<int> v1;
    vector<pair<int, int>> v2;
    for(auto it: result) {
        int w = it[0], u = it[1], v = it[2];
        if(u == 0) {
            v1.push_back(v);
        } else {
            v2.push_back({u, v});
        }
    }

    cout << v1.size() << endl;
    for(int i: v1) cout << i << " ";
    cout << endl;
    
    cout << v2.size() << endl;
    for(auto i: v2) cout << i.first << " " << i.second << endl;
}

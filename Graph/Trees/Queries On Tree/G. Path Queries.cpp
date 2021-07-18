// https://codeforces.com/problemset/problem/1213/G
// https://youtu.be/VCCcg6uxXfs

/*
You are given a weighted tree consisting of n vertices. Vertices ui and vi are connected by an edge with weight wi.
You are given m queries. The i-th query is given as an integer qi. 
In this query you need to calculate the number of pairs of vertices (u,v) (u < v) 
such that the maximum weight of an edge on a simple path between u and v doesn't exceed qi.

Input
The first line of the input contains two integers n and m (1 ≤ n, m ≤ 2⋅10^5) — the number of vertices in the tree and the number of queries.
Each of the next n−1 lines describes an edge of the tree. 
Edge i is denoted by three integers ui, vi and wi.
The last line of the input contains m integers q1,q2,…,qm (1≤qi≤2⋅105), where qi is the maximum weight of an edge in the i-th query.

Output
Print m integers — the answers to the queries. 
The i-th value should be equal to the number of pairs of vertices (u,v) (u<v) 
such that the maximum weight of an edge on a simple path between u and v doesn't exceed qi.
Queries are numbered from 1 to m in the order of the input.


input
7 5
1 2 1
3 2 3
2 4 1
4 5 2
5 7 4
3 6 2
5 2 3 4 1

output
21 7 15 21 3 
*/



/*
Hint:
i) Pairs which are valid for qi = 2 are also valid for qj = 3
ii) Try utilizing DSU
*/


#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;

struct edge {
    int u, v, w;
};

struct DSU {
    vector<int> par, rank;
    DSU(int n) {
        par.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }
    int findParent(int a) {
        if (par[a] == a) return a;
        return par[a] = findParent(par[a]);
    }
    int unionSet(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        int res = rank[a] * rank[b];
        if (a == b) return res;
        if (rank[a] < rank[b])
            swap(a, b);
        par[b] = a;
        rank[a] += rank[b];
        return res;
    }
};

bool comp(edge a , edge b) {
    return a.w < b.w;
}

signed main() {
    int n, q, u, v, w, x;
    cin >> n >> q;

    edge arr[n + 1];
    pair<int, int> query[n + 1];
    int res[n + 1];

    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        arr[i] = {u, v, w};
    }

    sort(arr + 1, arr + n, [](edge a, edge b) {
        return a.w < b.w;
    });

    for (int i = 1; i <= q; i++) {
        cin >> x;
        query[i] = {x, i};
    }

    sort(query + 1 , query + q + 1);

    DSU dsu(n + 5);

    int count = 0, index = 1;
    for (int i = 1; i <= q; i++) {
        int W = query[i].first, idx = query[i].second;

        while (index <= (n - 1) && arr[index].w <= W) {
            count += dsu.unionSet(arr[index].u , arr[index].v);
            index++;
        }

        res[idx] = count;
    }

    for (int i = 1; i <= q; i++) cout << res[i] << " ";

}






















// Method 2
struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n + 1, -1);
    }
    int findParent(int a) {
        if (par[a] < 0) return a;
        return par[a] = findParent(par[a]);
    }
    int unionSet(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        int rankA = -par[a], rankB = -par[b];
        int res = rankA * rankB;

        if (a == b) return res;

        if (par[a] > par[b]) swap(a, b);
        par[a] += par[b];
        par[b] = a;

        return res;
    }
};

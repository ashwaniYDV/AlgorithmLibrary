// https://cses.fi/problemset/task/1676/

/*
There are n cities and initially no roads between them. However, every day a new road will be constructed, and there will be a total of m roads.
A component is a group of cities where there is a route between any two cities using the roads. 
After each day, your task is to find the number of components and the size of the largest component.
Input:
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,…,n.
Then, there are m lines describing the new roads. Each line has two integers a and b: a new road is constructed between cities a and b.
You may assume that every road will be constructed between two different cities.
Output:
Print m lines: the required information after each day.
Constraints
1 ≤ n ≤ 10^5
1 ≤ m ≤ 2*10^5
1 ≤ a, b ≤ n
Example:
Input:
5 3
1 2
1 3
4 5
Output:
4 2
3 3
2 3
*/


const int N = 2e5+5;
int n, m;

struct DSU {
    vector<int> par;
    void init(int n) {
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


void solve() {
    int u, v;
    cin >> n >> m;
    
    DSU dsu;
    dsu.init(n);
    int noOfCC = n, largestCCSize = 1;
    
    f(i, m) {
        cin >> u >> v;
        if (dsu.unionSet(u, v)) {
            largestCCSize = max(largestCCSize, dsu.size(u));
            noOfCC--;
        }
        cout << noOfCC << ' ' << largestCCSize << '\n';
    }
}

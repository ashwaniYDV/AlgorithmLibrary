// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

/*
You are given an integer n. 
There is an undirected graph with n nodes, numbered from 0 to n - 1. 
You are given a 2D integer array edges where edges[i] = [ai, bi] 
denotes that there exists an undirected edge connecting nodes ai and bi.
Return the number of pairs of different nodes that are unreachable from each other.
*/


/*
Find the size of each connected component.

Let size of each connected component = [a, b, c, d, e]

res = (a*b + a*c + a*d + a*e) + (b*c + b*d + b*e) + (c*d + c*e) + (d*e)
res = a*(b+c+d+e) + b*(c+d+e) + c*(d+e) + d*(e)

or we can also write as:
res = (a)*b + (a+b)*c + (a+b+c)*d + (a+b+c+d)*e
*/

class Solution {
public:
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

    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto it: edges) {
            dsu.unionSet(it[0], it[1]);
        }

        long long res = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            if(i == dsu.findParent(i)) {
                long long cnt = dsu.size(i);
                res += cnt * sum;
                sum += cnt;
            }
        }

        return res;
    }
};
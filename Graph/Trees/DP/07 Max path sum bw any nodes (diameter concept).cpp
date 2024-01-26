// https://codeforces.com/blog/entry/81827

/*
Question asked in Google online coding challenge on 22nd AUG, 2020.

You are given a tree with N nodes numbered 1 to N. Each node is having weight Ai.
Find the maximum path sum between any two node u and v of the tree. Return the maximum path sum value. 

Constraints:
1 <= N <= 1e4
-1e6 <= Ai <= +1e6
*/

const int N = 1e5+5;
int n, m;

vi g[N];
int heightSum[N], a[N];
int res;

void dfs(int u, int par) {
    heightSum[u] = a[u];
    int mx1 = 0, mx2 = 0, child = 0;

    for (int v: g[u]) {
        if(v == par) continue;

        dfs(v, u);

        heightSum[u] = max(heightSum[u], a[u] + heightSum[v]);

        if(heightSum[v] > mx1) {
            mx2 = mx1;
            mx1 = heightSum[v];
        } else if(heightSum[v] > mx2) {
            mx2 = heightSum[v];
        }

        child++;
    }

    res = max(res, heightSum[u]);

    if(child >= 2) {
        res = max(res, a[u] + mx1 + mx2);
    }
} 

void solve() {
    int u, v;
    cin >> n;
    loop(i, 1, n) cin >> a[i];
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    
    res = -INF;
    dfs(1, -1);
    cout << res << endl;
}






















// https://github.com/Padmabala/SDE_Hiring-Challenges/blob/master/Google/maxPathSumUndirectedTree.py
from collections import defaultdict
class Solution(object):
    def sumOfDistancesInTree(self, N, values, edges):
        graph = defaultdict(set)
        for u, v in edges:
            graph[u].add(v)
            graph[v].add(u)
        def findMaxSum(node,parent):
            i=0
            childSumAsBranch=[]
            childMaxPathSum=[]
            for child in graph[node]:
                if(child!=parent):
                    csb,cps=findMaxSum(child,node)
                    childSumAsBranch.append(csb)
                    childMaxPathSum.append(cps)
                    i+=1
                else:
                    continue
            currentRoot=values[node-1]
            maxAmongChildSumAsBranch=float('-inf')
            for c in childSumAsBranch:
                maxAmongChildSumAsBranch=max(maxAmongChildSumAsBranch,c)
            maxSumAsBranch=max(maxAmongChildSumAsBranch+currentRoot,currentRoot)
            sumOfAllChild=0
            for c in childSumAsBranch:
                sumOfAllChild+=c
            maxSumAsRootNode=max(sumOfAllChild+currentRoot,maxSumAsBranch)
            maxAmongChildMaxPathSum=float('-inf')
            for c in childMaxPathSum:
                maxAmongChildMaxPathSum=max(maxAmongChildMaxPathSum,c)
            maxPathSum=max(maxAmongChildMaxPathSum,maxSumAsRootNode)
            return (maxSumAsBranch,maxPathSum)

        _, maxSum = findMaxSum(1, None)
        return maxSum

n=7
values=[6,3,10,-9,-4,-8,-6]
# edges=[[0,1],[0,2]]
edges=[[6,5],[7,2],[3,5],[2,1],[5,7],[4,3]]
s=Solution()
print(s.sumOfDistancesInTree(n,values,edges))

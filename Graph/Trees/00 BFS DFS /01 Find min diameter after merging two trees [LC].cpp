// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/

/*
There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. 
You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively.
You must connect one node from the first tree with another node from the second tree with an edge.
Return the minimum possible diameter of the resulting tree.
The diameter of a tree is the length of the longest path between any two nodes in the tree.
*/


/*
Intuition:
----------
1) We have to root both the trees separately at any node such that the height of these trees are minimum.
2) node1 and node2 are the end points of diameter of tree.
   When any node is rooted, it's max height will eventually end at end points of diameter, i.e. either node1 or node2
   depth1 = calculated when node1 is root
   depth2 = calculated when node2 is root
3) Ans = minHeightOfTree1 + 1 + minHeightOfTree2



Note (an edge case) -> Consider this example:
---------------------------------------------
We can root tree1 on 3 and tree2 on 0.

We would expect ans = 4 + 1 + 1 = 6
But answer is 7 since originally tree1 itself i having a diameter of 7

                   0
                 /   \
                1       2
                        |
                        3  -----------------------
                     /  |  \                      0
                    6   5   9                   / |  \
                        |                     1   2   3
                        4                     
                        |
                        8
                        |
                        7
*/


// Method 1: using diameter concept
class Solution {
public:
    int n;

    void dfs(int u, int par, int d, vector<int>& depth, vector<vector<int>>& g) {
        depth[u] = d;
        for(int v: g[u]) {
            if(v == par) continue;
            dfs(v, u, d + 1, depth, g);
        }
    };

    pair<int, int> getMaxDepthWhenRootIsOneToN(vector<vector<int>>& g) {
        vector<int> depth1(n, 0);
        // DFS 1
        dfs(0, -1, 0, depth1, g);
        int node1 = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            if(depth1[i] > mx) {
                mx = depth1[i];
                node1 = i;
            }
        }

        depth1 = vector<int>(n, 0);
        // DFS 2
        dfs(node1, -1, 0, depth1, g);

        int node2 = 0;
        mx = 0;
        for(int i = 0; i < n; i++) {
            if(depth1[i] > mx) {
                mx = depth1[i];
                node2 = i;
            }
        }

        vector<int> depth2(n, 0);
        // DFS 3
        dfs(node2, -1, 0, depth2, g);

        int minHeightOfTree = n-1;
        for (int i = 0; i < n; i++) {
            int heightWhenCurNodeIsRoot = max(depth1[i], depth2[i]);
            minHeightOfTree = min(minHeightOfTree, heightWhenCurNodeIsRoot);
        }
        
        int diameter = depth1[node2]; // or int diameter = depth2[node1]; 
        return { minHeightOfTree, diameter };
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;

        vector<vector<int>> g1(n1), g2(n2);
        for(auto& it: edges1) {
            g1[it[0]].push_back(it[1]);
            g1[it[1]].push_back(it[0]);
        }

        for(auto& it: edges2) {
            g2[it[0]].push_back(it[1]);
            g2[it[1]].push_back(it[0]);
        }

        n = n1;
        auto [minHeightOfTree1, diameter1]  = getMaxDepthWhenRootIsOneToN(g1);

        n = n2;
        auto [minHeightOfTree2, diameter2] = getMaxDepthWhenRootIsOneToN(g2);
        return max({minHeightOfTree1 + 1 + minHeightOfTree2, diameter1, diameter2});
    }
};

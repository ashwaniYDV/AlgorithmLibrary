// https://codeforces.com/blog/entry/20935

/*
Given a tree N nodes, where each node u has values[u] coins attached with it. 
You have to choose a subset of nodes such that no two adjacent nodes (i.e. nodes connected directly by an edge) are chosen 
and sum of coins attached with nodes in chosen subset is maximum.
*/


/*
This problem is quite similar to 1-D array problem where we are given an array A1, A2, ..., AN, 
where we can't choose adjacent elements and we have to maximise sum of chosen elements. 

Remember, how we define our state as dp[i] denoting answer for A1, A2, ..., Ai. 
Now, we define our recurrence as dp[i] = max(dp[i - 1], A[i] + dp[i - 2]) 
i.e. two cases: choose A[i] or not, respectively.
*/


/*
denoting maximum coins possible by choosing nodes from subtree of node V and if we include node V in our answer or not, respectively.

dp[u][0] = maximum coins possible by choosing nodes from subtree of node u and if we do not include node u in our answer
dp[u][1] = maximum coins possible by choosing nodes from subtree of node u and if we include node u in our answer

Our final answer is maximum of two case i.e. dp[u][0], dp[u][1]

Transition:
dp[u][0] = Σ[ edges u->v(max{dp[v][0], dp[v][1]}) ]    (since we can include children now, but we can also choose not include them in subset, hence max of both cases).
dp[u][1] = value[u] + Σ[ edges u->v(dp[v][0]) ]   (since we cannot include any of the children)
*/



const int N = 2e5+5;
int n, m;

vector<int> g[N];
int value[N];
int dp[N][2];

void dfs(int u, int par) {
    int sum0 = 0, sum1 = 0;

    for(auto v: g[u]){
        if(v == par) continue;
        dfs(v, u);
        sum1 += dp[v][0];
        sum0 += max(dp[v][0], dp[v][1]);
    }

    dp[u][1] = value[u] + sum1;
    dp[u][0] = sum0;
}

void solve() {
    int u, v;
    cin >> n;

    f(i, n - 1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    loop(i, 1, n) cin >> value[i];

    dfs(1, 0);

    int ans = max(dp[1][0], dp[1][1]);
    cout << ans << endl;
}


/*
Input:
7
1 2
1 3
2 4
2 5
3 6
3 7
1 2 3 4 5 6 7

Output:
23
*/








// https://leetcode.com/problems/house-robber-iii/
class Solution {
public:
    void dfs(TreeNode* root, map<pair<TreeNode*, int>, int>& dp) {
        if(!root) return;

        int sum0 = 0, sum1 = root->val;

        if(root->left) {
            dfs(root->left, dp);

            sum0 += max(dp[{root->left, 0}], dp[{root->left, 1}]);
            sum1 += dp[{root->left, 0}];
        }

        if(root->right) {
            dfs(root->right, dp);

            sum0 += max(dp[{root->right, 0}], dp[{root->right, 1}]);
            sum1 += dp[{root->right, 0}];
        }

        dp[{root, 0}] = sum0;
        dp[{root, 1}] = sum1;
    }

    int rob(TreeNode* root) {
        map<pair<TreeNode*, int>, int> dp;
        dfs(root, dp);
        return max(dp[{root, 0}], dp[{root, 1}]);
    }
};
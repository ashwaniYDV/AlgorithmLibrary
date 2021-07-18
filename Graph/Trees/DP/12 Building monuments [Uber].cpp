/*
Country of Hackerland can be represented as a tree of n cities numbered from 1 to n. 
Cities are connected by n - 1 bidirectional roads where the ith road connects the cities g_from[i] and g_to[i].
The king of Hackerland wants to build one of m different types of monuments in each of the cities 
such that no two adjacent cities or two cities adjacent to a common city have the same type of monument. 
Find the number of ways to build the monuments in all the cities as described. 
Since the answer can be large, print it modula (109+7).
Two cities are considered adjacent if they are directly connected through an edge.

Examaple
m = 4
n = 3
g_from = [1, 1]
g_to = [2, 3]

        1
       / \
      2   3
City 1 cannot have same type of monument as city 2 or 3 since they are directly connected.
City 2 cannot have the same type as city 3 because they both are connected to city 1.
Each city needs diff type of monument.
There are m = 4 diff types of monuments. Any three distinct type will work together.

So total no of ways = 4 * 3 * 2 = 24 ways.
*/


/*
Intuition
=========
* Traversal krk dekhte jaana hai kitne bache hue colors hain current node k liye 
and array bharke end mai multiply krdo.
* (color denotes monuments here)

                                root 
                             (m  ways)
                         /       |      \
                       /         |          \  
               child-1        child-2          child-3      
             (m-1 ways)     (m-2 ways)          (m-3 ways) 
           /    |  \                            /    |   \
        /       |      \                       /     |     \
      /         |         \                  /       |        \
    child-11    child-12   child-13       child-31   child-32  child-33     
 (m-2 ways)   (m-3 ways)   (m-4 ways)    (m-2 ways) (m-3 ways)  (m-4 ways) 
                                          /   |  \
                                        /     |    \
                                      /       |       \
                                    /         |         \
                                child-311   child-312  child-313  
                                (m-2 ways) (m-3 ways)  (m-4 ways) 

* Root can have m color = m ways
    * Its child-1 has = m-1 ways
    * Its child-2 has = m-2 ways
    * Its child-3 has = m-3 ways
* If m is lesser than required children's then asnwer is 0, since we cannot place color in any way.

* Child-1 acts as parent of child-11 and root is parent of child-1
* Child-11 cannot have same color as child-1 and root.
    * So, child-11 can have m-2 colors.
    * So, child-12 can have m-3 colors, and so on.

* Child-3 acts as parent of child-31 and root is parent of child-3
* Child-31 cannot have same color as child-3 and root.
    * So, child-31 can have m-2 colors.
    * So, child-32 can have m-3 colors, and so on.
*/



// samrath's solution

int maxCols;

void dfs(int u, int par, int colorsLeft, vector<int>& col, vector<vector<int>>& g) {
    col[u] = colorsLeft;

    int use = maxCols - 1;
    if(par != -1) use--;

    for(auto v: g[u]) {
        if(v == par) continue;

        dfs(v, u, max(0 , use), col, g);
        use--;
    }
}

int getTotalWays(int m, int n, vector<int> &g_from, vector<int>& g_to) {
    vector<int> col(n+1, 0);
    vector<vector<int>> g(n+1);

    for(int i = 0 ; i < n - 1; i++) {
        int u = g_from[i], v = g_to[i];
        g[u].push_back(v);
        g[v].push_back(u); 
    }

    maxCols = m;
    dfs(1, -1, m, col, g);
    
    int ans = 1 , mod = 1e9 + 7; 
    for(int i = 1; i <= n ; i++){
        ans = ans * col[i] ;
        ans %= mod ;
    }

    return ans;
}

void solve() {
    vector<int> g_from = {1, 1};
    vector<int> g_to = {2, 3};
    cout << getTotalWays(4, 3, g_from, g_to);
}






// Charsi's solution
const int MOD = 1e9+7;

int getTotalWays(int m, int n, vector<int> &g_from, vector<int>& g_to) {
    vector<int> g[n + 1];
    for (int i = 0; i < n - 1; i++) {
        g[g_from[i]].push_back(g_to[i]);
        g[g_to[i]].push_back(g_from[i]);
    }

    int ans = 1;
    function<void(int, int)> dfs = [&](int u, int p) -> void {
        int child_cnt = 0;

        for (auto v: g[u]) {
            if (v == p) continue;

            child_cnt++;
            dfs(v, u);
        }

        for (int i = 0; i < child_cnt; i++) {
            ans = (ans * 1LL * (m - 1 - i - (p != -1))) % MOD;
        }
        return;
    };

    dfs(1, -1);

    // root node can be colored in m ways
    return (ans * m) % MOD;
}

void solve() {
    vector<int> g_from = {1, 1};
    vector<int> g_to = {2, 3};
    cout << getTotalWays(4, 3, g_from, g_to);
}

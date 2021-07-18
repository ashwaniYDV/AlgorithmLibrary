/*
When you do dfs, you can consider vertices of 3 types; unvisited, visited but in the stack, or visited and finished 
(we called dfs on all their neighbors and returned already).

If your dfs detects a cycle, then all the cycle vertices are the type that's in the stack 
(they must have been visited, but they cannot be finished because you will find a cycle before finishing any vertex on it). 
So, one easy way to find the cycle is to maintain the stack along with a dfs (vector or stack, either global or passed by reference). 
When you find a visited neighbor, iterate from the back of the stack until you reach that visited node, 
and put all the vertices you iterated on in some vector, representing the cycle.
*/

const int N = 2e5+5;
int n, m;

vi g[N];
int color[N];
vector<int> vec;

void dfs(int u, int par) {
    color[u] = 1;
    vec.pb(u);

    for(int v: g[u]) {
        if(color[v] == 0) {
            dfs(v, u);
        }
        if(color[v] == 1 && v != par) {
            cout << "cycle\n";
            cout << v << " ";
            int pos = ((int)vec.size()) - 1;
            while(pos >= 0 && vec[pos] != v) {
                cout << vec[pos] << " ";
                --pos;
            }
            cout << "\n";
        }
    }

    color[u] = 2;
    vec.pop_back();
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v, g[u].pb(v), g[v].pb(u);
    }

    loop(i, 1, n) {
        if(color[i] == 0) {
            dfs(i, -1);
        }
    }
}

// https://www.geeksforgeeks.org/multi-source-shortest-path-in-unweighted-graph/

/*
Suppose there are n towns connected by m bidirectional roads. 
There are s towns among them with a police station. 
We want to find out the distance of each town from the nearest police station. 
If the town itself has one the distance is 0.
*/

int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e5+5;
int n, m;

vector<int> g[N];
int vis[N], dist[N];
vector<int> policeStations;


void bfs() {
	queue<pair<int, int>> q;
	for(int p: policeStations) {
		vis[p] = 1;
		dist[p] = 0;
		q.push({p, 0});
	}

	while(!q.empty()) {
		pair<int, int> x = q.front();
		int u = x.F, d = x.S;
		q.pop();

		for(int v: g[u]) {
			if(vis[v]) continue;
			vis[v] = 1;
			dist[v] = d + 1;
			q.push({v, dist[v]});
		}
	}

	loop(i, 1, n) {
		cout << i << " " << dist[i] << endl;
	}
}

void solve() {
	int u, v, x, y;
    cin >> n >> m;

    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    cin >> x;
    policeStations.resize(x);
    f(i, x) cin >> policeStations[i];

    bfs();
}






// https://leetcode.com/problems/01-matrix/
/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
*/

class Solution {
public:
    int n, m;
    vector<vector<int>> dist;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool isSafe(int i, int j) {
        return !(i < 0 || i >= n || j < 0 || j >= m);
    }
    
    void bfs(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;

            for(int z = 0; z < 4; z++) {
                int nx = x + dx[z], ny = y + dy[z];
                if(!isSafe(nx, ny)) continue;

                if(dist[nx][ny] == 1e9) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dist.resize(n, vector<int>(m, 1e9));
        bfs(matrix);
        return dist;
    }
};

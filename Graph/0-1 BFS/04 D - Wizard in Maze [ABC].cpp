// https://atcoder.jp/contests/abc176/tasks/abc176_d

/*
A maze is composed of a grid of N × M squares.
The square at (i, j) - is a "wall" if S[i][j] is "#" and a "road" if S[i][j] is "." 
There is a magician in (srcX, srcY) . He can do the following two kinds of moves: 
Move A: Walk to a road square that is vertically or horizontally adjacent to the square he is currently in. 
Move B: Use magic to jump himself to a "road square" in the 5 × 5 area centered at the square he is currently in. 
        Note: He cannot jump to a '#'.
In either case, he cannot go out of the maze. 
At least how many times does he need to use the magic to reach (destX, destY)?
*/

/*
Editorial:
It's a very typical 0-1 BFS, since the cost is 0 if we go along the roads, while the cost is 1 if we cast a magic spell.
Compared to ordinary BFS, we need to use a deque instead of a single-ended queue. 
For relaxations that cost 0, we do push_front, while for those cost 1, we do push_back. 
In this way, the elements in the deque are kept in an non-decreasing order, 
which means we will happily take the current value as the optimal value when we first reach the target position.
*/


// Method 1
const int N = 1e3+5;
int n, m;

string g[N];
int srcX, srcY, destX, destY;

bool isSafe(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')
        return false;
    return true;
}

void bfs01() {
    vector<vector<int>> dist(n, vector<int>(m, INF));

    deque<pair<int, int>> q;
    q.push_back({srcX, srcY});
    dist[srcX][srcY] = 0;

    while(!q.empty()) {
        auto it = q.front();
        q.pop_front();
        int x = it.first, y = it.second;

        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z], ny = y + dy[z];
            if(!isSafe(nx, ny)) continue;

            int w = 0;
            if(dist[nx][ny] > dist[x][y] + w) {
                dist[nx][ny] = dist[x][y] + w;
                q.push_front({nx, ny});
            }
        }

        for(int nx = x - 2; nx <= x + 2; nx++) {
            for(int ny = y - 2; ny <= y + 2; ny++) {
                if(!isSafe(nx, ny)) continue;

                int w = 1;
                if(dist[nx][ny] > dist[x][y] + w) {
                    dist[nx][ny] = dist[x][y] + w;
                    q.push_back({nx, ny});
                }
            }
        }
    }

    if(dist[destX][destY] != INF) cout << dist[destX][destY] << endl;
    else cout << -1;
}

void solve() {
    int x, y, z;
    cin >> n >> m;
    cin >> srcX >> srcY;
    cin >> destX >> destY;

    f(i, n) cin >> g[i];

    srcX--, srcY--, destX--, destY--;
    bfs01();
}



























// Method 2
const int N = 1e3+5;
int n, m;

string g[N];
int srcX, srcY, destX, destY;

bool isSafe(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')
        return false;
    return true;
}

void bfs01() {
    vector<vector<int>> dist(n, vector<int>(m, INF));

    deque<pair<int, int>> q;
    q.push_back({srcX, srcY});
    dist[srcX][srcY] = 0;

    while(!q.empty()) {
        auto it = q.front();
        q.pop_front();
        int x = it.first, y = it.second;

        if(x == destX && y == destY) {
            cout << dist[destX][destY];
            return;
        }

        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z], ny = y + dy[z];
            if(!isSafe(nx, ny)) continue;

            int w = 0;
            if(dist[nx][ny] > dist[x][y] + w) {
                dist[nx][ny] = dist[x][y] + w;
                q.push_front({nx, ny});
            }
        }

        for(int nx = x - 2; nx <= x + 2; nx++) {
            for(int ny = y - 2; ny <= y + 2; ny++) {
                if(!isSafe(nx, ny)) continue;

                int w = 1;
                if(dist[nx][ny] > dist[x][y] + w) {
                    dist[nx][ny] = dist[x][y] + w;
                    q.push_back({nx, ny});
                }
            }
        }
    }

    cout << -1;
}

void solve() {
    int x, y, z;
    cin >> n >> m;
    cin >> srcX >> srcY;
    cin >> destX >> destY;

    f(i, n) cin >> g[i];

    srcX--, srcY--, destX--, destY--;
    bfs01();
}

// https://codeforces.com/contest/1064/problem/D

/*
You are playing some computer game. One of its levels puts you in a maze consisting of n lines, each of which contains m cells. 
Each cell either is free or is occupied by an obstacle. The starting cell is in the row r and column c. 
In one step you can move one square up, left, down or right, if the target cell is not occupied by an obstacle. 
You can't move beyond the boundaries of the labyrinth.

Unfortunately, your keyboard is about to break, so you can move left no more than x times and move right no more than y times. 
There are no restrictions on the number of moves up and down since the keys used to move up and down are in perfect condition.

Now you would like to determine for each cell whether there exists a sequence of moves that will put you from the starting cell to this particular one. 
How many cells of the board have this property?
*/

int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = { -1, 0, 1, 0, -1, 1, 1, -1};
string stepDir = "LDRU";
const int N = 2e3+5;
int n, m;
 
string g[N];
int srcX, srcY, mxLeft, mxRight;
 
bool isSafe1(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '*')
        return false;
    return true;
}
 
void bfs01() {
    vector<vector<int>> distLeft(n, vector<int>(m, INF)), distRight(n, vector<int>(m, INF));
 
    deque<pair<int, int>> q;
    q.push_back({srcX, srcY});
    distLeft[srcX][srcY] = distRight[srcX][srcY] = 0;
 
    while(!q.empty()) {
        auto it = q.front();
        q.pop_front();
        int x = it.first, y = it.second;
 
        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z], ny = y + dy[z];
            if(!isSafe1(nx, ny)) continue;
 
            if(stepDir[z] == 'L') {
                int w = 1;
                if(distLeft[nx][ny] > distLeft[x][y] + w) {
                    distLeft[nx][ny] = distLeft[x][y] + w;
                    distRight[nx][ny] = distRight[x][y];
                    q.push_back({nx, ny});
                }
            }
 
            if(stepDir[z] == 'R') {
                int w = 1;
                if(distRight[nx][ny] > distRight[x][y] + w) {
                    distRight[nx][ny] = distRight[x][y] + w;
                    distLeft[nx][ny] = distLeft[x][y];
                    q.push_back({nx, ny});
                }
            }
 
            if(stepDir[z] == 'U' || stepDir[z] == 'D') {
                if(distLeft[nx][ny] > distLeft[x][y] || distRight[nx][ny] > distRight[x][y]) {
                    distLeft[nx][ny] = distLeft[x][y];
                    distRight[nx][ny] = distRight[x][y];
                    q.push_front({nx, ny});
                }
            }
        }
    }
 
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(distLeft[i][j] <= mxLeft && distRight[i][j] <= mxRight) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
 
void solve() {
    int x, y, z;
    cin >> n >> m;
    cin >> srcX >> srcY;
    cin >> mxLeft >> mxRight;
    
    f(i, n) cin >> g[i];
 
    srcX--, srcY--;
    bfs01();
}


















int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = { -1, 0, 1, 0, -1, 1, 1, -1};
string stepDir = "LDRU";
const int N = 2e3+5;
int n, m;
 
string g[N];
int srcX, srcY, mxLeft, mxRight;
 
bool isSafe1(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '*')
        return false;
    return true;
}
 
void bfs01() {
    vector<vector<int>> distLeft(n, vector<int>(m, INF)), distRight(n, vector<int>(m, INF));
 
    deque<pair<int, int>> q;
    q.push_back({srcX, srcY});
    distLeft[srcX][srcY] = distRight[srcX][srcY] = 0;
 
    while(!q.empty()) {
        auto it = q.front();
        q.pop_front();
        int x = it.first, y = it.second;
 
        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z], ny = y + dy[z];
            if(!isSafe1(nx, ny)) continue;
 
            if(stepDir[z] == 'L') {
                int w = 1;
                if(distLeft[nx][ny] > distLeft[x][y] + w) {
                    distLeft[nx][ny] = distLeft[x][y] + w;
                    distRight[nx][ny] = distRight[x][y];
                    q.push_back({nx, ny});
                }
            }
 
            if(stepDir[z] == 'R') {
                int w = 1;
                if(distRight[nx][ny] > distRight[x][y] + w) {
                    distRight[nx][ny] = distRight[x][y] + w;
                    distLeft[nx][ny] = distLeft[x][y];
                    q.push_back({nx, ny});
                }
            }
 
            if(stepDir[z] == 'U' || stepDir[z] == 'D') {
                if(distLeft[nx][ny] > distLeft[x][y]) {
                    distLeft[nx][ny] = distLeft[x][y];
                    distRight[nx][ny] = distRight[x][y];
                    q.push_front({nx, ny});
                }
                if(distRight[nx][ny] > distRight[x][y]) {
                    distLeft[nx][ny] = distLeft[x][y];
                    distRight[nx][ny] = distRight[x][y];
                    q.push_front({nx, ny});
                }
            }
        }
    }
 
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(distLeft[i][j] <= mxLeft && distRight[i][j] <= mxRight) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
 
void solve() {
    int x, y, z;
    cin >> n >> m;
    cin >> srcX >> srcY;
    cin >> mxLeft >> mxRight;
    
    f(i, n) cin >> g[i];
 
    srcX--, srcY--;
    bfs01();
}




















int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = { -1, 0, 1, 0, -1, 1, 1, -1};
string stepDir = "LDRU";
const int N = 2e3+5;
int n, m;
 
string g[N];
int vis[N][N];
int srcX, srcY, mxLeft, mxRight;
 
bool isSafe(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '*' || vis[x][y])
        return false;
    return true;
}
 
void bfs01() {
    vector<vector<int>> distLeft(n, vector<int>(m, INF)), distRight(n, vector<int>(m, INF));
 
    deque<pair<int, int>> q;
    q.pb({srcX, srcY});
 
    distLeft[srcX][srcY] = distRight[srcX][srcY] = 0;
    vis[srcX][srcY] = 1;
 
    while(!q.empty()){
        auto it = q.front();
        q.pop_front();
        int x = it.F, y = it.S;

        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z], ny = y + dy[z];
            if(!isSafe(nx, ny)) continue;

            if(stepDir[z] == 'L') {
                distLeft[nx][ny] = distLeft[x][y] + 1;
                distRight[nx][ny] = distRight[x][y];
                q.pb({x, y-1});
                vis[x][y-1] = 1;   
            }

            if(stepDir[z] == 'R') {
                distLeft[nx][ny] = distLeft[x][y];
                distRight[nx][ny] = distRight[x][y] + 1;
                q.pb({nx, ny});
                vis[nx][ny] = 1;
            }

            if(stepDir[z] == 'U' || stepDir[z] == 'D') {
                distLeft[nx][ny] = distLeft[x][y];
                distRight[nx][ny] = distRight[x][y];
                q.push_front({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(distLeft[i][j] <= mxLeft && distRight[i][j] <= mxRight) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
 
void solve() {
    int x, y, z;
    cin >> n >> m;
    cin >> srcX >> srcY;
    cin >> mxLeft >> mxRight;
    
    f(i, n) cin >> g[i];
 
    srcX--, srcY--;
    bfs01();
}

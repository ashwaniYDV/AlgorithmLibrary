// https://atcoder.jp/contests/abc213/tasks/abc213_e

/*
Problem:
There is a town divided into a grid of cells with H rows and W columns. 
The cell at (i, j) is a passable space if S[i][j] is "." and a block if S[i][j] is "#". 
Takahashi will go from his house to a fish market. 
His house is in the cell at the top-left corner, and the fish market is in the cell at the bottom-right corner. 
Takahashi can move one cell up, down, left, or right to a passable cell. He cannot leave the town. He cannot enter a block, either. 
However, his physical strength allows him to destroy all blocks in a square region with 2 × 2 cells of his choice with one punch, making these cells passable. 
Find the minimum number of punches needed for Takahashi to reach the fish market.
*/


/*
Editorial:
This problem can be solved with a 01-BFS
Assuming that he does not punch until needed, we can assume that a 2 × 2 region of destroying blocks is adjacent to the square Takahashi is at.

When Takahashi is in the square labeled T in the diagram below, after a single punch he can move to any square labeled *, 
regardless of the previous state of the squares.

$ * * * $
* * * * *
* * T * *
* * * * *
$ * * * $

Note that he cannot go to $ from T. So we have to neglect these 4 positions in the for loops.

Therefore, we can assume that a move on foot to an adjacent square costs 0 and moving to any * square after a punch costs 1, 
and perform a 01-BFS to solve the problem.

Similar problem: ABC176D “Wizard in Maze”
*/


// Method 1
const int N = 5e2+5;
int n, m;
 
string g[N];
int srcX, srcY, destX, destY;
 
bool isSafe1(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')
        return false;
    return true;
}
 
bool isSafe2(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m)
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
            if(!isSafe1(nx, ny)) continue;
 
            int w = 0;
            if(dist[nx][ny] > dist[x][y] + w) {
                dist[nx][ny] = dist[x][y] + w;
                q.push_front({nx, ny});
            }
        }
 
        for(int nx = x - 2; nx <= x + 2; nx++) {
            for(int ny = y - 2; ny <= y + 2; ny++) {
                if(!isSafe2(nx, ny)) continue;
                // we cannot go to these 4 boundary points
                if((nx == x-2 && ny == y-2) || (nx == x-2 && ny == y+2) || (nx == x+2 && ny == y-2) || (nx == x+2 && ny == y+2)) continue;
 
                int w = 1;
                if(dist[nx][ny] > dist[x][y] + w) {
                    dist[nx][ny] = dist[x][y] + w;
                    q.push_back({nx, ny});
                }
            }
        }
    }
 
    cout << dist[destX][destY];
}
 
void solve() {
    int x, y, z;
    cin >> n >> m;
    
    f(i, n) cin >> g[i];
 
    srcX = 0, srcY = 0, destX = n-1, destY = m-1;
    bfs01();
}































// Method 2
const int N = 5e2+5;
int n, m;

string g[N];
int srcX, srcY, destX, destY;

// when we do not break blocks
bool isSafe1(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')
        return false;
    return true;
}

// since we break '#' blocks thus neglecting it
bool isSafe2(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m)
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
            if(!isSafe1(nx, ny)) continue;

            int w = 0;
            if(dist[nx][ny] > dist[x][y] + w) {
                dist[nx][ny] = dist[x][y] + w;
                q.push_front({nx, ny});
            }
        }

        for(int nx = x - 2; nx <= x + 2; nx++) {
            for(int ny = y - 2; ny <= y + 2; ny++) {
                if(!isSafe2(nx, ny)) continue;
                // we cannot go to these 4 boundary points
                if((nx == x-2 && ny == y-2) || (nx == x-2 && ny == y+2) || (nx == x+2 && ny == y-2) || (nx == x+2 && ny == y+2)) continue;

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
    
    f(i, n) cin >> g[i];

    srcX = 0, srcY = 0, destX = n-1, destY = m-1;
    bfs01();
}

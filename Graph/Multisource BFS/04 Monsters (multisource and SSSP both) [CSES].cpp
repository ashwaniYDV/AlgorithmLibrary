// https://cses.fi/problemset/task/1194/

/*
Problem:
You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneously take one as well. 
Your goal is to reach one of the boundary squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is, print a path that you can follow. 
Your plan has to work in any situation; even if the monsters know your path beforehand.

Example

Input:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Output:
YES
5
RRDDR
*/

/*
Because the monsters move optimally, if a monster can reach a location in the maze before A, then A may never move to that spot. 
Thus for monsters do mutisource BFS to find minimum distances to all locations.
Now, for A to enter a spot, the distance from that location to A must be less than the distance from that location to the nearest monster. 
Knowing this, we may BFS to find all locations that are visitable by A.
*/


const int N = 2e3+5;
int n, m;

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string stepDir = "URDL";

// previousStep stores the previous direction that we moved in to arrive that this cell
int previousStep[N+5][N+5];

char g[N+5][N+5];
bool vis[N+5][N+5], visMonsters[N+5][N+5];
int dis[N][N], disMonsters[N+5][N+5];

bool isSafe(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || g[i][j] == '#')
        return false;
    return true;
}

bool isSafeMonsters(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m || visMonsters[i][j] || g[i][j] == '#')
        return false;
    return true;
}

void solve() {
    cin >> n >> m;

    queue<pair<int, int>> q, qMonsters;
    pair<int, int> source, dest;

    bool flag = false;

    f(i, n) {
        f(j, m) {
            cin >> g[i][j];
            dis[i][j] = INF;
            disMonsters[i][j] = INF;

            if (g[i][j] == 'A') {
                source = {i, j};
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    flag = true;
                }
            }
            if (g[i][j] == 'M') {
                qMonsters.push({i, j});
                disMonsters[i][j] = 0;
                visMonsters[i][j] = 1;
            }
        }
    }

    if(flag) {
        cout << "YES\n";
        cout << 0 << endl;
        return;
    }


    // multisource BFS for monsters
    while (!qMonsters.empty()) {
        auto u = qMonsters.front();
        qMonsters.pop();
        int x = u.first, y = u.second;

        f(z, 4) {
            int nx = x + dx[z], ny = y + dy[z];
            if (!isSafeMonsters(nx, ny)) continue;

            visMonsters[nx][ny] = true;
            disMonsters[nx][ny] = disMonsters[x][y] + 1;
            qMonsters.push({nx, ny});
        }
    }

    // single source BFS for you
    q.push(source);
    vis[source.first][source.second] = 1;
    dis[source.first][source.second] = 0;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int x = u.first, y = u.second;

        f(z, 4) {
            int nx = x + dx[z], ny = y + dy[z];
            if (!isSafe(nx, ny)) continue;

            vis[nx][ny] = true;
            dis[nx][ny] = dis[x][y] + 1;
            previousStep[nx][ny] = z;
            q.push({nx, ny});

            // reached boundary of grid earlier then any monster
            if((nx == 0 || nx == n-1 || ny == 0 || ny == m-1) && (dis[nx][ny] < disMonsters[nx][ny])) {
                flag = true;
                dest = {nx, ny};
            }
        }
    }

    if(!flag) {
        cout << "NO\n";
        return;
    }

    cout << "YES" << endl;
    vector<int> steps;
    while (dest != source) {
        int p = previousStep[dest.first][dest.second];
        steps.push_back(p);
        // undo the previous step to get back to the previous square
        // Notice how we subtract dx/dy, whereas we added dx/dy before
        dest = {dest.first - dx[p], dest.second - dy[p]};
    }

    reverse(steps.begin(), steps.end());
    cout << steps.size() << endl;
    for (int x: steps) {
        cout << stepDir[x];
    }
    cout << endl;
} 

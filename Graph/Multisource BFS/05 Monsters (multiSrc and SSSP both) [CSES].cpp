// https://cses.fi/problemset/task/1194/

/*
You and some monsters are in a labyrinth. 
When taking a step to some direction in the labyrinth, each monster may simultaneously take one as well. 
Your goal is to reach one of the boundary squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is, print a path that you can follow. 
Your plan has to work in any situation; even if the monsters know your path beforehand.

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
Intuition
---------
* Because monsters move optimally, if a monster can reach a location in maze before A, 
  then A may never move to that spot. 
* Thus for monsters, do mutiSrc BFS to find min distances to all locations.
* Now, for A to enter a spot, distance from that location to A must be less than distance from that location to nearest monster. 
* Knowing this, we may BFS to find all locations that are visitable by A.

Note:
* Instead of checking for all cells that if a monster can reach there before A or not,
  it is better to check this condition only for boundary cells.
* This will work because if monter can reach to a inside cell before A, then definitely moster can reach to boundary cell also before A.
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
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

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
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

        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z], ny = y + dy[z];
            if (!isSafeMonsters(nx, ny)) continue;

            visMonsters[nx][ny] = true;
            disMonsters[nx][ny] = disMonsters[x][y] + 1;
            qMonsters.push({nx, ny});
        }
    }

    // single source BFS for A
    q.push(source);
    vis[source.first][source.second] = 1;
    dis[source.first][source.second] = 0;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int x = u.first, y = u.second;

        // reached boundary of grid earlier then any monster
        if((x == 0 || x == n-1 || y == 0 || y == m-1) && (dis[x][y] < disMonsters[x][y])) {
            flag = true;
            dest = {x, y};
        }

        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z], ny = y + dy[z];
            if (!isSafe(nx, ny)) continue;

            vis[nx][ny] = true;
            dis[nx][ny] = dis[x][y] + 1;
            previousStep[nx][ny] = z;
            q.push({nx, ny});
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


int32_t main() {
    solve();
}
// https://www.spoj.com/problems/KATHTHI/

/*
Kathiresan is initially locked at cell (0,0) in a highly guarded rectangular prison of order RxC. 
He must reach the gate at (R-1,C-1) in order to escape from the prison. 
Kathiresan can move from any cell, to any of it's 4 adjacent cells (North, East, West and South). 

Kathiresan somehow manages to get the map of the prison.
If map[x1][y1] == map[x2][y2] then Kathiresan can move from (x1,y1) to (x2,y2) without killing any guards.
If map[x1][y1] != map[x2][y2], then Kathiresan can move from (x1,y1) to (x2,y2) by killing a guard.

Given the map of the prison, find the minimum number of guards Kathiresan must kill in order to escape from the prison.

Input:
The first line consists of an integer t, the number of test cases. 
For each test case, the first line consists of two integers R and C representing the order of the rectangular prison 
followed by R strings representing the map of the rectangular prison.

Output:
For each test case find the minimum number of guards Kathiresan must kill in order to escape from the prison.

Input Constraints:
1 <= t <= 10
2 <= R <= 1000
2 <= C <= 1000
'a' <= map[i][j] <= 'z'

Sample Input:
4
2 2
aa
aa
2 3
abc
def
6 6
akaccc
aaacfc
amdfcc
aokhdd
zyxwdp
zyxwdd
5 5
abbbc
abacc
aaacc
aefci
cdgdd

Sample Output:
0
3
2
2
*/

const int N = 1e3+5;
int n, m;

string g[N];

bool isSafe(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}

void bfs01() {
    vector<vector<int>> dis(n, vector<int>(m, INF));
    deque<pair<int, int>> dq;
    dq.push_front({0, 0});
    dis[0][0] = 0;

    while (!dq.empty()) {
        auto it = dq.front();
        dq.pop_front();
        int x = it.F, y = it.S;

        f(z, 4) {
            int nx = x + dx[z], ny = y + dy[z];
            if(!isSafe(nx, ny)) continue;

            int w = 1;
            if(g[nx][ny] == g[x][y]) w = 0;

            if (dis[nx][ny] > dis[x][y] + w) {
                dis[nx][ny] = dis[x][y] + w;
                if (w == 0) {
                    dq.push_front({nx, ny});
                } else {
                    dq.push_back({nx, ny});
                }
            }
        }
    }

    cout << dis[n - 1][m - 1] << endl;
}

void solve() {
    int x, y, z;
    cin >> n >> m;
    f(i, n) cin >> g[i];

    bfs01();
}

signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    PRECISION(10);
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}  

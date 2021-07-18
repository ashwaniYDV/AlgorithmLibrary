// https://www.codechef.com/problems/CC004

/*
Today is Valentine's Day and Kabir and Tara have decided to celebrate it. Now, both of them are going to park to spend some quality time together.
The city is in the form of a grid comprising of 0s and 1s where 1s denotes traffic signal at that position and 0s denote roads. 
They are already late, the location of home (x1,y1) and park (x2,y2) is given and they have to go such that there are minimum traffic lights in their way. 
You are a friend of Kabir, help him find a way to reach the park by crossing least number of traffic lights.

Note:
There is no traffic signal at x1,y1 and x2,y2.
They can only move from a cell to its left, right, up or down adjacent cell.
*/


const int N = 1e3+5;
int n, m;

string g[N];
int srcX, srcY, destX, destY;

bool isSafe(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}

void bfs01() {
    vector<vector<int>> dis(n, vector<int>(m, INF));

    deque<pair<int, int>> dq;
    dq.push_back({srcX, srcY});
    dis[srcX][srcY] = 0;

    while(!dq.empty()) {
        auto it = dq.front();
        dq.pop_front();
        int x = it.first, y = it.second;

        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z], ny = y + dy[z];
            if(!isSafe(nx, ny)) continue;

            int w = 0;
            if(g[nx][ny] == '1') w = 1;

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

    cout << dis[destX][destY] << endl;
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

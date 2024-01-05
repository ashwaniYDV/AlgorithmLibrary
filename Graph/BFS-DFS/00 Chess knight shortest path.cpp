// https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/
// https://practice.geeksforgeeks.org/problems/knight-walk4521/1


/*
Given a square chessboard, the initial position of Knight and position of a target. 
Find out the minimum steps a Knight will take to reach the target position.
If it cannot reach the target position return -1.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.
*/


class Solution {
public:
    int n, m;
    int row[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int col[8] = { -1, 1, 1, -1, 2, -2, 2, -2};
    vector < vector < int >> vis;

    struct Node {
        int x, y, dist;
        Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}
    };

    bool valid(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) return false;
        return true;
    }

    int bfs(pair < int, int > src, pair < int, int > dest) {
        queue < Node > q;
        q.push({src.first, src.second, 0});
        vis[src.first][src.second] = 1;

        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            int x = node.x;
            int y = node.y;
            int dist = node.dist;

            if (x == dest.first && y == dest.second) {
                return dist;
            }

            for (int z = 0; z < 8; z++) {
                int x1 = x + row[z], y1 = y + col[z];
                if (valid(x1, y1)) {
                    q.push({x1, y1, dist + 1});
                    vis[x1][y1] = 1;
                }
            }
        }

        return -1;
    }

    int minStepToReachTarget(vector < int > & KnightPos, vector < int > & TargetPos, int N) {
        n = N, m = N;
        vis.resize(n + 1, vector < int > (m + 1, 0));
        // make it 0 based index
        return bfs({KnightPos[0] - 1, KnightPos[1] - 1}, {TargetPos[0] - 1, TargetPos[1] - 1});
    }
};

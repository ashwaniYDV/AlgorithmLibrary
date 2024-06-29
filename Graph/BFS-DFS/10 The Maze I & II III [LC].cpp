// https://leetcode.com/problems/the-maze/

/*
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). 
The ball can go through the empty spaces by rolling up, down, left or right, 
but it won't stop rolling until hitting a wall. 
When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, 
return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls.

Note: You can pass through the destination, but if you cannot stop there, then it's not the answer.
*/


/*
Intuition
---------
* We don’t care about the path of the ball, which means they are not marked as “visited” when we just pass through it.
* We only mark the STOP point as visited each time we decide, ie we hit a wall.
*/

class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool isWall(int i, int j, vector<vector<int>>& maze) {
        return (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == 1);
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        n = maze.size(), m = maze[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>>q;

        q.push({start[0] , start[1]});
        // since starting point is a stoppage from where we chose directions, mark it as visited
        vis[start[0]][start[1]] = 1;
        
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            if(x == destination[0] && y == destination[1]) return true;

            for(int z = 0; z < 4; z++){
                int nx = x;
                int ny = y;

                // move in same direction till we hit a wall
                while(!isWall(nx + dx[z], ny + dy[z], maze)){
                    nx += dx[z];
                    ny += dy[z];
                }

                if(!vis[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }

        return false;

    }
};








// https://leetcode.com/problems/the-maze-ii/

/*
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). 
The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. 
When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, 
return the shortest distance for the ball to stop at the destination. 
If the ball cannot stop at destination, return -1.

The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).
You may assume that the borders of the maze are all walls (see examples).
*/


// Method 1: modified BFS
/*
Since path weights are not same, we have to check min of all possible paths.
[Note: Other approach is to use dijkstra]
*/
class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool isWall(int i, int j, vector<vector<int>>& maze) {
        return (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == 1);
    }

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        n = maze.size(), m = maze[0].size();

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        queue<vector<int>>q;

        q.push({start[0] , start[1], 0});
        dis[start[0]][start[1]] = 0;

        int res = 1e9;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it[0], y = it[1], cost = it[2];

            if(x == destination[0] && y == destination[1]) {
                res = min(res, cost);
                continue;
            }

            for(int z = 0; z < 4; z++){
                int nx = x;
                int ny = y;
                int w = 0;

                while(!isWall(nx + dx[z], ny + dy[z], maze)){
                    nx += dx[z];
                    ny += dy[z];
                    w++;
                }

                if(dis[nx][ny] > dis[x][y] + w) {
                    dis[nx][ny] = dis[x][y] + w;
                    q.push({nx, ny, dis[nx][ny]});
                }
            }
        }

        return res == 1e9 ? -1 : res;

    }
};


// Method 2: Dijkstra
/*
Dijkstra will be used since, finding shortest path implementation becomes weighted SSSP.
*/
class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool isWall(int i, int j, vector<vector<int>>& maze) {
        return (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == 1);
    }

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        n = maze.size(), m = maze[0].size();

        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, start[0] , start[1]});
        dis[start[0]][start[1]] = 0;
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int x = it[1], y = it[2];

            // if(x == destination[0] && y == destination[1]) return dis;

            for(int z = 0; z < 4; z++){
                int nx = x;
                int ny = y;
                int w = 0;

                while(!isWall(nx + dx[z], ny + dy[z], maze)){
                    nx += dx[z];
                    ny += dy[z];
                    w++;
                }

                if(dis[nx][ny] > dis[x][y] + w) {
                    dis[nx][ny] = dis[x][y] + w;
                    pq.push({dis[nx][ny], nx, ny});
                }
            }
        }

        int res = dis[destination[0]][destination[1]];
        return res == 1e9 ? -1 : res;
    }
};




// https://leetcode.com/problems/the-maze-iii/description/
// https://leetcode.com/problems/trapping-rain-water-ii/
// https://youtu.be/fywyCy6Fyoo?si=5b82fc3owy_Z6JtC

class Solution {
public:
    #define node array<int, 3>
    
    int n, m, x, y;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool isSafe(int i, int j, vector<vector<int>>& vis) {
        if(i < 0 || i >= n || j < 0 || j>= m || vis[i][j]) return false;
        return true;
    }
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        n = heightMap.size(), m = heightMap[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // this vector is not required [used for illustration of quantity of watertrapped per block]
        vector<vector<int>> water(n, vector<int>(m, 0));
        
        priority_queue<node, vector<node>, greater<node>> minHeap;
        
        // Pushes column and row boundary in min heap
        for(int i = 0; i < n; i++) {
            minHeap.push({heightMap[i][0], i, 0});
            vis[i][0] = 1;
            
            minHeap.push({heightMap[i][m-1], i, m-1});
            vis[i][m-1] = 1;
        }
        for(int j = 1; j < m-1; j++) {
            minHeap.push({heightMap[0][j], 0, j});
            vis[0][j] = 1;
            
            minHeap.push({heightMap[n-1][j], n-1, j});
            vis[n-1][j] = 1;
        }
        
        int res = 0;
        while(!minHeap.empty()) {
            node top = minHeap.top();
            minHeap.pop();
            int curHeight = top[0];
            x = top[1], y = top[2];
            
            for(int z = 0; z < 4; z++) {
                int nx = x + dx[z];
                int ny = y + dy[z];
                
                if(!isSafe(nx, ny, vis)) continue;
                
                int h = heightMap[nx][ny];
                
                // If water can be trapped 
                // (when height of this new element is less than the current weakest link)
                if (h < curHeight) {
                    res += curHeight - h;
                    water[nx][ny] = curHeight - h;
                }
                
                // If h < curHeight, then water will flow till final height with water becomes curHeight 
                // otherwise h will be the height as no water will flow
                minHeap.push({max(curHeight, h), nx, ny});
                vis[nx][ny] = 1;
            }
        }
        
        return res;
    }
};
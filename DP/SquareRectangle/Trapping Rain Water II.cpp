// https://youtu.be/hSUIFPrkOeo

#define node pair<int, pair<int, int>>
#define f(i,n) for(int i=0;i<n;i++)
class Solution {
public:
    int n, m, x, y;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool isSafe(int i, int j, vector<vector<int>>& vis) {
        if(i < 0 || i >= n || j < 0 || j>= m || vis[i][j]) return false;
        return true;
    }
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        n = heightMap.size();
        if(n == 0) return 0;
        m = heightMap[0].size();
        if(m == 0) return 0;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // this vector is not required [used for illustration of quantity of watertrapped per block]
        vector<vector<int>> water(n, vector<int>(m, 0));
        
        priority_queue<node, vector<node>, greater<node>> minHeap;
        
        // Pushes column and row boundary in min heap
        f(i, n) {
            minHeap.push({heightMap[i][0], {i, 0}});
            vis[i][0] = 1;
            
            minHeap.push({heightMap[i][m-1], {i, m-1}});
            vis[i][m-1] = 1;
        }
        f(j, m) {
            minHeap.push({heightMap[0][j], {0, j}});
            vis[0][j] = 1;
            
            minHeap.push({heightMap[n-1][j], {n-1, j}});
            vis[n-1][j] = 1;
        }
        
        int res = 0;
        while(!minHeap.empty()) {
            node top = minHeap.top();
            minHeap.pop();
            int h = top.first;
            x = top.second.first, y = top.second.second;
            
            f(z, 4) {
                int i = x + dx[z];
                int j = y + dy[z];
                
                if(!isSafe(i, j, vis)) continue;
                
                int curHeight = heightMap[i][j];
                
                // If water can be trapped (when height of this new element is less than the current weakest link) 
                if (h > curHeight) {
                    res += h - curHeight;
                    water[i][j] = h - curHeight;
                }
                
                // If curHeight < h, then water will flow till final height with water becomes h 
                // otherwise curHeight will be the height as no water will flow
                minHeap.push({max(curHeight, h), {i, j}});
                vis[i][j] = 1;
            }
        }
        
        return res;
        
    }
};

// https://leetcode.com/problems/flood-fill/

/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 
Replace the color of all of the aforementioned pixels with newColor.
Return the modified image after performing the flood fill.
*/

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int n, m, srcPixel, newColor;
    
    bool isSafe(int i, int j, vector<vector<int>>& image, vector<vector<int>>& vis) {
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || image[i][j] != srcPixel)
            return false;
        return true;
    }
    
    void dfs(int i, int j, vector<vector<int>>& image, vector<vector<int>>& vis) {
        if(!isSafe(i, j, image, vis)) return;
        
        vis[i][j] = 1;
        image[i][j] = newColor;
        for(int z = 0; z < 4; z++) {
            dfs(i + dx[z], j + dy[z], image, vis);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size(), m = image[0].size();
        this->srcPixel = image[sr][sc];
        this->newColor = newColor;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(sr, sc, image, vis);
        return image;
    }
};

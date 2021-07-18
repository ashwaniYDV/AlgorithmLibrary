// https://leetcode.com/problems/the-skyline-problem/
// https://www.geeksforgeeks.org/the-skyline-problem-set-2/

// https://youtu.be/GSBLe8cKu0s

/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 
Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.
The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:
a) lefti is the x coordinate of the left edge of the ith building.
b) righti is the x coordinate of the right edge of the ith building.
c) heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. 
Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, 
which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. 
Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.
*/


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // To store the left and right wall position of the buildings
        vector<pair<int, int>> wall;
        for(auto it: buildings) {
            int left = it[0], right = it[1], height = it[2];
            // Negative value means left wall will be inserted first for the same abscissa(x) as right wall
            wall.push_back({left, -height});
            wall.push_back({right, height});
        }
        // Sort the walls in ascending order
        sort(wall.begin(), wall.end());
        
        // Initialize a multiset to keep left wall heights sorted
        multiset<int, greater<int>> leftWallHeights;
        leftWallHeights.insert(0);
        // Current max height among leftWallHeights
        int mxHeight = 0;
        
        vector<vector<int>> res;
        
        for(auto it: wall) {
            // If left wall is found
            if(it.second < 0) {
                leftWallHeights.insert(-it.second);
            } 
            // If right wall is found, remove the height
            else {
                leftWallHeights.erase(leftWallHeights.find(it.second));
            }
            
            // Mark a skyline point if mxHeight changes
            if(*leftWallHeights.begin() != mxHeight) {
                mxHeight = *leftWallHeights.begin();
                res.push_back({it.first, mxHeight});
            }
        }
        return res;
    }
};

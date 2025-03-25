// http://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/

/*
You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. 
You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. 
Each rectangle is defined as follows:
  (startx, starty): The bottom-left corner of the rectangle.
  (endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:
  Each of the three resulting sections formed by the cuts contains at least one rectangle.
  Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.
*/


// Method 1: Not memory efficient
class Solution {
public:
    int sizeAfterMerge(vector<vector<int>>& a) {
        int n = a.size();
        if (n == 0) return 0;
        
        // sort on the basis of starting of interval
        sort(a.begin(), a.end(), [](vector<int>& a1, vector<int>& a2) {
            return a1[0] < a2[0];
        });
            
        vector<vector<int>> res;
        res.push_back(a[0]);
        
        for (int i = 1; i < n; i++) {
            if (res.back()[1] <= a[i][0]) {
                res.push_back(a[i]);
            } else {
                res.back()[1] = max(res.back()[1], a[i][1]);
            }
        }
        
        return res.size();
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x, y;
        for(auto& it: rectangles) {
            x.push_back({it[0], it[2]});
            y.push_back({it[1], it[3]});
        }

        if(sizeAfterMerge(x) >= 3) return 1;
        if(sizeAfterMerge(y) >= 3) return 1;
        return 0;
    }
};



// Method 2
class Solution {
public:
    int sizeAfterMerge(vector<vector<int>>& a) {
        int n = a.size();
        if (n == 0) return 0;
        
        // sort on the basis of starting of interval
        sort(a.begin(), a.end(), [](vector<int>& a1, vector<int>& a2) {
            return a1[0] < a2[0];
        });
            
        int end = a[0][1];
        int cnt = 1;
        
        for (int i = 1; i < n; i++) {
            if (end <= a[i][0]) {
                end = a[i][1];
                cnt++;
            } else {
                end = max(end, a[i][1]);
            }
        }
        
        return cnt;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x, y;
        for(auto& it: rectangles) {
            x.push_back({it[0], it[2]});
            y.push_back({it[1], it[3]});
        }

        if(sizeAfterMerge(x) >= 3) return 1;
        if(sizeAfterMerge(y) >= 3) return 1;
        return 0;
    }
};

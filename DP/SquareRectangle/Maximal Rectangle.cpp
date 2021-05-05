// https://leetcode.com/problems/maximal-rectangle/
// https://youtu.be/dAVF2NpC3j4

/*
Largest rectangle area in histogram concept is used here repetedly
*/

class Solution {
public:
    // Largest rectangle area in histogram function
    int largestRectangleAreaInHisto(vector<int>& heights) {
        int n = heights.size();
        int mxArea = 0;
        
        for(int i = 0; i < n; i++) {
            int h = heights[i];
            int left = 0, right = 0;
            
            for(int l = i - 1; l >= 0; l--) {
                if(heights[l] >= h) {
                    left++;
                } else {
                    break;
                }
            }
            for(int r = i + 1; r < n; r++) {
                if(heights[r] >= h) {
                    right++;
                } else {
                    break;
                }
            }
            
            int currArea = h * (left + right + 1);
            mxArea = max(mxArea, currArea);
        }
        return mxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        
        vector<vector<int>> heights(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0) {
                    heights[i][j] = matrix[i][j] - 48;
                } else {
                    if(matrix[i][j] == '0') {
                        heights[i][j] = 0;
                    } else {
                        heights[i][j] += (1 + heights[i - 1][j]);
                    }
                }
            }
        }
        
        int mxArea = 0;
        for(int i = 0; i < n; i++) {
            mxArea = max(mxArea, largestRectangleAreaInHisto(heights[i]));
        }
    
        return mxArea;
    }
};
























class Solution {
public:
    int largestRectangleAreaInHisto(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);
        
        stack<int> mystack;
        
        // Fill left
        for(int i = 0; i < n; i++) {
            if(mystack.empty()) {
                left[i] = 0;
                mystack.push(i);
            } else {
                while(!mystack.empty() and heights[mystack.top()] >= heights[i]) {
                    mystack.pop();
                }
                left[i] = mystack.empty() ? 0 : mystack.top() + 1;
                mystack.push(i);
            }
        }
        
        //Clear stack (reusing)
        while(!mystack.empty()) {
            mystack.pop();
        }
        
        // Fill right
        for(int i = n - 1; i >=0; i--) {
            if(mystack.empty()) {
                right[i] = n-1;
                mystack.push(i);
            } else {
                while(!mystack.empty() and heights[mystack.top()] >= heights[i]) {
                    mystack.pop();
                }
                right[i] = mystack.empty() ? n - 1 : mystack.top() - 1;
                mystack.push(i);
            }
        }
        
        int mxArea = 0;
        for(int i=0;i<n;++i)
            mxArea = max(mxArea, heights[i] * (right[i] - left[i] + 1));
        return mxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        
        vector<vector<int>> heights(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0) {
                    heights[i][j] = matrix[i][j] - 48;
                } else {
                    if(matrix[i][j] == '0') {
                        heights[i][j] = 0;
                    } else {
                        heights[i][j] += (1 + heights[i - 1][j]);
                    }
                }
            }
        }
        
        int mxArea = 0;
        for(int i = 0; i < n; i++) {
            mxArea = max(mxArea, largestRectangleAreaInHisto(heights[i]));
        }
    
        return mxArea;
    }
};
